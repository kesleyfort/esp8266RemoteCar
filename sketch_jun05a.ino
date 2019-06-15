#define BLYNK_PRINT Serial 
#define BLYNK_DEBUG
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 

// You should get Auth Token in the Blynk App. 
// Go to the Project Settings (nut icon). 
char auth[] = "1814ea23f9634367a50c937663269719"; 
// Your WiFi credentials. 
// Set password to "" for open networks. 
char ssid[] = "RedeDoKesley"; 
char pass[] = "adfd7139"; 
int PWMA=5;//Right side 
int PWMB=4;//Left side 
int DA=0;//Right reverse 
int DB=2;//Left reverse 
void setup(){ 
 // Debug console 
 Serial.begin(9600); 
 Blynk.begin(auth, ssid, pass,IPAddress(10,42,0,1),8080); 
 pinMode(PWMA, OUTPUT); 
 pinMode(PWMB, OUTPUT); 
 pinMode(DA, OUTPUT); 
 pinMode(DB, OUTPUT); 
} 
void loop(){ 
Blynk.run(); 
  
} 
// Handling Joystick data 
BLYNK_WRITE(V1){ 
int x = param[0].asInt(); 
int y = param[1].asInt();
Serial.write(x);
Serial.write(y);
if(x==-1 && y==-1){             //Backward and Left     
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, HIGH); 
}else if(x==-1 && y==0){        //Left Turn 
     digitalWrite(PWMA, 450); 
     digitalWrite(DA, HIGH); 
    
     digitalWrite(PWMB, 450); 
     digitalWrite(DB, LOW); 
}else if(x==-1 && y==1){        //Forward and Left     
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
    
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, LOW); 
}else if(x==0 && y==-1){        //Backward     
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, HIGH); 
     
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, HIGH);
}else if(x==0 && y==0){        //Stay 
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW); 
}else if(x==0 && y==1){        //Forward 
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, LOW); 
    
     digitalWrite(PWMB, HIGH);
     digitalWrite(DB, LOW); 
}else if(x==1 && y==-1){        //Backward and Right     
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, HIGH); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW); 
}else if(x==1 && y==0){        //Right turn 
     digitalWrite(PWMA, 450); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, 450); 
     digitalWrite(DB, HIGH); 
}else if(x==1 && y==1){        //Forward and Right 
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW);
 } 
}  
