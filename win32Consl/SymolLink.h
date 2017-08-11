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
	//���link����, ����ѧϰʹ��
	void AddLink(wchar_t value, char type, const bool *flag) {
		if (subWords.find(value) == subWords.end())
		{
			SymbolLinkAttr link(type, flag);
			subWords.insert(pair<wchar_t, SymbolLinkAttr>(value, link));
		}
		else
		{
			subWords[value].count += 1;
			if (flag[ALONE])
				subWords[value].flag[ALONE] = false; //���ø����Ӵ�������
			if (flag[VERB])
				subWords[value].flag[VERB] = true; //���ø����Ӵ�������
			if (flag[NOUN])
				subWords[value].flag[NOUN] = true; //���ø����Ӵ�������
			if (flag[MOD])
				subWords[value].flag[MOD] = true; //���ø����Ӵ�������
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

