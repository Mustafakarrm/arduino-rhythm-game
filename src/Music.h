#ifndef MUSIC_H
#define MUSIC_H

#include <Arduino.h>
#include <Constants.h>

class Music{
    private:
        int* melody;
        int tempo;
        int notes;
        int wholenote;
        int divider;
        int noteDuration;
        int currentNote;
        long lastNoteTime;
    public:
        Music(int melody[],int bpm,int noteSize);
        bool updateMusic(long millis);
        void raiseBPM(int bpm);
        int getCurrentBPM();
        void pause();
        void init();

};
#endif