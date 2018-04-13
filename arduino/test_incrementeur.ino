/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
 #define outputA 6
 #define outputB 7
 int counter = 0; 
 int aState;
 int aLastState;  
 int analogPin = 3;
 int val = 0;
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);
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
    Serial.print("Poids ");
    }
    else if(counter > 12 && counter < 18){
      Serial.print("temp ");
   }
   else if(counter > 18){
      Serial.print("Parametres");
      
   }  
   
   aLastState = aState; // Updates the previous state of the outputA with the current state; 
 }
    val = analogRead(analogPin); 
     if (val > 450 && val < 650){
  Serial.print("lol");}
 }


