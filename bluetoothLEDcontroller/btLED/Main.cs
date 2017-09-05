using System.Windows.Forms;
using System.IO.Ports;
using System;

namespace btLED
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
            UpdateCOMportList();

            btSerialPort.Open();
        }

        void UpdateCOMportList()
        {
            string[] ports = SerialPort.GetPortNames();

            comboBoxPortList.Items.Clear();
            comboBoxPortList.Items.AddRange(ports);

        }

        /* Data recieved from COM-port */
        private string data;
        private void btSerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            data = btSerialPort.ReadExisting();
            this.Invoke(new EventHandler(DisplayText));
        }

        private void DisplayText(object o, EventArgs e)
        {
            /* Display data in textbox */
            textBoxSerialData.AppendText(data);
        }

        private void comboBoxPortList_SelectedIndexChanged(object sender, EventArgs e)
        {
            string port = comboBoxPortList.SelectedText;

            if (btSerialPort.PortName != port && port != "")
            {
                btSerialPort.Close();
                btSerialPort.PortName = port;
                btSerialPort.Open();
            }
            
            
        }

        private void btnRefreshPortList_Click(object sender, EventArgs e)
        {
            UpdateCOMportList();
        }
    }

}
