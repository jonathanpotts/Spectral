// Copyright 2018 Jonathan Potts. All rights reserved.

#pragma once

#include "ModuleManager.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"

/**
 * Enumeration of LED Names.
 */
UENUM()
enum class ESpectralLedName : uint8
{
	/**
	 * Keyboard - Backspace
	 */
	Backspace = 0x01,

	/**
	 * Keyboard - Tab
	 */
	Tab = 0x02,

	/**
	 * Keyboard - Enter
	 */
	Enter = 0x03,

	/**
	 * Keyboard - Pause/Break
	 */
	Pause = 0x04,

	/**
	 * Keyboard - Caps Lock
	 */
	CapsLock = 0x05,

	/**
	 * Keyboard - Escape
	 */
	Escape = 0x06,

	/**
	 * Keyboard - Spacebar
	 */
	Spacebar = 0x07,

	/**
	 * Keyboard - Page Up
	 */
	PageUp = 0x08,

	/**
	 * Keyboard - Page Down
	 */
	PageDown = 0x09,

	/**
	 * Keyboard - End
	 */
	End = 0x0a,

	/**
	 * Keyboard - Home
	 */
	Home = 0x0b,

	/**
	 * Keyboard - Left Arrow
	 */
	LeftArrow = 0x0c,

	/**
	 * Keyboard - Up Arrow
	 */
	UpArrow = 0x0d,

	/**
	 * Keyboard - Right Arrow
	 */
	RightArrow = 0x0e,

	/**
	 * Keyboard - Down Arrow
	 */
	DownArrow = 0x0f,

	/**
	 * Keyboard - Print Screen
	 */
	PrintScreen = 0x10,

	/**
	 * Keyboard - Insert
	 */
	Insert = 0x11,

	/**
	 * Keyboard - Delete
	 */
	Delete = 0x12,

	/**
	 * Keyboard - 0
	 */
	Zero = 0x13,

	/**
	 * Keyboard - 1
	 */
	One = 0x14,

	/**
	 * Keyboard - 2
	 */
	Two = 0x15,

	/**
	 * Keyboard - 3
	 */
	Three = 0x16,

	/**
	 * Keyboard - 4
	 */
	Four = 0x17,

	/**
	 * Keyboard - 5
	 */
	Five = 0x18,

	/**
	 * Keyboard - 6
	 */
	Six = 0x19,

	/**
	 * Keyboard - 7
	 */
	Seven = 0x1a,

	/**
	 * Keyboard - 8
	 */
	Eight = 0x1b,

	/**
	 * Keyboard - 9
	 */
	Nine = 0x1c,

	/**
	 * Keyboard - A
	 */
	A = 0x1d,

	/**
	 * Keyboard - B
	 */
	B = 0x1e,

	/**
	 * Keyboard - C
	 */
	C = 0x1f,

	/**
	 * Keyboard - D
	 */
	D = 0x20,

	/**
	 * Keyboard - E
	 */
	E = 0x21,

	/**
	 * Keyboard - F
	 */
	F = 0x22,

	/**
	 * Keyboard - G
	 */
	G = 0x23,

	/**
	 * Keyboard - H
	 */
	H = 0x24,

	/**
	 * Keyboard - I
	 */
	I = 0x25,

	/**
	 * Keyboard - J
	 */
	J = 0x26,

	/**
	 * Keyboard - K
	 */
	K = 0x27,

	/**
	 * Keyboard - L
	 */
	L = 0x28,

	/**
	 * Keyboard - M
	 */
	M = 0x29,

	/**
	 * Keyboard - N
	 */
	N = 0x2a,

	/**
	 * Keyboard - O
	 */
	O = 0x2b,

	/**
	 * Keyboard - P
	 */
	P = 0x2c,

	/**
	 * Keyboard - Q
	 */
	Q = 0x2d,

	/**
	 * Keyboard - R
	 */
	R = 0x2e,

	/**
	 * Keyboard - S
	 */
	S = 0x2f,

	/**
	 * Keyboard - T
	 */
	T = 0x30,

	/**
	 * Keyboard - U
	 */
	U = 0x31,

	/**
	 * Keyboard - V
	 */
	V = 0x32,

	/**
	 * Keyboard - W
	 */
	W = 0x33,

	/**
	 * Keyboard - X
	 */
	X = 0x34,

	/**
	 * Keyboard - Y
	 */
	Y = 0x35,

	/**
	 * Keyboard - Z
	 */
	Z = 0x36,

	/**
	 * Keyboard - Left Windows
	 */
	LeftWindows = 0x37,

	/**
	 * Keyboard - Right Windows
	 */
	RightWindows = 0x38,

	/**
	 * Keyboard - Applications
	 */
	Applications = 0x39,

	/**
	 * Keyboard - Numpad 0
	 */
	Numpad0 = 0x3a,

	/**
	 * Keyboard - Numpad 1
	 */
	Numpad1 = 0x3b,

	/**
	 * Keyboard - Numpad 2
	 */
	Numpad2 = 0x3c,

	/**
	 * Keyboard - Numpad 3
	 */
	Numpad3 = 0x3d,

	/**
	 * Keyboard - Numpad 4
	 */
	Numpad4 = 0x3e,

	/**
	 * Keyboard - Numpad 5
	 */
	Numpad5 = 0x3f,

	/**
	 * Keyboard - Numpad 6
	 */
	Numpad6 = 0x40,

	/**
	 * Keyboard - Numpad 7
	 */
	Numpad7 = 0x41,

	/**
	 * Keyboard - Numpad 8
	 */
	Numpad8 = 0x42,

	/**
	 * Keyboard - Numpad 9
	 */
	Numpad9 = 0x43,

	/**
	 * Keyboard - Numpad Multiply
	 */
	Multiply = 0x44,

	/**
	 * Keyboard - Numpad Add
	 */
	Add = 0x45,

	/**
	 * Keyboard - Numpad Subtract
	 */
	Subtract = 0x46,

	/**
	 * Keyboard - Numpad Decimal
	 */
	Decimal = 0x47,

	/**
	 * Keyboard - Numpad Divide
	 */
	Divide = 0x48,

	/**
	 * Keyboard - F1
	 */
	F1 = 0x49,

	/**
	 * Keyboard - F2
	 */
	F2 = 0x4a,

	/**
	 * Keyboard - F3
	 */
	F3 = 0x4b,

	/**
	 * Keyboard - F4
	 */
	F4 = 0x4c,

	/**
	 * Keyboard - F5
	 */
	F5 = 0x4d,

	/**
	 * Keyboard - F6
	 */
	F6 = 0x4e,

	/**
	 * Keyboard - F7
	 */
	F7 = 0x4f,

	/**
	 * Keyboard - F8
	 */
	F8 = 0x50,

	/**
	 * Keyboard - F9
	 */
	F9 = 0x51,

	/**
	 * Keyboard - F10
	 */
	F10 = 0x52,

	/**
	 * Keyboard - F11
	 */
	F11 = 0x53,

	/**
	 * Keyboard - F12
	 */
	F12 = 0x54,

	/**
	 * Keyboard - Num Lock
	 */
	NumLock = 0x55,

	/**
	 * Keyboard - Scroll Lock
	 */
	ScrollLock = 0x56,

	/**
	 * Keyboard - Left Shift
	 */
	LeftShift = 0x57,

	/**
	 * Keyboard - Right Shift
	 */
	RightShift = 0x58,

	/**
	 * Keyboard - Left Control
	 */
	LeftControl = 0x59,

	/**
	 * Keyboard - Right Control
	 */
	RightControl = 0x5a,

	/**
	 * Keyboard - Semicolon/Colon
	 */
	Semicolon = 0x5b,

	/**
	 * Keyboard - Plus/Equal
	 */
	Plus = 0x5c,

	/**
	 * Keyboard - Comma/Less Than
	 */
	Comma = 0x5d,

	/**
	 * Keyboard - Minus/Underscore
	 */
	Minus = 0x5e,

	/**
	 * Keyboard - Period/Greater Than
	 */
	Period = 0x5f,

	/**
	 * Keyboard - Slash/Question
	 */
	Slash = 0x60,

	/**
	 * Keyboard - Tilde/Accent
	 */
	Tilde = 0x61,

	/**
	 * Keyboard - Left Bracket/Left Brace
	 */
	LeftBracket = 0x62,

	/**
	 * Keyboard - Backslash/Pipe
	 */
	Backslash = 0x63,

	/**
	 * Keyboard - Right Bracket/Right Brace
	 */
	RightBracket = 0x64,

	/**
	 * Keyboard - Quote/Apostrophe
	 */
	Quote = 0x65,

	/**
	 * Keyboard - Left Alt
	 */
	LeftAlt = 0x66,

	/**
	 * Keyboard - Right Alt
	 */
	RightAlt = 0x67,

	/**
	 * Keyboard - Numpad Enter
	 */
	NumpadEnter = 0x68,

	/**
	 * Keyboard - G1/Macro 1
	 */
	G1 = 0x69,

	/**
	 * Keyboard - G2/Macro 2
	 */
	G2 = 0x6a,

	/**
	 * Keyboard - G3/Macro 3
	 */
	G3 = 0x6b,

	/**
	 * Keyboard - G4/Macro 4
	 */
	G4 = 0x6c,

	/**
	 * Keyboard - G5/Macro 5
	 */
	G5 = 0x6d,

	/**
	 * Keyboard - G6/Macro 6
	 */
	G6 = 0x6e,

	/**
	 * Keyboard - G7/Macro 7
	 */
	G7 = 0x6f,

	/**
	 * Keyboard - G8/Macro 8
	 */
	G8 = 0x70,

	/**
	 * Keyboard - G9/Macro 9
	 */
	G9 = 0x71,

	/**
	 * Keyboard - Logo
	 */
	Logo = 0x72,

	/**
	 * Keyboard - Badge
	 */
	Badge = 0x73,

	/**
	 * Keyboard - Non-US Backslash
	 */
	NonUsBackslash = 0x74,

	/**
	 * Keyboard - Language 1/IME 1
	 */
	Lang1 = 0x75,

	/**
	 * Keyboard - Language 2/IME 2
	 */
	Lang2 = 0x76,

	/**
	 * Keyboard - LED Programming
	 */
	LedProgramming = 0x77,

	/**
	 * Keyboard - Brightness
	 */
	Brightness = 0x78,

	/**
	 * Keyboard - Non-US Tilde
	 */
	NonUsTilde = 0x79,

	/**
	 * Keyboard - Windows Lock
	 */
	WindowsLock = 0x7a,

	/**
	 * Keyboard - Mute
	 */
	Mute = 0x7b,

	/**
	 * Keyboard - Stop
	 */
	Stop = 0x7c,

	/**
	 * Keyboard - Previous Track
	 */
	PreviousTrack = 0x7d,

	/**
	 * Keyboard - Play/Pause
	 */
	PlayPause = 0x7e,

	/**
	 * Keyboard - Next Track
	 */
	NextTrack = 0x7f,

	/**
	 * Keyboard - Volume Up
	 */
	VolumeUp = 0x80,

	/**
	 * Keyboard - Volume Down
	 */
	VolumeDown = 0x81,

	/**
	 * Keyboard - Memory Reset
	 */
	MR = 0x82,

	/**
	 * Keyboard - Memory Profile 1
	 */
	M1 = 0x83,

	/**
	 * Keyboard - Memory Profile 2
	 */
	M2 = 0x84,

	/**
	 * Keyboard - Memory Profile 3
	 */
	M3 = 0x85,

	/**
	 * Keyboard - G10/Macro 10
	 */
	G10 = 0x86,

	/**
	 * Keyboard - G11/Macro 11
	 */
	G11 = 0x87,

	/**
	 * Keyboard - G12/Macro 12
	 */
	G12 = 0x88,

	/**
	 * Keyboard - G13/Macro 13
	 */
	G13 = 0x89,

	/**
	 * Keyboard - G14/Macro 14
	 */
	G14 = 0x8a,

	/**
	 * Keyboard - G15/Macro 15
	 */
	G15 = 0x8b,

	/**
	 * Keyboard - G16/Macro 16
	 */
	G16 = 0x8c,

	/**
	 * Keyboard - G17/Macro 17
	 */
	G17 = 0x8d,

	/**
	 * Keyboard - G18/Macro 18
	 */
	G18 = 0x8e,

	/**
	 * Keyboard - Fn
	 */
	Fn = 0x8f,

	/**
	 * Keyboard - International 1
	 */
	International1 = 0x90,

	/**
	 * Keyboard - International 2
	 */
	International2 = 0x91,

	/**
	 * Keyboard - International 3
	 */
	International3 = 0x92,

	/**
	 * Keyboard - International 4
	 */
	International4 = 0x93,

	/**
	 * Keyboard - International 5
	 */
	International5 = 0x94,

	/**
	 * Keyboard - International 6
	 */
	International6 = 0x95,

	/**
	 * Keyboard - International 7
	 */
	International7 = 0x96,

	/**
	 * Keyboard - Zone 1
	 */
	KeyboardZone1 = 0x97,

	/**
	 * Keyboard - Zone 2
	 */
	KeyboardZone2 = 0x98,

	/**
	 * Keyboard - Zone 3
	 */
	KeyboardZone3 = 0x99,

	/**
	 * Keyboard - Zone 4
	 */
	KeyboardZone4 = 0x9a,

	/**
	 * Keyboard - Zone 5
	 */
	KeyboardZone5 = 0x9b,

	/**
	 * Keyboard - Zone 6
	 */
	KeyboardZone6 = 0x9c,

	/**
	 * Keyboard - Zone 7
	 */
	KeyboardZone7 = 0x9d,

	/**
	 * Keyboard - Zone 8
	 */
	KeyboardZone8 = 0x9e,

	/**
	 * Keyboard - Zone 9
	 */
	KeyboardZone9 = 0x9f,

	/**
	 * Keyboard - Zone 10
	 */
	KeyboardZone10 = 0xa0,

	/**
	 * Keyboard - Zone 11
	 */
	KeyboardZone11 = 0xa1,

	/**
	 * Keyboard - Zone 12
	 */
	KeyboardZone12 = 0xa2,

	/**
	 * Keyboard - Zone 13
	 */
	KeyboardZone13 = 0xa3,

	/**
	 * Keyboard - Zone 14
	 */
	KeyboardZone14 = 0xa4,

	/**
	 * Keyboard - Zone 15
	 */
	KeyboardZone15 = 0xa5,

	/**
	 * Keyboard - Zone 16
	 */
	KeyboardZone16 = 0xa6,

	/**
	 * Keyboard - Zone 17
	 */
	KeyboardZone17 = 0xa7,

	/**
	 * Keyboard - Zone 18
	 */
	KeyboardZone18 = 0xa8,

	/**
	 * Keyboard - Zone 19
	 */
	KeyboardZone19 = 0xa9,

	/**
	 * Mouse - Zone 1
	 */
	MouseZone1 = 0xaa,

	/**
	 * Mouse - Zone 2
	 */
	MouseZone2 = 0xab,

	/**
	 * Mouse - Zone 3
	 */
	MouseZone3 = 0xac,

	/**
	 * Mouse - Zone 4
	 */
	MouseZone4 = 0xad,

	/**
	 * Mouse - Zone 5
	 */
	MouseZone5 = 0xae,

	/**
	 * Mouse - Zone 6
	 */
	MouseZone6 = 0xaf,

	/**
	 * Mouse - Zone 7
	 */
	MouseZone7 = 0xb0,

	/**
	 * Mouse - Zone 8
	 */
	MouseZone8 = 0xb1,

	/**
	 * Mouse - Zone 9
	 */
	MouseZone9 = 0xb2,

	/**
	 * Mouse - Zone 10
	 */
	MouseZone10 = 0xb3,

	/**
	 * Mouse - Zone 11
	 */
	MouseZone11 = 0xb4,

	/**
	 * Mouse - Zone 12
	 */
	MouseZone12 = 0xb5,

	/**
	 * Mouse - Zone 13
	 */
	MouseZone13 = 0xb6,

	/**
	 * Mouse - Zone 14
	 */
	MouseZone14 = 0xb7,

	/**
	 * Mouse - Zone 15
	 */
	MouseZone15 = 0xb8,

	/**
	 * Mouse - Zone 16
	 */
	MouseZone16 = 0xb9,

	/**
	 * Mouse - Zone 17
	 */
	MouseZone17 = 0xba,

	/**
	 * Mouse - Zone 18
	 */
	MouseZone18 = 0xbb,

	/**
	 * Mouse - Zone 19
	 */
	MouseZone19 = 0xbc,

	/**
	 * Mouse - Zone 20
	 */
	MouseZone20 = 0xbd,

	/**
	 * Mouse - Zone 21
	 */
	MouseZone21 = 0xbe,

	/**
	 * Mouse - Zone 22
	 */
	MouseZone22 = 0xbf,

	/**
	 * Headset - Left Zone (All Zones on Logitech)
	 */
	HeadsetLeftZone = 0xc0,

	/**
	 * Headset - Right Zone
	 */
	HeadsetRightZone = 0xc1,

	/**
	 * Mousepad - Zone 1
	 */
	MousepadZone1 = 0xc2,

	/**
	 * Mousepad - Zone 2
	 */
	MousepadZone2 = 0xc3,

	/**
	 * Mousepad - Zone 3
	 */
	MousepadZone3 = 0xc4,

	/**
	 * Mousepad - Zone 4
	 */
	MousepadZone4 = 0xc5,

	/**
	 * Mousepad - Zone 5
	 */
	MousepadZone5 = 0xc6,

	/**
	 * Mousepad - Zone 6
	 */
	MousepadZone6 = 0xc7,

	/**
	 * Mousepad - Zone 7
	 */
	MousepadZone7 = 0xc8,

	/**
	 * Mousepad - Zone 8
	 */
	MousepadZone8 = 0xc9,

	/**
	 * Mousepad - Zone 9
	 */
	MousepadZone9 = 0xca,

	/**
	 * Mousepad - Zone 10
	 */
	MousepadZone10 = 0xcb,

	/**
	 * Mousepad - Zone 11
	 */
	MousepadZone11 = 0xcc,

	/**
	 * Mousepad - Zone 12
	 */
	MousepadZone12 = 0xcd,

	/**
	 * Mousepad - Zone 13
	 */
	MousepadZone13 = 0xce,

	/**
	 * Mousepad - Zone 14
	 */
	MousepadZone14 = 0xcf,

	/**
	 * Mousepad - Zone 15
	 */
	MousepadZone15 = 0xd0,

	/**
	 * Headset Stand - Zone 1
	 */
	HeadsetStandZone1 = 0xd1,

	/**
	 * Headset Stand - Zone 2
	 */
	HeadsetStandZone2 = 0xd2,

	/**
	 * Headset Stand - Zone 3
	 */
	HeadsetStandZone3 = 0xd3,

	/**
	 * Headset Stand - Zone 4
	 */
	HeadsetStandZone4 = 0xd4,

	/**
	 * Headset Stand - Zone 5
	 */
	HeadsetStandZone5 = 0xd5,

	/**
	 * Headset Stand - Zone 6
	 */
	HeadsetStandZone6 = 0xd6,

	/**
	 * Headset Stand - Zone 7
	 */
	HeadsetStandZone7 = 0xd7,

	/**
	 * Headset Stand - Zone 8
	 */
	HeadsetStandZone8 = 0xd8,

	/**
	 * Headset Stand - Zone 9
	 */
	HeadsetStandZone9 = 0xd9,

	/**
	 * Speaker - Left
	 */
	SpeakerLeft = 0xda,

	/**
	 * Speaker - Right
	 */
	SpeakerRight = 0xdb
};

/**
 * Enumeration of Device Types.
 */
UENUM()
enum class ESpectralDeviceType : uint8
{
	/**
	 * Keyboard
	 */
	Keyboard = 0x01,

	/**
	 * Mouse
	 */
	Mouse = 0x02,

	/**
	 * Headset
	 */
	Headset = 0x03,

	/**
	 * Mousepad
	 */
	Mousepad = 0x04,

	/**
	 * Headset Stand
	 */
	HeadsetStand = 0x05,

	/**
	 * Speaker
	 */
	Speaker = 0x06
};

/**
 * Performs operations for RGB LED Illumination.
 */
class FSpectralModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/**
	 * Manually initialize the Spectral library. If Spectral is not initialized, this method will be called when trying to perform operations.
	 * @return True if initialization was successful.
	 */
	static bool Initialize();

	/**
	 * Checks if the Spectral library has been initialized.
	 * @return True if initialized.
	 */
	static bool IsInitialized();

	/**
	 * Checks if Logitech device support was enabled during initialization.
	 * @return True if device support is enabled.
	 */
	static bool LogitechIsEnabled();

	/**
	 * Checks if Corsair device support was enabled during initialization.
	 * @return True if device support is enabled.
	 */
	static bool CorsairIsEnabled();

	/**
	 * Checks if Razer device support was enabled during initialization.
	 * @return True if device support is enabled.
	 */
	//static bool RazerIsEnabled();

	/**
	 * Sets the color of all LEDs on enabled devices to the specified color.
	 * @param red - The R channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @param green - The G channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @param blue - The B channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @return True if all enabled devices reported success.
	 */
	static bool SetColor(UCHAR red, UCHAR green, UCHAR blue);

	/**
	 * Sets the color of all LEDs on enabled devices to the specified color.
	 * @param color - The color to set the LEDs to (A channel is ignored). On monochromatic devices, only the highest channel value is used.
	 * @return True if all enabled devices reported success.
	 */
	static bool SetColor(FColor color);

	/**
	 * Sets the color of the specified LED on enabled devices to the specified color.
	 * @param ledName - The LED to set.
	 * @param red - The R channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @param green - The G channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @param blue - The B channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @return True If at least one enabled device reported success.
	 */
	static bool SetColorForLed(ESpectralLedName ledName, UCHAR red, UCHAR green, UCHAR blue);

	/**
	 * Sets the color of the specified LED on enabled devices to the specified color.
	 * @param ledName - The LED to set.
	 * @param color - The color to set the LED to (A channel is ignored). On monochromatic devices, only the highest channel value is used.
	 * @return True If at least one enabled device reported success.
	 */
	static bool SetColorForLed(ESpectralLedName ledName, FColor color);

	/**
	 * Sets the color of the specified LEDs on enabled devices to the specified color.
	 * @param count - The number of LEDs to set.
	 * @param ledNames - The LEDs to set.
	 * @param red - The R channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @param green - The G channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @param blue - The B channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @return True If at least one enabled device reported success.
	 */
	static bool SetColorForLeds(int count, ESpectralLedName ledNames[], UCHAR red, UCHAR green, UCHAR blue);

	/**
	 * Sets the color of the specified LEDs on enabled devices to the specified color.
	 * @param ledNames - The LEDs to set.
	 * @param red - The R channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @param green - The G channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @param blue - The B channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	 * @return True If at least one enabled device reported success.
	 */
	static bool SetColorForLeds(TArray<ESpectralLedName> ledNames, UCHAR red, UCHAR green, UCHAR blue);

	/**
	 * Sets the color of the specified LEDs on enabled devices to the specified color.
	 * @param count - The number of LEDs to set.
	 * @param ledNames - The LEDs to set.
	 * @param color - The color to set the LEDs to (A channel is ignored). On monochromatic devices, only the highest channel value is used.
	 * @return True If at least one enabled device reported success.
	 */
	static bool SetColorForLeds(int count, ESpectralLedName ledNames[], FColor color);

	/**
	 * Sets the color of the specified LEDs on enabled devices to the specified color.
	 * @param ledNames - The LEDs to set.
	 * @param color - The color to set the LEDs to (A channel is ignored). On monochromatic devices, only the highest channel value is used.
	 * @return True If at least one enabled device reported success.
	 */
	static bool SetColorForLeds(TArray<ESpectralLedName> ledNames, FColor color);

	/**
	* Sets the color of all enabled devices of the specified type to the specified color.
	* @param deviceType - The type of devices to set.
	* @param red - The R channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	* @param green - The G channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	* @param blue - The B channel of the color to set the LEDs to. On monochromatic devices, only the highest channel value is used.
	* @return True if any enabled device of the specified type was successfully set.
	*/
	static bool SetColorForDevice(ESpectralDeviceType deviceType, UCHAR red, UCHAR green, UCHAR blue);

	/**
	* Sets the color of all enabled devices of the specified type to the specified color.
	* @param deviceType - The type of devices to set.
	* @param color - The color to set the LEDs to (A channel is ignored). On monochromatic devices, only the highest channel value is used.
	* @return True if any enabled device of the specified type was successfully set.
	*/
	static bool SetColorForDevice(ESpectralDeviceType deviceType, FColor color);

	/**
	 * Manually shut down the Spectral library. If not called, the library should shutdown when the application exits.
	 */
	static void Shutdown();
};
