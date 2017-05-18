// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

#include <atlbase.h>
#include <atlstr.h>

//Core Audio APIs
#include <Mmdeviceapi.h>  //MMDevice API

#include <Audiosessiontypes.h>  //defines constants that are used by WASAPI
#include <Audioclient.h>  //WASAPI
#include <Audiopolicy.h>

#include <Devicetopology.h>  //DeviceTopology API

#include <Endpointvolume.h>  //EndpointVolume API

//STL
#include <map>

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�

#include "base.h"
#include "SymbolLinkAttr.h"
#include "SymolLink.h"
#include "SymDataBase.h"
#include "MyAudioSink.h"
#include "RecordAudioStream.h"