#pragma once
class SymbolLinkAttr
{
public:

	char type; //���� B��C��E�����ڷִ�
	int count; //���Ӵ��������ڷ�Ȩ
	bool flag[3]; //�����ôʱ�ǣ�����������Eʱ����, 
				 //Verb, Noun, Mod
	//vector<bool> flags; ������������
	//�Զ���Ĭ�ϴ������Թ���
	SymbolLinkAttr()
	{
		type = 'O';
		count = 0;
		bool flag[] = { false, false, false };
	}//                 Alone Verb   Noun   Mod
	//�Զ���������Թ���
	SymbolLinkAttr(char t, const bool *f, int c = 0)
	{
		type = t;
		count = c;

		//if (f[ALONE])
		//	flag[ALONE] = true; //���ø����Ӵ�������
		if (f[VERB])
			flag[VERB] = true; //���ø����Ӵ�������
		if (f[NOUN])
			flag[NOUN] = true; //���ø����Ӵ�������
		if (f[MOD])
			flag[MOD] = true; //���ø����Ӵ�������
	}
	//Ĭ������
	~SymbolLinkAttr()
	{
	}
};

