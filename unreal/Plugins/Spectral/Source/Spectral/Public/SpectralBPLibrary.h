// Copyright 2018 Jonathan Potts. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include "Spectral.h"
#include "SpectralBPLibrary.generated.h"

/**
 * Performs operations for RGB LED Illumination.
 */
UCLASS()
class SPECTRAL_API USpectralBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/**
	 * Manually initialize the Spectral library. If Spectral is not initialized, this method will be called when trying to perform operations.
	 * @return True if initialization was successful.
	 */
	UFUNCTION(BlueprintCallable, Category = "RGB LED Illumination (Spectral)", DisplayName = "Initialize Spectral")
	static bool Initialize();

	/**
	 * Checks if the Spectral library has been initialized.
	 * @return True if initialized.
	 */
	UFUNCTION(BlueprintPure, Category = "RGB LED Illumination (Spectral)", DisplayName = "Spectral Is Initialized")
	static bool IsInitialized();

	/**
	 * Checks if Logitech device support was enabled during initialization.
	 * @return True if device support is enabled.
	 */
	UFUNCTION(BlueprintPure, Category = "RGB LED Illumination (Spectral)", DisplayName = "Logitech Device Support Is Enabled")
	static bool LogitechIsEnabled();

	/**
	 * Checks if Corsair device support was enabled during initialization.
	 * @return True if device support is enabled.
	 */
	UFUNCTION(BlueprintPure, Category = "RGB LED Illumination (Spectral)", DisplayName = "Corsair Device Support Is Enabled")
	static bool CorsairIsEnabled();

	/**
	 * Checks if Razer device support was enabled during initialization.
	 * @return True if device support is enabled.
	 */
	UFUNCTION(BlueprintPure, Category = "RGB LED Illumination (Spectral)", DisplayName = "Razer Device Support Is Enabled")
	static bool RazerIsEnabled();

	/**
	 * Sets the color of all LEDs on enabled devices to the specified color.
	 * @param color - The color to set the LEDs to (A channel is ignored). On monochromatic devices, only the highest channel value is used.
	 * @return True if all enabled devices reported success.
	 */
	UFUNCTION(BlueprintCallable, Category = "RGB LED Illumination (Spectral)", DisplayName = "Set Color For All LEDs")
	static bool SetColor(FColor color);

	/**
	 * Sets the color of the specified LED on enabled devices to the specified color.
	 * @param ledName - The LED to set.
	 * @param color - The color to set the LED to (A channel is ignored). On monochromatic devices, only the highest channel value is used.
	 * @return True If at least one enabled device reported success.
	 */
	UFUNCTION(BlueprintCallable, Category = "RGB LED Illumination (Spectral)", DisplayName = "Set Color For LED")
	static bool SetColorForLed(ESpectralLedName ledName, FColor color);

	/**
	 * Sets the color of the specified LEDs on enabled devices to the specified color.
	 * @param ledNames - The LEDs to set.
	 * @param color - The color to set the LEDs to (A channel is ignored). On monochromatic devices, only the highest channel value is used.
	 * @return True If at least one enabled device reported success.
	 */
	UFUNCTION(BlueprintCallable, Category = "RGB LED Illumination (Spectral)", DisplayName = "Set Color For LEDs")
	static bool SetColorForLeds(TArray<ESpectralLedName> ledNames, FColor color);

	/**
	* Sets the color of all enabled devices of the specified type to the specified color.
	* @param deviceType - The type of devices to set.
	* @param color - The color to set the LED to (A channel is ignored). On monochromatic devices, only the highest channel value is used.
	* @return True if any enabled device of the specified type was successfully set.
	*/
	UFUNCTION(BlueprintCallable, Category = "RGB LED Illumination (Spectral)", DisplayName = "Set Color For Device")
		static bool SetColorForDevice(ESpectralDeviceType deviceType, FColor color);

	/**
	 * Manually shut down the Spectral library. If not called, the library should shutdown when the application exits.
	 */
	UFUNCTION(BlueprintCallable, Category = "RGB LED Illumination (Spectral)", DisplayName = "Shutdown Spectral")
	static void Shutdown();
};
