#pragma once
//-----------------------------------------------------------
// Record an audio stream from the default audio capture device
// ¼��һ������Ĭ����Ƶ�����豸

// The RecordAudioStream function allocates a shared buffer big enough to hold one second of PCM audio data.
// RecordAudioStream����һ���㹻��Ĺ�����������1s����Ƶ����

// The function uses this buffer to stream data from the capture device.
// �ú���ʹ�������������ȡ���ݴ���Ƶ�����豸

// The main loop runs every 1/2 second.
// ������ѭ��ÿ0.5s����һ��
//-----------------------------------------------------------

// REFERENCE_TIME time units ÿ����ÿ����
// REFERENCE_TIME 100ns base unit
// ����ʱ��
#define REFTIMES_PER_SEC  10000000  //10000000*100ns == 10000*100us == 1000ms ==1s
#define REFTIMES_PER_MILLISEC  10000//10000*100ns == 1000us == 1ms

#define EXIT_ON_ERROR(hres)  \
              if (FAILED(hres)) { goto Exit; }
#define SAFE_RELEASE(punk)  \
              if ((punk) != NULL)  \
                { (punk)->Release(); (punk) = NULL; }



class RecordAudioStream
{

public:

	const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
	const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
	const IID IID_IAudioClient = __uuidof(IAudioClient);
	const IID IID_IAudioCaptureClient = __uuidof(IAudioCaptureClient);

	BOOL AdjustFormatTo16Bits(WAVEFORMATEX *pwfx);
	HRESULT Record(MyAudioSink *pMySink);

	RecordAudioStream();
	~RecordAudioStream();
};

