#define echoPin 12 
#define trigPin 13
#define MotorR1 7
#define MotorR2 6
#define MotorRE 9  
#define MotorL1 5
#define MotorL2 4
#define MotorLE 3

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);


long sure, uzaklik; 

void setup() {

  
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT); 
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);


  Serial.begin(9600);
  lcd.init();                      
  lcd.backlight();                 
  lcd.begin(16, 2);
 
}

void loop() {


  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 

  sure = pulseIn(echoPin, HIGH); 
  uzaklik = sure / 29.1 / 2; 

  Serial.println(uzaklik);

if(uzaklik<20){
  geri();
  delay(250);
  sol();
  delay(100);
  lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("RUN GOOD BOY RUN");
   lcd.setCursor(0, 1);
   lcd.print(uzaklik);
   lcd.setCursor(4, 1);
   lcd.print("CM LEFT");
    delay(1150);
   lcd.clear();


}
else{
  ileri();
  lcd.setCursor(0, 0);
  lcd.print("UTKU-KAAN");
  lcd.setCursor(0, 1);
  lcd.print("SERHAT-HASAN");
  
}

}

void ileri(){  

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 100); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 100); 
  
  
}


void sol(){ 

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 0); 
  
  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 80);
  
  
}


void geri(){ 

  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, HIGH);
  analogWrite(MotorRE, 100); 

  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLE, 100); 
  
}
