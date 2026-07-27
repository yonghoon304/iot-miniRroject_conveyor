// 적외선 IR 센서
int sensor = A0;
int val;

void setup() {
  Serial.begin(19200);
  pinMode(sensor, INPUT);
  Serial.println("Arduino start!");
}

void loop() {
  val = digitalRead(sensor);
  if (val == LOW) {
    Serial.println("Detected");
    delay(300);
  } else {
    Serial.println("0");
    delay(300);
  }

}

