// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

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

// TODO: 在此处引用程序需要的其他头文件

#include "base.h"
#include "SymbolLinkAttr.h"
#include "SymolLink.h"
#include "SymDataBase.h"
#include "MyAudioSink.h"
#include "RecordAudioStream.h"