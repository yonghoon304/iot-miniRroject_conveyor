// 라이브러리 
#include <Adafruit_NeoPixel.h>  // LED 모듈 라이브러리
#include <Adafruit_TCS34725.h>  // 컬러 센서 라이브러리
#include <Servo.h>              // 서보모터 라이브러리 불러오기
#include <Wire.h>               // I2C 통신에 사용되는 라이브러리

// 상수 선언부
#define PIN_DC_DIRECTION 13  // DC모터(레일) 방향을 정하는 핀(현재 B모터 사용)
#define PIN_DC_SPEED 11      // DC모터(레일) 속도를 정하는 핀(현재 B모터 사용)
#define PIN_SERVO 9          // 서보모터 연결 핀
#define PIN_LED 5            // LED 연결 핀
#define PIN_IR A0            // 적외선 IR센서 연결 핀

#define POS_RED 35   // 빨간 색 제품을 분류할 서보모터의 각도
#define POS_GREEN 57  // 초록 색 제품을 분류할 서보모터의 각도
#define POS_BLUE 2    // 파란 색 제품을 분류할 서보모터의 각도
#define NUM_PIXELS 3  // 네오픽셀의 픽셀 수: 3

//변수 선언부
Servo servo;
Adafruit_TCS34725 TCS = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
Adafruit_NeoPixel pixels(NUM_PIXELS, PIN_LED, NEO_GRB + NEO_KHZ800);

uint16_t clear, red, green, blue;  // 색상 값을 저장할 unsigned short int형 변수 선언
int r, g, b, sum;                  // 색상 값을 사용하기 위한 변환값
int railSpeed = 120;               // 레일 기본 속도, 초기값은 160

void setup() {
  // 모터설정
  pinMode(PIN_DC_DIRECTION,OUTPUT); // DC모터 방향핀 OUTPUT으로 설정
  digitalWrite(PIN_DC_DIRECTION,HIGH);  // 방향 정방향
  analogWrite(PIN_DC_SPEED,railSpeed); // 레일 동작

  servo.attach(PIN_SERVO);  // 서보모터 연결
  servo.write(2);  // 초기 각도 재설정
  delay(500);
  servo.detach(); // 서보모터 연결분리
  

}

void loop() {
 
}
