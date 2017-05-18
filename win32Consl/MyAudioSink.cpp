#include "stdafx.h"
#include "MyAudioSink.h"


int MyAudioSink::SetFormat(WAVEFORMATEX * pwfx)
{
	printf("wFormatTag is %x\n", pwfx->wFormatTag);
	printf("nChannels is %x\n", pwfx->nChannels);
	printf("nSamplesPerSec is %d\n", pwfx->nSamplesPerSec);
	printf("nAvgBytesPerSec is %d\n", pwfx->nAvgBytesPerSec);
	printf("wBitsPerSample is %d\n", pwfx->wBitsPerSample);

	return 0;
}

int MyAudioSink::CopyData(char * pData, UINT32 numFramesAvailable, BOOL * pbDone)
{
	if (pData != NULL)
		fwrite(pData, numFramesAvailable, 1, fp);

	return 0;
}

/// pwfx->nSamplesPerSec    = 44100; 
/// 不支持修改采样率， 看来只能等得到数据之后再 swr 转换了

MyAudioSink::MyAudioSink(FILE * fp)
{
	this->fp = fp;
}


MyAudioSink::~MyAudioSink()
{
}
