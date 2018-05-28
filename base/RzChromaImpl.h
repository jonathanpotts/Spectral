// Based on Razer SDK Example. Copyright Razer. All rights reserved.
// All additions/changes:
// Copyright 2018 Jonathan Potts. All rights reserved.

#pragma once

#include "stdafx.h"

#define ALL_DEVICES         0
#define KEYBOARD_DEVICES    1
#define MOUSEMAT_DEVICES    2
#define MOUSE_DEVICES       3
#define HEADSET_DEVICES     4
#define KEYPAD_DEVICES      5

class RzChromaImpl
{
public:
	RzChromaImpl();
	~RzChromaImpl();
	BOOL Initialize();

	void Shutdown();

	void ResetEffects(size_t DeviceType);

	//Define your methods here
	BOOL SetColorForKey(ChromaSDK::Keyboard::RZKEY key, UCHAR red, UCHAR green, UCHAR blue);
	BOOL SetColorForKeyboardLogo(UCHAR red, UCHAR green, UCHAR blue);
	BOOL SetColorForMouseLed(ChromaSDK::Mouse::RZLED2 led, UCHAR red, UCHAR green, UCHAR blue);
	BOOL SetColorForHeadsetZone(UCHAR zone, UCHAR red, UCHAR green, UCHAR blue);
	BOOL SetColorForMousepadZone(UCHAR zone, UCHAR red, UCHAR green, UCHAR blue);
	BOOL IsDeviceConnected(RZDEVICEID DeviceId);

private:
	HMODULE m_ChromaSDKModule;
};