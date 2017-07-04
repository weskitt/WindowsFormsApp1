#pragma once
class SymbolLinkAttr
{
public:

	char type; //���� B��C��E�����ڷִ�
	int count; //���Ӵ��������ڷ�Ȩ
	bool fun[3]; //�ʹ��ܣ�����������Eʱ����
				 //Verb, Noun, Mod

	//�Զ���Ĭ�ϴ������Թ���
	SymbolLinkAttr()
	{
		type = 'O';
		count = 0;
		bool fun[] = { false, false, false };
	}
	//�Զ���������Թ���
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
	//Ĭ������
	~SymbolLinkAttr()
	{
	}
};

