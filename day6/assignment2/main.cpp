/*
Write a function which can encode the information in the given figure : Speed/20 km/h, Distance/150 meters
uint16_t 4bit speed, sensors front, rear, left, right 3bit

Detect crash any sensor = 0 return speed and sensors 
*/
#include <time.h>
#include <bitset>
#include "include.h"

int main(){

    srand(time(NULL));
    DistancePack dist;
    //random input data
    uint16_t speed = rand() % 512;     
    dist.distfront = rand() % 2048;    dist.distrear = rand() % 2048;      
    dist.distleft = rand() % 2048;     dist.distright = rand() % 2048;  
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
//input value vehicle speed and sensor distance struct
//return value packed frame
uint16_t packFrame(const uint16_t speed, const DistancePack *distances)
{
    uint16_t frame = 0;
    std::cout << "Vehicle speed: " << speed << " DistanceF: " << distances->distfront; //print input raw values (debug)
    std::cout << " DistanceR: " << distances->distrear << " DistanceL: " << distances->distleft << " DistanceR: " << distances->distright << std::endl;     
    
    frame |= ((((speed > 300 ? 300 : speed) / 20) << 12) & 0b1111000000000000); //check max value, divide resolution, shift to correct bit and mask
    frame |= ((((distances->distfront > 1050 ? 1050 : distances->distfront)/150) << 9) & 0b0000111000000000);    
    frame |= ((((distances->distrear > 1050 ? 1050 : distances->distrear)/150) << 6) & 0b0000000111000000);
    frame |= ((((distances->distleft > 1050 ? 1050 : distances->distleft)/150) << 3) & 0b0000000000111000);    
    frame |= ((((distances->distright > 1050 ? 1050 : distances->distright)/150)) & 0b0000000000000111);       

    return frame;
}
//input value frame from bus
//return data include 12-16 sensor status 0-3 vehicle speed
uint16_t detectCrash(const uint16_t frameInput)    
{
    uint16_t initmask = 0x0007;
    uint16_t crashData = 0; 

    for(int x = 0; x < 4; x++) {
        if(((frameInput & (initmask << (x * 3))) == 0 && (frameInput & 0xF000) > 0)) { //check if any sensor value == 0 and speed > 0
            crashData |= (frameInput >> 12) & 0x000F; // return crash speed
            crashData |= (0x1 << (x+12)) & 0xF000; // return  crashed sensors 0-3
        }
    }
    return crashData;
}