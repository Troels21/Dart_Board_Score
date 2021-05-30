#include <LiquidCrystal.h>
#include <Keypad.h>
//Tællere og score
int scoreP1=501;
int scoreP2=501;
int point=0;
char key[4];
String keyString="";
int counter=0;
int refresh=0;

//LCD
const int rs =14, en = 15, d4 = 16, d5 = 17, d6 = 18, d7 = 19;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Keypad
const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'7', '8', '9', 'C'},
  {'4', '5', '6', 'B'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  // set up the LCD's number of columns and rows:
scoreSetup();
Serial.begin(9600);
}

void loop() {
 point= pointSet();
 scoreUpdate(point,0);
 point = pointSet();
 scoreUpdate(0,point);
 
   
}

void scoreSetup(){
   lcd.begin(16, 2);
    lcd.print("P1: ");
    lcd.print(scoreP1);
    lcd.print("  ");
    lcd.print(scoreP2);
    lcd.print(" :P2");
    lcd.setCursor(0,2);
    lcd.display();
}

void scoreUpdate(int point1,int point2){
    lcd.setCursor(0,0);
    lcd.print("P1: ");
    scoreCheck(scoreP1,point1,1);
    scoreP1=scoreP1-point1;
    lcd.print(scoreP1);
    if (scoreP1<100 && scoreP1>10){
      lcd.print(" ");}
        if (scoreP1<10){
        lcd.print("  ");}
    lcd.print("  ");
    scoreCheck(scoreP2,point2,2);
    scoreP2=scoreP2-point2;
    if (scoreP2<100 && scoreP2>10){
      lcd.print(" ");}
        if (scoreP2<10){
        lcd.print("  ");}
    lcd.print(scoreP2);
    lcd.print(" :P2");
    lcd.setCursor(0,2);
    point=0;
    }

int pointSet(){
      keyString="";
  while (true){
     char customKey = customKeypad.getKey();
  if (customKey=='A'){
    while (customKey!='D'){
          customKey =customKeypad.getKey();
          if (customKey=='D'){
            for (int i=0;i<(counter+1);i++){
      keyString += (key[i]-48);}
    lcd.setCursor(0,2);
    lcd.print("                ");
    lcd.setCursor(0,2);
    counter=0;
      return keyString.toInt();}
           
      if (customKey){
    key[counter]=customKey;
    lcd.print(customKey);
    counter =counter+1;
         }
       }
     }
    }
  }

  void scoreCheck(int score,int score2,int Playernr){
    score=score-score2;
    if (score<0){
      lcd.setCursor(0,2);
      lcd.print("You Went Under 0");
      delay(2500);
      lcd.setCursor(0,2);
      lcd.print("                ");
      if (Playernr ==1){
      scoreP1 += score2;
      lcd.setCursor(4,0);}
      if (Playernr ==2){
        scoreP2 +=score2;
        lcd.setCursor(9,0);}
      }
      if (score==0){
        lcd.setCursor(0,0);
        lcd.print("YOU WON  YOU WON");
        lcd.setCursor(0,2);
        lcd.print("YOU WON  YOU WON");
        delay(5000);
              lcd.setCursor(0,0);
              lcd.print("                ");
              lcd.setCursor(0,2);
              lcd.print("                ");
              if (Playernr ==1){
                scoreP1 =scoreP1- score2;
                }
                if (Playernr ==2){
                  scoreP2 =scoreP2- score2;}
              lcd.setCursor(0,0);
              lcd.print("P1: ");
              lcd.print(scoreP1);
              if (scoreP1<100 && scoreP1>10){
               lcd.print(" ");}
               if (scoreP1<10){
                lcd.print("  ");}
              lcd.print("  ");
               if (scoreP2<100 && scoreP2>10){
               lcd.print(" ");}
                 if (scoreP2<10){
                  lcd.print("  ");}
              lcd.print(scoreP2);
              lcd.print(" :P2");
            while (true){
              delay(5000);
              }
            }
    }
