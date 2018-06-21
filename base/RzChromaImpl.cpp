// Based on Razer SDK Example. Copyright Razer. All rights reserved.
// All additions/changes:
// Copyright 2018 Jonathan Potts. All rights reserved.

#include "stdafx.h"

#ifdef _WIN64
#define CHROMASDKDLL        _T("RzChromaSDK64.dll")
#else
#define CHROMASDKDLL        _T("RzChromaSDK.dll")
#endif

using namespace ChromaSDK;
using namespace ChromaSDK::Keyboard;
using namespace ChromaSDK::Keypad;
using namespace ChromaSDK::Mouse;
using namespace ChromaSDK::Mousepad;
using namespace ChromaSDK::Headset;
using namespace std;

typedef RZRESULT(*INIT)(void);
typedef RZRESULT(*UNINIT)(void);
typedef RZRESULT(*CREATEEFFECT)(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEKEYBOARDEFFECT)(ChromaSDK::Keyboard::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEHEADSETEFFECT)(ChromaSDK::Headset::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEMOUSEPADEFFECT)(ChromaSDK::Mousepad::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEMOUSEEFFECT)(ChromaSDK::Mouse::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEKEYPADEFFECT)(ChromaSDK::Keypad::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*SETEFFECT)(RZEFFECTID EffectId);
typedef RZRESULT(*DELETEEFFECT)(RZEFFECTID EffectId);
typedef RZRESULT(*REGISTEREVENTNOTIFICATION)(HWND hWnd);
typedef RZRESULT(*UNREGISTEREVENTNOTIFICATION)(void);
typedef RZRESULT(*QUERYDEVICE)(RZDEVICEID DeviceId, ChromaSDK::DEVICE_INFO_TYPE &DeviceInfo);

INIT Init = nullptr;
UNINIT UnInit = nullptr;
CREATEEFFECT CreateEffect = nullptr;
CREATEKEYBOARDEFFECT CreateKeyboardEffect = nullptr;
CREATEMOUSEEFFECT CreateMouseEffect = nullptr;
CREATEHEADSETEFFECT CreateHeadsetEffect = nullptr;
CREATEMOUSEPADEFFECT CreateMousepadEffect = nullptr;
CREATEKEYPADEFFECT CreateKeypadEffect = nullptr;
SETEFFECT SetEffect = nullptr;
DELETEEFFECT DeleteEffect = nullptr;
QUERYDEVICE QueryDevice = nullptr;

BOOL RzChromaImpl::IsDeviceConnected(RZDEVICEID DeviceId)
{
	if (QueryDevice != nullptr)
	{
		ChromaSDK::DEVICE_INFO_TYPE DeviceInfo = {};
		auto Result = QueryDevice(DeviceId, DeviceInfo);

		return DeviceInfo.Connected;
	}

	return FALSE;
}

RzChromaImpl::RzChromaImpl() :m_ChromaSDKModule(nullptr)
{
}
RzChromaImpl::~RzChromaImpl()
{
}

BOOL RzChromaImpl::Initialize()
{
	if (m_ChromaSDKModule == nullptr)
	{
		m_ChromaSDKModule = LoadLibrary(CHROMASDKDLL);
		if (m_ChromaSDKModule == nullptr)
		{
			return FALSE;
		}
	}

	if (Init == nullptr)
	{
		auto Result = RZRESULT_INVALID;
		Init = reinterpret_cast<INIT>(GetProcAddress(m_ChromaSDKModule, "Init"));
		if (Init)
		{
			Result = Init();
			if (Result == RZRESULT_SUCCESS)
			{
				UnInit = reinterpret_cast<UNINIT>(GetProcAddress(m_ChromaSDKModule, "UnInit"));
				CreateEffect = reinterpret_cast<CREATEEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateEffect"));
				CreateKeyboardEffect = reinterpret_cast<CREATEKEYBOARDEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateKeyboardEffect"));
				CreateMouseEffect = reinterpret_cast<CREATEMOUSEEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateMouseEffect"));
				CreateHeadsetEffect = reinterpret_cast<CREATEHEADSETEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateHeadsetEffect"));
				CreateMousepadEffect = reinterpret_cast<CREATEMOUSEPADEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateMousepadEffect"));
				CreateKeypadEffect = reinterpret_cast<CREATEKEYPADEFFECT>(GetProcAddress(m_ChromaSDKModule, "CreateKeypadEffect"));
				SetEffect = reinterpret_cast<SETEFFECT>(GetProcAddress(m_ChromaSDKModule, "SetEffect"));
				DeleteEffect = reinterpret_cast<DELETEEFFECT>(GetProcAddress(m_ChromaSDKModule, "DeleteEffect"));
				QueryDevice = reinterpret_cast<QUERYDEVICE>(GetProcAddress(m_ChromaSDKModule, "QueryDevice"));

				if (UnInit &&
					CreateEffect &&
					CreateKeyboardEffect &&
					CreateMouseEffect &&
					CreateHeadsetEffect &&
					CreateMousepadEffect &&
					CreateKeypadEffect &&
					SetEffect &&
					DeleteEffect &&
					QueryDevice)
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
			}
		}
	}

	return TRUE;
}

void RzChromaImpl::Shutdown()
{
	if (UnInit != nullptr)
	{
		UnInit();
	}
}

void RzChromaImpl::ResetEffects(size_t DeviceType)
{
	switch (DeviceType)
	{
	case 0:
		if (CreateKeyboardEffect)
		{
			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, nullptr, nullptr);
		}

		if (CreateMousepadEffect)
		{
			CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, nullptr, nullptr);
		}

		if (CreateMouseEffect)
		{
			CreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, nullptr, nullptr);
		}

		if (CreateHeadsetEffect)
		{
			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, nullptr, nullptr);
		}

		if (CreateKeypadEffect)
		{
			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 1:
		if (CreateKeyboardEffect)
		{
			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 2:
		if (CreateMousepadEffect)
		{
			CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 3:
		if (CreateMouseEffect)
		{
			CreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 4:
		if (CreateHeadsetEffect)
		{
			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	case 5:
		if (CreateKeypadEffect)
		{
			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, nullptr, nullptr);
		}
		break;
	}
}

BOOL RzChromaImpl::SetColorForKey(ChromaSDK::Keyboard::RZKEY key, UCHAR red, UCHAR green, UCHAR blue)
{
	Keyboard::CUSTOM_KEY_EFFECT_TYPE keyboardEffect = {};
	keyboardEffect.Key[HIBYTE(key)][LOBYTE(key)] = 0x01000000 | RGB(red, green, blue);

	RZRESULT result = CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &keyboardEffect, nullptr);
	return (result == RZRESULT_SUCCESS);
}

BOOL RzChromaImpl::SetColorForKeyboardLogo(UCHAR red, UCHAR green, UCHAR blue)
{
	Keyboard::CUSTOM_KEY_EFFECT_TYPE keyboardEffect = {};
	keyboardEffect.Key[HIBYTE(ChromaSDK::Keyboard::RZLED_LOGO)][LOBYTE(ChromaSDK::Keyboard::RZLED_LOGO)] = 0x01000000 | RGB(red, green, blue);

	RZRESULT result = CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &keyboardEffect, nullptr);
	return (result == RZRESULT_SUCCESS);
}

BOOL RzChromaImpl::SetColorForMouseLed(ChromaSDK::Mouse::RZLED2 led, UCHAR red, UCHAR green, UCHAR blue)
{
	Mouse::CUSTOM_EFFECT_TYPE2 mouseEffect = {};
	mouseEffect.Color[HIBYTE(led)][LOBYTE(led)] = RGB(red, green, blue);

	RZRESULT result = CreateMouseEffect(Mouse::CHROMA_CUSTOM2, &mouseEffect, nullptr);
	return (result == RZRESULT_SUCCESS);
}

BOOL RzChromaImpl::SetColorForHeadsetZone(UCHAR zone, UCHAR red, UCHAR green, UCHAR blue)
{
	Headset::CUSTOM_EFFECT_TYPE headsetEffect = {};
	headsetEffect.Color[zone] = RGB(red, green, blue);

	RZRESULT result = CreateHeadsetEffect(Headset::CHROMA_CUSTOM, &headsetEffect, nullptr);
	return (result == RZRESULT_SUCCESS);
}

BOOL RzChromaImpl::SetColorForMousepadZone(UCHAR zone, UCHAR red, UCHAR green, UCHAR blue)
{
	Mousepad::CUSTOM_EFFECT_TYPE mousepadEffect = {};
	mousepadEffect.Color[zone] = RGB(red, green, blue);

	RZRESULT result = CreateMousepadEffect(Mousepad::CHROMA_CUSTOM, &mousepadEffect, nullptr);
	return (result == RZRESULT_SUCCESS);
}