#include <Arduino.h>
#include <Servo.h>

#define PIN_POT_IN A0
#define PIN_SERVO_OUT 3

#define SERVO_MIN 20
#define SERVO_MAX 180

Servo servo;
//These are reversed to reverse pot direction.
#define POT_MAX 0
#define POT_MIN 1023

void setup() {
    pinMode(PIN_POT_IN, INPUT);
    pinMode(PIN_SERVO_OUT, OUTPUT);

    servo.attach(PIN_SERVO_OUT);
    Serial.begin(115200);
}

void loop() {
    int pot_val = analogRead(PIN_POT_IN);
    int servo_pos = map(pot_val, POT_MIN, POT_MAX, SERVO_MIN, SERVO_MAX);
    servo.write(servo_pos);

    Serial.println(pot_val);
    delay(10);
}