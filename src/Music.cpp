#include <Music.h>


Music::Music(int melody[], int bpm,int noteSize){
    this->melody = melody;
    this->tempo = bpm;
    this->notes=noteSize;

    this->init();
    
}

void Music::raiseBPM(int bpm){
    this->tempo += bpm;
}

int Music::getCurrentBPM(){
    return this->tempo;
}

bool Music::updateMusic(long currentMillis){
    if (this->currentNote > this->notes)
        return false; //music has ended
    
    if (currentMillis - this->lastNoteTime < this->noteDuration)
        return true; //silence
    noTone(BUZZER_PIN); // To cancel previous tone

    // calculates the duration of each note
    this->divider = this->melody[this->currentNote + 1];
    if (this->divider > 0) {
      // regular note, just proceed
      this->noteDuration = (this->wholenote) / this->divider;
    } else if (this->divider < 0) {
      // dotted notes are represented with negative durations!!
      this->noteDuration = (this->wholenote) / abs(this->divider);
      this->noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    tone(BUZZER_PIN, melody[this->currentNote], this->noteDuration*0.9);
    this->lastNoteTime = currentMillis;
    this->currentNote = this->currentNote + 2;
    return true;
    //endl
}

void Music::init(){
    this->wholenote = (60000 * 4) / tempo;
    this->divider = 0; 
    this->noteDuration = 0;
    this->currentNote = 0;
}

void Music::pause(){
    noTone(BUZZER_PIN);
}