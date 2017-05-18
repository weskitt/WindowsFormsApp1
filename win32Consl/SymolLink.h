#pragma once

using namespace std;

class SymolLink
{
	map<wchar_t, SymbolLinkAttr> subWords;
	map<wchar_t, SymbolLinkAttr>::iterator iter;

public:

	bool IfLink(wchar_t key) {
		if (subWords.find(key) == subWords.end())
			return false; //������
		else
			return true; //���ڸ�key
	}

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
				subWords[value].fun[VERB] = true; //���ø����Ӵ�������
			if (fun[NOUN])
				subWords[value].fun[NOUN] = true; //���ø����Ӵ�������
			if (fun[MOD])
				subWords[value].fun[MOD] = true; //���ø����Ӵ�������
		}
	}


	SymolLink()
	{
	}

	~SymolLink()
	{
	}
};

