#include <SoundManagement.h>

SoundManagement_::SoundManagement_(){};


void SoundManagement_::mainPhaseBGMUpdate(long currentMillis){
    if (!mainPhaseBGM.updateMusic(currentMillis))
        mainPhaseBGM.init();
}

void SoundManagement_::fPressedSFX(){
    f_SFX.init();
}
void SoundManagement_::ePressedSFX(){
    e_SFX.init();
}
void SoundManagement_::dPressedSFX(){
    d_SFX.init();
}
void SoundManagement_::cPressedSFX(){
    c_SFX.init();
}

void SoundManagement_::sfxUpdate(long currentMillis){
    f_SFX.updateMusic(currentMillis);
    e_SFX.updateMusic(currentMillis);
    d_SFX.updateMusic(currentMillis);
    c_SFX.updateMusic(currentMillis);
}

