/* Coche Inalambrico Bluetooth por Radio Control
ARDUINO   L293D(Puente H)        
  5          10
  6          15
  9          7
  10         2
  5V         1, 9, 16
  GND        4, 5, 12, 13
  
  El motor 1 se conecta a los pines 3 y 6 del Puente H
  El motor 2 se conecta a los pines 11 y 14 del Puente H
  
  La fuente de alimentacion de los Motores se conecta a tierra y
  el positivo al pin 8 del puennte H. 
 
Conexion del Modulo Bluetooth HC-06 y el Arduino
ARDUINO    Bluetooth HC-06 
 0 (RX)       TX
 1 (TX)       RX
 5V           VCC
 GND          GND
!!Cuidado!! Las conexiones de TX y RX al modulo Bluetooth deben estar desconectadas
en el momento que se realiza la carga del codigo (Sketch) al Arduino.

*/
int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10; 
int vel = 255;          
int estado = 'g';        

void setup()  { 
  Serial.begin(9600);    
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
 } 
 
void loop()  { 
  
  if(Serial.available()>0){       
      estado = Serial.read();
  }
  if(estado=='e'){          
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, vel);  
      analogWrite(izqA, vel);       
  }
  if(estado=='b'){          
      analogWrite(derB, vel);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);  
      analogWrite(izqA, 0);      
  }
  if(estado=='c'){         
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);    
      analogWrite(izqA, 0); 
  }
  if(estado=='d'){          
       analogWrite(derB, 0);     
       analogWrite(izqB, vel);
       analogWrite(izqA, 0);
       analogWrite(derA, 0);  
  } 
  
  if(estado=='a'){          
       analogWrite(derA, 0);    
       analogWrite(izqA, 0);
       analogWrite(derB, vel);  
       analogWrite(izqB, vel);      
       
  }    
}
