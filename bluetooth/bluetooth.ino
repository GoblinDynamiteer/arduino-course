/* COMMANDS
    RGB PWM
    R###X
    G###X
    B###X

    RGB OFF
    R0X
    G0X
    B0X
 */


/* PWM ports for RGB-LED */
#define LED_PIN_RED 3
#define LED_PIN_BLUE 6
#define LED_PIN_GREEN 5

#define ON 1
#define OFF 0

/* Command buffer size / lenght */
#define SERIAL_BUFFER_SIZE 6

/* Commands */
const char COMMAND_END = 'X';
const char COMMAND_LED_RED = 'R';
const char COMMAND_LED_GREEN = 'G';
const char COMMAND_LED_BLUE = 'B';
const char COMMAND_LED_ON = '1';
const char COMMAND_LED_OFF = '0';

void setup()
{
    /* Set LED pins to output */
    pinMode(LED_PIN_RED, OUTPUT);
    pinMode(LED_PIN_GREEN, OUTPUT);
    pinMode(LED_PIN_BLUE, OUTPUT);

    Serial.begin(9600);
    Serial.setTimeout(1000);
}

void loop()
{
    /* Get command from bluetooth serial */
    String data = readSerial();

    /* If command is not empty */
    if(data.length() > 0)
    {
        int led_pin = 0;
        led_pin = data[0] == COMMAND_LED_RED    ? LED_PIN_RED   : led_pin;
        led_pin = data[0] == COMMAND_LED_BLUE   ? LED_PIN_BLUE  : led_pin;
        led_pin = data[0] == COMMAND_LED_GREEN  ? LED_PIN_GREEN : led_pin;

        if(data[1] == COMMAND_LED_OFF)
        {
            ledOff(led_pin);
        }

        else
        {
            String pwm = "";

            for(int i = 1; i < data.length(); i++)
            {
                if(!isDigit(data[i]))
                {
                    break;
                }

                pwm += data[i];
            }

            Serial.println("Setting " +  String(data[0]) + "LED to PWM: " + pwm);
            ledOn(led_pin, (byte)pwm.toInt());
        }
    }

    delay(100);
}

/* Set LED on */
void ledOn(int pin, byte pwm_value)
{
    pwm_value = pwm_value > 255 ? 255 : pwm_value;
    analogWrite(pin, pwm_value);
}

/* Set LED off */
void ledOff(int pin)
{
    analogWrite(pin, OFF);
}

/* Read serial command (from bluetooth) */
String readSerial()
{
    char command[SERIAL_BUFFER_SIZE + 1];

    byte size = Serial.readBytesUntil(
        COMMAND_END,
        command,
        SERIAL_BUFFER_SIZE
    );

    command[size] = '\0';

    //String retval(command);

    return String(command);
}
