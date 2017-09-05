using System.Windows.Forms;
using System.IO.Ports;
using System;

namespace btLED
{
    public partial class frmMain : Form
    {
        enum ledColor : int { Red, Blue, Green };

        public frmMain()
        {
            InitializeComponent();
            UpdateCOMportList();

            /* Set labels to zero */
            lblPwmBlue.Text = "0";
            lblPwmRed.Text = "0";
            lblPwmGreen.Text = "0";

            if (!btSerialPort.IsOpen)
            {
                btSerialPort.Open();
            }

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

        /* Display serial data and misc */
        private void DisplayText(object o, EventArgs e)
        {
            /* Display data in textbox */
            textBoxSerialData.AppendText(data);
        }

        /* Event for port select in drop-down */
        private void comboBoxPortList_SelectedIndexChanged(object sender, EventArgs e)
        {
            string port = comboBoxPortList.Text;

            btSerialPort.Close();

            btSerialPort.PortName = port == "" ? btSerialPort.PortName : port;

            if (!btSerialPort.IsOpen)
            {
                btSerialPort.Open();
            }

            textBoxSerialData.AppendText("Port set to " + port);
            
        }

        /* Event for refrsh-button */
        private void btnRefreshPortList_Click(object sender, EventArgs e)
        {
            UpdateCOMportList();
        }

        private void scrollPwmRed_Scroll(object sender, EventArgs e)
        {
            lblPwmRed.Text = scrollPwmRed.Value.ToString();
            setLedPWM(ledColor.Red, scrollPwmRed.Value);
        }

        private void scrollPwmGreen_Scroll(object sender, EventArgs e)
        {
            lblPwmGreen.Text = scrollPwmGreen.Value.ToString();
            setLedPWM(ledColor.Green, scrollPwmGreen.Value);
        }

        private void scrollPwmBlue_Scroll(object sender, EventArgs e)
        {
            lblPwmBlue.Text = scrollPwmBlue.Value.ToString();
            setLedPWM(ledColor.Blue, scrollPwmBlue.Value);
        }

        /* Set GRB LED PWM with Serial communication */
        private void setLedPWM(ledColor color, int pwm)
        {
            string commandColor = "";

            switch (color)
            {
                case ledColor.Red:
                    commandColor = "R";
                    break;

                case ledColor.Blue:
                    commandColor = "B";
                    break;

                case ledColor.Green:
                    commandColor = "G";
                    break;

                default:
                    break;
            }

            /* Limit PWM to 255 */
            pwm = pwm > 255 ? 255 : pwm;

            btSerialPort.Write(commandColor + pwm + "X");
        }
    }

}
