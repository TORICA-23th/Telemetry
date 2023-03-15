#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire);

char TWE_BUF[256];

#define rate_SW 2
#define zero_SW 3

float offset_pitch = 0;
float offset_roll = 0;

uint32_t time_ms = 0;
uint32_t period = 1000;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rate_SW, INPUT_PULLUP);
  pinMode(zero_SW, INPUT_PULLUP);

  Wire.setClock(400000);
  if (!bno.begin()) {
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
    }
  }
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  float pitch = euler.y();
  float roll = euler.z();

  if (pitch > 180) {
    pitch -= 360;
  }
  if (roll > 180) {
    roll -= 360;
  }
  pitch = -pitch;

  pitch -= offset_pitch;
  roll -= offset_roll;

  if (period < 1000) {
    sprintf(TWE_BUF, "%+06.2f,%+06.2f\n", pitch, roll);
    Serial1.print(TWE_BUF);
  } else {
    Serial1.print("+roll means left wing up\n");
    delay(10);
    Serial1.print("pitch[deg] roll[deg] IAS[m/s]\n");
    delay(10);
    sprintf(TWE_BUF, "%+06.2f     %+06.2f    %.2f\n", pitch, roll, 0.0 );
    Serial1.print(TWE_BUF);
    Serial1.print("\n");
    delay(10);
    Serial1.print("\n");
    delay(10);    
  }


  digitalWrite(LED_BUILTIN, HIGH);
  while (millis() - time_ms < period) {
    if (digitalRead(rate_SW)) {
      period = 1000;
    } else {
      period = 100;
    }
    if (digitalRead(zero_SW) == LOW) {
      set_offset();
    }
  }
  time_ms = millis();
  digitalWrite(LED_BUILTIN, LOW);
}

void set_offset() {
  double _offset_pitch = 0;
  double _offset_roll = 0;

  for (int i = 0; i < 3; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial1.print("offset setting...\n");
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }

  for (int i = 0; i < 10; i++)
  {
    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    float pitch = euler.y();
    float roll = euler.z();

    if (pitch > 180) {
      pitch -= 360;
    }
    if (roll > 180) {
      roll -= 360;
    }
    pitch = -pitch;

    _offset_pitch += pitch;
    _offset_roll += roll;
    digitalWrite(LED_BUILTIN, HIGH);
    Serial1.print("offset setting...\n");
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }
  offset_pitch = _offset_pitch / 10;
  offset_roll = _offset_roll / 10;
}
