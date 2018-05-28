namespace SpectralTest
{
    partial class FormSpectralTest
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.colorDialog = new System.Windows.Forms.ColorDialog();
            this.buttonSetColor = new System.Windows.Forms.Button();
            this.labelStatus = new System.Windows.Forms.Label();
            this.comboLedName = new System.Windows.Forms.ComboBox();
            this.buttonSetColorDevice = new System.Windows.Forms.Button();
            this.comboDeviceType = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // colorDialog
            // 
            this.colorDialog.AnyColor = true;
            this.colorDialog.FullOpen = true;
            // 
            // buttonSetColor
            // 
            this.buttonSetColor.Location = new System.Drawing.Point(210, 229);
            this.buttonSetColor.Name = "buttonSetColor";
            this.buttonSetColor.Size = new System.Drawing.Size(192, 23);
            this.buttonSetColor.TabIndex = 0;
            this.buttonSetColor.Text = "Set Color for ";
            this.buttonSetColor.UseVisualStyleBackColor = true;
            this.buttonSetColor.Click += new System.EventHandler(this.buttonSetColor_Click);
            // 
            // labelStatus
            // 
            this.labelStatus.AutoSize = true;
            this.labelStatus.Location = new System.Drawing.Point(12, 9);
            this.labelStatus.Name = "labelStatus";
            this.labelStatus.Size = new System.Drawing.Size(0, 13);
            this.labelStatus.TabIndex = 2;
            // 
            // comboLedName
            // 
            this.comboLedName.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboLedName.FormattingEnabled = true;
            this.comboLedName.Location = new System.Drawing.Point(12, 231);
            this.comboLedName.Name = "comboLedName";
            this.comboLedName.Size = new System.Drawing.Size(192, 21);
            this.comboLedName.TabIndex = 5;
            this.comboLedName.SelectedIndexChanged += new System.EventHandler(this.comboLedName_SelectedIndexChanged);
            // 
            // buttonSetColorDevice
            // 
            this.buttonSetColorDevice.Location = new System.Drawing.Point(210, 200);
            this.buttonSetColorDevice.Name = "buttonSetColorDevice";
            this.buttonSetColorDevice.Size = new System.Drawing.Size(192, 23);
            this.buttonSetColorDevice.TabIndex = 6;
            this.buttonSetColorDevice.Text = "Set Color for";
            this.buttonSetColorDevice.UseVisualStyleBackColor = true;
            this.buttonSetColorDevice.Click += new System.EventHandler(this.buttonSetColorDevice_Click);
            // 
            // comboDeviceType
            // 
            this.comboDeviceType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboDeviceType.FormattingEnabled = true;
            this.comboDeviceType.Location = new System.Drawing.Point(12, 200);
            this.comboDeviceType.Name = "comboDeviceType";
            this.comboDeviceType.Size = new System.Drawing.Size(192, 21);
            this.comboDeviceType.TabIndex = 7;
            this.comboDeviceType.SelectedIndexChanged += new System.EventHandler(this.comboDeviceType_SelectedIndexChanged);
            // 
            // FormSpectralTest
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(414, 264);
            this.Controls.Add(this.comboDeviceType);
            this.Controls.Add(this.buttonSetColorDevice);
            this.Controls.Add(this.comboLedName);
            this.Controls.Add(this.labelStatus);
            this.Controls.Add(this.buttonSetColor);
            this.Name = "FormSpectralTest";
            this.Text = "Spectral Test";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.FormSpectralTest_FormClosed);
            this.Load += new System.EventHandler(this.FormSpectralTest_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ColorDialog colorDialog;
        private System.Windows.Forms.Button buttonSetColor;
        private System.Windows.Forms.Label labelStatus;
        private System.Windows.Forms.ComboBox comboLedName;
        private System.Windows.Forms.Button buttonSetColorDevice;
        private System.Windows.Forms.ComboBox comboDeviceType;
    }
}

