#ifndef MAINPHASE_h
#define MAINPHASE_h
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <SoundManagement.h>
#include <Constants.h>

class MainPhase{
    private:
        bool isVisible = true;
    protected:
        LiquidCrystal_I2C *lcd = nullptr;
        SoundManagement_ *sndmgmt = nullptr;
        int *phase = nullptr;
        long lastUpdate = 0;
        void updateLCD(long millis);
        void updateBGM(long millis);
        bool isStarted = false;
    public:
        MainPhase();
        void init(int &phase,LiquidCrystal_I2C &lcd,SoundManagement_ &sndmgmt);
        void start();
        void buttonPressed(int button);
        void update(long millis);
        
};

#endif