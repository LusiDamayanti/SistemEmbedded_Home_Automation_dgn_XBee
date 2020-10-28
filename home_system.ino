#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

void setup() {
  Serial.begin(9600);
  for(int i = 2;i<=8;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  Serial.print("Simulasi Home Automation dengan XBee");
  Serial.println();
  Serial.println("Lusi Damayanti");
  Serial.println();
  Serial.println();
  Serial.println();
}

int i,state = 0;
int high9 = 0,high10 = 0;
int DataCheck = 0;

void loop() {
 if(Serial.available())
  {
    char data = Serial.read();
    Serial.print(data);
    Serial.print("      ======== >      ");
    
    if(data == '1'){DataCheck = 1; digitalWrite(2, HIGH); Serial.println("Lampu ruang tamu menyala");}
    if(data == '2'){DataCheck = 1; digitalWrite(2, HIGH); Serial.println("Lampu kamar menyala");}
    if(data == '3'){DataCheck = 1; digitalWrite(2, HIGH); Serial.println("Lampu kamar mandi menyala");} 
    if(data == '4'){DataCheck = 1; digitalWrite(2, LOW); Serial.println("Lampu ruang tamu mati");}
    if(data == '5'){DataCheck = 1; digitalWrite(2, LOW); Serial.println("Lampu kamar mati");}
    if(data == '6'){DataCheck = 1; digitalWrite(2, LOW); Serial.println("Lampu kamar mandi mati");}

    if(data == '7'){DataCheck = 1; digitalWrite(6, LOW);digitalWrite(5, HIGH); Serial.println("Kipas ruang tamu menyala");}
    if(data == '8'){DataCheck = 1; digitalWrite(7, LOW);digitalWrite(8, HIGH); Serial.println("Kipas kamar menyala");}
    if(data == '9'){DataCheck = 1; digitalWrite(12, LOW);digitalWrite(11, HIGH); Serial.println("Kipas ruang keluarga menyala");} 
    if(data == '*'){DataCheck = 1; digitalWrite(5, LOW);digitalWrite(6, LOW); Serial.println("Kipas ruang tamu mati");}
    if(data == '0'){DataCheck = 1; digitalWrite(7, LOW);digitalWrite(8,  LOW); Serial.println("Kipas kamar mati");}
    if(data == '#'){DataCheck = 1; digitalWrite(11, LOW);digitalWrite(12,  LOW); Serial.println("Kipas ruang keluarga mati");}
    if(DataCheck == 0){Serial.println("Perintah Salah. Silakan ulangi !!! ");}
    Serial.println();
    DataCheck = 0;
  }

 if(digitalRead(9)==1 && high9 ==0){
  Serial.print(91);
  Serial.println("    -->  GAS DETECTED");
  high9 = 1;
 }
 else if(digitalRead(9)==0 && high9 == 1){
  Serial.print(90);
  Serial.println("    -->  GAS NOT DETECTED");
  high9 = 0;
 }
 else if(digitalRead(10)==1 && high10 ==0){
  Serial.print(101);
  Serial.println("    -->  FLAME DETECTED");
  high10 = 1;
 }
 else if(digitalRead(10)==0 && high10 == 1){
  Serial.print(100);
  Serial.println("    -->  FLAME NOT DETECTED");
  high10 = 0;
 }
}
