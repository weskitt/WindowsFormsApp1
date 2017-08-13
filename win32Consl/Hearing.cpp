#include "stdafx.h"
#include "Hearing.h"


void Hearing::HearingInit()
{
	//首先枚举你的音频设备，你可以在这个时候获取到你机器上所有可用的设备
	//并指定你需要用到的那个设置

	//初始化音频设备枚举器 pEnumerator
	hr = CoCreateInstance( CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL, IID_IMMDeviceEnumerator, (void**)&pEnumerator); 
	EXIT_ON_ERROR(hr)

	//音频设备枚举器获取默认音频终端设备
	hr = pEnumerator->GetDefaultAudioEndpoint( eCapture, eConsole, &pDevice); 
	EXIT_ON_ERROR(hr)

	// 创建一个管理对象COM，通过它可以获取到你需要的一切数据  
	hr = pDevice->Activate( IID_IAudioClient, CLSCTX_ALL, NULL, (void**)&pAudioClient); 
	EXIT_ON_ERROR(hr)
	
	//这里面就可以获取，音频终端设备，的数据格式：频率，采集位数，声道数  
	hr = pAudioClient->GetMixFormat(&pwfx); 
	EXIT_ON_ERROR(hr)
		
	//初始化管理对象，指定它的最大缓冲区长度，这个很重要
	//应用程序控制数据块的大小以及延时长短都 靠这里的初始化，具体参数大家看看文档解释 
	hr = pAudioClient->Initialize( AUDCLNT_SHAREMODE_SHARED, 0,	hnsRequestedDuration, 0, pwfx, NULL); 
	EXIT_ON_ERROR(hr)

	hr = pAudioClient->GetBufferSize(&bufferFrameCount);  
	EXIT_ON_ERROR(hr)

	//创建采集管理接口，这个接口很简单，没什么重要的东西  
	hr = pAudioClient->GetService( IID_IAudioCaptureClient, (void**)&pCaptureClient); 
	EXIT_ON_ERROR(hr)

	// Calculate the actual duration of the allocated buffer.
	//填满一个指定缓冲时长所需真实时间
	hnsActualDuration = (double)REFTIMES_PER_SEC * bufferFrameCount / pwfx->nSamplesPerSec;


	Exit:
		CoTaskMemFree(pwfx);
		SAFE_RELEASE(pEnumerator)
		SAFE_RELEASE(pDevice)
		SAFE_RELEASE(pAudioClient)
		SAFE_RELEASE(pCaptureClient)
}

//转换格式为16bits
BOOL Hearing::AdjustFormatTo16Bits(WAVEFORMATEX * pwfx)
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
HRESULT Hearing::Record()
{
	// Start recording.
	hr = pAudioClient->Start(); 
	EXIT_ON_ERROR(hr)

	// Each loop fills about half of the shared buffer.
	while (bDone == FALSE)
	{
		//让程序暂停运行一段时间，缓冲区里在这段时间会被填充数据  
		Sleep(hnsActualDuration / REFTIMES_PER_MILLISEC / 2);//约30ms的数据量

		hr = pCaptureClient->GetNextPacketSize(&packetLength); 
		EXIT_ON_ERROR(hr)

			while (packetLength != 0) //超快内部循环，3ms完成捕获
			{
				// Get the available data in the shared buffer.
				//锁定缓冲区，获取数据
				hr = pCaptureClient->GetBuffer( &pData, &numFramesAvailable, &flags, NULL, NULL); 
				EXIT_ON_ERROR(hr)

				if (flags & AUDCLNT_BUFFERFLAGS_SILENT)
					pData = NULL;  // Tell CopyData to write silence.

				hr = pCaptureClient->ReleaseBuffer(numFramesAvailable); 
				EXIT_ON_ERROR(hr)
				hr = pCaptureClient->GetNextPacketSize(&packetLength); 
				EXIT_ON_ERROR(hr)
			}
		}
    // Stop recording.
	hr = pAudioClient->Stop(); 
	EXIT_ON_ERROR(hr)

	Exit:
		CoTaskMemFree(pwfx);
		SAFE_RELEASE(pEnumerator)
		SAFE_RELEASE(pDevice)
		SAFE_RELEASE(pAudioClient)
		SAFE_RELEASE(pCaptureClient)

		return hr;
}

Hearing::Hearing()
{
}


Hearing::~Hearing()
{
}
