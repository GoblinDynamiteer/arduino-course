namespace btLED
{
    partial class frmMain
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
            this.components = new System.ComponentModel.Container();
            this.btSerialPort = new System.IO.Ports.SerialPort(this.components);
            this.comboBoxPortList = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxSerialData = new System.Windows.Forms.TextBox();
            this.btnRefreshPortList = new System.Windows.Forms.Button();
            this.scrollPwmRed = new System.Windows.Forms.HScrollBar();
            this.lblRed = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.scrollPwmGreen = new System.Windows.Forms.HScrollBar();
            this.scrollPwmBlue = new System.Windows.Forms.HScrollBar();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.lblPwmRed = new System.Windows.Forms.Label();
            this.lblPwmGreen = new System.Windows.Forms.Label();
            this.lblPwmBlue = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btSerialPort
            // 
            this.btSerialPort.PortName = "COM5";
            this.btSerialPort.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.btSerialPort_DataReceived);
            // 
            // comboBoxPortList
            // 
            this.comboBoxPortList.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxPortList.FormattingEnabled = true;
            this.comboBoxPortList.Location = new System.Drawing.Point(44, 6);
            this.comboBoxPortList.Name = "comboBoxPortList";
            this.comboBoxPortList.Size = new System.Drawing.Size(110, 21);
            this.comboBoxPortList.TabIndex = 0;
            this.comboBoxPortList.SelectedIndexChanged += new System.EventHandler(this.comboBoxPortList_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(26, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Port";
            // 
            // textBoxSerialData
            // 
            this.textBoxSerialData.Location = new System.Drawing.Point(15, 37);
            this.textBoxSerialData.Multiline = true;
            this.textBoxSerialData.Name = "textBoxSerialData";
            this.textBoxSerialData.Size = new System.Drawing.Size(303, 160);
            this.textBoxSerialData.TabIndex = 2;
            // 
            // btnRefreshPortList
            // 
            this.btnRefreshPortList.Location = new System.Drawing.Point(160, 4);
            this.btnRefreshPortList.Name = "btnRefreshPortList";
            this.btnRefreshPortList.Size = new System.Drawing.Size(75, 23);
            this.btnRefreshPortList.TabIndex = 3;
            this.btnRefreshPortList.Text = "Uppdatera";
            this.btnRefreshPortList.UseVisualStyleBackColor = true;
            this.btnRefreshPortList.Click += new System.EventHandler(this.btnRefreshPortList_Click);
            // 
            // scrollPwmRed
            // 
            this.scrollPwmRed.LargeChange = 1;
            this.scrollPwmRed.Location = new System.Drawing.Point(56, 42);
            this.scrollPwmRed.Maximum = 255;
            this.scrollPwmRed.Name = "scrollPwmRed";
            this.scrollPwmRed.Size = new System.Drawing.Size(181, 20);
            this.scrollPwmRed.TabIndex = 4;
            this.scrollPwmRed.ValueChanged += new System.EventHandler(this.scrollPwmRed_Scroll);
            // 
            // lblRed
            // 
            this.lblRed.AutoSize = true;
            this.lblRed.Location = new System.Drawing.Point(7, 47);
            this.lblRed.Name = "lblRed";
            this.lblRed.Size = new System.Drawing.Size(30, 13);
            this.lblRed.TabIndex = 5;
            this.lblRed.Text = "RED";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lblPwmBlue);
            this.groupBox1.Controls.Add(this.lblPwmGreen);
            this.groupBox1.Controls.Add(this.lblPwmRed);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.scrollPwmBlue);
            this.groupBox1.Controls.Add(this.scrollPwmGreen);
            this.groupBox1.Controls.Add(this.scrollPwmRed);
            this.groupBox1.Controls.Add(this.lblRed);
            this.groupBox1.Location = new System.Drawing.Point(15, 216);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(303, 146);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "RGB-Kontroll";
            // 
            // scrollPwmGreen
            // 
            this.scrollPwmGreen.LargeChange = 1;
            this.scrollPwmGreen.Location = new System.Drawing.Point(56, 73);
            this.scrollPwmGreen.Maximum = 255;
            this.scrollPwmGreen.Name = "scrollPwmGreen";
            this.scrollPwmGreen.Size = new System.Drawing.Size(181, 20);
            this.scrollPwmGreen.TabIndex = 6;
            this.scrollPwmGreen.ValueChanged += new System.EventHandler(this.scrollPwmGreen_Scroll);
            // 
            // scrollPwmBlue
            // 
            this.scrollPwmBlue.LargeChange = 1;
            this.scrollPwmBlue.Location = new System.Drawing.Point(56, 104);
            this.scrollPwmBlue.Maximum = 255;
            this.scrollPwmBlue.Name = "scrollPwmBlue";
            this.scrollPwmBlue.Size = new System.Drawing.Size(181, 20);
            this.scrollPwmBlue.TabIndex = 7;
            this.scrollPwmBlue.ValueChanged += new System.EventHandler(this.scrollPwmBlue_Scroll);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(7, 76);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(45, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "GREEN";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 105);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(35, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "BLUE";
            // 
            // lblPwmRed
            // 
            this.lblPwmRed.AutoSize = true;
            this.lblPwmRed.Location = new System.Drawing.Point(255, 47);
            this.lblPwmRed.Name = "lblPwmRed";
            this.lblPwmRed.Size = new System.Drawing.Size(34, 13);
            this.lblPwmRed.TabIndex = 10;
            this.lblPwmRed.Text = "PWM";
            // 
            // lblPwmGreen
            // 
            this.lblPwmGreen.AutoSize = true;
            this.lblPwmGreen.Location = new System.Drawing.Point(255, 76);
            this.lblPwmGreen.Name = "lblPwmGreen";
            this.lblPwmGreen.Size = new System.Drawing.Size(34, 13);
            this.lblPwmGreen.TabIndex = 11;
            this.lblPwmGreen.Text = "PWM";
            // 
            // lblPwmBlue
            // 
            this.lblPwmBlue.AutoSize = true;
            this.lblPwmBlue.Location = new System.Drawing.Point(255, 104);
            this.lblPwmBlue.Name = "lblPwmBlue";
            this.lblPwmBlue.Size = new System.Drawing.Size(34, 13);
            this.lblPwmBlue.TabIndex = 12;
            this.lblPwmBlue.Text = "PWM";
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(331, 384);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnRefreshPortList);
            this.Controls.Add(this.textBoxSerialData);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBoxPortList);
            this.Name = "frmMain";
            this.Text = "Arduino BT RGB-LED Controller";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort btSerialPort;
        private System.Windows.Forms.ComboBox comboBoxPortList;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxSerialData;
        private System.Windows.Forms.Button btnRefreshPortList;
        private System.Windows.Forms.HScrollBar scrollPwmRed;
        private System.Windows.Forms.Label lblRed;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.HScrollBar scrollPwmBlue;
        private System.Windows.Forms.HScrollBar scrollPwmGreen;
        private System.Windows.Forms.Label lblPwmRed;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lblPwmBlue;
        private System.Windows.Forms.Label lblPwmGreen;
    }
}

