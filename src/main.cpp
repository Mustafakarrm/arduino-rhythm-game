#include "Arduino.h"
#include <LiquidCrystal_I2C.h>

#include <Constants.h>
#include <MainPhase.h>


LiquidCrystal_I2C lcd(0x27,20,4);
//END OF Hardware defines

int currentPhase;;

MainPhase mainPhase;

void setup()
{
  lcd.init();
  lcd.backlight();

  mainPhase.init(currentPhase,lcd);
  mainPhase.start();
}

void loop()
{
 if (currentPhase == MAIN_MENU){
    mainPhase.update(millis());
  }



 delay (250);
}
