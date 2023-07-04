// For pico: RASPBERRY_PI_PICO
// For KB2040: ADAFRUIT_KB2040_RP2040
// Look under C:\Users\rohan\AppData\Local\Arduino15\packages\rp2040\hardware\rp2040\3.3.0\boards.txt
// Macro name is assigned to build.board

void setup()
{
    Serial.begin(9600);
}

void loop()
{
#if defined(ARDUINO_AVR_UNO)
    Serial.println("uno");
#define yea
#else
    Serial.println("IDK");
#endif
#if defined(yea)
    Serial.println("yea");
#endif
}