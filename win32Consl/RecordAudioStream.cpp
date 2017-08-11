#include "stdafx.h"
#include "RecordAudioStream.h"


//转换格式为16bits
BOOL RecordAudioStream::AdjustFormatTo16Bits(WAVEFORMATEX * pwfx)
{
	BOOL bRet(FALSE);

	if (pwfx->wFormatTag == WAVE_FORMAT_IEEE_FLOAT)
	{
		pwfx->wFormatTag = WAVE_FORMAT_PCM;
		pwfx->wBitsPerSample = 16;
		pwfx->nBlockAlign = pwfx->nChannels * pwfx->wBitsPerSample / 8;
		pwfx->nAvgBytesPerSec = pwfx->nBlockAlign * pwfx->nSamplesPerSec;

		bRet = TRUE;
	}
	else if (pwfx->wFormatTag == WAVE_FORMAT_EXTENSIBLE)
	{
		PWAVEFORMATEXTENSIBLE pEx = reinterpret_cast<PWAVEFORMATEXTENSIBLE>(pwfx);
		if (IsEqualGUID(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT, pEx->SubFormat))
		{
			pEx->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
			pEx->Samples.wValidBitsPerSample = 16;
			pwfx->wBitsPerSample = 16;
			pwfx->nBlockAlign = pwfx->nChannels * pwfx->wBitsPerSample / 8;
			pwfx->nAvgBytesPerSec = pwfx->nBlockAlign * pwfx->nSamplesPerSec;

			bRet = TRUE;
		}
	}

	return bRet;
}

//录制音频, 可选参数录制时度，频响范围，采样率(决定波形疏密)
HRESULT RecordAudioStream::Record(MyAudioSink *pMySink)
{
	HRESULT				hr;
	REFERENCE_TIME		hnsActualDuration; //100ns实际周期
	UINT32				bufferFrameCount; //缓冲帧数
	UINT32				numFramesAvailable; //可用帧数
	BYTE *				pData; //音频数据
	DWORD				flags;

	REFERENCE_TIME			hnsRequestedDuration = REFTIMES_PER_SEC; //1s缓冲请求
	IMMDeviceEnumerator *	pEnumerator = NULL;  //音频设备枚举器
	IMMDevice *				pDevice = NULL;      //选中的音频设备
	IAudioClient *			pAudioClient = NULL; //音频客户端
	IAudioCaptureClient *	pCaptureClient = NULL;//音频捕获客户端
	WAVEFORMATEX *			pwfx = NULL;          //音频格式  
	UINT32					packetLength = 0;     //打包长度
	BOOL					bDone = FALSE;

	//首先枚举你的音频设备，你可以在这个时候获取到你机器上所有可用的设备
	//并指定你需要用到的那个设置

	//初始化音频设备枚举器 pEnumerator
	hr = CoCreateInstance(
		CLSID_MMDeviceEnumerator, NULL,
		CLSCTX_ALL, IID_IMMDeviceEnumerator,
		(void**)&pEnumerator);
	EXIT_ON_ERROR(hr)

		//音频设备枚举器获取默认音频终端设备
		hr = pEnumerator->GetDefaultAudioEndpoint(
			eCapture, eConsole, &pDevice);
	EXIT_ON_ERROR(hr)

		// 创建一个管理对象COM，通过它可以获取到你需要的一切数据  
		hr = pDevice->Activate(
			IID_IAudioClient, CLSCTX_ALL,
			NULL, (void**)&pAudioClient);
	EXIT_ON_ERROR(hr)
	
		//这里面就可以获取，音频终端设备，的数据格式：频率，采集位数，声道数  
		hr = pAudioClient->GetMixFormat(&pwfx);
	EXIT_ON_ERROR(hr)
		
		//初始化管理对象，指定它的最大缓冲区长度，这个很重要
		//应用程序控制数据块的大小以及延时长短都 靠这里的初始化，具体参数大家看看文档解释 
		hr = pAudioClient->Initialize(
			AUDCLNT_SHAREMODE_EXCLUSIVE,//---SHARED其他IAudioCilent可用---EXCLUSIVE独占
			0,						//StreamFlags 
			hnsRequestedDuration,  //hnsBufferDuration：1s缓冲时长请求
			0,						//hnsPeriodicity设备周期，设置为0则使用默认
			pwfx,					//音频format
			NULL);
	EXIT_ON_ERROR(hr)
		//hnsBufferDuration，终点缓冲时长
		//hnsPeriodicity，设备周期。仅在exclusive独占模式可设为非0，shared共享模式则一定为0。 
		//在独占模式，该参数设定 请求设备周期来连续地读取缓冲数据，通过端点设备。
		//如果这个请求设备周期超出设备的最小周期及系统最大周期, 那么该方法 clamps固定 这个周期到该范围,,即丢帧。
		//如果设为0, 该方法将设备周期设为它的默认值。
		//要获取默认的设备周期, 调用 IAudioClient::GetDevicePeriod 方法. 
		//如果设置 AUDCLNT_STREAMFLAGS_EVENTCALLBACK 流标签，并且 AUDCLNT_SHAREMODE_EXCLUSIVE 设置为 ShareMode, 
		//那么 hnsPeriodicity 一定是非0 并且 等于 hnsBufferDuration.

		// Get the size of the allocated buffer.
		//这个buffersize，指的是缓冲区最多可以存放多少帧的数据量 
		//每帧大小为pwfx.nChannels*pwfx.wBitsPerSample
		hr = pAudioClient->GetBufferSize(&bufferFrameCount);
	EXIT_ON_ERROR(hr)

		//创建采集管理接口，这个接口很简单，没什么重要的东西  
		hr = pAudioClient->GetService(
			IID_IAudioCaptureClient,
			(void**)&pCaptureClient);
	EXIT_ON_ERROR(hr)

		// Notify the audio sink which format to use.
		//指定数据格式，计算数据量 
		//这就决定了，pMySink每一次读取数据量的大小，保证我们在获取的每一帧数据都是正确的 
		hr = pMySink->SetFormat(pwfx);
	EXIT_ON_ERROR(hr)

		// Calculate the actual duration of the allocated buffer.
		//填满一个指定缓冲时长所需真实时间
		hnsActualDuration = (double)REFTIMES_PER_SEC * 
		bufferFrameCount / pwfx->nSamplesPerSec;

	hr = pAudioClient->Start();  // Start recording.
	EXIT_ON_ERROR(hr)

		// Each loop fills about half of the shared buffer.
		while (bDone == FALSE)
		{
			// Sleep for half the buffer duration.
			//让程序暂停运行一段时间，缓冲区里在这段时间会被填充数据  
			Sleep(hnsActualDuration / REFTIMES_PER_MILLISEC / 2);

			hr = pCaptureClient->GetNextPacketSize(&packetLength);
			EXIT_ON_ERROR(hr)

				while (packetLength != 0)
				{
					// Get the available data in the shared buffer.
					//锁定缓冲区，获取数据
					hr = pCaptureClient->GetBuffer(
						&pData,
						&numFramesAvailable,
						&flags, NULL, NULL);
					EXIT_ON_ERROR(hr)

						if (flags & AUDCLNT_BUFFERFLAGS_SILENT)
						{
							pData = NULL;  // Tell CopyData to write silence.
						}

					// Copy the available capture data to the audio sink.
					hr = pMySink->CopyData(
						(char *)pData, numFramesAvailable, &bDone);
					EXIT_ON_ERROR(hr)

						hr = pCaptureClient->ReleaseBuffer(numFramesAvailable);
					EXIT_ON_ERROR(hr)

						hr = pCaptureClient->GetNextPacketSize(&packetLength);
					EXIT_ON_ERROR(hr)
				}
		}

	hr = pAudioClient->Stop();  // Stop recording.
	EXIT_ON_ERROR(hr)

		Exit:
	CoTaskMemFree(pwfx);
	SAFE_RELEASE(pEnumerator)
		SAFE_RELEASE(pDevice)
		SAFE_RELEASE(pAudioClient)
		SAFE_RELEASE(pCaptureClient)

		return hr;
}

RecordAudioStream::RecordAudioStream()
{
}


RecordAudioStream::~RecordAudioStream()
{
}
