#pragma once
//-----------------------------------------------------------
// Record an audio stream from the default audio capture device
// 录制一条流从默认音频捕获设备

// The RecordAudioStream function allocates a shared buffer big enough to hold one second of PCM audio data.
// RecordAudioStream分配一个足够大的共享缓冲来容纳1s的音频数据

// The function uses this buffer to stream data from the capture device.
// 该函数使用这个缓冲来读取数据从音频捕获设备

// The main loop runs every 1/2 second.
// 这条主循环每0.5s运行一次
//-----------------------------------------------------------

// REFERENCE_TIME time units 每秒与每毫秒
// REFERENCE_TIME 100ns base unit
// 定义时间
#define REFTIME 400000    //40MS
#define REFTIMES_PER_SEC  10000000  //10000000*100ns == 10000*100us == 1000ms ==1s
#define REFTIMES_PER_MILLISEC  10000//10000*100ns == 1000us == 1ms

#define EXIT_ON_ERROR(hres)  \
              if (FAILED(hres)) { goto Exit; }
#define SAFE_RELEASE(punk)  \
              if ((punk) != NULL)  \
                { (punk)->Release(); (punk) = NULL; }



class Hearing
{

public:

	const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
	const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
	const IID IID_IAudioClient = __uuidof(IAudioClient);
	const IID IID_IAudioCaptureClient = __uuidof(IAudioCaptureClient);

public:
	HRESULT				hr;
	REFERENCE_TIME		hnsActualDuration; //100ns实际周期
	UINT32				bufferFrameCount; //缓冲帧数
	UINT32				numFramesAvailable; //可用帧数
	BYTE *				pData; //音频数据
	DWORD				flags;
	//REFERENCE_TIME      hnsDefaultDevicePeriod(0); //默认设备周期

	//REFERENCE_TIME			hnsRequestedDuration = REFTIMES_PER_SEC; //定义1s缓冲填充等待时间
	REFERENCE_TIME			hnsRequestedDuration = REFTIME; //定义40ms缓冲填充等待时间
	IMMDeviceEnumerator *	pEnumerator			 = NULL;  //音频设备枚举器
	IMMDevice *				pDevice				 = NULL;  //选中的音频设备
	IAudioClient *			pAudioClient		 = NULL;  //音频客户端
	IAudioCaptureClient *	pCaptureClient		 = NULL;  //音频捕获客户端
	WAVEFORMATEX *			pwfx				 = NULL;  //音频格式  
	UINT32					packetLength		 = 0;     //打包长度
	BOOL					bDone				 = FALSE;
	HANDLE					hTimerWakeUp		 = NULL;


public:

	void HearingInit();

	//BOOL AdjustFormatTo16Bits(WAVEFORMATEX *pwfx);
	HRESULT Record();

	Hearing();
	~Hearing();
};

