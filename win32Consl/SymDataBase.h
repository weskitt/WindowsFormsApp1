#pragma once

class SymDataBase
{
	//�ʿ�
	map<wchar_t, SymolLink> wordsData; 
public:
	//�����ַ�����
	bool Ifdata(wchar_t key)
	{
		if (wordsData.find(key) == wordsData.end())
			return false;
		else
			return true;
	}

public:
	//����ַ�����,����ѧϰʹ��
	void AddWords(wstring words, char type, const bool *fun)
	{
		wchar_t keyWord = words[0];
		words.erase(0, 1);
		if (wordsData.find(keyWord) == wordsData.end()) //�������û���м�¼
		{
			SymolLink tLink;
			wordsData.insert(pair<wchar_t, SymolLink>(keyWord, tLink));
		}
		for each (wchar_t item in words)
		{
			wordsData[keyWord].AddLink(item, type, fun);
		}
	}

	//Ĭ�Ϲ���
	SymDataBase()
	{
	}
	//Ĭ������
	~SymDataBase()
	{
	}
};
