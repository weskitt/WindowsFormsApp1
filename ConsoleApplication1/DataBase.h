#pragma once

class DataBase
{
	map<wchar_t, Link> wordsData; //�ʿ�

public:
	bool Ifdata(wchar_t key);
	void AddWords(wstring words, char type, const bool *fun);

	DataBase();
	~DataBase();
};

