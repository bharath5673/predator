#include <AFMotor.h>
#include <Servo.h>              // Add library
Servo servo_pan;               // Define any servo name
Servo servo_tilt;


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int servo_position = 0 ;

int r1 = A0; //  frontlight
int g1 = A1; //  backlight
int b1 = A2; //  hornplease
int Speed = 120;

char bt = 'S';
void setup()
{
  servo_pan.attach (10);
  servo_tilt.attach (9);

  Serial.begin(9600);
  Serial.println("CAR READY");
  pinMode(r1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(g1, OUTPUT);

  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
  Stop();
}


void loop() {

  bt = Serial.read();

  if (bt == '0')
  {
    motor1.setSpeed(20);
    motor2.setSpeed(20);
    motor3.setSpeed(20);
    motor4.setSpeed(20);
  }

  if (bt == '1')
  {
    motor1.setSpeed(40);
    motor2.setSpeed(40);
    motor3.setSpeed(40);
    motor4.setSpeed(40);
  }

  if (bt == '2')
  {
    motor1.setSpeed(80);
    motor2.setSpeed(80);
    motor3.setSpeed(80);
    motor4.setSpeed(80);
  }

  if (bt == '3')
  {
    motor1.setSpeed(100);
    motor2.setSpeed(100);
    motor3.setSpeed(100);
    motor4.setSpeed(100);
  }


  if (bt == '4')
  {
    motor1.setSpeed(120);
    motor2.setSpeed(120);
    motor3.setSpeed(120);
    motor4.setSpeed(120);
  }

  if (bt == '5')
  {
    motor1.setSpeed(140);
    motor2.setSpeed(140);
    motor3.setSpeed(140);
    motor4.setSpeed(140);
  }

  if (bt == '6')
  {
    motor1.setSpeed(160);
    motor2.setSpeed(160);
    motor3.setSpeed(160);
    motor4.setSpeed(160);
  }


  if (bt == '7')
  {
    motor1.setSpeed(180);
    motor2.setSpeed(180);
    motor3.setSpeed(180);
    motor4.setSpeed(180);
  }


  if (bt == '8')
  {
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);
  }

  if (bt == '9')
  {
    motor1.setSpeed(225);
    motor2.setSpeed(225);
    motor3.setSpeed(225);
    motor4.setSpeed(225);
  }




  if (bt == '9')
  {
    Speed = 225;
  }


  if (bt == 'F')
  {
    forward();
  }

  if (bt == 'B')
  {
    backward();
  }

  if (bt == 'L')
  {
    left();
  }

  if (bt == 'R')
  {
    right();
  }

  if (bt == 'G')
  {
    frontleft();
  }

  if (bt == 'I')
  {
    frontright();
  }

  if (bt == 'H')
  {
    backleft();
  }

  if (bt == 'J')
  {
    backright();
  }


  if (bt == 'S')
  {
    Stop();
  }

  if (bt == 'W')
  { Serial.println("HEADLIGHTS ON");
    digitalWrite(r1, HIGH);
  }
  if (bt == 'w')
  { Serial.println("HEADLIGHTS OFF");
    digitalWrite(r1, LOW);
  }

  if (bt == 'U')
  { Serial.println("BACKLIGHTS ON");
    digitalWrite(g1, HIGH);
  }
  if (bt == 'u')
  { Serial.println("BACKLIGHTS OFF");
    digitalWrite(g1, LOW);
  }

  if (bt == 'V')
  { Serial.println("HORN ON");
    digitalWrite(b1, HIGH);
  }
  if (bt == 'v')
  { Serial.println("HORN OFF");
    digitalWrite(b1, LOW);
  }


  if (bt == 'X')
  {

    for (servo_position = 15; servo_position <= 120; servo_position += 1) {

      servo_pan.write(servo_position);
      delay(100);
    }

    for (servo_position = 90; servo_position >= 50; servo_position -= 1) {

      servo_pan.write(servo_position);
      delay(100);
    }
  }

  if (bt == 'x')
  {
    for (servo_position = 40; servo_position <= 180; servo_position += 1) {

      servo_tilt.write(servo_position);
      delay(100);
    }

    for (servo_position = 180; servo_position >= 25; servo_position -= 1 ) {

      servo_tilt.write(servo_position);
      delay(100);
    }
  }
}
void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void right()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void left()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void frontright()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void frontleft()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backright()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void backleft()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

