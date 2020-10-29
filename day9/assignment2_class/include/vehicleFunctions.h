#ifndef _VEHICLEFUNCTIONS_H_
#define _VEHICLEFUNCTIONS_H_
#include <iostream>

class vehicleFunctions{

    private:
        uint16_t frame = 0;
        uint16_t vehicleSpeed = 0;
        struct DistancePack{
            uint16_t distfront = 0;
            uint16_t distrear = 0;
            uint16_t distleft = 0;
            uint16_t distright = 0;  
    }_pack;

    public:
        vehicleFunctions();
        uint16_t detectCrash();
        uint16_t packFrame();
        void setSpeed(uint16_t _speed) { this->vehicleSpeed = _speed; };
        void setDistance(uint16_t fr, uint16_t re, uint16_t lf, uint16_t rt) { this->_pack.distfront = fr; this->_pack.distrear = re; 
        this->_pack.distleft = lf; this->_pack.distright = rt; };
};
#endif