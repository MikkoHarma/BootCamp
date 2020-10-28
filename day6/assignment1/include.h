#ifndef _INCLUDE_H_
#define _INCLUDE_H_
#include <iostream>

void printVehicleStatus(uint16_t);

union Status{
    uint16_t fullstatus;
    struct bitwise {  //wrong endian
        unsigned driverB:1;
        unsigned passengerB:1;
        unsigned rearLeftB:1;
        unsigned rearRightB:1;
        unsigned rearCenterB:1;
        unsigned driverW:1;
        unsigned passengerW:1;
        unsigned rearLeftW:1;
        unsigned rearRightW:1;
        unsigned driverD:1;
        unsigned passengerD:1;
        unsigned rearLeftD:1;
        unsigned rearRightD:1;
        unsigned front:1;
        unsigned rear:1;
        unsigned interior:1; 
    }bitStatus;
};

#endif