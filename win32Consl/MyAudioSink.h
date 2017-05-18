#pragma once
class MyAudioSink
{

public:

	FILE *fp;

	int SetFormat(WAVEFORMATEX *pwfx);

	int CopyData(char * pData, UINT32 numFramesAvailable, BOOL *pbDone);

	MyAudioSink(FILE * fp);
	~MyAudioSink();
};

