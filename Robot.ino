/*
   Данный скетч предназначен для Arduino Nano
   Робот
   @author Ilya
*/

const int FRONT_LEFT_IN1 = 11;  // вывод pin 11 соединен с выводом переднего левого IN1
const int FRONT_LEFT_IN2 = 10;  // вывод pin 10 соединен с выводом переднего левого IN2
const int REAR_LEFT_IN1 = 3;    // вывод pin 3 соединен с выводом заднего левого IN1
const int REAR_LEFT_IN2 = 2;    // вывод pin 2 соединен с выводом заднего левого IN2

const int FRONT_RIGHT_IN1 = A2; // вывод pin A2 соединен с выводом переднего правого IN1
const int FRONT_RIGHT_IN2 = A3; // вывод pin A3 соединен с выводом переднего правого IN2
const int REAR_RIGHT_IN1 = A4;  // вывод pin A4 соединен с выводом заднего правого IN1
const int REAR_RIGHT_IN2 = A5;  // вывод pin A5 соединен с выводом заднего правого IN2

boolean highSpeed = HIGH; // скорость HIGH 
boolean lowSpeed = LOW;   // скорость LOW

void setup() {
  pinMode(FRONT_LEFT_IN1, OUTPUT);
  pinMode(FRONT_LEFT_IN2, OUTPUT);
  pinMode(REAR_LEFT_IN1, OUTPUT);
  pinMode(REAR_LEFT_IN2, OUTPUT);
  pinMode(FRONT_RIGHT_IN1, OUTPUT);
  pinMode(FRONT_RIGHT_IN2, OUTPUT);
  pinMode(REAR_RIGHT_IN1, OUTPUT);
  pinMode(REAR_RIGHT_IN2, OUTPUT);

  // Открывается связь по bluetooth
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    switch (Serial.read()) {
      stopMotors();
      case '1':
        forward(); 
        break;
      case '2':
        backward();
        break;  
      case '3':
        left();
        break;
      case '4':
        right();
        break;
      case '0':
        stopMotors();
        break; 
    }
  }
}

void forward() {
  digitalWrite(FRONT_LEFT_IN1, highSpeed);
  digitalWrite(FRONT_LEFT_IN2, lowSpeed);
  digitalWrite(REAR_LEFT_IN1, highSpeed);
  digitalWrite(REAR_LEFT_IN2, lowSpeed);

  digitalWrite(FRONT_RIGHT_IN1, highSpeed);
  digitalWrite(FRONT_RIGHT_IN2, lowSpeed);
  digitalWrite(REAR_RIGHT_IN1, highSpeed);
  digitalWrite(REAR_RIGHT_IN2, lowSpeed);
}

void backward() {
  digitalWrite(FRONT_LEFT_IN1, lowSpeed);
  digitalWrite(FRONT_LEFT_IN2, highSpeed);
  digitalWrite(REAR_LEFT_IN1, lowSpeed);
  digitalWrite(REAR_LEFT_IN2, highSpeed);

  digitalWrite(FRONT_RIGHT_IN1, lowSpeed);
  digitalWrite(FRONT_RIGHT_IN2, highSpeed);
  digitalWrite(REAR_RIGHT_IN1, lowSpeed);
  digitalWrite(REAR_RIGHT_IN2, highSpeed);
}

void left() {
  digitalWrite(FRONT_LEFT_IN1, highSpeed);
  digitalWrite(FRONT_LEFT_IN2, lowSpeed);
  digitalWrite(REAR_LEFT_IN1, highSpeed);
  digitalWrite(REAR_LEFT_IN2, lowSpeed);

  digitalWrite(FRONT_RIGHT_IN1, lowSpeed);
  digitalWrite(FRONT_RIGHT_IN2, lowSpeed);
  digitalWrite(REAR_RIGHT_IN1, lowSpeed);
  digitalWrite(REAR_RIGHT_IN2, lowSpeed);
}

void right() {
  digitalWrite(FRONT_LEFT_IN1, lowSpeed);
  digitalWrite(FRONT_LEFT_IN2, lowSpeed);
  digitalWrite(REAR_LEFT_IN1, lowSpeed);
  digitalWrite(REAR_LEFT_IN2, lowSpeed);

  digitalWrite(FRONT_RIGHT_IN1, highSpeed);
  digitalWrite(FRONT_RIGHT_IN2, lowSpeed);
  digitalWrite(REAR_RIGHT_IN1, highSpeed);
  digitalWrite(REAR_RIGHT_IN2, lowSpeed);
}

void stopMotors() {
  digitalWrite(FRONT_LEFT_IN1, lowSpeed);
  digitalWrite(FRONT_LEFT_IN2, lowSpeed);
  digitalWrite(REAR_LEFT_IN1, lowSpeed);
  digitalWrite(REAR_LEFT_IN2, lowSpeed);

  digitalWrite(FRONT_RIGHT_IN1, lowSpeed);
  digitalWrite(FRONT_RIGHT_IN2, lowSpeed);
  digitalWrite(REAR_RIGHT_IN1, lowSpeed);
  digitalWrite(REAR_RIGHT_IN2, lowSpeed);
}
