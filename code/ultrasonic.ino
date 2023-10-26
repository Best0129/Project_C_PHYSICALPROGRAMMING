#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pos = 0; 
bool check = false;
const int ldrPin = 8;

void setup() {
  Serial.begin(9600);     
  pinMode(4, OUTPUT);   
  pinMode(2, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(10, OUTPUT); //LED
  myservo.attach(6);
  myservo.write(65);
}

void loop() {
  int ldrStatus = analogRead(ldrPin);
  Serial.print("LDR Sensor: "); 
  Serial.println(ldrStatus);
  if (ldrStatus > 200) {
    digitalWrite(10,   HIGH);
  }else{
    digitalWrite(10,   LOW);
  }
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  int pulseWidth = pulseIn(2, HIGH);    
  Serial.print("Pulse Width: ");    
  Serial.println(pulseWidth);    
  long distance = pulseWidth/29/2;    
  Serial.print("Distance: ");    
  Serial.println(distance);    
  if ((pulseWidth < 700) && (check == false)){
    for (pos = 65; pos <= 155; pos += 1) { 
    myservo.write(pos);
    delay(15);
    }
    check = true;
  }else if ((pulseWidth > 700) && (check == true)){
    for (pos = 155; pos >= 65; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                 
    }
    check = false;
  }
  delay(1000);
}