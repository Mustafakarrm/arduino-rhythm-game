#include "Arduino.h"
#include <LiquidCrystal_I2C.h>

#include <Constants.h>
#include <MainPhase.h>
#include <SelectingPhase.h>

LiquidCrystal_I2C lcd(0x27,20,4);
SoundManagement_ soundManagement;

int currentPhase = MAIN_MENU;

MainPhase mainPhase;
SelectingPhase selectingPhase;


void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(F_BUTTON,INPUT_PULLUP);
  pinMode(E_BUTTON,INPUT_PULLUP);
  pinMode(D_BUTTON,INPUT_PULLUP);
  pinMode(C_BUTTON,INPUT_PULLUP);
  pinMode(BGM_BUZZER,OUTPUT);
  pinMode(SFX_BUZZER,OUTPUT);
  mainPhase.init(currentPhase,lcd,soundManagement);
  selectingPhase.init(currentPhase,lcd,soundManagement);
  
}

void loop()
{
  mainPhase.update(millis());
  selectingPhase.update(millis());
  
  
  
  if (!digitalRead(F_BUTTON))
    soundManagement.fPressedSFX();
  if (!digitalRead(E_BUTTON))
    soundManagement.ePressedSFX();
  if (!digitalRead(D_BUTTON))
    soundManagement.dPressedSFX();
  if (!digitalRead(C_BUTTON))
    soundManagement.cPressedSFX();
  soundManagement.sfxUpdate(millis()); //endl
}
