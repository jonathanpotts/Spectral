// Logi_SetTargetZone_Sample_CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LogitechLEDLib.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
    // Initialize the LED SDK
    bool LedInitialized = LogiLedInit();

    if (!LedInitialized)
    {
        std::cout << "LogiLedInit() failed." << std::endl;
        
        return 0;
    }

    std::cout << "LED SDK Initialized" << std::endl;

    LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);

    // Set all devices to Black
    LogiLedSetLighting(0, 0, 0);

    // Set some keys on keyboard
    LogiLedSetLightingForKeyWithKeyName(LogiLed::KeyName::L, 0, 100, 100);
    LogiLedSetLightingForKeyWithKeyName(LogiLed::KeyName::O, 0, 100, 100);
    LogiLedSetLightingForKeyWithKeyName(LogiLed::KeyName::G, 0, 100, 100);
    LogiLedSetLightingForKeyWithKeyName(LogiLed::KeyName::I, 0, 100, 100);

    // Set RGB mouse logo to Red
    LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Mouse, 1, 100, 0, 0);

    // Set G213 keyboard zones to Red, Yellow, Green, Cyan, Blue
    LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 1, 100, 0, 0);
    LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 2, 100, 100, 0);
    LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 3, 0, 100, 0);
    LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 4, 0, 100, 100);
    LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 5, 0, 0, 100);

    // Set G633/G933 headset logos to White, backsides to Purple
    LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Headset, 0, 100, 100, 100);
    LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Headset, 1, 100, 0, 100);

    std::cout << "Press \"ENTER\" to continue...";
    std::cin.ignore();

    std::cout << "LED SDK Shutting down" << std::endl;

    LogiLedShutdown();
    
    return 0;
}

