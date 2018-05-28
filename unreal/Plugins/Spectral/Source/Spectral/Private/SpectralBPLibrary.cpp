// Copyright 2018 Jonathan Potts. All rights reserved.

#include "SpectralBPLibrary.h"

bool USpectralBPLibrary::Initialize()
{
	return FSpectralModule::Initialize();
}

bool USpectralBPLibrary::IsInitialized()
{
	return FSpectralModule::IsInitialized();
}

bool USpectralBPLibrary::LogitechIsEnabled()
{
	return FSpectralModule::LogitechIsEnabled();
}

bool USpectralBPLibrary::CorsairIsEnabled()
{
	return FSpectralModule::CorsairIsEnabled();
}

bool USpectralBPLibrary::RazerIsEnabled()
{
	return FSpectralModule::RazerIsEnabled();
}

bool USpectralBPLibrary::SetColor(FColor color)
{
	return FSpectralModule::SetColor(color);
}

bool USpectralBPLibrary::SetColorForLed(ESpectralLedName ledName, FColor color)
{
	return FSpectralModule::SetColorForLed(ledName, color);
}

bool USpectralBPLibrary::SetColorForLeds(TArray<ESpectralLedName> ledNames, FColor color)
{
	return FSpectralModule::SetColorForLeds(ledNames, color);
}

bool USpectralBPLibrary::SetColorForDevice(ESpectralDeviceType deviceType, FColor color)
{
	return FSpectralModule::SetColorForDevice(deviceType, color);
}

void USpectralBPLibrary::Shutdown()
{
	FSpectralModule::Shutdown();
}