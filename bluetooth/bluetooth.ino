/* COMMANDS

    R1X -- LED ON
    R0X -- LED OFF
 */


#define LED_PIN_RED 3
#define LED_PIN_BLUE 3
#define LED_PIN_GREEN 4

#define ON 1
#define OFF 0

#define SERIAL_BUFFER_SIZE 6

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
        led_pin = data[0] == COMMAND_LED_RED ? LED_PIN_RED : led_pin;
        led_pin = data[0] == COMMAND_LED_BLUE ? LED_PIN_BLUE : led_pin;
        led_pin = data[0] == COMMAND_LED_GREEN ? LED_PIN_GREEN : led_pin;

        Serial.println(data);

        if(data[1] == COMMAND_LED_OFF)
        {
            ledOff(led_pin);
        }

        else
        {
            
        }
    }

    delay(100);
}

/* Set LED on */
void ledOn(int pin, byte pwm_value)
{
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
