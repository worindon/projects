#include "HID-Project.h"

#define DEBUG 0         // режим отладки
#define ENC_TYPE 1      // тип энкодера, 0 или 1
#define INV_WHEEL 0     // инверсия руля


#define ENC_A 5         // пин энкодера 
#define ENC_B 6         // пин энкодера

#define BUTT_CAL 3      // кнопка калибровки
#define KNA 16          // доп. кнопка
#define KNB 9           // доп. кнопка
#define KNC 10          // доп. кнопка
#define KND 14          // доп. кнопка

#define Axe_Throttle A0 // педаль газа
#define Axe_Clutch A3   // педаль сцепления
#define Axe_Brake A1    // педаль тормоза

#define BUTT_BR 4       // ручник
#define KNF 7           // доп. кнопка
#define KNG 2           // доп. кнопка

#define KNH 15          //  доп. кнопка
#define KNI A2          //  доп. кнопка
#define KNJ 8           // доп. кнопка

volatile int encCounter = 0;
volatile boolean state0, lastState, turnFlag;
int wheelMax;
uint32_t timer;

#include <EEPROM.h>
#include "HID-Project.h"


int16_t Axis1_ = 0, Axis2_ = 0, Axis3_ = 0, Axis4_ = 0;

bool throttle_present = true;
bool brake_present = true, clutch_present = true;

void setup() {
  
  // Инициализация джойстика:
  pinMode(BUTT_BR, INPUT_PULLUP);
  pinMode(KNA, INPUT_PULLUP);
  pinMode(KNB, INPUT_PULLUP);
  pinMode(KNC, INPUT_PULLUP);
  pinMode(KND, INPUT_PULLUP);
  pinMode(KNF, INPUT_PULLUP);
  pinMode(KNG, INPUT_PULLUP);
  pinMode(KNH, INPUT_PULLUP);
  pinMode(KNI, INPUT_PULLUP);
  pinMode(KNJ, INPUT_PULLUP);
  pinMode(BUTT_CAL, INPUT_PULLUP);
  setupTmr();
 
  calibration();
  EEPROM.get(12, wheelMax);
  Gamepad.begin();

  int16_t ap1 = analogRead(Axe_Throttle),
  ap2 = analogRead(Axe_Brake),
  ap3 = analogRead(Axe_Clutch),
  
  delay(10);
 
  
}

void loop() {
   gamepadTick();

  
  if (!digitalRead(BUTT_CAL)) {
    encCounter = 0;
  }


  
  Axis1_ = 0, Axis2_ = 0, Axis3_ = 0, Axis4_ = 0;

  
//  Педаль Газа:
  if (throttle_present == true) {
    Axis1_ = analogRead(Axe_Throttle);
    Axis1_ = map(Axis1_,0,1023,-32768,32767);
    Gamepad.rxAxis(Axis1_);}
  else{Gamepad.rxAxis(0);}
  // Педаль Тормоза:
  if (brake_present == true) {
    Axis2_ = analogRead(Axe_Brake);
    Axis2_ = map(Axis2_,0,1023,-128,127);
    Gamepad.zAxis(Axis2_);}
  else{Gamepad.zAxis(0);}
  // Педаль Сцепления:
  if (clutch_present == true) {
    Axis3_ = analogRead(Axe_Clutch);
    Axis3_ = map(Axis3_,0,1023,-128,127);
    Gamepad.rzAxis(Axis3_);}
  else{Gamepad.rzAxis(0);}
  
  
  // Отправляем значения в ПК:
  Gamepad.write();
}



void encTick() {
  state0 = digitalRead(ENC_A);
  if (state0 != lastState) {
#if (ENC_TYPE == 1)
    turnFlag = !turnFlag;
    if (turnFlag)
      encCounter += (digitalRead(ENC_B) != lastState) ? -1 : 1;
#else
    encCounter += (digitalRead(ENC_B) != lastState) ? -1 : 1;
#endif
    lastState = state0;
  }
}
void gamepadTick() {
  if (millis() - timer > 10) {
    timer = millis();
    int wheel;
    if (INV_WHEEL) wheel = constrain(-encCounter, -wheelMax, wheelMax);
    else wheel = constrain(encCounter, -wheelMax, wheelMax);

    wheel = map(wheel, -wheelMax, wheelMax, -32768, 32767);
    Gamepad.xAxis(wheel);
    if (!digitalRead(BUTT_BR)) Gamepad.press(1);
    else Gamepad.release(1);
    Gamepad.write();

    if (!digitalRead(KNA)) Gamepad.press(2);
    else Gamepad.release(2);
    Gamepad.write();

    if (!digitalRead(KNB)) Gamepad.press(3);
    else Gamepad.release(3);
    Gamepad.write();

    if (!digitalRead(KNC)) Gamepad.press(4);
    else Gamepad.release(4);
    Gamepad.write();

    if (!digitalRead(KND)) Gamepad.press(5);
    else Gamepad.release(5);
    Gamepad.write();
    
    if (!digitalRead(KNF)) Gamepad.press(6);
    else Gamepad.release(6);
    Gamepad.write();

    if (!digitalRead(KNG)) Gamepad.press(7);
    else Gamepad.release(7);
    Gamepad.write();

    if (!digitalRead(KNH)) Gamepad.press(8);
    else Gamepad.release(8);
    Gamepad.write();
    
    if (!digitalRead(KNI)) Gamepad.press(9);
    else Gamepad.release(9);
    Gamepad.write();
    
    if (!digitalRead(KNJ)) Gamepad.press(10);
    else Gamepad.release(10);
    Gamepad.write();
  }
}
void calibration() {                                
  if (!digitalRead(BUTT_CAL)) {     // нажата кнопка
    while (!digitalRead(BUTT_CAL)); // пока кнопка удерживается
    Serial.begin(9600);
    delay(100);
    Serial.print(F("Calibration start"));
    encCounter = 0;
    
    int maxWHEEL;

   
    delay(100);                     // дебаунс
    while (true) {                  // крутимся
      if (!digitalRead(BUTT_CAL)) break;
      Serial.println(encCounter);
    }
    
    EEPROM.put(12, abs(encCounter));

    Serial.println(F("Calibration end"));
    Serial.print(F("Wheel: "));
    Serial.println(abs(encCounter));
    
  }
  Serial.end();
  delay(3000);  // задержка чтобы кнопку отпустить
}
// опрос энкодера в прерывании
ISR(TIMER3_COMPA_vect) {
  encTick();
}

// ставим таймер 3, канал А, период 0.5 мс. Для опроса энкодера
void setupTmr() {
  TCCR3B = 0b00001001;
  TIMSK3 = 0b00000010;
  OCR3AH = highByte(15999 / 2);
  OCR3AL = lowByte(15999 / 2);
}
