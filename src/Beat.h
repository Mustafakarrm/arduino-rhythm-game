#ifndef BEAT_H
#define BEAT_H

#include <Melodies.h>

struct Beat{
    char* name;
    const int *melody;
    int tempo;
    Beat(char* beatName,const int *melody,int bpm){
        this->name = beatName;
        this->melody = melody;
        this->tempo = bpm;

    };
};


#endif