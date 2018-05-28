using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LedCSharp;

namespace Logi_SetTargetZone_Sample_CS
{
    public class Program
    {
        static void Main(string[] args)
        {
            // Initialize the LED SDK
            bool LedInitialized = LogitechGSDK.LogiLedInit();

            if (!LedInitialized)
            {
                Console.WriteLine("LogitechGSDK.LogiLedInit() failed.");
                return;
            }

            Console.WriteLine("LED SDK Initialized");

            LogitechGSDK.LogiLedSetTargetDevice(LogitechGSDK.LOGI_DEVICETYPE_ALL);

            // Set all devices to Black
            LogitechGSDK.LogiLedSetLighting(0, 0, 0);

            // Set some keys on keyboard
            LogitechGSDK.LogiLedSetLightingForKeyWithKeyName(keyboardNames.L, 0, 100, 100);
            LogitechGSDK.LogiLedSetLightingForKeyWithKeyName(keyboardNames.O, 0, 100, 100);
            LogitechGSDK.LogiLedSetLightingForKeyWithKeyName(keyboardNames.G, 0, 100, 100);
            LogitechGSDK.LogiLedSetLightingForKeyWithKeyName(keyboardNames.I, 0, 100, 100);

            // Set RGB mouse logo to Red
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Mouse, 1, 100, 0, 0);

            // Set G213 keyboard zones to Red, Yellow, Green, Cyan, Blue
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Keyboard, 1, 100, 0, 0);
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Keyboard, 2, 100, 100, 0);
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Keyboard, 3, 0, 100, 0);
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Keyboard, 4, 0, 100, 100);
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Keyboard, 5, 0, 0, 100);

            // Set G633/G933 headset logos to White, backsides to Purple
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Headset, 0, 100, 100, 100);
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Headset, 1, 100, 0, 100);

            Console.WriteLine("Press \"ENTER\" to continue...");
            Console.ReadLine();

            Console.WriteLine("LED SDK Shutting down");
            LogitechGSDK.LogiLedShutdown();
        }
    }
}
