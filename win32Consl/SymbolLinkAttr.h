#pragma once
class SymbolLinkAttr
{
public:

	char type; //链接类型，用于分词
	int count; //链接次数，用于分权
	bool fun[3]; //链接功能，语法:Verb, Noun, Mod


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
			fun[VERB] = true; //设置该连接词性属性
		if (f[NOUN])
			fun[NOUN] = true; //设置该连接词性属性
		if (f[MOD])
			fun[MOD] = true; //设置该连接词性属性
	}

	~SymbolLinkAttr()
	{
	}
};

