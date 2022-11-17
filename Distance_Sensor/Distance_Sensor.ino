#include<NewPing.h>

int maxDistance = 24;
int currentDistance = 0;
int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int pin8 = 8;
NewPing sonar (pin2, pin3, maxDistance);

void setup() {
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  Serial.begin(9600);
  delay(50);
}

void loop() {
  Serial.print("The Distance is: ");
  currentDistance = sonar.ping_cm();
  Serial.println(currentDistance);
  if(currentDistance > 0){
    lightLEDs(currentDistance, pin8);
  }else{
    closeLEDs(pin8);
  }
  
  delay(100);
}

void lightLEDs(int distance, int currentPin){
  for(int i=0;i<5;i++){
    if(distance-4 >= 0){
      digitalWrite(currentPin--, LOW);
    }else{
      digitalWrite(currentPin--, HIGH);
    }
    distance -=4;
  }
}

void closeLEDs(int currentPin){
  for(int i = currentPin; i>0 ;i--){
    digitalWrite(currentPin--, LOW);
  }
}
