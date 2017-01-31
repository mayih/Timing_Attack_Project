#ifndef KeypadEmulation_h
#define KeypadEmulation_h

#include <Energia.h>

#define PB2 5
#define kEYPADPIN_1 23 
#define kEYPADPIN_2 24
#define kEYPADPIN_3 25
#define kEYPADPIN_4 26
#define kEYPADPIN_5 27
#define kEYPADPIN_6 28
#define kEYPADPIN_7 29
class KeypadEmulation
{
    unsigned int buttonPushed(const byte row, const byte col, bool computeTimeThankSignal);
    
  public:
    KeypadEmulation();
    unsigned int pushButton(unsigned short input, bool computeTimeThankSignal);
    unsigned int inputSimulation(unsigned short button1, unsigned short button2, unsigned short button3, unsigned short button4);
};

#endif /* KeypadEmulation_h */
