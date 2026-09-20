#ifndef MAINPHASE_h
#define MAINPHASE_h
#include <Constants.h>
#include <LiquidCrystal_I2C.h>

class MainPhase{
    private:
        bool isVisible = true;
    protected:
        LiquidCrystal_I2C *lcd = nullptr;
        int *phase = nullptr;
        long lastUpdate = 0;
        void updateLCD(long millis);
        void updateBGM(long millis);
    public:
        MainPhase();
        void init(int &phase,LiquidCrystal_I2C &lcd);
        void start();
        void buttonPressed(int button);
        void update(long millis);
        
};

#endif