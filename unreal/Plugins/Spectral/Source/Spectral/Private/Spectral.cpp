// Copyright 2018 Jonathan Potts. All rights reserved.

#include "Spectral.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"

#define LOCTEXT_NAMESPACE "FSpectralModule"

#if PLATFORM_WINDOWS

typedef bool(*SPECTRALINITIALIZE)(void);
typedef bool(*SPECTRALISINITIALIZED)(void);
typedef bool(*SPECTRALLOGITECHISENABLED)(void);
typedef bool(*SPECTRALCORSAIRISENABLED)(void);
typedef bool(*SPECTRALRAZERISENABLED)(void);
typedef bool(*SPECTRALSTEELSERIESISENABLED)(void);
typedef bool(*SPECTRALSETCOLOR)(UCHAR red, UCHAR green, UCHAR blue);
typedef bool(*SPECTRALSETCOLORFORLED)(ESpectralLedName ledName, UCHAR red, UCHAR green, UCHAR blue);
typedef bool(*SPECTRALSETCOLORFORLEDS)(int count, ESpectralLedName ledNames[], UCHAR red, UCHAR green, UCHAR blue);
typedef bool(*SPECTRALSETCOLORFORDEVICE)(ESpectralDeviceType deviceType, UCHAR red, UCHAR green, UCHAR blue);
typedef void(*SPECTRALSHUTDOWN)(void);

SPECTRALINITIALIZE SpectralInitialize = nullptr;
SPECTRALISINITIALIZED SpectralIsInitialized = nullptr;
SPECTRALLOGITECHISENABLED SpectralLogitechIsEnabled = nullptr;
SPECTRALCORSAIRISENABLED SpectralCorsairIsEnabled = nullptr;
SPECTRALRAZERISENABLED SpectralRazerIsEnabled = nullptr;
SPECTRALSTEELSERIESISENABLED SpectralSteelSeriesIsEnabled = nullptr;
SPECTRALSETCOLOR SpectralSetColor = nullptr;
SPECTRALSETCOLORFORLED SpectralSetColorForLed = nullptr;
SPECTRALSETCOLORFORLEDS SpectralSetColorForLeds = nullptr;
SPECTRALSETCOLORFORDEVICE SpectralSetColorForDevice = nullptr;
SPECTRALSHUTDOWN SpectralShutdown = nullptr;

void *SpectralHandle;
void *CorsairHandle;

#endif

void FSpectralModule::StartupModule()
{
#if PLATFORM_WINDOWS
	FString BaseDir = IPluginManager::Get().FindPlugin("Spectral")->GetBaseDir();
	FString SpectralPath, CorsairPath;

#if PLATFORM_64BITS
	CorsairPath = FPaths::Combine(*BaseDir, TEXT("ThirdParty/Corsair/Win64/CUESDK.x64_2015.dll"));
	SpectralPath = FPaths::Combine(*BaseDir, TEXT("ThirdParty/Spectral/Win64/Spectral.dll"));
#else
	CorsairPath = FPaths::Combine(*BaseDir, TEXT("ThirdParty/Corsair/Win32/CUESDK_2015.dll"));
	SpectralPath = FPaths::Combine(*BaseDir, TEXT("ThirdParty/Spectral/Win32/Spectral.dll"));
#endif

	CorsairHandle = !CorsairPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*CorsairPath) : nullptr;
	SpectralHandle = !SpectralPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*SpectralPath) : nullptr;

	if (SpectralHandle != nullptr)
	{
		FString procName = "SpectralInitialize";
		SpectralInitialize = (SPECTRALINITIALIZE)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralIsInitialized";
		SpectralIsInitialized = (SPECTRALISINITIALIZED)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralLogitechIsEnabled";
		SpectralLogitechIsEnabled = (SPECTRALLOGITECHISENABLED)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralCorsairIsEnabled";
		SpectralCorsairIsEnabled = (SPECTRALCORSAIRISENABLED)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralRazerIsEnabled";
		SpectralRazerIsEnabled = (SPECTRALRAZERISENABLED)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralSteelSeriesIsEnabled";
		SpectralSteelSeriesIsEnabled = (SPECTRALSTEELSERIESISENABLED)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralSetColor";
		SpectralSetColor = (SPECTRALSETCOLOR)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralSetColorForLed";
		SpectralSetColorForLed = (SPECTRALSETCOLORFORLED)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralSetColorForLeds";
		SpectralSetColorForLeds = (SPECTRALSETCOLORFORLEDS)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralSetColorForDevice";
		SpectralSetColorForDevice = (SPECTRALSETCOLORFORDEVICE)FPlatformProcess::GetDllExport(SpectralHandle, *procName);

		procName = "SpectralShutdown";
		SpectralShutdown = (SPECTRALSHUTDOWN)FPlatformProcess::GetDllExport(SpectralHandle, *procName);
	}
#endif
}

void FSpectralModule::ShutdownModule()
{
#if PLATFORM_WINDOWS
	if (IsInitialized())
	{
		Shutdown();
	}

	SpectralInitialize = nullptr;
	SpectralIsInitialized = nullptr;
	SpectralLogitechIsEnabled = nullptr;
	SpectralCorsairIsEnabled = nullptr;
	SpectralRazerIsEnabled = nullptr;
	SpectralSteelSeriesIsEnabled = nullptr;
	SpectralSetColor = nullptr;
	SpectralSetColorForLed = nullptr;
	SpectralSetColorForLeds = nullptr;
	SpectralSetColorForDevice = nullptr;
	SpectralShutdown = nullptr;

	FPlatformProcess::FreeDllHandle(SpectralHandle);
	SpectralHandle = nullptr;

	FPlatformProcess::FreeDllHandle(CorsairHandle);
	CorsairHandle = nullptr;
#endif
}

bool FSpectralModule::Initialize()
{
#if PLATFORM_WINDOWS
	if (SpectralInitialize != nullptr)
	{
		return SpectralInitialize();
	}
	else
	{
		return false;
	}
#else
	return false;
#endif
}

bool FSpectralModule::IsInitialized()
{
#if PLATFORM_WINDOWS
	if (SpectralIsInitialized != nullptr)
	{
		return SpectralIsInitialized();
	}
	else
	{
		return false;
	}
#else
	return false;
#endif
}

bool FSpectralModule::LogitechIsEnabled()
{
#if PLATFORM_WINDOWS
	if (SpectralLogitechIsEnabled != nullptr)
	{
		return SpectralLogitechIsEnabled();
	}
	else
	{
		return false;
	}
#else
	return false;
#endif
}

bool FSpectralModule::CorsairIsEnabled()
{
#if PLATFORM_WINDOWS
	if (SpectralCorsairIsEnabled != nullptr)
	{
		return SpectralCorsairIsEnabled();
	}
	else
	{
		return false;
	}
#else
	return false;
#endif
}

bool FSpectralModule::RazerIsEnabled()
{
#if PLATFORM_WINDOWS
	if (SpectralRazerIsEnabled != nullptr)
	{
		return SpectralRazerIsEnabled();
	}
	else
	{
		return false;
	}
#else
	return false;
#endif
}

bool FSpectralModule::SetColor(UCHAR red, UCHAR green, UCHAR blue)
{
#if PLATFORM_WINDOWS
	if (SpectralSetColor != nullptr)
	{
		return SpectralSetColor(red, green, blue);
	}
	else
	{
		return false;
	}
#else
	return false;
#endif
}

bool FSpectralModule::SetColor(FColor color)
{
	return SpectralSetColor(color.R, color.G, color.B);
}

bool FSpectralModule::SetColorForLed(ESpectralLedName ledName, UCHAR red, UCHAR green, UCHAR blue)
{
#if PLATFORM_WINDOWS
	if (SpectralSetColorForLed != nullptr)
	{
		return SpectralSetColorForLed(ledName, red, green, blue);
	}
	else
	{
		return false;
	}
#else
	return false;
#endif
}

bool FSpectralModule::SetColorForLed(ESpectralLedName ledName, FColor color)
{
	return SetColorForLed(ledName, color.R, color.G, color.B);
}

bool FSpectralModule::SetColorForLeds(int count, ESpectralLedName ledNames[], UCHAR red, UCHAR green, UCHAR blue)
{
#if PLATFORM_WINDOWS
	if (SpectralSetColorForLeds != nullptr)
	{
		return SpectralSetColorForLeds(count, ledNames, red, green, blue);
	}
	else
	{
		return false;
	}
#else
	return false;
#endif
}

bool FSpectralModule::SetColorForLeds(TArray<ESpectralLedName> ledNames, UCHAR red, UCHAR green, UCHAR blue)
{
	return SetColorForLeds(ledNames.Num(), ledNames.GetData(), red, green, blue);
}

bool FSpectralModule::SetColorForLeds(int count, ESpectralLedName ledNames[], FColor color)
{
	return SetColorForLeds(count, ledNames, color.R, color.G, color.B);
}

bool FSpectralModule::SetColorForLeds(TArray<ESpectralLedName> ledNames, FColor color)
{
	return SetColorForLeds(ledNames.Num(), ledNames.GetData(), color.R, color.G, color.B);
}

bool FSpectralModule::SetColorForDevice(ESpectralDeviceType deviceType, UCHAR red, UCHAR green, UCHAR blue)
{
#if PLATFORM_WINDOWS
	if (SpectralSetColorForDevice != nullptr)
	{
		return SpectralSetColorForDevice(deviceType, red, green, blue);
	}
	else
	{
		return false;
	}
#else
	return false;
#endif
}

bool FSpectralModule::SetColorForDevice(ESpectralDeviceType deviceType, FColor color)
{
	return SetColorForDevice(deviceType, color.R, color.G, color.B);
}

void FSpectralModule::Shutdown()
{
#if PLATFORM_WINDOWS
	if (SpectralShutdown != nullptr)
	{
		SpectralShutdown();
	}
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSpectralModule, Spectral)