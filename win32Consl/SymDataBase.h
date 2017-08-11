#pragma once

class SymDataBase
{
	//词库
	map<wchar_t, SymolLink> wordsData; 
public:
	//查找字符操作
	bool Ifdata(wchar_t key)
	{
		if (wordsData.find(key) == wordsData.end())
			return false;
		else
			return true;
	}

public:
	//添加字符操作,仅供学习使用
	void AddWords(wstring words, char type, const bool *fun)
	{
		wchar_t keyWord = words[0];
		words.erase(0, 1);
		if (wordsData.find(keyWord) == wordsData.end()) //如果词首没有有记录
		{
			SymolLink tLink;
			wordsData.insert(pair<wchar_t, SymolLink>(keyWord, tLink));
		}
		for each (wchar_t item in words)
		{
			wordsData[keyWord].AddLink(item, type, fun);
		}
	}

	//默认构造
	SymDataBase()
	{
	}
	//默认析构
	~SymDataBase()
	{
	}
};
