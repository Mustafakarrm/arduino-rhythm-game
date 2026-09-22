#include <MainPhase.h>

MainPhase::MainPhase(){};

void MainPhase::init(int &phase,LiquidCrystal_I2C &lcd, SoundManagement_ &sndmgmt){
    this->lcd       = &lcd;
    this->phase     = &phase;
    this->sndmgmt   = &sndmgmt;
}

void MainPhase::start(){
        this->lcd->clear();
        this->lcd->setCursor(3,0);
        this->lcd->print("TYPING BEAT///");
        this->lcd->setCursor(9,3);
        this->lcd->print("By: Mustafa");
        this->isStarted = true;
}

void MainPhase::update(long currentMillis){
        if (*this->phase != MAIN_MENU)
            return;
        if (!isStarted)
            this->start();
        this->updateLCD(currentMillis);
        this->updateBGM(currentMillis);

        if (!digitalRead(F_BUTTON)){
            this->isStarted = false;
            *this->phase = SELECTING_BEAT;
        }
        
}

void MainPhase::updateLCD(long currnetMillis){
    if (currnetMillis - lastUpdate < 500)
        return;
    lastUpdate = currnetMillis;
    this->lcd->setCursor(2,2);
    if (this->isVisible)
        this->lcd->print("                    ");
    else
        this->lcd->print("Press F To START");
    
    this->isVisible = !this->isVisible;
}

void MainPhase::updateBGM(long currentMillis){
    this->sndmgmt->mainPhaseBGMUpdate(currentMillis);
}