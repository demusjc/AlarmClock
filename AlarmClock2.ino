#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int setButton = 6;
const int hourButton = 9;
const int minButton = 8;
const int speakerPin = 7;

int alarmSet = LOW;
int hourSet = LOW;
int minSet = LOW;

int alarmHour = 12;
int alarmMin = 00;

//int minute = 0;
//int hour = 1;

unsigned long minCheck = 0;


void setup() {
  lcd.begin(16, 2);
  pinMode(setButton, INPUT);
  pinMode(hourButton, INPUT);
  pinMode(minButton, INPUT);
  pinMode(speakerPin, OUTPUT);

  setTime(1, 00, 00, 10, 3, 2019);
  

  displayTime();

}

void loop() {

  int set = digitalRead(setButton);
  int newHour = digitalRead(hourButton);
  int newMin = digitalRead(minButton);

    if(set==HIGH)
      alarmSet = HIGH;
    else
      alarmSet = LOW;
    if (alarmSet == HIGH)
      displayAlarm();
    else
      displayTime();

    if (newHour == HIGH) {
      hourSet = HIGH;

      if ((hourSet == HIGH) && (alarmSet == HIGH)) {
        if (alarmHour == 12)
          alarmHour = 1;
        else
          alarmHour = alarmHour + 1;
        displayAlarm();
      }
    }

    if (newMin == HIGH) {
      minSet = newMin;

      if ((minSet == HIGH) && (alarmSet == HIGH)) {
        if (alarmMin == 59)
          alarmMin = 0;
        else
          alarmMin = alarmMin + 1;
        displayAlarm();
      }
    }

    if((hour() == alarmHour) && (minute() == alarmMin)){
    tone(speakerPin, 1000);
    }
//    else
//    noTone(speakerPin);
 
      

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  //alarmSet = set;
  minSet = newMin;
  hourSet = newHour;
}

void displayAlarm() {
  lcd.setCursor(0, 0);
  lcd.print("Enter alarm time");
  lcd.setCursor(0, 1);
  lcd.print("-->");
  if (alarmHour < 10) {
    lcd.print("0");
    lcd.print(alarmHour);
    lcd.print(":");
  }
  else {
    lcd.print(alarmHour);
    lcd.print(":");
  }
  if (alarmMin < 10) {
    lcd.print("0");
    lcd.print(alarmMin);
    lcd.print("    ");
  }
  else {
    lcd.print(alarmMin);
    lcd.print("     ");
  }
}

void displayTime() {
  lcd.setCursor(0, 0);
  lcd.print("Time:           ");
  lcd.setCursor(0, 1);
  hourFormat12();

  int hr = hour();
  int m = minute();
  
  if (hr < 10) {
    lcd.print("0");
    lcd.print(hr);
    lcd.print(":");
  }
  else {
    lcd.print(hr);
    lcd.print(":");
  }
  if (m < 10) {
    lcd.print("0");
    lcd.print(m);
    lcd.print("    ");
  }
  else {
    lcd.print(m);
    lcd.print("      ");
  }
}
