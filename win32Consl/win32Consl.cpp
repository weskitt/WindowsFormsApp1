// win32Consl.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
HRESULT				hr;

int main()
{
	ios::sync_with_stdio(false);
	//FILE *fp;
	//fopen_s(&fp, "C://Users/Akitt/Music/record.pcm", "wb");


	//CoInitialize(NULL);
	
	//Hearing hearing;
	//hearing.HearingInit();

	//auto thr = bind(&Hearing::Record, hearing);
	//thread Sensor(thr);
	//Sensor.detach(); //�ȴ���һ�λ�ȡ����
	
	//�ȴ� Capture
	//state //ϵͳ״̬feel�����������߼�ǰ�ں���Ҫ�����ڹ��ɺ����߼�
	//LARGE_INTEGER m_start;
	//LARGE_INTEGER m_stop;
	//LARGE_INTEGER m_frequency;
	//m_start.QuadPart = 0;
	//m_stop.QuadPart = 0;
	//QueryPerformanceFrequency(&m_frequency);
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
	//ACT act; //ִ�в�
	while (1)
	{
		//QueryPerformanceCounter(&m_start);
		//...
		//QueryPerformanceCounter(&m_stop);
		//LARGE_INTEGER time;
		//time.QuadPart = m_stop.QuadPart - m_start.QuadPart;
		//double t = time.QuadPart / (double)m_frequency.QuadPart;

		

		cout << "mes" << endl;


		//update Capture
	}

	
//	Audio.Record(hearing);

    return 0;
}

