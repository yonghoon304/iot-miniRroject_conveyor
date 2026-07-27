// 서보모터
#include <Servo.h>
#define SERVO_PIN 9  // Digital 9
Servo servo;

void setup() {
  Serial.begin(19200);
  servo.attach(SERVO_PIN);  // 서보모터 연결
  servo.write(0);  // 0도로 초기화(!)
  delay(500);
}

void loop() {
  if (Serial.available()) {
    int value = Serial.parseInt();
    servo.write(value);
    Serial.println(value);
    delay(100);
  }
}
