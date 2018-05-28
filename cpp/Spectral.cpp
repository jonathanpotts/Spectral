// Copyright 2018 Jonathan Potts. All rights reserved.

#include "stdafx.h"
#include "Spectral.h"

using namespace std;
using namespace Spectral;

#define SPECTRALDLL L"Spectral.dll"

HMODULE SpectralHandle = nullptr;

typedef bool(*SPECTRALINITIALIZE)(void);
typedef bool(*SPECTRALISINITIALIZED)(void);
typedef bool(*SPECTRALLOGITECHISENABLED)(void);
typedef bool(*SPECTRALCORSAIRISENABLED)(void);
typedef bool(*SPECTRALRAZERISENABLED)(void);
typedef bool(*SPECTRALSETCOLOR)(unsigned char red, unsigned char green, unsigned char blue);
typedef bool(*SPECTRALSETCOLORFORLED)(LedName ledName, unsigned char red, unsigned char green, unsigned char blue);
typedef bool(*SPECTRALSETCOLORFORLEDS)(int count, LedName *ledName, unsigned char red, unsigned char green, unsigned char blue);
typedef bool(*SPECTRALSETCOLORFORDEVICE)(DeviceType deviceType, unsigned char red, unsigned char green, unsigned char blue);
typedef void(*SPECTRALSHUTDOWN)(void);

SPECTRALINITIALIZE SpectralInitialize = nullptr;
SPECTRALISINITIALIZED SpectralIsInitialized = nullptr;
SPECTRALLOGITECHISENABLED SpectralLogitechIsEnabled = nullptr;
SPECTRALCORSAIRISENABLED SpectralCorsairIsEnabled = nullptr;
SPECTRALRAZERISENABLED SpectralRazerIsEnabled = nullptr;
SPECTRALSETCOLOR SpectralSetColor = nullptr;
SPECTRALSETCOLORFORLED SpectralSetColorForLed = nullptr;
SPECTRALSETCOLORFORLEDS SpectralSetColorForLeds = nullptr;
SPECTRALSETCOLORFORDEVICE SpectralSetColorForDevice = nullptr;
SPECTRALSHUTDOWN SpectralShutdown = nullptr;

bool Led::Initialize()
{
	if (SpectralHandle == nullptr)
	{
		SpectralHandle = LoadLibrary(SPECTRALDLL);

		if (SpectralHandle != nullptr)
		{
			SpectralInitialize = (SPECTRALINITIALIZE)GetProcAddress(SpectralHandle, "SpectralInitialize");
			SpectralIsInitialized = (SPECTRALISINITIALIZED)GetProcAddress(SpectralHandle, "SpectralIsInitialized");
			SpectralLogitechIsEnabled = (SPECTRALLOGITECHISENABLED)GetProcAddress(SpectralHandle, "SpectralLogitechIsEnabled");
			SpectralCorsairIsEnabled = (SPECTRALCORSAIRISENABLED)GetProcAddress(SpectralHandle, "SpectralCorsairIsEnabled");
			SpectralRazerIsEnabled = (SPECTRALRAZERISENABLED)GetProcAddress(SpectralHandle, "SpectralRazerIsEnabled");
			SpectralSetColor = (SPECTRALSETCOLOR)GetProcAddress(SpectralHandle, "SpectralSetColor");
			SpectralSetColorForLed = (SPECTRALSETCOLORFORLED)GetProcAddress(SpectralHandle, "SpectralSetColorForLed");
			SpectralSetColorForLeds = (SPECTRALSETCOLORFORLEDS)GetProcAddress(SpectralHandle, "SpectralSetColorForLeds");
			SpectralSetColorForDevice = (SPECTRALSETCOLORFORDEVICE)GetProcAddress(SpectralHandle, "SpectralSetColorForDevice");
			SpectralShutdown = (SPECTRALSHUTDOWN)GetProcAddress(SpectralHandle, "SpectralShutdown");
		}
	}
	
	if (SpectralInitialize != nullptr)
	{
		return SpectralInitialize();
	}
	else
	{
		return false;
	}
}

bool Led::IsInitialized()
{
	if (SpectralIsInitialized != nullptr)
	{
		return SpectralIsInitialized();
	}
	else
	{
		return false;
	}
}

bool Led::LogitechIsEnabled()
{
	if (SpectralLogitechIsEnabled != nullptr)
	{
		return SpectralLogitechIsEnabled();
	}
	else
	{
		return false;
	}
}

bool Led::CorsairIsEnabled()
{
	if (SpectralCorsairIsEnabled != nullptr)
	{
		return SpectralCorsairIsEnabled();
	}
	else
	{
		return false;
	}
}

bool Led::RazerIsEnabled()
{
	if (SpectralRazerIsEnabled != nullptr)
	{
		return SpectralRazerIsEnabled();
	}
	else
	{
		return false;
	}
}

bool Led::SetColor(unsigned char red, unsigned char green, unsigned char blue)
{
	if (SpectralSetColor == nullptr)
	{
		Initialize();
	}

	if (SpectralSetColor != nullptr)
	{
		return SpectralSetColor(red, green, blue);
	}
	else
	{
		return false;
	}
}

bool Led::SetColorForLed(LedName ledName, unsigned char red, unsigned char green, unsigned char blue)
{
	if (SpectralSetColorForLed == nullptr)
	{
		Initialize();
	}

	if (SpectralSetColorForLed != nullptr)
	{
		return SpectralSetColorForLed(ledName, red, green, blue);
	}
	else
	{
		return false;
	}
}

bool Led::SetColorForLeds(vector<LedName> ledNames, unsigned char red, unsigned char green, unsigned char blue)
{
	if (SpectralSetColorForLeds == nullptr)
	{
		Initialize();
	}

	if (SpectralSetColorForLeds != nullptr)
	{
		return SpectralSetColorForLeds((int)ledNames.size(), &ledNames[0], red, green, blue);
	}
	else
	{
		return false;
	}
}

bool Led::SetColorForDevice(DeviceType deviceType, unsigned char red, unsigned char green, unsigned char blue)
{
	if (SpectralSetColorForDevice == nullptr)
	{
		Initialize();
	}

	if (SpectralSetColorForDevice != nullptr)
	{
		return SpectralSetColorForDevice(deviceType, red, green, blue);
	}
	else
	{
		return false;
	}
}


void Led::Shutdown()
{
	if (SpectralShutdown != nullptr)
	{
		SpectralShutdown();
	}
}