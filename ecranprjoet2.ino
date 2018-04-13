#include <LiquidCrystal.h>
#include "HX711.h"

#define outputA 6
#define outputB 7
 int counter = 0; 
 int aState;
 int aLastState;
 int analogPin = 3;
 int val = 0; 
#define DOUT  10
#define CLK  13
HX711 scale(DOUT, CLK);
float calibration_factor = 2140;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);
    
Serial.begin (9600);
  lcd.begin(16, 2);
  lcd.print("Alphacycle©:Life");
  lcd.setCursor(0, 1);
  lcd.print("Démarrage en cours");
  lcd.clear();
for(int pinNumber = 2;pinNumber<5; pinNumber++){
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);

  
   scale.set_scale();
  scale.tare(); //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline readin
}
}
void loop() {
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
         if(counter > 6 && counter < 12){
          lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Poids ");
    }
    else if(counter > 12 && counter < 18){
      lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("temp ");
   }
   else if(counter > 18 && counter < 24){
     lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Parametres");
   }
   else if(counter > 24){
     lcd.clear();
    int counter = 0;
   }
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }
  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1);
  Serial.print(" g"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print(" calibration_factor: ");
  delay(1000);
  Serial.print(calibration_factor);
  Serial.println();
  lcd.setCursor(0, 1);
  lcd.clear();
  lcd.print(scale.get_units(), 1);
  lcd.print("g");


  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
      
  }
}



