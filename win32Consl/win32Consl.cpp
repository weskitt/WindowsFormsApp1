// win32Consl.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	FILE *fp;
	fopen_s(&fp, "C://Users/Akitt/Music/record.pcm", "wb");
	CoInitialize(NULL);
	RecordAudioStream Audio;
	MyAudioSink test(fp);
	Audio.Record(&test);

    return 0;
}

