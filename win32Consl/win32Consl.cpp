// win32Consl.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
HRESULT				hr;

int main()
{
	//FILE *fp;
	//fopen_s(&fp, "C://Users/Akitt/Music/record.pcm", "wb");


	CoInitialize(NULL);
	
	Hearing hearing;
	hearing.HearingInit();

	auto thr = bind(&Hearing::Record, hearing);
	thread Sensor(thr);
	Sensor.detach();; //�ȴ���һ�λ�ȡ����
	
	while (1)
	{






		
	}

	
//	Audio.Record(hearing);

    return 0;
}

