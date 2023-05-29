#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pulsePin = 0;
int buzzerPin = 11;

volatile int LPM;
volatile int Signal;
volatile int IBI = 600;
volatile boolean Pulse = false;
volatile boolean QS = false;

void setup() {
  pinMode(11, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
  interruptSetup();
}

void loop() {
  int pulso = analogRead(A0);
  if (pulso >= 525) {
    digitalWrite(11, HIGH);
  }
  else {
    digitalWrite(11, LOW);
  }
  lcd.setCursor(1, 0);
  lcd.print("LPM= ");
  lcd.print(LPM);
  lcd.print("   ");
  //Serial.print("LPM = ");  Serial.println(BPM); //Habilitar estas linea para ver BPM en el monitor serial pero deshabilitar la siguiente
  Serial.println(pulso);                          // envia el valor del pulso por el puerto serie  (desabilitarla si habilita la anterior linea)
  if (QS == true) {                      
    QS = false;                          
  }

}
