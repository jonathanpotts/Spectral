// Copyright 2018 Jonathan Potts. All rights reserved.

#include "stdafx.h"

#define LOGILED_KEYNAME_INVALID (LogiLed::KeyName)0
#define LOGILED_KEYBOARDZONE_1 1
#define LOGILED_KEYBOARDZONE_2 2
#define LOGILED_KEYBOARDZONE_3 3
#define LOGILED_KEYBOARDZONE_4 4
#define LOGILED_KEYBOARDZONE_5 5
#define LOGILED_MOUSEZONE_1 0
#define LOGILED_MOUSEZONE_2 1
#define LOGILED_HEADSETZONE_LOGO 0
#define LOGILED_HEADSETZONE_BACK 1
#define LOGILED_MOUSEMATZONE_LOGO 0
#define LOGILED_SPEAKERZONE_FRONTLEFT 0
#define LOGILED_SPEAKERZONE_FRONTRIGHT 1
#define LOGILED_SPEAKERZONE_REARLEFT 2
#define LOGILED_SPEAKERZONE_REARRIGHT 3
#define CHROMASDK_MOUSE_RZLED2_INVALID (ChromaSDK::Mouse::RZLED2)0

bool SpectralInitialized = false;
bool SpectralLogitechEnabled = false;
bool SpectralCorsairEnabled = false;
bool SpectralRazerEnabled = false;
CorsairLedColor SpectralSavedCorsairLedColors[CLI_Last];
RzChromaImpl RazerImplementation;

UCHAR SpectralGetColorPercentage(UCHAR value)
{
	return (UCHAR)roundf((float)value / (float)UCHAR_MAX * 100.0f);
}

LogiLed::KeyName SpectralGetLogiLedKeyName(Spectral::LedName ledName)
{
	switch (ledName)
	{
	case Spectral::Backspace:
		return LogiLed::BACKSPACE;

	case Spectral::Tab:
		return LogiLed::TAB;

	case Spectral::Enter:
		return LogiLed::ENTER;

	case Spectral::Pause:
		return LogiLed::PAUSE_BREAK;

	case Spectral::CapsLock:
		return LogiLed::CAPS_LOCK;

	case Spectral::Escape:
		return LogiLed::ESC;

	case Spectral::Spacebar:
		return LogiLed::SPACE;

	case Spectral::PageUp:
		return LogiLed::PAGE_UP;

	case Spectral::PageDown:
		return LogiLed::PAGE_DOWN;

	case Spectral::End:
		return LogiLed::END;

	case Spectral::Home:
		return LogiLed::HOME;

	case Spectral::LeftArrow:
		return LogiLed::ARROW_LEFT;

	case Spectral::UpArrow:
		return LogiLed::ARROW_UP;

	case Spectral::RightArrow:
		return LogiLed::ARROW_RIGHT;

	case Spectral::DownArrow:
		return LogiLed::ARROW_DOWN;

	case Spectral::PrintScreen:
		return LogiLed::PRINT_SCREEN;

	case Spectral::Insert:
		return LogiLed::INSERT;

	case Spectral::Delete:
		return LogiLed::KEYBOARD_DELETE;

	case Spectral::Zero:
		return LogiLed::ZERO;

	case Spectral::One:
		return LogiLed::ONE;

	case Spectral::Two:
		return LogiLed::TWO;

	case Spectral::Three:
		return LogiLed::THREE;

	case Spectral::Four:
		return LogiLed::FOUR;

	case Spectral::Five:
		return LogiLed::FIVE;

	case Spectral::Six:
		return LogiLed::SIX;

	case Spectral::Seven:
		return LogiLed::SEVEN;

	case Spectral::Eight:
		return LogiLed::EIGHT;

	case Spectral::Nine:
		return LogiLed::NINE;

	case Spectral::A:
		return LogiLed::A;

	case Spectral::B:
		return LogiLed::B;

	case Spectral::C:
		return LogiLed::C;

	case Spectral::D:
		return LogiLed::D;

	case Spectral::E:
		return LogiLed::E;

	case Spectral::F:
		return LogiLed::F;

	case Spectral::G:
		return LogiLed::G;

	case Spectral::H:
		return LogiLed::H;

	case Spectral::I:
		return LogiLed::I;

	case Spectral::J:
		return LogiLed::J;

	case Spectral::K:
		return LogiLed::K;

	case Spectral::L:
		return LogiLed::L;

	case Spectral::M:
		return LogiLed::M;

	case Spectral::N:
		return LogiLed::N;

	case Spectral::O:
		return LogiLed::O;

	case Spectral::P:
		return LogiLed::P;

	case Spectral::Q:
		return LogiLed::Q;

	case Spectral::R:
		return LogiLed::R;

	case Spectral::S:
		return LogiLed::S;

	case Spectral::T:
		return LogiLed::T;

	case Spectral::U:
		return LogiLed::U;

	case Spectral::V:
		return LogiLed::V;

	case Spectral::W:
		return LogiLed::W;

	case Spectral::X:
		return LogiLed::X;

	case Spectral::Y:
		return LogiLed::Y;

	case Spectral::Z:
		return LogiLed::Z;

	case Spectral::LeftWindows:
		return LogiLed::LEFT_WINDOWS;

	case Spectral::RightWindows:
		return LogiLed::RIGHT_WINDOWS;

	case Spectral::Applications:
		return LogiLed::APPLICATION_SELECT;

	case Spectral::Numpad0:
		return LogiLed::NUM_ZERO;

	case Spectral::Numpad1:
		return LogiLed::NUM_ONE;

	case Spectral::Numpad2:
		return LogiLed::NUM_TWO;

	case Spectral::Numpad3:
		return LogiLed::NUM_THREE;

	case Spectral::Numpad4:
		return LogiLed::NUM_FOUR;

	case Spectral::Numpad5:
		return LogiLed::NUM_FIVE;

	case Spectral::Numpad6:
		return LogiLed::NUM_SIX;

	case Spectral::Numpad7:
		return LogiLed::NUM_SEVEN;

	case Spectral::Numpad8:
		return LogiLed::NUM_EIGHT;

	case Spectral::Numpad9:
		return LogiLed::NUM_NINE;

	case Spectral::Multiply:
		return LogiLed::NUM_ASTERISK;

	case Spectral::Add:
		return LogiLed::NUM_PLUS;

	case Spectral::Subtract:
		return LogiLed::NUM_MINUS;

	case Spectral::Decimal:
		return LogiLed::NUM_PERIOD;

	case Spectral::Divide:
		return LogiLed::NUM_SLASH;

	case Spectral::F1:
		return LogiLed::F1;

	case Spectral::F2:
		return LogiLed::F2;

	case Spectral::F3:
		return LogiLed::F3;

	case Spectral::F4:
		return LogiLed::F4;

	case Spectral::F5:
		return LogiLed::F5;

	case Spectral::F6:
		return LogiLed::F6;

	case Spectral::F7:
		return LogiLed::F7;

	case Spectral::F8:
		return LogiLed::F8;

	case Spectral::F9:
		return LogiLed::F9;

	case Spectral::F10:
		return LogiLed::F10;

	case Spectral::F11:
		return LogiLed::F11;

	case Spectral::F12:
		return LogiLed::F12;

	case Spectral::NumLock:
		return LogiLed::NUM_LOCK;

	case Spectral::ScrollLock:
		return LogiLed::SCROLL_LOCK;

	case Spectral::LeftShift:
		return LogiLed::LEFT_SHIFT;

	case Spectral::RightShift:
		return LogiLed::RIGHT_SHIFT;

	case Spectral::LeftControl:
		return LogiLed::LEFT_CONTROL;

	case Spectral::RightControl:
		return LogiLed::RIGHT_CONTROL;

	case Spectral::Semicolon:
		return LogiLed::SEMICOLON;

	case Spectral::Plus:
		return LogiLed::EQUALS;

	case Spectral::Comma:
		return LogiLed::COMMA;

	case Spectral::Minus:
		return LogiLed::MINUS;

	case Spectral::Period:
		return LogiLed::PERIOD;

	case Spectral::Slash:
		return LogiLed::FORWARD_SLASH;

	case Spectral::Tilde:
		return LogiLed::TILDE;

	case Spectral::LeftBracket:
		return LogiLed::OPEN_BRACKET;

	case Spectral::Backslash:
		return LogiLed::BACKSLASH;

	case Spectral::RightBracket:
		return LogiLed::CLOSE_BRACKET;

	case Spectral::Quote:
		return LogiLed::APOSTROPHE;

	case Spectral::LeftAlt:
		return LogiLed::LEFT_ALT;

	case Spectral::RightAlt:
		return LogiLed::RIGHT_ALT;

	case Spectral::NumpadEnter:
		return LogiLed::NUM_ENTER;

	case Spectral::G1:
		return LogiLed::G_1;

	case Spectral::G2:
		return LogiLed::G_2;

	case Spectral::G3:
		return LogiLed::G_3;

	case Spectral::G4:
		return LogiLed::G_4;

	case Spectral::G5:
		return LogiLed::G_5;

	case Spectral::G6:
		return LogiLed::G_6;

	case Spectral::G7:
		return LogiLed::G_7;
		
	case Spectral::G8:
		return LogiLed::G_8;

	case Spectral::G9:
		return LogiLed::G_9;

	case Spectral::Logo:
		return LogiLed::G_LOGO;

	case Spectral::Badge:
		return LogiLed::G_BADGE;

	default:
		return LOGILED_KEYNAME_INVALID;
	}
}

CorsairLedId SpectralGetCorsairLedId(Spectral::LedName ledName)
{
	switch (ledName)
	{
	case Spectral::Backspace:
		return CLK_Backspace;

	case Spectral::Tab:
		return CLK_Tab;

	case Spectral::Enter:
		return CLK_Enter;

	case Spectral::Pause:
		return CLK_PauseBreak;

	case Spectral::CapsLock:
		return CLK_CapsLock;

	case Spectral::Escape:
		return CLK_Escape;

	case Spectral::Spacebar:
		return CLK_Space;

	case Spectral::PageUp:
		return CLK_PageUp;

	case Spectral::PageDown:
		return CLK_PageDown;

	case Spectral::End:
		return CLK_End;

	case Spectral::Home:
		return CLK_Home;

	case Spectral::LeftArrow:
		return CLK_LeftArrow;

	case Spectral::UpArrow:
		return CLK_UpArrow;

	case Spectral::RightArrow:
		return CLK_RightArrow;

	case Spectral::DownArrow:
		return CLK_DownArrow;

	case Spectral::PrintScreen:
		return CLK_PrintScreen;

	case Spectral::Insert:
		return CLK_Insert;

	case Spectral::Delete:
		return CLK_Delete;

	case Spectral::Zero:
		return CLK_0;

	case Spectral::One:
		return CLK_1;

	case Spectral::Two:
		return CLK_2;

	case Spectral::Three:
		return CLK_3;

	case Spectral::Four:
		return CLK_4;

	case Spectral::Five:
		return CLK_5;

	case Spectral::Six:
		return CLK_6;

	case Spectral::Seven:
		return CLK_7;

	case Spectral::Eight:
		return CLK_8;

	case Spectral::Nine:
		return CLK_9;

	case Spectral::A:
		return CLK_A;

	case Spectral::B:
		return CLK_B;

	case Spectral::C:
		return CLK_C;

	case Spectral::D:
		return CLK_D;

	case Spectral::E:
		return CLK_E;

	case Spectral::F:
		return CLK_F;

	case Spectral::G:
		return CLK_G;

	case Spectral::H:
		return CLK_H;

	case Spectral::I:
		return CLK_I;

	case Spectral::J:
		return CLK_J;

	case Spectral::K:
		return CLK_K;

	case Spectral::L:
		return CLK_L;

	case Spectral::M:
		return CLK_M;

	case Spectral::N:
		return CLK_N;

	case Spectral::O:
		return CLK_O;

	case Spectral::P:
		return CLK_P;

	case Spectral::Q:
		return CLK_Q;

	case Spectral::R:
		return CLK_R;

	case Spectral::S:
		return CLK_S;

	case Spectral::T:
		return CLK_T;

	case Spectral::U:
		return CLK_U;

	case Spectral::V:
		return CLK_V;

	case Spectral::W:
		return CLK_W;

	case Spectral::X:
		return CLK_X;

	case Spectral::Y:
		return CLK_Y;

	case Spectral::Z:
		return CLK_Z;

	case Spectral::LeftWindows:
		return CLK_LeftGui;

	case Spectral::RightWindows:
		return CLK_RightGui;

	case Spectral::Applications:
		return CLK_Application;

	case Spectral::Numpad0:
		return CLK_Keypad0;

	case Spectral::Numpad1:
		return CLK_Keypad1;

	case Spectral::Numpad2:
		return CLK_Keypad2;

	case Spectral::Numpad3:
		return CLK_Keypad3;

	case Spectral::Numpad4:
		return CLK_Keypad4;

	case Spectral::Numpad5:
		return CLK_Keypad5;

	case Spectral::Numpad6:
		return CLK_Keypad6;

	case Spectral::Numpad7:
		return CLK_Keypad7;

	case Spectral::Numpad8:
		return CLK_Keypad8;

	case Spectral::Numpad9:
		return CLK_Keypad9;

	case Spectral::Multiply:
		return CLK_KeypadAsterisk;

	case Spectral::Add:
		return CLK_KeypadPlus;

	case Spectral::Subtract:
		return CLK_KeypadMinus;

	case Spectral::Decimal:
		return CLK_KeypadPeriodAndDelete;

	case Spectral::Divide:
		return CLK_KeypadSlash;

	case Spectral::F1:
		return CLK_F1;

	case Spectral::F2:
		return CLK_F2;

	case Spectral::F3:
		return CLK_F3;

	case Spectral::F4:
		return CLK_F4;

	case Spectral::F5:
		return CLK_F5;

	case Spectral::F6:
		return CLK_F6;

	case Spectral::F7:
		return CLK_F7;

	case Spectral::F8:
		return CLK_F8;

	case Spectral::F9:
		return CLK_F9;

	case Spectral::F10:
		return CLK_F10;

	case Spectral::F11:
		return CLK_F11;

	case Spectral::F12:
		return CLK_F12;

	case Spectral::NumLock:
		return CLK_NumLock;

	case Spectral::ScrollLock:
		return CLK_ScrollLock;

	case Spectral::LeftShift:
		return CLK_LeftShift;

	case Spectral::RightShift:
		return CLK_RightShift;

	case Spectral::LeftControl:
		return CLK_LeftCtrl;

	case Spectral::RightControl:
		return CLK_RightCtrl;

	case Spectral::Semicolon:
		return CLK_SemicolonAndColon;

	case Spectral::Plus:
		return CLK_EqualsAndPlus;

	case Spectral::Comma:
		return CLK_CommaAndLessThan;

	case Spectral::Minus:
		return CLK_MinusAndUnderscore;

	case Spectral::Period:
		return CLK_PeriodAndBiggerThan;

	case Spectral::Slash:
		return CLK_SlashAndQuestionMark;

	case Spectral::Tilde:
		return CLK_GraveAccentAndTilde;

	case Spectral::LeftBracket:
		return CLK_BracketLeft;

	case Spectral::Backslash:
		return CLK_Backslash;

	case Spectral::RightBracket:
		return CLK_BracketRight;

	case Spectral::Quote:
		return CLK_ApostropheAndDoubleQuote;

	case Spectral::LeftAlt:
		return CLK_LeftAlt;

	case Spectral::RightAlt:
		return CLK_RightAlt;

	case Spectral::NumpadEnter:
		return CLK_KeypadEnter;

	case Spectral::G1:
		return CLK_G1;

	case Spectral::G2:
		return CLK_G2;

	case Spectral::G3:
		return CLK_G3;

	case Spectral::G4:
		return CLK_G4;


	case Spectral::G5:
		return CLK_G5;

	case Spectral::G6:
		return CLK_G6;

	case Spectral::G7:
		return CLK_G7;

	case Spectral::G8:
		return CLK_G8;

	case Spectral::G9:
		return CLK_G9;

	case Spectral::Logo:
		return CLK_Logo;

	case Spectral::NonUsBackslash:
		return CLK_NonUsBackslash;

	case Spectral::Lang1:
		return CLK_Lang1;

	case Spectral::Lang2:
		return CLK_Lang2;

	case Spectral::International1:
		return CLK_International1;

	case Spectral::International2:
		return CLK_International2;

	case Spectral::International3:
		return CLK_International3;

	case Spectral::LedProgramming:
		return CLK_LedProgramming;

	case Spectral::Brightness:
		return CLK_Brightness;

	case Spectral::NonUsTilde:
		return CLK_NonUsTilde;

	case Spectral::WindowsLock:
		return CLK_WinLock;

	case Spectral::Mute:
		return CLK_Mute;

	case Spectral::Stop:
		return CLK_Stop;

	case Spectral::PreviousTrack:
		return CLK_ScanPreviousTrack;

	case Spectral::PlayPause:
		return CLK_PlayPause;

	case Spectral::NextTrack:
		return CLK_ScanNextTrack;

	case Spectral::VolumeUp:
		return CLK_VolumeUp;

	case Spectral::VolumeDown:
		return CLK_VolumeDown;

	case Spectral::MR:
		return CLK_MR;

	case Spectral::M1:
		return CLK_M1;

	case Spectral::M2:
		return CLK_M2;

	case Spectral::M3:
		return CLK_M3;

	case Spectral::G10:
		return CLK_G10;
		
	case Spectral::G11:
		return CLK_G11;

	case Spectral::G12:
		return CLK_G12;

	case Spectral::G13:
		return CLK_G13;

	case Spectral::G14:
		return CLK_G14;

	case Spectral::G15:
		return CLK_G15;

	case Spectral::G16:
		return CLK_G16;

	case Spectral::G17:
		return CLK_G17;

	case Spectral::G18:
		return CLK_G18;

	case Spectral::International4:
		return CLK_International4;

	case Spectral::International5:
		return CLK_International5;

	case Spectral::Fn:
		return CLK_Fn;

	case Spectral::MouseZone1:
		return CLM_1;

	case Spectral::MouseZone2:
		return CLM_2;

	case Spectral::MouseZone3:
		return CLM_3;

	case Spectral::MouseZone4:
		return CLM_4;

	case Spectral::HeadsetLeftZone:
		return CLH_LeftLogo;

	case Spectral::HeadsetRightZone:
		return CLH_RightLogo;

	case Spectral::MousepadZone1:
		return CLMM_Zone1;

	case Spectral::MousepadZone2:
		return CLMM_Zone2;

	case Spectral::MousepadZone3:
		return CLMM_Zone3;

	case Spectral::MousepadZone4:
		return CLMM_Zone4;

	case Spectral::MousepadZone5:
		return CLMM_Zone5;

	case Spectral::MousepadZone6:
		return CLMM_Zone6;

	case Spectral::MousepadZone7:
		return CLMM_Zone7;

	case Spectral::MousepadZone8:
		return CLMM_Zone8;

	case Spectral::MousepadZone9:
		return CLMM_Zone9;

	case Spectral::MousepadZone10:
		return CLMM_Zone10;

	case Spectral::MousepadZone11:
		return CLMM_Zone11;

	case Spectral::MousepadZone12:
		return CLMM_Zone12;

	case Spectral::MousepadZone13:
		return CLMM_Zone13;

	case Spectral::MousepadZone14:
		return CLMM_Zone14;

	case Spectral::MousepadZone15:
		return CLMM_Zone15;

	case Spectral::KeyboardZone1:
		return CLKLP_Zone1;

	case Spectral::KeyboardZone2:
		return CLKLP_Zone2;

	case Spectral::KeyboardZone3:
		return CLKLP_Zone3;

	case Spectral::KeyboardZone4:
		return CLKLP_Zone4;

	case Spectral::KeyboardZone5:
		return CLKLP_Zone5;

	case Spectral::KeyboardZone6:
		return CLKLP_Zone6;

	case Spectral::KeyboardZone7:
		return CLKLP_Zone7;

	case Spectral::KeyboardZone8:
		return CLKLP_Zone8;

	case Spectral::KeyboardZone9:
		return CLKLP_Zone9;

	case Spectral::KeyboardZone10:
		return CLKLP_Zone10;

	case Spectral::KeyboardZone11:
		return CLKLP_Zone11;

	case Spectral::KeyboardZone12:
		return CLKLP_Zone12;

	case Spectral::KeyboardZone13:
		return CLKLP_Zone13;

	case Spectral::KeyboardZone14:
		return CLKLP_Zone14;

	case Spectral::KeyboardZone15:
		return CLKLP_Zone15;

	case Spectral::KeyboardZone16:
		return CLKLP_Zone16;

	case Spectral::KeyboardZone17:
		return CLKLP_Zone17;

	case Spectral::KeyboardZone18:
		return CLKLP_Zone18;

	case Spectral::KeyboardZone19:
		return CLKLP_Zone19;

	case Spectral::MouseZone5:
		return CLM_5;

	case Spectral::MouseZone6:
		return CLM_6;

	case Spectral::HeadsetStandZone1:
		return CLHSS_Zone1;

	case Spectral::HeadsetStandZone2:
		return CLHSS_Zone2;

	case Spectral::HeadsetStandZone3:
		return CLHSS_Zone3;

	case Spectral::HeadsetStandZone4:
		return CLHSS_Zone4;

	case Spectral::HeadsetStandZone5:
		return CLHSS_Zone5;

	case Spectral::HeadsetStandZone6:
		return CLHSS_Zone6;

	case Spectral::HeadsetStandZone7:
		return CLHSS_Zone7;

	case Spectral::HeadsetStandZone8:
		return CLHSS_Zone8;

	case Spectral::HeadsetStandZone9:
		return CLHSS_Zone9;

	default:
		return CLI_Invalid;
	}
}

ChromaSDK::Keyboard::RZKEY SpectralGetRazerKey(Spectral::LedName ledName)
{
	switch (ledName)
	{
	case Spectral::Backspace:
		return ChromaSDK::Keyboard::RZKEY_BACKSPACE;

	case Spectral::Tab:
		return ChromaSDK::Keyboard::RZKEY_TAB;

	case Spectral::Enter:
		return ChromaSDK::Keyboard::RZKEY_ENTER;

	case Spectral::Pause:
		return ChromaSDK::Keyboard::RZKEY_PAUSE;

	case Spectral::CapsLock:
		return ChromaSDK::Keyboard::RZKEY_CAPSLOCK;

	case Spectral::Escape:
		return ChromaSDK::Keyboard::RZKEY_ESC;

	case Spectral::Spacebar:
		return ChromaSDK::Keyboard::RZKEY_SPACE;

	case Spectral::PageUp:
		return ChromaSDK::Keyboard::RZKEY_PAGEUP;

	case Spectral::PageDown:
		return ChromaSDK::Keyboard::RZKEY_PAGEDOWN;

	case Spectral::End:
		return ChromaSDK::Keyboard::RZKEY_END;

	case Spectral::Home:
		return ChromaSDK::Keyboard::RZKEY_HOME;

	case Spectral::LeftArrow:
		return ChromaSDK::Keyboard::RZKEY_LEFT;

	case Spectral::UpArrow:
		return ChromaSDK::Keyboard::RZKEY_UP;

	case Spectral::RightArrow:
		return ChromaSDK::Keyboard::RZKEY_RIGHT;

	case Spectral::DownArrow:
		return ChromaSDK::Keyboard::RZKEY_DOWN;

	case Spectral::PrintScreen:
		return ChromaSDK::Keyboard::RZKEY_PRINTSCREEN;

	case Spectral::Insert:
		return ChromaSDK::Keyboard::RZKEY_INSERT;

	case Spectral::Delete:
		return ChromaSDK::Keyboard::RZKEY_DELETE;

	case Spectral::Zero:
		return ChromaSDK::Keyboard::RZKEY_0;

	case Spectral::One:
		return ChromaSDK::Keyboard::RZKEY_1;

	case Spectral::Two:
		return ChromaSDK::Keyboard::RZKEY_2;

	case Spectral::Three:
		return ChromaSDK::Keyboard::RZKEY_3;

	case Spectral::Four:
		return ChromaSDK::Keyboard::RZKEY_4;

	case Spectral::Five:
		return ChromaSDK::Keyboard::RZKEY_5;

	case Spectral::Six:
		return ChromaSDK::Keyboard::RZKEY_6;

	case Spectral::Seven:
		return ChromaSDK::Keyboard::RZKEY_7;

	case Spectral::Eight:
		return ChromaSDK::Keyboard::RZKEY_8;

	case Spectral::Nine:
		return ChromaSDK::Keyboard::RZKEY_9;

	case Spectral::A:
		return ChromaSDK::Keyboard::RZKEY_A;

	case Spectral::B:
		return ChromaSDK::Keyboard::RZKEY_B;

	case Spectral::C:
		return ChromaSDK::Keyboard::RZKEY_C;

	case Spectral::D:
		return ChromaSDK::Keyboard::RZKEY_D;

	case Spectral::E:
		return ChromaSDK::Keyboard::RZKEY_E;

	case Spectral::F:
		return ChromaSDK::Keyboard::RZKEY_F;

	case Spectral::G:
		return ChromaSDK::Keyboard::RZKEY_G;

	case Spectral::H:
		return ChromaSDK::Keyboard::RZKEY_H;

	case Spectral::I:
		return ChromaSDK::Keyboard::RZKEY_I;

	case Spectral::J:
		return ChromaSDK::Keyboard::RZKEY_J;

	case Spectral::K:
		return ChromaSDK::Keyboard::RZKEY_K;

	case Spectral::L:
		return ChromaSDK::Keyboard::RZKEY_L;

	case Spectral::M:
		return ChromaSDK::Keyboard::RZKEY_M;

	case Spectral::N:
		return ChromaSDK::Keyboard::RZKEY_N;

	case Spectral::O:
		return ChromaSDK::Keyboard::RZKEY_O;

	case Spectral::P:
		return ChromaSDK::Keyboard::RZKEY_P;

	case Spectral::Q:
		return ChromaSDK::Keyboard::RZKEY_Q;

	case Spectral::R:
		return ChromaSDK::Keyboard::RZKEY_R;

	case Spectral::S:
		return ChromaSDK::Keyboard::RZKEY_S;

	case Spectral::T:
		return ChromaSDK::Keyboard::RZKEY_T;

	case Spectral::U:
		return ChromaSDK::Keyboard::RZKEY_U;

	case Spectral::V:
		return ChromaSDK::Keyboard::RZKEY_V;

	case Spectral::W:
		return ChromaSDK::Keyboard::RZKEY_W;

	case Spectral::X:
		return ChromaSDK::Keyboard::RZKEY_X;

	case Spectral::Y:
		return ChromaSDK::Keyboard::RZKEY_Y;

	case Spectral::Z:
		return ChromaSDK::Keyboard::RZKEY_Z;

	case Spectral::LeftWindows:
		return ChromaSDK::Keyboard::RZKEY_LWIN;

	case Spectral::Applications:
		return ChromaSDK::Keyboard::RZKEY_RMENU;

	case Spectral::Numpad0:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD0;

	case Spectral::Numpad1:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD1;

	case Spectral::Numpad2:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD2;

	case Spectral::Numpad3:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD3;

	case Spectral::Numpad4:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD4;

	case Spectral::Numpad5:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD5;

	case Spectral::Numpad6:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD6;

	case Spectral::Numpad7:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD7;

	case Spectral::Numpad8:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD8;

	case Spectral::Numpad9:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD9;

	case Spectral::Multiply:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD_MULTIPLY;

	case Spectral::Add:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD_ADD;

	case Spectral::Subtract:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD_SUBTRACT;

	case Spectral::Decimal:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD_DECIMAL;

	case Spectral::Divide:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD_DIVIDE;

	case Spectral::F1:
		return ChromaSDK::Keyboard::RZKEY_F1;

	case Spectral::F2:
		return ChromaSDK::Keyboard::RZKEY_F2;

	case Spectral::F3:
		return ChromaSDK::Keyboard::RZKEY_F3;

	case Spectral::F4:
		return ChromaSDK::Keyboard::RZKEY_F4;

	case Spectral::F5:
		return ChromaSDK::Keyboard::RZKEY_F5;

	case Spectral::F6:
		return ChromaSDK::Keyboard::RZKEY_F6;

	case Spectral::F7:
		return ChromaSDK::Keyboard::RZKEY_F7;

	case Spectral::F8:
		return ChromaSDK::Keyboard::RZKEY_F8;

	case Spectral::F9:
		return ChromaSDK::Keyboard::RZKEY_F9;

	case Spectral::F10:
		return ChromaSDK::Keyboard::RZKEY_F10;

	case Spectral::F11:
		return ChromaSDK::Keyboard::RZKEY_F11;

	case Spectral::F12:
		return ChromaSDK::Keyboard::RZKEY_F12;

	case Spectral::NumLock:
		return ChromaSDK::Keyboard::RZKEY_NUMLOCK;

	case Spectral::ScrollLock:
		return ChromaSDK::Keyboard::RZKEY_SCROLL;

	case Spectral::LeftShift:
		return ChromaSDK::Keyboard::RZKEY_LSHIFT;

	case Spectral::RightShift:
		return ChromaSDK::Keyboard::RZKEY_RSHIFT;

	case Spectral::LeftControl:
		return ChromaSDK::Keyboard::RZKEY_LCTRL;

	case Spectral::RightControl:
		return ChromaSDK::Keyboard::RZKEY_RCTRL;

	case Spectral::Semicolon:
		return ChromaSDK::Keyboard::RZKEY_OEM_7;

	case Spectral::Plus:
		return ChromaSDK::Keyboard::RZKEY_OEM_3;

	case Spectral::Comma:
		return ChromaSDK::Keyboard::RZKEY_OEM_9;

	case Spectral::Minus:
		return ChromaSDK::Keyboard::RZKEY_OEM_2;

	case Spectral::Period:
		return ChromaSDK::Keyboard::RZKEY_OEM_10;

	case Spectral::Slash:
		return ChromaSDK::Keyboard::RZKEY_OEM_11;

	case Spectral::Tilde:
		return ChromaSDK::Keyboard::RZKEY_OEM_1;

	case Spectral::LeftBracket:
		return ChromaSDK::Keyboard::RZKEY_OEM_4;

	case Spectral::Backslash:
		return ChromaSDK::Keyboard::RZKEY_OEM_6;

	case Spectral::RightBracket:
		return ChromaSDK::Keyboard::RZKEY_OEM_5;

	case Spectral::Quote:
		return ChromaSDK::Keyboard::RZKEY_OEM_8;

	case Spectral::LeftAlt:
		return ChromaSDK::Keyboard::RZKEY_LALT;

	case Spectral::RightAlt:
		return ChromaSDK::Keyboard::RZKEY_RALT;

	case Spectral::NumpadEnter:
		return ChromaSDK::Keyboard::RZKEY_NUMPAD_ENTER;

	case Spectral::G1:
		return ChromaSDK::Keyboard::RZKEY_MACRO1;

	case Spectral::G2:
		return ChromaSDK::Keyboard::RZKEY_MACRO2;

	case Spectral::G3:
		return ChromaSDK::Keyboard::RZKEY_MACRO3;

	case Spectral::G4:
		return ChromaSDK::Keyboard::RZKEY_MACRO4;

	case Spectral::G5:
		return ChromaSDK::Keyboard::RZKEY_MACRO5;

	case Spectral::Fn:
		return ChromaSDK::Keyboard::RZKEY_FN;

	default:
		return ChromaSDK::Keyboard::RZKEY_INVALID;
	}
}

ChromaSDK::Mouse::RZLED2 SpectralGetRazerMouseLedId(Spectral::LedName ledName)
{
	switch (ledName)
	{
	case Spectral::MouseZone1:
		return ChromaSDK::Mouse::RZLED2_SCROLLWHEEL;

	case Spectral::MouseZone2:
		return ChromaSDK::Mouse::RZLED2_LOGO;

	case Spectral::MouseZone3:
		return ChromaSDK::Mouse::RZLED2_BACKLIGHT;

	case Spectral::MouseZone4:
		return ChromaSDK::Mouse::RZLED2_LEFT_SIDE1;

	case Spectral::MouseZone5:
		return ChromaSDK::Mouse::RZLED2_LEFT_SIDE2;

	case Spectral::MouseZone6:
		return ChromaSDK::Mouse::RZLED2_LEFT_SIDE3;

	case Spectral::MouseZone7:
		return ChromaSDK::Mouse::RZLED2_LEFT_SIDE4;

	case Spectral::MouseZone8:
		return ChromaSDK::Mouse::RZLED2_LEFT_SIDE5;

	case Spectral::MouseZone9:
		return ChromaSDK::Mouse::RZLED2_LEFT_SIDE6;

	case Spectral::MouseZone10:
		return ChromaSDK::Mouse::RZLED2_LEFT_SIDE7;

	case Spectral::MouseZone11:
		return ChromaSDK::Mouse::RZLED2_BOTTOM1;

	case Spectral::MouseZone12:
		return ChromaSDK::Mouse::RZLED2_BOTTOM2;

	case Spectral::MouseZone13:
		return ChromaSDK::Mouse::RZLED2_BOTTOM3;

	case Spectral::MouseZone14:
		return ChromaSDK::Mouse::RZLED2_BOTTOM4;

	case Spectral::MouseZone15:
		return ChromaSDK::Mouse::RZLED2_BOTTOM5;

	case Spectral::MouseZone16:
		return ChromaSDK::Mouse::RZLED2_RIGHT_SIDE1;

	case Spectral::MouseZone17:
		return ChromaSDK::Mouse::RZLED2_RIGHT_SIDE2;

	case Spectral::MouseZone18:
		return ChromaSDK::Mouse::RZLED2_RIGHT_SIDE3;

	case Spectral::MouseZone19:
		return ChromaSDK::Mouse::RZLED2_RIGHT_SIDE4;

	case Spectral::MouseZone20:
		return ChromaSDK::Mouse::RZLED2_RIGHT_SIDE5;

	case Spectral::MouseZone21:
		return ChromaSDK::Mouse::RZLED2_RIGHT_SIDE6;

	case Spectral::MouseZone22:
		return ChromaSDK::Mouse::RZLED2_RIGHT_SIDE7;

	default:
		return CHROMASDK_MOUSE_RZLED2_INVALID;
	}
}

bool SpectralInitialize()
{
	if (SpectralInitialized)
	{
		return true;
	}

	SpectralLogitechEnabled = LogiLedInit();
	SpectralCorsairEnabled = (CorsairPerformProtocolHandshake().serverProtocolVersion > 0) && CorsairSetLayerPriority(128);

	if (SpectralCorsairEnabled)
	{
		for (UCHAR i = CLK_Escape; i <= CLI_Last; i++)
		{
			SpectralSavedCorsairLedColors[i - 1].ledId = (CorsairLedId)i;
		}

		CorsairGetLedsColors(CLI_Last, SpectralSavedCorsairLedColors);
	}

	SpectralRazerEnabled = (RazerImplementation.Initialize() == TRUE);

	SpectralInitialized = SpectralLogitechEnabled || SpectralCorsairEnabled || SpectralRazerEnabled;

	return SpectralInitialized;
}

bool SpectralIsInitialized()
{
	return SpectralInitialized;
}

bool SpectralLogitechIsEnabled()
{
	return SpectralLogitechEnabled;
}

bool SpectralCorsairIsEnabled()
{
	return SpectralCorsairEnabled;
}

bool SpectralRazerIsEnabled()
{
	return SpectralRazerEnabled;
}

bool SpectralSetColor(UCHAR red, UCHAR green, UCHAR blue)
{
	if (!SpectralInitialized)
	{
		SpectralInitialize();
	}

	if (SpectralInitialized)
	{
		bool success = true;

		if (SpectralLogitechEnabled)
		{
			auto redPercentage = SpectralGetColorPercentage(red);
			auto greenPercentage = SpectralGetColorPercentage(green);
			auto bluePercentage = SpectralGetColorPercentage(blue);

			success = LogiLedSetLighting(redPercentage, greenPercentage, bluePercentage) && success;
		}

		if (SpectralCorsairEnabled)
		{
			CorsairLedColor corsairLedColors[CLI_Last];

			for (UCHAR i = CLK_Escape; i <= CLI_Last; i++)
			{
				corsairLedColors[i - 1].ledId = (CorsairLedId)i;
				corsairLedColors[i - 1].r = red;
				corsairLedColors[i - 1].g = green;
				corsairLedColors[i - 1].b = blue;
			}

			success = CorsairSetLedsColors(CLI_Last, corsairLedColors) && success;
		}

		if (SpectralRazerEnabled)
		{
			success = false || success;
		}

		return success;
	}
	else
	{
		return false;
	}
}

bool SpectralSetColorForLed(UCHAR ledName, UCHAR red, UCHAR green, UCHAR blue)
{
	if (!SpectralInitialized)
	{
		SpectralInitialize();
	}

	if (SpectralInitialized)
	{
		bool success = false;

		if (SpectralLogitechEnabled)
		{
			auto redPercentage = SpectralGetColorPercentage(red);
			auto greenPercentage = SpectralGetColorPercentage(green);
			auto bluePercentage = SpectralGetColorPercentage(blue);

			if ((Spectral::LedName)ledName >= Spectral::KeyboardZone1 && (Spectral::LedName)ledName <= Spectral::KeyboardZone5)
			{
				success = LogiLedSetLightingForTargetZone(LogiLed::Keyboard, ledName - Spectral::KeyboardZone1 + LOGILED_KEYBOARDZONE_1, redPercentage, greenPercentage, bluePercentage) || success;
			}
			else if ((Spectral::LedName)ledName == Spectral::MouseZone1)
			{
				success = LogiLedSetLightingForTargetZone(LogiLed::Mouse, LOGILED_MOUSEZONE_1, redPercentage, greenPercentage, bluePercentage) || success;
				success = LogiLedSetLightingForTargetZone(LogiLed::Mouse, LOGILED_MOUSEZONE_2, redPercentage, greenPercentage, bluePercentage) || success;
			}
			else if ((Spectral::LedName)ledName == Spectral::HeadsetLeftZone)
			{
				success = LogiLedSetLightingForTargetZone(LogiLed::Headset, LOGILED_HEADSETZONE_LOGO, redPercentage, greenPercentage, bluePercentage) || success;
				success = LogiLedSetLightingForTargetZone(LogiLed::Headset, LOGILED_HEADSETZONE_BACK, redPercentage, greenPercentage, bluePercentage) || success;
			}
			else if ((Spectral::LedName)ledName == Spectral::MousepadZone1)
			{
				success = LogiLedSetLightingForTargetZone(LogiLed::Mousemat, LOGILED_MOUSEMATZONE_LOGO, redPercentage, greenPercentage, bluePercentage) || success;
			}
			else if ((Spectral::LedName)ledName == Spectral::SpeakerLeft)
			{
				success = LogiLedSetLightingForTargetZone(LogiLed::Speaker, LOGILED_SPEAKERZONE_FRONTLEFT, redPercentage, greenPercentage, bluePercentage) || success;
				success = LogiLedSetLightingForTargetZone(LogiLed::Speaker, LOGILED_SPEAKERZONE_REARLEFT, redPercentage, greenPercentage, bluePercentage) || success;
			}
			else if ((Spectral::LedName)ledName == Spectral::SpeakerRight)
			{
				success = LogiLedSetLightingForTargetZone(LogiLed::Speaker, LOGILED_SPEAKERZONE_FRONTRIGHT, redPercentage, greenPercentage, bluePercentage) || success;
				success = LogiLedSetLightingForTargetZone(LogiLed::Speaker, LOGILED_SPEAKERZONE_REARRIGHT, redPercentage, greenPercentage, bluePercentage) || success;
			}
			else
			{
				auto logiLedKeyName = SpectralGetLogiLedKeyName((Spectral::LedName)ledName);

				if (logiLedKeyName != LOGILED_KEYNAME_INVALID)
				{
					success = LogiLedSetLightingForKeyWithKeyName(logiLedKeyName, redPercentage, greenPercentage, bluePercentage) || success;
				}
			}
		}

		if (SpectralCorsairEnabled)
		{
			CorsairLedColor corsairLedColor;
			corsairLedColor.ledId = SpectralGetCorsairLedId((Spectral::LedName)ledName);
			corsairLedColor.r = red;
			corsairLedColor.g = green;
			corsairLedColor.b = blue;

			if (corsairLedColor.ledId != CLI_Invalid)
			{
				success = CorsairSetLedsColors(1, &corsairLedColor) || success;
			}
		}

		if (SpectralRazerEnabled)
		{
			if ((Spectral::LedName)ledName >= Spectral::Backspace && (Spectral::LedName)ledName <= Spectral::Fn)
			{
				if ((Spectral::LedName)ledName == Spectral::International1)
				{
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_EUR_1, red, green, blue) == TRUE) || success;
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_1, red, green, blue) == TRUE) || success;
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_1, red, green, blue) == TRUE) || success;
				}
				else if ((Spectral::LedName)ledName == Spectral::International2)
				{
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_EUR_2, red, green, blue) == TRUE) || success;
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_2, red, green, blue) == TRUE) || success;
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_2, red, green, blue) == TRUE) || success;
				}
				else if ((Spectral::LedName)ledName == Spectral::International3)
				{
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_3, red, green, blue) == TRUE) || success;
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_3, red, green, blue) == TRUE) || success;
				}
				else if ((Spectral::LedName)ledName == Spectral::International4)
				{
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_4, red, green, blue) == TRUE) || success;
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_4, red, green, blue) == TRUE) || success;
				}
				else if ((Spectral::LedName)ledName == Spectral::International5)
				{
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_5, red, green, blue) == TRUE) || success;
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_5, red, green, blue) == TRUE) || success;
				}
				else if ((Spectral::LedName)ledName == Spectral::International6)
				{
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_6, red, green, blue) == TRUE) || success;
				}
				else if ((Spectral::LedName)ledName == Spectral::International7)
				{
					success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_7, red, green, blue) == TRUE) || success;
				}
				else if ((Spectral::LedName)ledName == Spectral::Logo)
				{
					success = (RazerImplementation.SetColorForKeyboardLogo(red, green, blue) == TRUE) || success;
				}
				else
				{
					auto razerKey = SpectralGetRazerKey((Spectral::LedName)ledName);

					if (razerKey != ChromaSDK::Keyboard::RZKEY_INVALID)
					{
						success = (RazerImplementation.SetColorForKey(razerKey, red, green, blue) == TRUE) || success;
					}
				}
				
			}
			else if ((Spectral::LedName)ledName >= Spectral::MouseZone1 && (Spectral::LedName)ledName <= Spectral::MouseZone15)
			{
				auto razerMouseLedId = SpectralGetRazerMouseLedId((Spectral::LedName)ledName);

				if (razerMouseLedId != CHROMASDK_MOUSE_RZLED2_INVALID)
				{
					success = (RazerImplementation.SetColorForMouseLed(razerMouseLedId, red, green, blue) == TRUE) || success;
				}
			}
			else if ((Spectral::LedName)ledName >= Spectral::HeadsetLeftZone && (Spectral::LedName)ledName <= Spectral::HeadsetRightZone)
			{
				success = (RazerImplementation.SetColorForHeadsetZone((UCHAR)((Spectral::LedName)ledName - Spectral::HeadsetLeftZone), red, green, blue) == TRUE) || success;
			}
			else if ((Spectral::LedName)ledName >= Spectral::MousepadZone1 && (Spectral::LedName)ledName <= Spectral::MousepadZone15)
			{
				success = (RazerImplementation.SetColorForMousepadZone((UCHAR)((Spectral::LedName)ledName - Spectral::MousepadZone1), red, green, blue) == TRUE) || success;
			}
		}

		return success;
	}
	else
	{
		return false;
	}
}

bool SpectralSetColorForLeds(int count, UCHAR ledNames[], UCHAR red, UCHAR green, UCHAR blue)
{
	if (!SpectralInitialized)
	{
		SpectralInitialize();
	}

	if (SpectralInitialized)
	{
		bool success = false;

		UCHAR redPercentage, greenPercentage, bluePercentage;

		if (SpectralLogitechEnabled)
		{
			redPercentage = SpectralGetColorPercentage(red);
			greenPercentage = SpectralGetColorPercentage(green);
			bluePercentage = SpectralGetColorPercentage(blue);

			for (int i = 0; i < count; i++)
			{
				if ((Spectral::LedName)ledNames[i] >= Spectral::KeyboardZone1 && (Spectral::LedName)ledNames[i] <= Spectral::KeyboardZone5)
				{
					success = LogiLedSetLightingForTargetZone(LogiLed::Keyboard, ledNames[i] - Spectral::KeyboardZone1 + LOGILED_KEYBOARDZONE_1, redPercentage, greenPercentage, bluePercentage) || success;
				}
				else if ((Spectral::LedName)ledNames[i] == Spectral::MouseZone1)
				{
					success = LogiLedSetLightingForTargetZone(LogiLed::Mouse, LOGILED_MOUSEZONE_1, redPercentage, greenPercentage, bluePercentage) || success;
					success = LogiLedSetLightingForTargetZone(LogiLed::Mouse, LOGILED_MOUSEZONE_2, redPercentage, greenPercentage, bluePercentage) || success;
				}
				else if ((Spectral::LedName)ledNames[i] == Spectral::HeadsetLeftZone)
				{
					success = LogiLedSetLightingForTargetZone(LogiLed::Headset, LOGILED_HEADSETZONE_LOGO, redPercentage, greenPercentage, bluePercentage) || success;
					success = LogiLedSetLightingForTargetZone(LogiLed::Headset, LOGILED_HEADSETZONE_BACK, redPercentage, greenPercentage, bluePercentage) || success;
				}
				else if ((Spectral::LedName)ledNames[i] == Spectral::MousepadZone1)
				{
					success = LogiLedSetLightingForTargetZone(LogiLed::Mousemat, LOGILED_MOUSEMATZONE_LOGO, redPercentage, greenPercentage, bluePercentage) || success;
				}
				else if ((Spectral::LedName)ledNames[i] == Spectral::SpeakerLeft)
				{
					success = LogiLedSetLightingForTargetZone(LogiLed::Speaker, LOGILED_SPEAKERZONE_FRONTLEFT, redPercentage, greenPercentage, bluePercentage) || success;
					success = LogiLedSetLightingForTargetZone(LogiLed::Speaker, LOGILED_SPEAKERZONE_REARLEFT, redPercentage, greenPercentage, bluePercentage) || success;
				}
				else if ((Spectral::LedName)ledNames[i] == Spectral::SpeakerRight)
				{
					success = LogiLedSetLightingForTargetZone(LogiLed::Speaker, LOGILED_SPEAKERZONE_FRONTRIGHT, redPercentage, greenPercentage, bluePercentage) || success;
					success = LogiLedSetLightingForTargetZone(LogiLed::Speaker, LOGILED_SPEAKERZONE_REARRIGHT, redPercentage, greenPercentage, bluePercentage) || success;
				}
				else
				{
					auto logiLedKeyName = SpectralGetLogiLedKeyName((Spectral::LedName)ledNames[i]);

					if (logiLedKeyName != LOGILED_KEYNAME_INVALID)
					{
						success = LogiLedSetLightingForKeyWithKeyName(logiLedKeyName, redPercentage, greenPercentage, bluePercentage) || success;
					}
				}
			}
		}

		if (SpectralCorsairEnabled)
		{
			std::vector<CorsairLedColor> corsairLedColors;

			for (int i = 0; i < count; i++)
			{
				auto corsairLedId = SpectralGetCorsairLedId((Spectral::LedName)ledNames[i]);

				if (corsairLedId != CLI_Invalid)
				{
					CorsairLedColor corsairLedColor;
					corsairLedColor.ledId = corsairLedId;
					corsairLedColor.r = red;
					corsairLedColor.g = green;
					corsairLedColor.b = blue;
					corsairLedColors.push_back(corsairLedColor);
				}
			}

			auto corsairLedColorsSize = (int)corsairLedColors.size();

			if (corsairLedColorsSize > 0)
			{
				success = CorsairSetLedsColors(corsairLedColorsSize, &corsairLedColors[0]) || success;
			}
		}

		if (SpectralRazerEnabled)
		{
			for (int i = 0; i < count; i++)
			{
				if ((Spectral::LedName)ledNames[i] >= Spectral::Backspace && (Spectral::LedName)ledNames[i] <= Spectral::Fn)
				{
					if ((Spectral::LedName)ledNames[i] == Spectral::International1)
					{
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_EUR_1, red, green, blue) == TRUE) || success;
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_1, red, green, blue) == TRUE) || success;
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_1, red, green, blue) == TRUE) || success;
					}
					else if ((Spectral::LedName)ledNames[i] == Spectral::International2)
					{
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_EUR_2, red, green, blue) == TRUE) || success;
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_2, red, green, blue) == TRUE) || success;
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_2, red, green, blue) == TRUE) || success;
					}
					else if ((Spectral::LedName)ledNames[i] == Spectral::International3)
					{
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_3, red, green, blue) == TRUE) || success;
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_3, red, green, blue) == TRUE) || success;
					}
					else if ((Spectral::LedName)ledNames[i] == Spectral::International4)
					{
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_4, red, green, blue) == TRUE) || success;
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_4, red, green, blue) == TRUE) || success;
					}
					else if ((Spectral::LedName)ledNames[i] == Spectral::International5)
					{
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_JPN_5, red, green, blue) == TRUE) || success;
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_5, red, green, blue) == TRUE) || success;
					}
					else if ((Spectral::LedName)ledNames[i] == Spectral::International6)
					{
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_6, red, green, blue) == TRUE) || success;
					}
					else if ((Spectral::LedName)ledNames[i] == Spectral::International7)
					{
						success = (RazerImplementation.SetColorForKey(ChromaSDK::Keyboard::RZKEY_KOR_7, red, green, blue) == TRUE) || success;
					}
					else if ((Spectral::LedName)ledNames[i] == Spectral::Logo)
					{
						success = (RazerImplementation.SetColorForKeyboardLogo(red, green, blue) == TRUE) || success;
					}
					else
					{
						auto razerKey = SpectralGetRazerKey((Spectral::LedName)ledNames[i]);

						if (razerKey != ChromaSDK::Keyboard::RZKEY_INVALID)
						{
							success = (RazerImplementation.SetColorForKey(razerKey, red, green, blue) == TRUE) || success;
						}
					}
				}
				else if ((Spectral::LedName)ledNames[i] >= Spectral::MouseZone1 && (Spectral::LedName)ledNames[i] <= Spectral::MouseZone15)
				{
					auto razerMouseLedId = SpectralGetRazerMouseLedId((Spectral::LedName)ledNames[i]);

					if (razerMouseLedId != CHROMASDK_MOUSE_RZLED2_INVALID)
					{
						success = (RazerImplementation.SetColorForMouseLed(razerMouseLedId, red, green, blue) == TRUE) || success;
					}
				}
				else if ((Spectral::LedName)ledNames[i] >= Spectral::HeadsetLeftZone && (Spectral::LedName)ledNames[i] <= Spectral::HeadsetRightZone)
				{
					success = (RazerImplementation.SetColorForHeadsetZone((UCHAR)((Spectral::LedName)ledNames[i] - Spectral::HeadsetLeftZone), red, green, blue) == TRUE) || success;
				}
				else if ((Spectral::LedName)ledNames[i] >= Spectral::MousepadZone1 && (Spectral::LedName)ledNames[i] <= Spectral::MousepadZone15)
				{
					success = (RazerImplementation.SetColorForMousepadZone((UCHAR)((Spectral::LedName)ledNames[i] - Spectral::MousepadZone1), red, green, blue) == TRUE) || success;
				}
			}
		}

		return success;
	}
	else
	{
		return false;
	}
}

bool SpectralSetColorForDevice(UCHAR deviceType, UCHAR red, UCHAR green, UCHAR blue)
{
	std::vector<UCHAR> ledNames;

	bool success = false;

	switch ((Spectral::DeviceType)deviceType)
	{
	case Spectral::Keyboard:
		for (UCHAR i = Spectral::Backspace; i <= Spectral::KeyboardZone19; i++)
		{
			ledNames.push_back(i);
		}

		break;

	case Spectral::Mouse:
		for (UCHAR i = Spectral::MouseZone1; i <= Spectral::MouseZone22; i++)
		{
			ledNames.push_back(i);
		}

		break;

	case Spectral::Headset:
		for (UCHAR i = Spectral::HeadsetLeftZone; i <= Spectral::HeadsetRightZone; i++)
		{
			ledNames.push_back(i);
		}

		break;

	case Spectral::Mousepad:
		for (UCHAR i = Spectral::MousepadZone1; i <= Spectral::MousepadZone15; i++)
		{
			ledNames.push_back(i);
		}

		break;

	case Spectral::HeadsetStand:
		for (UCHAR i = Spectral::HeadsetStandZone1; i <= Spectral::HeadsetStandZone9; i++)
		{
			ledNames.push_back(i);
		}

		break;

	case Spectral::Speaker:
		for (UCHAR i = Spectral::SpeakerLeft; i <= Spectral::SpeakerRight; i++)
		{
			ledNames.push_back(i);
		}

		break;
	}

	auto ledCount = (int)ledNames.size();

	if (ledCount > 0)
	{
		return SpectralSetColorForLeds(ledCount, &ledNames[0], red, green, blue);
	}
	else
	{
		return false;
	}
	
}

void SpectralShutdown()
{
	if (SpectralLogitechEnabled)
	{
		LogiLedShutdown();
	}

	if (SpectralCorsairEnabled)
	{
		CorsairSetLayerPriority(0);
		CorsairSetLedsColors(CLI_Last, SpectralSavedCorsairLedColors);
	}

	if (SpectralRazerEnabled)
	{
		RazerImplementation.Shutdown();
	}
	
	SpectralLogitechEnabled = false;
	SpectralCorsairEnabled = false;
	SpectralRazerEnabled = false;

	SpectralInitialized = false;
}