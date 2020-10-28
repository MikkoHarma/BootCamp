/*
Use CMake to build one of the assignments from last week in which you 
have multiple source codes.
*/
#include <time.h>
#include <bitset>
#include "include.h"
#include "vehicleFunctions.h"

int main(){

    srand(time(NULL));
    DistancePack dist;
    //random input data
    uint16_t speed = rand() % speedMaxValue;     
    dist.distfront = rand() % distanceMaxValue;    dist.distrear = rand() % distanceMaxValue;      
    dist.distleft = rand() % distanceMaxValue;     dist.distright = rand() % distanceMaxValue;  
    //pack input data
    uint16_t framedata = packFrame(speed, &dist);   
    // for print output frame (debug)
    std::bitset<16> framebits = framedata;                
    std:: cout << "Output bits 0x" << framebits << std::endl;
    //check frame if crash
    if(uint16_t crashdata = detectCrash(framedata)){
        std::cout << "Crashed: " << ((crashdata & 0x000F)*20) << " km/h" << " Sensors: " << ((crashdata & 0xF000) >> 12) << std::endl; //sensor in binary 1,2,4,8
    }
    return 0;
}