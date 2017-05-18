#pragma once
class LinkAttribute
{

public:
	char type; //�������ͣ����ڷִ�
	int count; //���Ӵ��������ڷ�Ȩ
	bool fun[3]; //���ӹ��ܣ��﷨:Verb, Noun, Mod

	LinkAttribute()
	{
		type = 'O';
		count = 0;
		bool fun[] = { false, false, false };
	}
	LinkAttribute(char t, const bool *f, int c=0)
	{
		type = t;
		count = c;

		if (f[VERB])
			fun[VERB] = true; //���ø����Ӵ�������
		if (f[NOUN])
			fun[NOUN] = true; //���ø����Ӵ�������
		if (f[MOD])
			fun[MOD] = true; //���ø����Ӵ�������
	}

	~LinkAttribute()
	{
	}
};

