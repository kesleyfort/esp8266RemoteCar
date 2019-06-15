#define BLYNK_PRINT Serial 
#define BLYNK_DEBUG
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 

//Código de autenticação do Blynk. 
char auth[] = "TokenDeAutenticacao"; 
// Dados da rede Wifi. Caso seja uma rede aberta, defina a variável pass como ""
char ssid[] = "NomeDaRede"; 
char pass[] = "SenhaDaRede"; 
int PWMA=5;// Motor Direito 
int PWMB=4;//Motor Esquerdo 
int DA=0;//Ré Motor Direito 
int DB=2;//Ré Motor Esquerdo
void setup(){ 
 //Inicia o console para Debug 
 Serial.begin(9600); 
 //Instancia a classe Blynk. Note que, caso o servidor rode localmente, modifique a função
 //IPAddress para refletir o IP do servidor.
 //Para conexões via internet, usar Blynk.begin(auth, ssid, pass); 
 Blynk.begin(auth, ssid, pass,IPAddress(10,42,0,1),8080); 
 //Definimos os pinos como OUTPUT.
 pinMode(PWMA, OUTPUT); 
 pinMode(PWMB, OUTPUT); 
 pinMode(DA, OUTPUT); 
 pinMode(DB, OUTPUT); 
} 
void loop(){ 
Blynk.run(); 
  
} 
// Verificamos o retorno do PIN V1 nesta função. 
BLYNK_WRITE(V1){
//Os parâmetros x e y são usados para sabermos a direção do joystick no aplicativo de controle.
int x = param[0].asInt(); 
int y = param[1].asInt();
Serial.write(x);
Serial.write(y);
if(x==-1 && y==-1){             //Para trás e Esquerda     
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, HIGH); 
}else if(x==-1 && y==0){        //Virar a Esquerda 
     digitalWrite(PWMA, 450); 
     digitalWrite(DA, HIGH); 
    
     digitalWrite(PWMB, 450); 
     digitalWrite(DB, LOW); 
}else if(x==-1 && y==1){        //Diagonal Esquerda     
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
    
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, LOW); 
}else if(x==0 && y==-1){        //Para trás     
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, HIGH); 
     
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, HIGH);
}else if(x==0 && y==0){        //Manter Parado 
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW); 
}else if(x==0 && y==1){        //Forward 
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, LOW); 
    
     digitalWrite(PWMB, HIGH);
     digitalWrite(DB, LOW); 
}else if(x==1 && y==-1){        //Para trás e Direita     
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, HIGH); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW); 
}else if(x==1 && y==0){        //Virar a Direita 
     digitalWrite(PWMA, 450); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, 450); 
     digitalWrite(DB, HIGH); 
}else if(x==1 && y==1){        //Diagonal para frente e Direita 
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW);
 } 
}
