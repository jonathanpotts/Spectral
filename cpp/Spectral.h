// Copyright 2018 Jonathan Potts. All rights reserved.

#pragma once

#include <vector>

namespace Spectral
{
	/// <summary>Enumeration of LED Names.</summary>
	enum class LedName : unsigned char
	{
		/// <summary>Keyboard - Backspace</summary>
		Backspace = 0x01,

		/// <summary>Keyboard - Tab</summary>
		Tab = 0x02,

		/// <summary>Keyboard - Enter</summary>
		Enter = 0x03,

		/// <summary>Keyboard - Pause/Break</summary>
		Pause = 0x04,

		/// <summary>Keyboard - Caps Lock</summary>
		CapsLock = 0x05,

		/// <summary>Keyboard - Escape</summary>
		Escape = 0x06,

		/// <summary>Keyboard - Spacebar</summary>
		Spacebar = 0x07,

		/// <summary>Keyboard - Page Up</summary>
		PageUp = 0x08,

		/// <summary>Keyboard - Page Down</summary>
		PageDown = 0x09,

		/// <summary>Keyboard - End</summary>
		End = 0x0a,

		/// <summary>Keyboard - Home</summary>
		Home = 0x0b,

		/// <summary>Keyboard - Left Arrow</summary>
		LeftArrow = 0x0c,

		/// <summary>Keyboard - Up Arrow</summary>
		UpArrow = 0x0d,

		/// <summary>Keyboard - Right Arrow</summary>
		RightArrow = 0x0e,

		/// <summary>Keyboard - Down Arrow</summary>
		DownArrow = 0x0f,

		/// <summary>Keyboard - Print Screen</summary>
		PrintScreen = 0x10,

		/// <summary>Keyboard - Insert</summary>
		Insert = 0x11,

		/// <summary>Keyboard - Delete</summary>
		Delete = 0x12,

		/// <summary>Keyboard - 0</summary>
		Zero = 0x13,

		/// <summary>Keyboard - 1</summary>
		One = 0x14,

		/// <summary>Keyboard - 2</summary>
		Two = 0x15,

		/// <summary>Keyboard - 3</summary>
		Three = 0x16,

		/// <summary>Keyboard - 4</summary>
		Four = 0x17,

		/// <summary>Keyboard - 5</summary>
		Five = 0x18,

		/// <summary>Keyboard - 6</summary>
		Six = 0x19,

		/// <summary>Keyboard - 7</summary>
		Seven = 0x1a,

		/// <summary>Keyboard - 8</summary>
		Eight = 0x1b,

		/// <summary>Keyboard - 9</summary>
		Nine = 0x1c,

		/// <summary>Keyboard - A</summary>
		A = 0x1d,

		/// <summary>Keyboard - B</summary>
		B = 0x1e,

		/// <summary>Keyboard - C</summary>
		C = 0x1f,

		/// <summary>Keyboard - D</summary>
		D = 0x20,

		/// <summary>Keyboard - E</summary>
		E = 0x21,

		/// <summary>Keyboard - F</summary>
		F = 0x22,

		/// <summary>Keyboard - G</summary>
		G = 0x23,

		/// <summary>Keyboard - H</summary>
		H = 0x24,

		/// <summary>Keyboard - I</summary>
		I = 0x25,

		/// <summary>Keyboard - J</summary>
		J = 0x26,

		/// <summary>Keyboard - K</summary>
		K = 0x27,

		/// <summary>Keyboard - L</summary>
		L = 0x28,

		/// <summary>Keyboard - M</summary>
		M = 0x29,

		/// <summary>Keyboard - N</summary>
		N = 0x2a,

		/// <summary>Keyboard - O</summary>
		O = 0x2b,

		/// <summary>Keyboard - P</summary>
		P = 0x2c,

		/// <summary>Keyboard - Q</summary>
		Q = 0x2d,

		/// <summary>Keyboard - R</summary>
		R = 0x2e,

		/// <summary>Keyboard - S</summary>
		S = 0x2f,

		/// <summary>Keyboard - T</summary>
		T = 0x30,

		/// <summary>Keyboard - U</summary>
		U = 0x31,

		/// <summary>Keyboard - V</summary>
		V = 0x32,

		/// <summary>Keyboard - W</summary>
		W = 0x33,

		/// <summary>Keyboard - X</summary>
		X = 0x34,

		/// <summary>Keyboard - Y</summary>
		Y = 0x35,

		/// <summary>Keyboard - Z</summary>
		Z = 0x36,

		/// <summary>Keyboard - Left Windows</summary>
		LeftWindows = 0x37,

		/// <summary>Keyboard - Right Windows</summary>
		RightWindows = 0x38,

		/// <summary>Keyboard - Applications</summary>
		Applications = 0x39,

		/// <summary>Keyboard - Numpad 0</summary>
		Numpad0 = 0x3a,

		/// <summary>Keyboard - Numpad 1</summary>
		Numpad1 = 0x3b,

		/// <summary>Keyboard - Numpad 2</summary>
		Numpad2 = 0x3c,

		/// <summary>Keyboard - Numpad 3</summary>
		Numpad3 = 0x3d,

		/// <summary>Keyboard - Numpad 4</summary>
		Numpad4 = 0x3e,

		/// <summary>Keyboard - Numpad 5</summary>
		Numpad5 = 0x3f,

		/// <summary>Keyboard - Numpad 6</summary>
		Numpad6 = 0x40,

		/// <summary>Keyboard - Numpad 7</summary>
		Numpad7 = 0x41,

		/// <summary>Keyboard - Numpad 8</summary>
		Numpad8 = 0x42,

		/// <summary>Keyboard - Numpad 9</summary>
		Numpad9 = 0x43,

		/// <summary>Keyboard - Numpad Multiply</summary>
		Multiply = 0x44,

		/// <summary>Keyboard - Numpad Add</summary>
		Add = 0x45,

		/// <summary>Keyboard - Numpad Subtract</summary>
		Subtract = 0x46,

		/// <summary>Keyboard - Numpad Decimal</summary>
		Decimal = 0x47,

		/// <summary>Keyboard - Numpad Divide</summary>
		Divide = 0x48,

		/// <summary>Keyboard - F1</summary>
		F1 = 0x49,

		/// <summary>Keyboard - F2</summary>
		F2 = 0x4a,

		/// <summary>Keyboard - F3</summary>
		F3 = 0x4b,

		/// <summary>Keyboard - F4</summary>
		F4 = 0x4c,

		/// <summary>Keyboard - F5</summary>
		F5 = 0x4d,

		/// <summary>Keyboard - F6</summary>
		F6 = 0x4e,

		/// <summary>Keyboard - F7</summary>
		F7 = 0x4f,

		/// <summary>Keyboard - F8</summary>
		F8 = 0x50,

		/// <summary>Keyboard - F9</summary>
		F9 = 0x51,

		/// <summary>Keyboard - F10</summary>
		F10 = 0x52,

		/// <summary>Keyboard - F11</summary>
		F11 = 0x53,

		/// <summary>Keyboard - F12</summary>
		F12 = 0x54,

		/// <summary>Keyboard - Num Lock</summary>
		NumLock = 0x55,

		/// <summary>Keyboard - Scroll Lock</summary>
		ScrollLock = 0x56,

		/// <summary>Keyboard - Left Shift</summary>
		LeftShift = 0x57,

		/// <summary>Keyboard - Right Shift</summary>
		RightShift = 0x58,

		/// <summary>Keyboard - Left Control</summary>
		LeftControl = 0x59,

		/// <summary>Keyboard - Right Control</summary>
		RightControl = 0x5a,

		/// <summary>Keyboard - Semicolon/Colon</summary>
		Semicolon = 0x5b,

		/// <summary>Keyboard - Plus/Equal</summary>
		Plus = 0x5c,

		/// <summary>Keyboard - Comma/Less Than</summary>
		Comma = 0x5d,

		/// <summary>Keyboard - Minus/Underscore</summary>
		Minus = 0x5e,

		/// <summary>Keyboard - Period/Greater Than</summary>
		Period = 0x5f,

		/// <summary>Keyboard - Slash/Question</summary>
		Slash = 0x60,

		/// <summary>Keyboard - Tilde/Accent</summary>
		Tilde = 0x61,

		/// <summary>Keyboard - Left Bracket/Left Brace</summary>
		LeftBracket = 0x62,

		/// <summary>Keyboard - Backslash/Pipe</summary>
		Backslash = 0x63,

		/// <summary>Keyboard - Right Bracket/Right Brace</summary>
		RightBracket = 0x64,

		/// <summary>Keyboard - Quote/Apostrophe</summary>
		Quote = 0x65,

		/// <summary>Keyboard - Left Alt</summary>
		LeftAlt = 0x66,

		/// <summary>Keyboard - Right Alt</summary>
		RightAlt = 0x67,

		/// <summary>Keyboard - Numpad Enter</summary>
		NumpadEnter = 0x68,

		/// <summary>Keyboard - G1/Macro 1</summary>
		G1 = 0x69,

		/// <summary>Keyboard - G2/Macro 2</summary>
		G2 = 0x6a,

		/// <summary>Keyboard - G3/Macro 3</summary>
		G3 = 0x6b,

		/// <summary>Keyboard - G4/Macro 4</summary>
		G4 = 0x6c,

		/// <summary>Keyboard - G5/Macro 5</summary>
		G5 = 0x6d,

		/// <summary>Keyboard - G6/Macro 6</summary>
		G6 = 0x6e,

		/// <summary>Keyboard - G7/Macro 7</summary>
		G7 = 0x6f,

		/// <summary>Keyboard - G8/Macro 8</summary>
		G8 = 0x70,

		/// <summary>Keyboard - G9/Macro 9</summary>
		G9 = 0x71,

		/// <summary>Keyboard - Logo</summary>
		Logo = 0x72,

		/// <summary>Keyboard - Badge</summary>
		Badge = 0x73,

		/// <summary>Keyboard - Non-US Backslash</summary>
		NonUsBackslash = 0x74,

		/// <summary>Keyboard - Language 1/IME 1</summary>
		Lang1 = 0x75,

		/// <summary>Keyboard - Language 2/IME 2</summary>
		Lang2 = 0x76,

		/// <summary>Keyboard - LED Programming</summary>
		LedProgramming = 0x77,

		/// <summary>Keyboard - Brightness</summary>
		Brightness = 0x78,

		/// <summary>Keyboard - Non-US Tilde</summary>
		NonUsTilde = 0x79,

		/// <summary>Keyboard - Windows Lock</summary>
		WindowsLock = 0x7a,

		/// <summary>Keyboard - Mute</summary>
		Mute = 0x7b,

		/// <summary>Keyboard - Stop</summary>
		Stop = 0x7c,

		/// <summary>Keyboard - Previous Track</summary>
		PreviousTrack = 0x7d,

		/// <summary>Keyboard - Play/Pause</summary>
		PlayPause = 0x7e,

		/// <summary>Keyboard - Next Track</summary>
		NextTrack = 0x7f,

		/// <summary>Keyboard - Volume Up</summary>
		VolumeUp = 0x80,

		/// <summary>Keyboard - Volume Down</summary>
		VolumeDown = 0x81,

		/// <summary>Keyboard - Memory Reset</summary>
		MR = 0x82,

		/// <summary>Keyboard - Memory Profile 1</summary>
		M1 = 0x83,

		/// <summary>Keyboard - Memory Profile 2</summary>
		M2 = 0x84,

		/// <summary>Keyboard - Memory Profile 3</summary>
		M3 = 0x85,

		/// <summary>Keyboard - G10/Macro 10</summary>
		G10 = 0x86,

		/// <summary>Keyboard - G11/Macro 11</summary>
		G11 = 0x87,

		/// <summary>Keyboard - G12/Macro 12</summary>
		G12 = 0x88,

		/// <summary>Keyboard - G13/Macro 13</summary>
		G13 = 0x89,

		/// <summary>Keyboard - G14/Macro 14</summary>
		G14 = 0x8a,

		/// <summary>Keyboard - G15/Macro 15</summary>
		G15 = 0x8b,

		/// <summary>Keyboard - G16/Macro 16</summary>
		G16 = 0x8c,

		/// <summary>Keyboard - G17/Macro 17</summary>
		G17 = 0x8d,

		/// <summary>Keyboard - G18/Macro 18</summary>
		G18 = 0x8e,

		/// <summary>Keyboard - Fn</summary>
		Fn = 0x8f,

		/// <summary>Keyboard - International 1</summary>
		International1 = 0x90,

		/// <summary>Keyboard - International 2</summary>
		International2 = 0x91,

		/// <summary>Keyboard - International 3</summary>
		International3 = 0x92,

		/// <summary>Keyboard - International 4</summary>
		International4 = 0x93,

		/// <summary>Keyboard - International 5</summary>
		International5 = 0x94,

		/// <summary>Keyboard - International 6</summary>
		International6 = 0x95,

		/// <summary>Keyboard - International 7</summary>
		International7 = 0x96,

		/// <summary>Keyboard - Zone 1</summary>
		KeyboardZone1 = 0x97,

		/// <summary>Keyboard - Zone 2</summary>
		KeyboardZone2 = 0x98,

		/// <summary>Keyboard - Zone 3</summary>
		KeyboardZone3 = 0x99,

		/// <summary>Keyboard - Zone 4</summary>
		KeyboardZone4 = 0x9a,

		/// <summary>Keyboard - Zone 5</summary>
		KeyboardZone5 = 0x9b,

		/// <summary>Keyboard - Zone 6</summary>
		KeyboardZone6 = 0x9c,

		/// <summary>Keyboard - Zone 7</summary>
		KeyboardZone7 = 0x9d,

		/// <summary>Keyboard - Zone 8</summary>
		KeyboardZone8 = 0x9e,

		/// <summary>Keyboard - Zone 9</summary>
		KeyboardZone9 = 0x9f,

		/// <summary>Keyboard - Zone 10</summary>
		KeyboardZone10 = 0xa0,

		/// <summary>Keyboard - Zone 11</summary>
		KeyboardZone11 = 0xa1,

		/// <summary>Keyboard - Zone 12</summary>
		KeyboardZone12 = 0xa2,

		/// <summary>Keyboard - Zone 13</summary>
		KeyboardZone13 = 0xa3,

		/// <summary>Keyboard - Zone 14</summary>
		KeyboardZone14 = 0xa4,

		/// <summary>Keyboard - Zone 15</summary>
		KeyboardZone15 = 0xa5,

		/// <summary>Keyboard - Zone 16</summary>
		KeyboardZone16 = 0xa6,

		/// <summary>Keyboard - Zone 17</summary>
		KeyboardZone17 = 0xa7,

		/// <summary>Keyboard - Zone 18</summary>
		KeyboardZone18 = 0xa8,

		/// <summary>Keyboard - Zone 19</summary>
		KeyboardZone19 = 0xa9,

		/// <summary>Mouse - Zone 1</summary>
		MouseZone1 = 0xaa,

		/// <summary>Mouse - Zone 2</summary>
		MouseZone2 = 0xab,

		/// <summary>Mouse - Zone 3</summary>
		MouseZone3 = 0xac,

		/// <summary>Mouse - Zone 4</summary>
		MouseZone4 = 0xad,

		/// <summary>Mouse - Zone 5</summary>
		MouseZone5 = 0xae,

		/// <summary>Mouse - Zone 6</summary>
		MouseZone6 = 0xaf,

		/// <summary>Mouse - Zone 7</summary>
		MouseZone7 = 0xb0,

		/// <summary>Mouse - Zone 8</summary>
		MouseZone8 = 0xb1,

		/// <summary>Mouse - Zone 9</summary>
		MouseZone9 = 0xb2,

		/// <summary>Mouse - Zone 10</summary>
		MouseZone10 = 0xb3,

		/// <summary>Mouse - Zone 11</summary>
		MouseZone11 = 0xb4,

		/// <summary>Mouse - Zone 12</summary>
		MouseZone12 = 0xb5,

		/// <summary>Mouse - Zone 13</summary>
		MouseZone13 = 0xb6,

		/// <summary>Mouse - Zone 14</summary>
		MouseZone14 = 0xb7,

		/// <summary>Mouse - Zone 15</summary>
		MouseZone15 = 0xb8,

		/// <summary>Mouse - Zone 16</summary>
		MouseZone16 = 0xb9,

		/// <summary>Mouse - Zone 17</summary>
		MouseZone17 = 0xba,

		/// <summary>Mouse - Zone 18</summary>
		MouseZone18 = 0xbb,

		/// <summary>Mouse - Zone 19</summary>
		MouseZone19 = 0xbc,

		/// <summary>Mouse - Zone 20</summary>
		MouseZone20 = 0xbd,

		/// <summary>Mouse - Zone 21</summary>
		MouseZone21 = 0xbe,

		/// <summary>Mouse - Zone 22</summary>
		MouseZone22 = 0xbf,

		/// <summary>Headset - Left Zone (All Zones on Logitech)</summary>
		HeadsetLeftZone = 0xc0,

		/// <summary>Headset - Right Zone</summary>
		HeadsetRightZone = 0xc1,

		/// <summary>Mousepad - Zone 1</summary>
		MousepadZone1 = 0xc2,

		/// <summary>Mousepad - Zone 2</summary>
		MousepadZone2 = 0xc3,

		/// <summary>Mousepad - Zone 3</summary>
		MousepadZone3 = 0xc4,

		/// <summary>Mousepad - Zone 4</summary>
		MousepadZone4 = 0xc5,

		/// <summary>Mousepad - Zone 5</summary>
		MousepadZone5 = 0xc6,

		/// <summary>Mousepad - Zone 6</summary>
		MousepadZone6 = 0xc7,

		/// <summary>Mousepad - Zone 7</summary>
		MousepadZone7 = 0xc8,

		/// <summary>Mousepad - Zone 8</summary>
		MousepadZone8 = 0xc9,

		/// <summary>Mousepad - Zone 9</summary>
		MousepadZone9 = 0xca,

		/// <summary>Mousepad - Zone 10</summary>
		MousepadZone10 = 0xcb,

		/// <summary>Mousepad - Zone 11</summary>
		MousepadZone11 = 0xcc,

		/// <summary>Mousepad - Zone 12</summary>
		MousepadZone12 = 0xcd,

		/// <summary>Mousepad - Zone 13</summary>
		MousepadZone13 = 0xce,

		/// <summary>Mousepad - Zone 14</summary>
		MousepadZone14 = 0xcf,

		/// <summary>Mousepad - Zone 15</summary>
		MousepadZone15 = 0xd0,

		/// <summary>Headset Stand - Zone 1</summary>
		HeadsetStandZone1 = 0xd1,

		/// <summary>Headset Stand - Zone 2</summary>
		HeadsetStandZone2 = 0xd2,

		/// <summary>Headset Stand - Zone 3</summary>
		HeadsetStandZone3 = 0xd3,

		/// <summary>Headset Stand - Zone 4</summary>
		HeadsetStandZone4 = 0xd4,

		/// <summary>Headset Stand - Zone 5</summary>
		HeadsetStandZone5 = 0xd5,

		/// <summary>Headset Stand - Zone 6</summary>
		HeadsetStandZone6 = 0xd6,

		/// <summary>Headset Stand - Zone 7</summary>
		HeadsetStandZone7 = 0xd7,

		/// <summary>Headset Stand - Zone 8</summary>
		HeadsetStandZone8 = 0xd8,

		/// <summary>Headset Stand - Zone 9</summary>
		HeadsetStandZone9 = 0xd9,

		/// <summary>Speaker - Left</summary>
		SpeakerLeft = 0xda,

		/// <summary>Speaker - Right</summary>
		SpeakerRight = 0xdb
	};

	/// <summary>Enumeration of Device Types.</summary>
	enum class DeviceType : unsigned char
	{
		/// <summary>Keyboard</summary>
		Keyboard = 0x01,

		/// <summary>Mouse</summary>
		Mouse = 0x02,

		/// <summary>Headset</summary>
		Headset = 0x03,

		/// <summary>Mousepad</summary>
		Mousepad = 0x04,

		/// <summary>Headset Stand</summary>
		HeadsetStand = 0x05,

		/// <summary>Speaker</summary>
		Speaker = 0x06
	};

	/// <summary>Performs operations for RGB LED Illumination.</summary>
	class Led
	{
	public:
		/// <summary>Manually initialize the Spectral library. If Spectral is not initialized, this method will be called when trying to perform operations.</summary>
		/// <returns>True if initialization was successful.</returns>
		static bool Initialize();

		/// <summary>Checks if the Spectral library is initialized.</summary>
		/// <returns>True if initialized.</returns>
		static bool IsInitialized();

		/// <summary>Checks if Logitech device support was enabled during initialization.</summary>
		/// <returns>True if Logitech device support is enabled.</returns>
		static bool LogitechIsEnabled();

		/// <summary>Checks if Corsair device support was enabled during initialization.</summary>
		/// <returns>True if Corsair device support is enabled.</returns>
		static bool CorsairIsEnabled();

		/// <summary>Checks if Razer device support was enabled during initialization.</summary>
		/// <returns>True if Razer device support is enabled.</returns>
		static bool RazerIsEnabled();

		/// <summary>Sets the color of all LEDs on enabled devices to the specified color.</summary>
		/// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <returns>True if LEDs on all enabled devices were successfully set.</returns>
		static bool SetColor(unsigned char red, unsigned char green, unsigned char blue);

		/// <summary>Sets the color of the specified LED on enabled devices to the specified color.</summary>
		/// <param name="ledName">The LED Name value for the LED to be set.</param>
		/// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <returns>True if specified LED on any enabled device was successfully set.</returns>
		static bool SetColorForLed(LedName ledName, unsigned char red, unsigned char green, unsigned char blue);

		/// <summary>Sets the color of the specified LEDs on enabled devices to the specified color.</summary>
		/// <param name="ledNames">The LED Name values for the LEDs to be set.</param>
		/// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <returns>True if specified LEDs on any enabled device was successfully set.</returns>
		static bool SetColorForLeds(std::vector<LedName> ledNames, unsigned char red, unsigned char green, unsigned char blue);

		/// <summary>Sets the color of all enabled devices of the specified type to the specified color.</summary>
		/// <param name="deviceType">The type of devices to set.</param>
		/// <param name="red">The red channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <param name="green">The green channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <param name="blue">The blue channel value for the color to set. On monochromatic devices, only the highest channel value is used.</param>
		/// <returns>True if any enabled device of the specified type was successfully set.</returns>
		static bool SetColorForDevice(DeviceType deviceType, unsigned char red, unsigned char green, unsigned char blue);

		/// <summary>Manually shut down the Spectral library. If not called, the library should shutdown when the application exits.</summary>
		static void Shutdown();
	};
}