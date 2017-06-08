#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int contloc = 0;
int contvis = 0;

int stateloc = 0;
int statevis = 0;

const int pinloc = 6;
const int pinvis = 7;
void setup() {
  pinMode(pinloc, INPUT);
  pinMode(pinvis, INPUT);

  lcd.begin(16, 2);
}

void loop() {
  stateloc = digitalRead(pinloc);
  statevis = digitalRead(pinvis);
  delay(200);
  
  lcd.setCursor(0, 0);
  lcd.print("Atletico, Madrid");
  lcd.setCursor(0, 1);
  
  if(stateloc == HIGH){
    contloc ++;
  }
  if(statevis == HIGH){
    contvis ++;
  }
  if(contvis + contloc == 7){
    if(contloc > contvis){
        lcd.print("R.MADID GANA!!");
        delay(5000);
      }
    if(contvis > contloc){
        lcd.print("ATLETICO GANA!!");
        delay(5000);
      }
      lcd.clear();
      contloc = 0;
      contvis = 0;
    }
  lcd.setCursor(4, 1);
  lcd.print(contvis);
  lcd.setCursor(12,1); 
  lcd.print(contloc); 
}

