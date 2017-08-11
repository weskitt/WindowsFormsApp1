#pragma once
class SymbolLinkAttr
{
public:

	char type; //词桥 B，C，E，用于分词
	int count; //链接次数，用于分权
	bool flag[4]; //词功能，仅当词桥是E时作用
				 //Alone, Verb, Noun, Mod

	//自定义默认词桥属性构造
	SymbolLinkAttr()
	{
		type = 'O';
		count = 0;
		bool flag[] = { true, false, false, false };
	}//                 Alone Verb   Noun   Mod
	//自定义词桥属性构造
	SymbolLinkAttr(char t, const bool *f, int c = 0)
	{
		type = t;
		count = c;

		//if (f[ALONE])
		//	flag[ALONE] = true; //设置该连接词性属性
		if (f[VERB])
			flag[VERB] = true; //设置该连接词性属性
		if (f[NOUN])
			flag[NOUN] = true; //设置该连接词性属性
		if (f[MOD])
			flag[MOD] = true; //设置该连接词性属性
	}
	//默认析构
	~SymbolLinkAttr()
	{
	}
};

