// Copyright 2018 Jonathan Potts. All rights reserved.

namespace Spectral
{
    /// <summary>Enumeration of Device Types.</summary>
    public enum DeviceType : byte
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
    }
}
