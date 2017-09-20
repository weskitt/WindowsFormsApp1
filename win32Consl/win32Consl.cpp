// win32Consl.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
HRESULT				hr;

int main()
{
	//FILE *fp;
	//fopen_s(&fp, "C://Users/Akitt/Music/record.pcm", "wb");


	//CoInitialize(NULL);
	
	//Hearing hearing;
	//hearing.HearingInit();

	//auto thr = bind(&Hearing::Record, hearing);
	//thread Sensor(thr);
	//Sensor.detach(); //等待第一次获取数据
	
	//d等待 Capture
	//state //系统状态feel，情绪，无逻辑前期很重要，用于构成后期逻辑
	struct State
	{
		//感光器
		//声音能量感受器 能量的变换和高低对之有影响
		//感温器
		//人体红外热释感应
		//
		//虚拟情感
		int EPC;//对外表现  喜，怒  expectation EPC
		int MOOD;//自身体现  乐，哀  mood		MOOD
		//
		//
	};
	//Action act; //执行部
	while (1)
	{






		//update Capture
	}

	
//	Audio.Record(hearing);

    return 0;
}

