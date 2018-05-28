// Copyright 2018 Jonathan Potts. All rights reserved.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Spectral;

namespace SpectralTest
{
    public partial class FormSpectralTest : Form
    {
        DeviceType selectedDevice = DeviceType.Keyboard;
        LedName selectedLed = LedName.Backspace;

        public FormSpectralTest()
        {
            InitializeComponent();
        }

        private void FormSpectralTest_FormClosed(object sender, FormClosedEventArgs e)
        {
            Led.Shutdown();
        }

        private void FormSpectralTest_Load(object sender, EventArgs e)
        {
            comboDeviceType.DataSource = Enum.GetValues(typeof(DeviceType));
            comboLedName.DataSource = Enum.GetValues(typeof(LedName));

            Led.Initialize();

            string status = "";
            status += $"Logitech is enabled: {Led.LogitechIsEnabled().ToString()}\n";
            status += $"Corsair is enabled: {Led.CorsairIsEnabled().ToString()}\n";
            status += $"Razer is enabled: {Led.RazerIsEnabled().ToString()}\n";

            labelStatus.Text = status;

            Led.SetColor(Color.Black);
            Led.SetColorForLeds(new List<LedName> { LedName.W, LedName.A, LedName.S, LedName.D }, Color.OrangeRed);
            Led.SetColorForLeds(new List<LedName> { LedName.LeftShift, LedName.E, LedName.Q }, Color.Green);
            Led.SetColorForLeds(new List<LedName> { LedName.One, LedName.Two, LedName.Three, LedName.Four }, Color.Blue);
            Led.SetColorForLed(LedName.R, Color.Red);
            Led.SetColorForLed(LedName.F, Color.Purple);
            Led.SetColorForLed(LedName.Spacebar, Color.White);
            Led.SetColorForLed(LedName.MouseZone1, Color.ForestGreen);
            Led.SetColorForLed(LedName.HeadsetLeftZone, Color.SeaGreen);
            Led.SetColorForLed(LedName.MousepadZone1, Color.PaleVioletRed);
            Led.SetColorForLed(LedName.SpeakerLeft, Color.MediumOrchid);
        }

        private void buttonSetColor_Click(object sender, EventArgs e)
        {
            colorDialog.ShowDialog();

            if (!Led.SetColorForLed(selectedLed, colorDialog.Color))
            {
                MessageBox.Show($"There was an issue setting the color for {selectedLed.ToString()}.");
            }
        }

        private void comboLedName_SelectedIndexChanged(object sender, EventArgs e)
        {
            selectedLed = (LedName)comboLedName.SelectedItem;

            buttonSetColor.Text = $"Set Color for {selectedLed.ToString()}";
        }

        private void buttonSetColorDevice_Click(object sender, EventArgs e)
        {
            colorDialog.ShowDialog();

            if (!Led.SetColorForDevice(selectedDevice, colorDialog.Color))
            {
                MessageBox.Show($"There was an issue setting the color for {selectedDevice.ToString()}.");
            }
        }

        private void comboDeviceType_SelectedIndexChanged(object sender, EventArgs e)
        {
            selectedDevice = (DeviceType)comboDeviceType.SelectedItem;

            buttonSetColorDevice.Text = $"Set Color for {selectedDevice.ToString()}";
        }
    }
}
