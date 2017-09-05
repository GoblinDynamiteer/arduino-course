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

            lblPwmBlue.Text = "0";
            lblPwmRed.Text = "0";
            lblPwmGreen.Text = "0";
        }

        /* Update drop-down list with available COM-ports */
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

        /* Event for port select in drop-down */
        private void comboBoxPortList_SelectedIndexChanged(object sender, EventArgs e)
        {
            string port = comboBoxPortList.SelectedText;

            btSerialPort.PortName = port;

            if (!btSerialPort.IsOpen)
            {
                btSerialPort.Open();
            }
            
        }

        /* Event for refrsh-button */
        private void btnRefreshPortList_Click(object sender, EventArgs e)
        {
            UpdateCOMportList();
        }

        private void scrollPwmRed_Scroll(object sender, EventArgs e)
        {
            lblPwmRed.Text = scrollPwmRed.Value.ToString();
            btSerialPort.Write("R" + scrollPwmRed.Value.ToString() + "X");
        }

        private void scrollPwmGreen_Scroll(object sender, EventArgs e)
        {
            lblPwmGreen.Text = scrollPwmGreen.Value.ToString();
            btSerialPort.Write("G" + scrollPwmRed.Value.ToString() + "X");
        }

        private void scrollPwmBlue_Scroll(object sender, EventArgs e)
        {
            lblPwmBlue.Text = scrollPwmBlue.Value.ToString();
            btSerialPort.Write("B" + scrollPwmRed.Value.ToString() + "X");
        }
    }

}
