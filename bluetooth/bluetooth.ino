/* COMMANDS
    RGB PWM
    R###X
    G###X
    B###X

    RGB OFF
    R0X
    G0X
    B0X

    STATUS
    SX
 */


/* PWM ports for RGB-LED */
#define LED_PIN_RED 3
#define LED_PIN_BLUE 6
#define LED_PIN_GREEN 5

/* Command buffer size / lenght */
#define SERIAL_BUFFER_SIZE 6

/* Commands */
const char COMMAND_END = 'X';
const char COMMAND_STATUS = 'S';
const char COMMAND_LED_RED = 'R';
const char COMMAND_LED_GREEN = 'G';
const char COMMAND_LED_BLUE = 'B';
const char COMMAND_LED_RESET = 'N';

byte led_red_pwm_last = 0;
byte led_green_pwm_last = 0;
byte led_blue_pwm_last = 0;

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
    byte pwm = 0;

    /* If command is not empty */
    if(data.length() > 0)
    {
        switch (data[0]) {
            case COMMAND_LED_RED:
                pwm = GetPWMfromCommand(data);
                led_red_pwm_last = pwm;
                ledPWM(LED_PIN_RED, pwm);
                Serial.println("Setting RED to: " + pwm);
                break;

            case COMMAND_LED_BLUE:
                pwm = GetPWMfromCommand(data);
                led_blue_pwm_last = pwm;
                ledPWM(LED_PIN_BLUE, pwm);
                Serial.println("Setting BLUE to: " + pwm);
                break;

            case COMMAND_LED_GREEN:
                pwm = GetPWMfromCommand(data);
                led_green_pwm_last = pwm;
                ledPWM(LED_PIN_GREEN, pwm);
                Serial.println("Setting GREEN to: " + pwm);
                break;

            case COMMAND_LED_RESET:
                ledPWM(LED_PIN_GREEN, 0);
                ledPWM(LED_PIN_RED, 0);
                ledPWM(LED_PIN_BLUE, 0);
                Serial.println("LEDs Reset!");
                break;

            case COMMAND_STATUS:
                Serial.println("RED:   " + led_red_pwm_last);
                Serial.println("BLUE:  " + led_blue_pwm_last);
                Serial.println("GREEN: " + led_green_pwm_last);
                break;

            default:
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

    return String(command);
}

/* Get pwm value from command */
byte GetPWMfromCommand(String data)
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

    return (byte)pwm.toInt();
}
