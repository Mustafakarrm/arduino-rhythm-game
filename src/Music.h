#ifndef MUSIC_H
#define MUSIC_H

#include <Arduino.h>

class Music{
    private:
        const int* melody;
        int tempo;
        int notes;
        int buzzerPIN;
        int wholenote;
        int divider;
        int noteDuration;
        int currentNote;
        long lastNoteTime;
    public:
        Music(int buzzer,const int* melody,int bpm,int noteSize);
        bool updateMusic(long millis);
        void raiseBPM(int bpm);
        int getCurrentBPM();
        void pause();
        void init();

};
#endif