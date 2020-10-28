#ifndef _VEHICLEFUNCTIONS_H_
#define _VEHICLEFUNCTIONS_H_
#include <iostream>

struct DistancePack{
    uint16_t distfront;
    uint16_t distrear;
    uint16_t distleft;
    uint16_t distright;    
};

uint16_t packFrame(const uint16_t, const DistancePack*);

uint16_t detectCrash(const uint16_t);

#endif