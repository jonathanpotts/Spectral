// Copyright 2018 Jonathan Potts. All rights reserved.

using System;
using System.Collections.Generic;
using System.Drawing;
using System.Runtime.InteropServices;

namespace Spectral
{
    /// <summary>Performs operations for RGB LED Illumination.</summary>
    public class Led
    {
        private Led()
        {

        }

        const string DllName = "Spectral";

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return:MarshalAs(UnmanagedType.I1)]
        private extern static bool SpectralInitialize();

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private extern static bool SpectralIsInitialized();

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private extern static bool SpectralLogitechIsEnabled();

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private extern static bool SpectralCorsairIsEnabled();

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private extern static bool SpectralRazerIsEnabled();

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private extern static bool SpectralSetColor(byte red, byte green, byte blue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private extern static bool SpectralSetColorForLed(LedName ledName, byte red, byte green, byte blue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private extern static bool SpectralSetColorForLeds(int count, LedName[] ledNames, byte red, byte green, byte blue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private extern static bool SpectralSetColorForDevice(DeviceType deviceType, byte red, byte green, byte blue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        private extern static void SpectralShutdown();

        /// <summary>Manually initialize the Spectral library. If Spectral is not initialized, this method will be called when trying to perform operations.</summary>
        /// <returns>True if initialization was successful.</returns>
        public static bool Initialize()
        {
            try
            {
                return SpectralInitialize();
            }
            catch(DllNotFoundException)
            {
                return false;
            }
            catch(EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Checks if the Spectral library is initialized.</summary>
        /// <returns>True if initialized.</returns>
        public static bool IsInitialized()
        {
            try
            {
                return SpectralIsInitialized();
            }
            catch (DllNotFoundException)
            {
                return false;
            }
            catch (EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Checks if Logitech device support was enabled during initialization.</summary>
        /// <returns>True if Logitech device support is enabled.</returns>
        public static bool LogitechIsEnabled()
        {
            try
            {
                return SpectralLogitechIsEnabled();
            }
            catch (DllNotFoundException)
            {
                return false;
            }
            catch (EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Checks if Corsair device support was enabled during initialization.</summary>
        /// <returns>True if Corsair device support is enabled.</returns>
        public static bool CorsairIsEnabled()
        {
            try
            {
                return SpectralCorsairIsEnabled();
            }
            catch (DllNotFoundException)
            {
                return false;
            }
            catch (EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Checks if Razer device support was enabled during initialization.</summary>
        /// <returns>True if Razer device support is enabled.</returns>
        public static bool RazerIsEnabled()
        {
            try
            {
                return SpectralRazerIsEnabled();
            }
            catch (DllNotFoundException)
            {
                return false;
            }
            catch (EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Sets the color of all LEDs on enabled devices to the specified color.</summary>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if LEDs on all enabled devices were successfully set.</returns>
        public static bool SetColor(byte red, byte green, byte blue)
        {
            try
            {
                return SpectralSetColor(red, green, blue);
            }
            catch (DllNotFoundException)
            {
                return false;
            }
            catch (EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Sets the color of all LEDs on enabled devices to the specified color.</summary>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if LEDs on all enabled devices were successfully set.</returns>
        public static bool SetColor(Color color)
        {
            return SetColor(color.R, color.G, color.B);
        }

        /// <summary>Sets the color of the specified LED on enabled devices to the specified color.</summary>
        /// <param name="ledName">The LED Name value for the LED to be set.</param>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LED on any enabled device was successfully set.</returns>
        public static bool SetColorForLed(LedName ledName, byte red, byte green, byte blue)
        {
            try
            {
                return SpectralSetColorForLed(ledName, red, green, blue);
            }
            catch (DllNotFoundException)
            {
                return false;
            }
            catch (EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Sets the color of the specified LED on enabled devices to the specified color.</summary>
        /// <param name="ledName">The LED Name value for the LED to be set.</param>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LED on any enabled device was successfully set.</returns>
        public static bool SetColorForLed(LedName ledName, Color color)
        {
            return SetColorForLed(ledName, color.R, color.G, color.B);
        }

        /// <summary>Sets the color of the specified LEDs on enabled devices to the specified color.</summary>
        /// <param name="ledNames">The LED Name values for the LEDs to be set.</param>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LEDs on any enabled device was successfully set.</returns>
        public static bool SetColorForLeds(List<LedName> ledNames, byte red, byte green, byte blue)
        {
            try
            {
                return SpectralSetColorForLeds(ledNames.Count, ledNames.ToArray(), red, green, blue);
            }
            catch (DllNotFoundException)
            {
                return false;
            }
            catch (EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Sets the color of the specified LEDs on enabled devices to the specified color.</summary>
        /// <param name="ledNames">The LED Name values for the LEDs to be set.</param>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LEDs on any enabled device was successfully set.</returns>
        public static bool SetColorForLeds(List<LedName> ledNames, Color color)
        {
            return SetColorForLeds(ledNames, color.R, color.G, color.B);
        }

        /// <summary>Sets the color of the specified LEDs on enabled devices to the specified color.</summary>
        /// <param name="ledNames">The LED Name values for the LEDs to be set.</param>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LEDs on any enabled device was successfully set.</returns>
        public static bool SetColorForLeds(LedName[] ledNames, byte red, byte green, byte blue)
        {
            try
            {
                return SpectralSetColorForLeds(ledNames.Length, ledNames, red, green, blue);
            }
            catch (DllNotFoundException)
            {
                return false;
            }
            catch (EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Sets the color of the specified LEDs on enabled devices to the specified color.</summary>
        /// <param name="ledNames">The LED Name values for the LEDs to be set.</param>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LEDs on any enabled device was successfully set.</returns>
        public static bool SetColorForLeds(LedName[] ledNames, Color color)
        {
            return SetColorForLeds(ledNames, color.R, color.G, color.B);
        }

        /// <summary>Sets the color of all enabled devices of the specified type to the specified color.</summary>
        /// <param name="deviceType">The type of devices to set.</param>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if any enabled device of the specified type was successfully set.</returns>
        public static bool SetColorForDevice(DeviceType deviceType, byte red, byte green, byte blue)
        {
            try
            {
                return SpectralSetColorForDevice(deviceType, red, green, blue);
            }
            catch (DllNotFoundException)
            {
                return false;
            }
            catch (EntryPointNotFoundException)
            {
                return false;
            }
        }

        /// <summary>Sets the color of all enabled devices of the specified type to the specified color.</summary>
        /// <param name="deviceType">The type of devices to set.</param>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if any enabled device of the specified type was successfully set.</returns>
        public static bool SetColorForDevice(DeviceType deviceType, Color color)
        {
            return SpectralSetColorForDevice(deviceType, color.R, color.G, color.B);
        }

        /// <summary>Manually shut down the Spectral library. If not called, the library should shutdown when the application exits.</summary>
        public static void Shutdown()
        {
            try
            {
                SpectralShutdown();
            }
            catch (DllNotFoundException)
            {
            }
            catch (EntryPointNotFoundException)
            {
            }
        }
    }
}