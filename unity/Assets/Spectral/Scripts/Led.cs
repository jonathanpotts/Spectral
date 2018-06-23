// Copyright 2018 Jonathan Potts. All rights reserved.

using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

namespace Spectral
{
    /// <summary>Performs operations for RGB LED Illumination.</summary>
    public class Led
    {
        private Led()
        {

        }

#if UNITY_STANDALONE_WIN
        const string DllName = "Spectral";

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
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
#endif

        /// <summary>Manually initialize the Spectral library. If Spectral is not initialized, this method will be called when trying to perform operations.</summary>
        /// <returns>True if initialization was successful.</returns>
        public static bool Initialize()
        {
#if UNITY_STANDALONE_WIN
            try
            {
                return SpectralInitialize();
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Checks if the Spectral library is initialized.</summary>
        /// <returns>True if initialized.</returns>
        public static bool IsInitialized()
        {
#if UNITY_STANDALONE_WIN
            try
            {
                return SpectralIsInitialized();
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Checks if Logitech device support was enabled during initialization.</summary>
        /// <returns>True if Logitech device support is enabled.</returns>
        public static bool LogitechIsEnabled()
        {
#if UNITY_STANDALONE_WIN
            try
            {
                return SpectralLogitechIsEnabled();
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Checks if Corsair device support was enabled during initialization.</summary>
        /// <returns>True if Corsair device support is enabled.</returns>
        public static bool CorsairIsEnabled()
        {
#if UNITY_STANDALONE_WIN
            try
            {
                return SpectralCorsairIsEnabled();
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of all LEDs on enabled devices to the specified color.</summary>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if LEDs on all enabled devices were successfully set.</returns>
        public static bool SetColor(byte red, byte green, byte blue)
        {
#if UNITY_STANDALONE_WIN
            try
            {
                return SpectralSetColor(red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of all LEDs on enabled devices to the specified color.</summary>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if LEDs on all enabled devices were successfully set.</returns>
        public static bool SetColor(Color color)
        {
#if UNITY_STANDALONE_WIN
            byte red = (byte)Mathf.Round(color.r * byte.MaxValue);
            byte green = (byte)Mathf.Round(color.g * byte.MaxValue);
            byte blue = (byte)Mathf.Round(color.b * byte.MaxValue);

            try
            {
                return SpectralSetColor(red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of the specified LED on enabled devices to the specified color.</summary>
        /// <param name="ledName">The LED Name value for the LED to be set.</param>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LED on any enabled device was successfully set.</returns>
        public static bool SetColorForLed(LedName ledName, byte red, byte green, byte blue)
        {
#if UNITY_STANDALONE_WIN
            try
            {
                return SpectralSetColorForLed(ledName, red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of the specified LED on enabled devices to the specified color.</summary>
        /// <param name="ledName">The LED Name value for the LED to be set.</param>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LED on any enabled device was successfully set.</returns>
        public static bool SetColorForLed(LedName ledName, Color color)
        {
#if UNITY_STANDALONE_WIN
            byte red = (byte)Mathf.Round(color.r * byte.MaxValue);
            byte green = (byte)Mathf.Round(color.g * byte.MaxValue);
            byte blue = (byte)Mathf.Round(color.b * byte.MaxValue);

            try
            {
                return SpectralSetColorForLed(ledName, red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of the specified LEDs on enabled devices to the specified color.</summary>
        /// <param name="ledNames">The LED Name values for the LEDs to be set.</param>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LEDs on any enabled device was successfully set.</returns>
        public static bool SetColorForLeds(List<LedName> ledNames, byte red, byte green, byte blue)
        {
#if UNITY_STANDALONE_WIN
            try
            {
                return SpectralSetColorForLeds(ledNames.Count, ledNames.ToArray(), red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of the specified LEDs on enabled devices to the specified color.</summary>
        /// <param name="ledNames">The LED Name values for the LEDs to be set.</param>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LEDs on any enabled device was successfully set.</returns>
        public static bool SetColorForLeds(List<LedName> ledNames, Color color)
        {
#if UNITY_STANDALONE_WIN
            byte red = (byte)Mathf.Round(color.r * byte.MaxValue);
            byte green = (byte)Mathf.Round(color.g * byte.MaxValue);
            byte blue = (byte)Mathf.Round(color.b * byte.MaxValue);

            try
            {
                return SpectralSetColorForLeds(ledNames.Count, ledNames.ToArray(), red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of the specified LEDs on enabled devices to the specified color.</summary>
        /// <param name="ledNames">The LED Name values for the LEDs to be set.</param>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LEDs on any enabled device was successfully set.</returns>
        public static bool SetColorForLeds(LedName[] ledNames, byte red, byte green, byte blue)
        {
#if UNITY_STANDALONE_WIN
            try
            {
                return SpectralSetColorForLeds(ledNames.Length, ledNames, red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of the specified LEDs on enabled devices to the specified color.</summary>
        /// <param name="ledNames">The LED Name values for the LEDs to be set.</param>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if specified LEDs on any enabled device was successfully set.</returns>
        public static bool SetColorForLeds(LedName[] ledNames, Color color)
        {
#if UNITY_STANDALONE_WIN
            byte red = (byte)Mathf.Round(color.r * byte.MaxValue);
            byte green = (byte)Mathf.Round(color.g * byte.MaxValue);
            byte blue = (byte)Mathf.Round(color.b * byte.MaxValue);

            try
            {
                return SpectralSetColorForLeds(ledNames.Length, ledNames, red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of all enabled devices of the specified type to the specified color.</summary>
        /// <param name="deviceType">The type of devices to set.</param>
        /// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if any enabled device of the specified type was successfully set.</returns>
        public static bool SetColorForDevice(DeviceType deviceType, byte red, byte green, byte blue)
        {
#if UNITY_STANDALONE_WIN
            try
            {
                return SpectralSetColorForDevice(deviceType, red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Sets the color of all enabled devices of the specified type to the specified color.</summary>
        /// <param name="deviceType">The type of devices to set.</param>
        /// <param name="color">The color to set. On monochromatic devices, only the highest channel value is used.</param>
        /// <returns>True if any enabled device of the specified type was successfully set.</returns>
        public static bool SetColorForDevice(DeviceType deviceType, Color color)
        {
#if UNITY_STANDALONE_WIN
            byte red = (byte)Mathf.Round(color.r * byte.MaxValue);
            byte green = (byte)Mathf.Round(color.g * byte.MaxValue);
            byte blue = (byte)Mathf.Round(color.b * byte.MaxValue);

            try
            {
                return SpectralSetColorForDevice(deviceType, red, green, blue);
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
                return false;
            }
#else
            return false;
#endif
        }

        /// <summary>Manually shut down the Spectral library. If not called, the library should shutdown when the application exits.</summary>
        public static void Shutdown()
        {
#if UNITY_STANDALONE_WIN
            try
            {
                SpectralShutdown();
            }
            catch (System.DllNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
            }
            catch (System.EntryPointNotFoundException)
            {
                Debug.LogError("The Spectral library could not be loaded. Is the Corsair CUE SDK missing (see setup guide)?");
            }
#endif
        }
    }
}