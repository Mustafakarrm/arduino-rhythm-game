#ifndef SELECTINGPHASE_H
#define SELECTINGPHASE_h
#include <MainPhase.h>
#include <Beat.h>
class SelectingPhase : public MainPhase{
    protected:    
    private:
        int selection = -1;
        void setSelection(int selected);
    public:
        void start();
        int getSelection();
        void update(long currentMillis);
};
#endif