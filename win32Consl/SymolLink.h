#pragma once

using namespace std;

class SymolLink
{
	map<wchar_t, SymbolLinkAttr> subWords;
	map<wchar_t, SymbolLinkAttr>::iterator iter;
	//��wchar_t=���ա�����SymbolLinkAttr->ALONE==trueʱ���ж�Ϊ������
	
public:
	//����link����
	bool IfLink(wchar_t key) {
		if (subWords.find(key) == subWords.end())
			return false; //������
		else
			return true; //���ڸ�key
	}

public:
	//���link����
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

	//Ĭ�Ϲ���
	SymolLink()
	{
	}
	//Ĭ������
	~SymolLink()
	{
	}
};

