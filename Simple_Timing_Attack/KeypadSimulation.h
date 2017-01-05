#ifndef KeypadSimulation_h
#define KeypadSimulation_h
#include <Energia.h>
#define kEYPADPIN_1 23
#define kEYPADPIN_2 24
#define kEYPADPIN_3 25
#define kEYPADPIN_4 26
#define kEYPADPIN_5 27
#define kEYPADPIN_6 28
#define kEYPADPIN_7 29

void keyPadInit();
void inputSimulation(int input);


#endif /* KeypadSimulation_h */
