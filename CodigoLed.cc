#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int upButton=10;
int downButton=9;
int selectButton=8;
#define pulsador1 7
boolean estadoActual1 = LOW;
boolean estadoAnterior1 = LOW;
#define pulsador2 6
boolean estadoActual2 = LOW;
boolean estadoAnterior2 = LOW;
boolean estadoActual = LOW;
boolean estadoAnterior = LOW;
int contador = 0;
void setup() {
pinMode(pulsador1, INPUT);
pinMode(pulsador2, INPUT);
Serial.begin(9600);
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.display();
lcd.print("MariaGuadalupeEspinosa");
lcd.setCursor(0, 1);
lcd.print("Ing.SistemasComputacionales");
delay(2000);
menu();
}
boolean rebote(boolean estadoAnterior, int pin){
boolean estadoActual = digitalRead(pin);
if (estadoAnterior != estadoActual){
delay(5);
estadoActual = digitalRead(pin);
}
return estadoActual;
}
void loop() {
estadoActual1 = rebote(estadoAnterior1, pulsador1);
if (estadoAnterior1 == LOW && estadoActual1 == HIGH){
contador++;
if(contador>=2){
contador = 2;
}
Serial.println(contador);
menu();
}
estadoAnterior1 = estadoActual1;
estadoActual2 = rebote(estadoAnterior2, pulsador2);
if (estadoAnterior2 == LOW && estadoActual2 == HIGH){
contador--;
if(contador <= 0){
contador = 0;
}
Serial.println(contador);
menu();
}
estadoAnterior2 = estadoActual2;
}
void menu(){
switch (contador){
case 0:{
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("InformaticaIndustrial");
lcd.setCursor(0, 1);
lcd.print("Menu");
break;
}
case 1:
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Iniciando");
break;
case 2:
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Terminado");
break;
}}
