#pragma once
class SymbolLinkAttr
{
public:

	char type; //�������ͣ����ڷִ�
	int count; //���Ӵ��������ڷ�Ȩ
	bool fun[3]; //���ӹ��ܣ��﷨:Verb, Noun, Mod


	SymbolLinkAttr()
	{
		type = 'O';
		count = 0;
		bool fun[] = { false, false, false };
	}

	SymbolLinkAttr(char t, const bool *f, int c = 0)
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

	~SymbolLinkAttr()
	{
	}
};

