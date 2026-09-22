#ifndef SOUNDMANGEMENT_H
#define SOUNDMANGEMENT_H

#include <Music.h>
#include <Melodies.h>
#include <Constants.h>

class SoundManagement_{
    private:
        Music mainPhaseBGM{BGM_BUZZER, MAIN_MENU_MELODY, 180,
                   sizeof(MAIN_MENU_MELODY) / sizeof(MAIN_MENU_MELODY[0])};
        Music f_SFX{SFX_BUZZER,F_NOTE,200,
                    sizeof(F_NOTE)/sizeof(F_NOTE[0])};
        Music e_SFX{SFX_BUZZER,E_NOTE,200,
                    sizeof(E_NOTE)/sizeof(E_NOTE[0])};
        Music d_SFX{SFX_BUZZER,D_NOTE,200,
                    sizeof(D_NOTE)/sizeof(D_NOTE[0])};
        Music c_SFX{SFX_BUZZER,C_NOTE,200,
                    sizeof(C_NOTE)/sizeof(C_NOTE[0])};
    public:
        SoundManagement_();
        void sfxUpdate(long curentMillis);
        
        void mainPhaseBGMUpdate (long currentMillis);

        void fPressedSFX();
        void ePressedSFX();
        void dPressedSFX();
        void cPressedSFX();
};

#endif