#include <SelectingPhase.h>
#include <CustomChars.h>

Beat SIGNED_BEATS[] = {
    Beat("Never Gonna",NEVERGONNAGIVEYOUUP,125),
    Beat("GOT"        ,GOT                ,85 ),
    Beat("Green Hill" ,GREENHILL          ,140),
};

int SelectingPhase::getSelection(){
    return this->selection;
}

void SelectingPhase::setSelection(int selected){
    if (0 > selected)
        return;
    if ((sizeof(SIGNED_BEATS)/sizeof(SIGNED_BEATS[0])) <= selected)
        return;

    this->selection = selected;
    this->lcd->setCursor(0,1);
    this->lcd->print("                    ");
    this->lcd->setCursor(0,2);
    this->lcd->print("                    ");
    this->lcd->setCursor(4,1);
    this->lcd->print(SIGNED_BEATS[this->selection].name);
    this->lcd->setCursor(12,2);
    this->lcd->write(4);
    this->lcd->print(String(SIGNED_BEATS[this->selection].tempo));
    this->lcd->setCursor(17,2);
    this->lcd->print("BPM");
    
}

void SelectingPhase::start(){
    this->lcd->clear();
    this->lcd->setCursor(0,0);
    this->lcd->print("Select Beat      ///");
    this->lcd->setCursor(0,3);
    this->lcd->print("       E   C   D   F");
    this->lcd->createChar(0,UPARROW);
    this->lcd->createChar(1,DOWNARROW);
    this->lcd->createChar(2,BACKARROW);
    this->lcd->createChar(3,CONFIRM_CHAR);
    this->lcd->createChar(4,MELODY_CHAR);
    this->lcd->setCursor(6,3);
    this->lcd->write(0);
    this->lcd->setCursor(10,3);
    this->lcd->write(1);
    this->lcd->setCursor(14,3);
    this->lcd->write(2);
    this->lcd->setCursor(18,3);
    this->lcd->write(3);
    this->setSelection(0);
    this->isStarted = true;
}

void SelectingPhase::update(long currentMillis){
    if (*this->phase != SELECTING_BEAT)
        return;
    if (!this->isStarted)
        this->start();
    
    updateBGM(currentMillis);
    
    if (currentMillis-lastUpdate < 250)
        return;
        if (!digitalRead(F_BUTTON)){
            
        }
        if (!digitalRead(E_BUTTON)){
            this->setSelection(this->getSelection()-1);
            lastUpdate = currentMillis;
        }
        if (!digitalRead(D_BUTTON)){
            this->isStarted = false;
            *this->phase = MAIN_MENU;
        }
        
        if (!digitalRead(C_BUTTON)){
            this->setSelection(this->getSelection()+1);
            lastUpdate = currentMillis;
    }
    
}