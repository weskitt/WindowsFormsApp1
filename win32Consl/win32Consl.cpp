// win32Consl.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//Sensor.detach(); //�ȴ���һ�λ�ȡ����
	
	//d�ȴ� Capture
	//state //ϵͳ״̬feel�����������߼�ǰ�ں���Ҫ�����ڹ��ɺ����߼�
	struct State
	{
		//�й���
		//�������������� �����ı任�͸ߵͶ�֮��Ӱ��
		//������
		//����������͸�Ӧ
		//
		//�������
		int EPC;//�������  ϲ��ŭ  expectation EPC
		int MOOD;//��������  �֣���  mood		MOOD
		//
		//
	};
	//Action act; //ִ�в�
	while (1)
	{






		//update Capture
	}

	
//	Audio.Record(hearing);

    return 0;
}

