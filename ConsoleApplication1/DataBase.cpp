#include "stdafx.h"
#include "DataBase.h"

bool DataBase::Ifdata(wchar_t key)
{
	if (wordsData.find(key) == wordsData.end())
		return false;
	else
		return true;
}

void DataBase::AddWords(wstring words, char type, const bool *fun)
{
	char keyWord = words[0];
	words.erase(0, 1);
	if (wordsData.find(keyWord) == wordsData.end()) //如果词首没有有记录
	{
		Link tLink;
		wordsData.insert(pair<wchar_t, Link>(keyWord, tLink));
	}
	for each (wchar_t item in words)
	{
		wordsData[keyWord].AddLink(item, type, fun);
	}
}

DataBase::DataBase()
{
}


DataBase::~DataBase()
{
}
