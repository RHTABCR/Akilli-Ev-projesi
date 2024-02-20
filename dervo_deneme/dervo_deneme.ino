#include <Servo.h>

Servo servo;
int button_pin = 2;
int servo_pin = 3;

volatile int state = LOW;

void setup() {
 pinMode(button_pin, INPUT_PULLUP);
 pinMode(servo_pin, OUTPUT);

 servo.attach(servo_pin);
 servo.write(0);

 attachInterrupt(digitalPinToInterrupt(button_pin), button_pressed, FALLING);
}

void loop() {
 // Yeni değişiklik yapmak zorunda kalmadık, interrupt servosu yönetiyor.
}

void button_pressed() {
 for (int i = 0; i < 1000; i++) {
    servo.write(180);
    delay(500);

    servo.write(0);
    delay(5000);
 }
}
