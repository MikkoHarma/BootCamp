/*
Write tests for one of your previous assignments – preferably something with classes and private functions
*/
#include <time.h>
#include <bitset>
#include "include.h"
#include "vehicleFunctions.h"
#include "testCases.h"

int main(){
   
    vehicleFunctions vf;

    vf.setSpeed(100);
    vf.setDistance(550, 0, 550, 550);

    std::cout << vf.packFrame() << std::endl;

    std::cout << vf.detectCrash() << std::endl;

  //  runTestSuite();
    return 0;
}