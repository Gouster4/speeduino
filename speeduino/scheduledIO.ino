#include "scheduledIO.h"
#include "scheduler.h"
#include "globals.h"
#include "timers.h"

inline void beginCoil1Charge() { digitalWrite(pinCoil1, coilHIGH); tachoOutputFlag = READY; }
inline void endCoil1Charge() { digitalWrite(pinCoil1, coilLOW); }

inline void beginCoil2Charge() { digitalWrite(pinCoil2, coilHIGH); tachoOutputFlag = READY; }
inline void endCoil2Charge() { digitalWrite(pinCoil2, coilLOW); }

inline void beginCoil3Charge() { digitalWrite(pinCoil3, coilHIGH); tachoOutputFlag = READY; }
inline void endCoil3Charge() { digitalWrite(pinCoil3, coilLOW); }

inline void beginCoil4Charge() { digitalWrite(pinCoil4, coilHIGH); tachoOutputFlag = READY; }
inline void endCoil4Charge() { digitalWrite(pinCoil4, coilLOW); }

inline void beginCoil5Charge() { digitalWrite(pinCoil5, coilHIGH); tachoOutputFlag = READY; }
inline void endCoil5Charge() { digitalWrite(pinCoil5, coilLOW); }

inline void beginCoil6Charge() { digitalWrite(pinCoil6, coilHIGH); tachoOutputFlag = READY; }
inline void endCoil6Charge() { digitalWrite(pinCoil6, coilLOW); }

inline void beginCoil7Charge() { digitalWrite(pinCoil7, coilHIGH); tachoOutputFlag = READY; }
inline void endCoil7Charge() { digitalWrite(pinCoil7, coilLOW); }

inline void beginCoil8Charge() { digitalWrite(pinCoil8, coilHIGH); tachoOutputFlag = READY; }
inline void endCoil8Charge() { digitalWrite(pinCoil8, coilLOW); }

//The below 3 calls are all part of the rotary ignition mode
inline void beginTrailingCoilCharge() { digitalWrite(pinCoil2, coilHIGH); }
inline void endTrailingCoilCharge1() { digitalWrite(pinCoil2, coilLOW); *ign3_pin_port |= ign3_pin_mask; } //Sets ign3 (Trailing select) high
inline void endTrailingCoilCharge2() { digitalWrite(pinCoil2, coilLOW); *ign3_pin_port &= ~(ign3_pin_mask); } //sets ign3 (Trailing select) low

//As above but for ignition (Wasted COP mode)
void beginCoil1and3Charge() { digitalWrite(pinCoil1, coilHIGH); digitalWrite(pinCoil3, coilHIGH); tachoOutputFlag = READY; }
void endCoil1and3Charge()   { digitalWrite(pinCoil1, coilLOW);  digitalWrite(pinCoil3, coilLOW);  }
void beginCoil2and4Charge() { digitalWrite(pinCoil2, coilHIGH); digitalWrite(pinCoil4, coilHIGH); tachoOutputFlag = READY; }
void endCoil2and4Charge()   { digitalWrite(pinCoil2, coilLOW);  digitalWrite(pinCoil4, coilLOW);  }

//For 6cyl wasted COP mode)
void beginCoil1and4Charge() { digitalWrite(pinCoil1, coilHIGH); digitalWrite(pinCoil4, coilHIGH); tachoOutputFlag = READY; }
void endCoil1and4Charge()   { digitalWrite(pinCoil1, coilLOW);  digitalWrite(pinCoil4, coilLOW);  }
void beginCoil2and5Charge() { digitalWrite(pinCoil2, coilHIGH); digitalWrite(pinCoil5, coilHIGH); tachoOutputFlag = READY; }
void endCoil2and5Charge()   { digitalWrite(pinCoil2, coilLOW);  digitalWrite(pinCoil5, coilLOW);  }
void beginCoil3and6Charge() { digitalWrite(pinCoil3, coilHIGH); digitalWrite(pinCoil6, coilHIGH); tachoOutputFlag = READY; }
void endCoil3and6Charge()   { digitalWrite(pinCoil3, coilLOW);  digitalWrite(pinCoil6, coilLOW);  }

//Special case for 6cyl seqvential if not enough timers for it
void beginCoil1or4Charge()
    {
    tachoOutputFlag = READY;
    //change ignition pin based on which rotation engine is
	int crankAngle = getCrankAngle();
    if(crankAngle < 360 ){
        digitalWrite(pinCoil1, coilHIGH);
        }
    else{
        digitalWrite(pinCoil4, coilHIGH);
        }
    }
void endCoil1or4Charge()
    {
        //both coils can go to LOW state, because the way this works, these can't be charged at the same time anyway.
        digitalWrite(pinCoil1, coilLOW);
        digitalWrite(pinCoil4, coilLOW);
    }
void beginCoil2or5Charge()
    {
    tachoOutputFlag = READY;
	int crankAngle = getCrankAngle();
    if(crankAngle < 360 ){
        digitalWrite(pinCoil2, coilHIGH);
        }
    else{
        digitalWrite(pinCoil5, coilHIGH);
        }
    }
void endCoil2or5Charge()
    {
        digitalWrite(pinCoil2, coilLOW);
        digitalWrite(pinCoil5, coilLOW);
    }
void beginCoil3or6Charge()
    {
    tachoOutputFlag = READY;
	int crankAngle = getCrankAngle();
    if(crankAngle < 360 ){
        digitalWrite(pinCoil3, coilHIGH);
        }
    else{
        digitalWrite(pinCoil6, coilHIGH);
        }
    }
void endCoil3or6Charge()
    {
        digitalWrite(pinCoil3, coilLOW);
        digitalWrite(pinCoil6, coilLOW);
    }

void nullCallback() { return; }
