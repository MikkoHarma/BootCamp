#include "vehicleFunctions.h"
#include <iostream>
//input value vehicle speed and sensor distance struct
//return value packed frame
uint16_t vehicleFunctions::packFrame(){
    
    std::cout << "Vehicle speed: " << this->vehicleSpeed << " DistanceF: " << this->_pack.distfront; //print input raw values (debug)
    std::cout << " DistanceR: " << this->_pack.distrear << " DistanceL: " << this->_pack.distleft << " DistanceR: " << this->_pack.distright << std::endl;     
    
    this->frame |= ((((this->vehicleSpeed > 300 ? 300 : this->vehicleSpeed) / 20) << 12) & 0b1111000000000000); //check max value, divide resolution, shift to correct bit and mask
    this->frame |= ((((this->_pack.distfront > 1050 ? 1050 : this->_pack.distfront)/150) << 9) & 0b0000111000000000);    
    this->frame |= ((((this->_pack.distrear > 1050 ? 1050 : this->_pack.distrear)/150) << 6) & 0b0000000111000000);
    this->frame |= ((((this->_pack.distleft > 1050 ? 1050 : this->_pack.distleft)/150) << 3) & 0b0000000000111000);    
    this->frame |= ((((this->_pack.distright > 1050 ? 1050 : this->_pack.distright)/150)) & 0b0000000000000111);       

    return this->frame;
}
//input value frame from bus
//return data include 12-16 sensor status 0-3 vehicle speed
uint16_t vehicleFunctions::detectCrash() {
    uint16_t initmask = 0x0007;
    uint16_t crashData = 0; 

    for(int x = 0; x < 4; x++) {
        if(((this->frame & (initmask << (x * 3))) == 0 && (this->frame & 0xF000) > 0)) { //check if any sensor value == 0 and speed > 0
            crashData |= (this->frame >> 12) & 0x000F; // return crash speed
            crashData |= (0x1 << (x+12)) & 0xF000; // return  crashed sensors 0-3
        }
    }
    
    return crashData;
}

vehicleFunctions::vehicleFunctions(){

    this->vehicleSpeed = 0;
    this->_pack.distfront = 0;
    this->_pack.distrear = 0;
    this->_pack.distleft = 0;
    this->_pack.distright = 0;
};