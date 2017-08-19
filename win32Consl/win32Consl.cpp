// win32Consl.cpp : 定义控制台应用程序的入口点。
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
	Sensor.detach();; //等待第一次获取数据
	
	while (1)
	{






		
	}

	
//	Audio.Record(hearing);

    return 0;
}

