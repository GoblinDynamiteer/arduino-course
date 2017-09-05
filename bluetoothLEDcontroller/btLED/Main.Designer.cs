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
            this.textBoxSerialData.Size = new System.Drawing.Size(139, 160);
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
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(409, 232);
            this.Controls.Add(this.btnRefreshPortList);
            this.Controls.Add(this.textBoxSerialData);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBoxPortList);
            this.Name = "frmMain";
            this.Text = "Arduino BT RGB-LED Controller";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort btSerialPort;
        private System.Windows.Forms.ComboBox comboBoxPortList;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxSerialData;
        private System.Windows.Forms.Button btnRefreshPortList;
    }
}

