#include <MainPhase.h>

MainPhase::MainPhase(){};

void MainPhase::init(int &phase, LiquidCrystal_I2C &lcd){
    this->lcd   = &lcd;
    this->phase = &phase;
}

void MainPhase::start(){
    if (*this->phase != MAIN_MENU){
        *this->phase = MAIN_MENU;
        this->lcd->clear();
        this->lcd->setCursor(3,0);
        this->lcd->print("TYPING BEAT///");
        this->lcd->setCursor(9,3);
        this->lcd->print("By: Mustafa");
    }
}

void MainPhase::update(long millis){
    this->updateLCD(millis);
    this->updateBGM(millis);

}

void MainPhase::updateLCD(long millis){
    if (millis - lastUpdate < 500)
        return;
    lastUpdate = millis;
    this->lcd->setCursor(2,2);
    if (this->isVisible)
        this->lcd->print("                    ");
    else
        this->lcd->print("Press F To START");
    
    this->isVisible = !this->isVisible;
}

void MainPhase::updateBGM(long millis){
    
}