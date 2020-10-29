#include "vehicleFunctions.h"
#include "testCases.h"
#include "include.h"
#include <bitset>
#include <iostream>

void runTestSuite(){

    testSpeedMin(); //negative test
    testSpeedMax(); //negative test
    testSpeedNormal(); //positive test  
    testCrashNormalNoCrash(); //positive test  
    testCrashNormalCrash(); //positive test    
}

void testSpeedMin(){   //Test vehicle speed min
 
    DistancePack dist;
    uint16_t response;     
    
        if((response = packFrame(-100, &dist)) != 0x0000)
            std::cout << "Vehicle speed min failed: " << response << std::endl;
        else
            std::cout << "Vehicle speed min passed: " << response << std::endl;         
} 

void testSpeedMax(){  //Test vehicle speed max
 
    DistancePack dist;
    uint16_t response;     
    
        if((response = packFrame( 65335, &dist)) !=  0xF000)
            std::cout << "Vehicle speed max failed: " << response << std::endl;
        else
            std::cout << "Vehicle speed max passed: " << response << std::endl;  
} 

void testSpeedNormal(){   //Test vehicle speed max
 
    DistancePack dist;
    uint16_t response;     
    
        if((response = packFrame( 100, &dist)) !=  0x5000)
            std::cout << "Vehicle speed normal failed: " << std::hex << response << std::endl;
        else
            std::cout << "Vehicle speed normal passed: " << std::hex << response << std::endl;

        if((response = packFrame( 0, &dist)) !=  0x0000)
            std::cout << "Vehicle speed 0 failed: " << std::hex << response << std::endl;
        else
            std::cout << "Vehicle speed 0 passed: " << std::hex << response << std::endl;   

}

void testCrashNormalNoCrash(){   //Test crash sensor no crash
 
    uint16_t response; 

        if((response = detectCrash(0xAAAA)) !=  0x0000) //750m*4 200km/h
            std::cout << "No crash failed: " << response << std::endl;
        else
            std::cout << "No crash passed: " << response << std::endl;  
} 

void testCrashNormalCrash(){   //Test crash sensor
 
    uint16_t response; 
    
        if((response = detectCrash( 0xAA00)) ==  0x0000) //some sensor crash, 200km/h
            std::cout << "Crash failed: " << response << std::endl;
        else
            std::cout << "Crash passed: " << response << std::endl;  
} 