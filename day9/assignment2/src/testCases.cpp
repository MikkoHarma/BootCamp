#include "vehicleFunctions.h"
#include "testCases.h"
#include "include.h"
#include <bitset>
#include <iostream>

void runTestSuite(){

    DistancePack dist;
    std::bitset<16> responseB; 
    uint16_t response;    

    testSpeedMin();
    testSpeedMax();

}
// todo
  //  if(uint16_t crashdata = detectCrash(framedata)){

void testSpeedMin(){   //Test vehicle speed min
 
    DistancePack dist;
    std::bitset<16> responseB;  
    uint16_t response;     
    
        if((response = packFrame(-100, &dist)) > (response & (0xF000 >> 12)))
            std::cout << "Vehicle speed min failed " << response << std::endl;
        else
            std::cout << "Vehicle speed min passed " << response << std::endl;         
} 

void testSpeedMax(){   //Test vehicle speed max
 
    DistancePack dist;
    std::bitset<16> responseB;  
    uint16_t response;     
    
        if((response = packFrame( 65335, &dist)) ==  0xF000)
            std::cout << "Vehicle speed max failed " << response << std::endl;
        else
            std::cout << "Vehicle speed min passed " << response << std::endl;         
} 