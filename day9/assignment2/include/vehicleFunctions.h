#ifndef _VEHICLEFUNCTIONS_H_
#define _VEHICLEFUNCTIONS_H_
#include <iostream>

struct DistancePack{
    uint16_t distfront = 0;
    uint16_t distrear = 0;
    uint16_t distleft = 0;
    uint16_t distright = 0;    
};

uint16_t packFrame(const uint16_t, const DistancePack*);

uint16_t detectCrash(const uint16_t);

#endif