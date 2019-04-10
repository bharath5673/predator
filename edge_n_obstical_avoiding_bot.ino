int trigPin = 6;
int echoPin = 7;
#define FS 2 // front sensor
#define BS 4 // back sensor 

int revright = 8;
int fwdright = 9;
#define ENR 10
#define ENL 11
int fwdleft = 12 ;
int revleft = 13;



//ForWarD motion of Right motor
int c = 0;

void setup() {
  //Serial.begin(9600);
  pinMode(revright, OUTPUT);
  pinMode(fwdleft, OUTPUT);
  pinMode(revleft, OUTPUT);
  pinMode(fwdright, OUTPUT);
  pinMode(ENR, INPUT);
  pinMode(ENL, INPUT);
  pinMode(FS, INPUT);
  pinMode(BS, INPUT);

  analogWrite(ENL, 100);
  analogWrite(ENR, 100);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  //Serial.print(distance);
  //Serial.println("CM");
  delay(10);


  if ((distance > 20))
  {
    digitalWrite(revright, HIGH);                              //       If you dont get proper movements of your robot,
    digitalWrite(fwdleft, LOW);                              //        then alter the pin numbers
    digitalWrite(revleft, HIGH);                              //
    digitalWrite(fwdright, LOW);
    delay(400);//
  }
   {
    digitalWrite(revright, LOW);                              //       If you dont get proper movements of your robot,
    digitalWrite(fwdleft, LOW);                              //        then alter the pin numbers
    digitalWrite(revleft, HIGH);                              //
    digitalWrite(fwdright, HIGH);
    delay(400);
  }


  if (digitalRead(FS) && digitalRead(BS))
    // Move Forward
  { digitalWrite(fwdleft, HIGH);
    digitalWrite(revleft, LOW);
    digitalWrite(fwdright, HIGH);
    digitalWrite(revright, LOW);
  }
  if (!(digitalRead(FS)) && digitalRead(BS))
    // Turn right
  { digitalWrite(fwdleft, LOW);
    digitalWrite(revleft, LOW);
    digitalWrite(fwdright, HIGH);
    digitalWrite(revright, HIGH);
  }
  if (digitalRead(FS) && !(digitalRead(BS)))
    // turn left
  { digitalWrite(fwdleft, HIGH);
    digitalWrite(revleft, HIGH);
    digitalWrite(fwdright, LOW);
    digitalWrite(revright, LOW);
  }
  if (!(digitalRead(FS)) && !(digitalRead(BS)))
    // stop
  { digitalWrite(fwdleft, LOW);
    digitalWrite(revleft, LOW);
    digitalWrite(fwdright, LOW);
    digitalWrite(revright, LOW);
  }

  if (distance < 20)
  {
    digitalWrite(revright, LOW);
    digitalWrite(fwdleft, HIGH);
    digitalWrite(revleft, LOW);                                 //HIGH
    digitalWrite(fwdright, HIGH);
  }


}