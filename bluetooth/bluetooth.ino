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

/* Command buffer size / lenght */
#define SERIAL_BUFFER_SIZE 6

/* Commands */
const char COMMAND_END = 'X';
const char COMMAND_LED_RED = 'R';
const char COMMAND_LED_GREEN = 'G';
const char COMMAND_LED_BLUE = 'B';

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

        if(led_pin)
        {
            String pwm = ""; // For int conversion

            for(int i = 1; i < data.length(); i++)
            {
                /* Break when char is non-digit */
                if(!isDigit(data[i]))
                {
                    break;
                }

                pwm += data[i]; // Concatenate numbers to string
            }

            Serial.println(
                "Setting " +  String(data[0]) + "-LED to PWM: " + pwm);

            /* Use toInt to convert to int, cast as byte */
            ledPWM(led_pin, (byte)pwm.toInt());
        }

        else // led_pin not set by command
        {
            Serial.println("Invalid command!");
        }

    }

    delay(50);
}

/* Set LED PWM value */
void ledPWM(int pin, byte pwm_value)
{
    /* Limit PWM value (not needed as byte is max 255?) */
    pwm_value = pwm_value > 255 ? 255 : pwm_value;

    analogWrite(pin, pwm_value);
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
