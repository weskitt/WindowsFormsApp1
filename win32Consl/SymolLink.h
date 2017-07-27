#pragma once

using namespace std;

class SymolLink
{
	map<wchar_t, SymbolLinkAttr> subWords;
	map<wchar_t, SymbolLinkAttr>::iterator iter;
	//当wchar_t=‘空’，且SymbolLinkAttr->ALONE==true时，判断为独立词
	
public:
	//查找link操作
	bool IfLink(wchar_t key) {
		if (subWords.find(key) == subWords.end())
			return false; //不存在
		else
			return true; //存在该key
	}

public:
	//添加link操作
	void AddLink(wchar_t value, char type, const bool *fun) {
		if (subWords.find(value) == subWords.end())
		{
			SymbolLinkAttr link(type, fun);
			subWords.insert(pair<wchar_t, SymbolLinkAttr>(value, link));
		}
		else
		{
			subWords[value].count += 1;
			if (fun[VERB])
				subWords[value].fun[VERB] = true; //设置该连接词性属性
			if (fun[NOUN])
				subWords[value].fun[NOUN] = true; //设置该连接词性属性
			if (fun[MOD])
				subWords[value].fun[MOD] = true; //设置该连接词性属性
		}
	}

	//默认构造
	SymolLink()
	{
	}
	//默认析构
	~SymolLink()
	{
	}
};

