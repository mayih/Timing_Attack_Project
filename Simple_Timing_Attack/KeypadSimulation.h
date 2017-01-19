#ifndef KeypadSimulation_h
#define KeypadSimulation_h

#include <Energia.h>

#define PB2 9
#define kEYPADPIN_1 23
#define kEYPADPIN_2 24
#define kEYPADPIN_3 25
#define kEYPADPIN_4 26
#define kEYPADPIN_5 27
#define kEYPADPIN_6 28
#define kEYPADPIN_7 29
class KeypadSimulation
{

    long unsigned int m_inputTime;
    void pushButton(unsigned short input);
  public:
    long unsigned int getInputTime() {
      return m_inputTime;
    }
    //int setInputTime(long unsigned int inputTime) m_inputTime = inputTime;
    KeypadSimulation();
    unsigned long inputSimulation(unsigned short button1, unsigned short button2, unsigned short button3, unsigned short button4);
};

#endif /* KeypadSimulation_h */
