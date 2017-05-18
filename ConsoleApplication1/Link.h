#pragma once

using namespace std;

class Link
{
	map<wchar_t, LinkAttribute> subWords;
	map<wchar_t, LinkAttribute>::iterator iter;
public:

	bool IfLink(wchar_t key) {
		if (subWords.find(key) == subWords.end())
			return false; //不存在
		else
			return true; //存在该key
	}

	void AddLink(wchar_t value, char type, const bool *fun) {
		if (subWords.find(value)==subWords.end())
		{
			LinkAttribute link(value, fun);
			subWords.insert( pair<wchar_t, LinkAttribute>(value, link) );
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

	Link()
	{
	}

	~Link()
	{
	}
};

