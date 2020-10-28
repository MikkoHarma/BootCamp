/*
Implement a function that can read the information shown in the figure.
uint16_t 5bit belt, 4bit door, 4bit window, 3 bit lights
*/
#include "include.h"
#include <time.h>
#include <bitset>

int main(){

    srand(time(NULL));
    printVehicleStatus(rand() % 65535);
    
    return 0;
}

void printVehicleStatus(uint16_t status){

    Status bits;
    std::bitset<16> fullsts = status;
    std:: cout << "Input bits 0x" << fullsts << std::endl;

    bits.fullstatus = status;
    std::cout << "Belt status:" << std::endl;
        std::cout << std::boolalpha << "Front: " << static_cast<bool>(bits.bitStatus.driverB);
        std::cout << std::boolalpha << " Passenger: " << static_cast<bool>(bits.bitStatus.passengerB); 
        std::cout << std::boolalpha << " RearLeft: " << static_cast<bool>(bits.bitStatus.rearLeftB); 
        std::cout << std::boolalpha << " RearRight: " << static_cast<bool>(bits.bitStatus.rearRightB);  
        std::cout << std::boolalpha << " RearCenter: " << static_cast<bool>(bits.bitStatus.rearCenterB) << std::endl;             

    std::cout << "Window status:" << std::endl;
        std::cout << std::boolalpha << "Front: " << static_cast<bool>(bits.bitStatus.driverW);
        std::cout << std::boolalpha << " Passenger: " << static_cast<bool>(bits.bitStatus.passengerW); 
        std::cout << std::boolalpha << " RearLeft: " << static_cast<bool>(bits.bitStatus.rearLeftW); 
        std::cout << std::boolalpha << " RearRight: " << static_cast<bool>(bits.bitStatus.rearRightW) << std::endl;  

    std::cout << "Door status:" << std::endl;
        std::cout << std::boolalpha << "Front: " << static_cast<bool>(bits.bitStatus.driverD);
        std::cout << std::boolalpha << " Passenger: " << static_cast<bool>(bits.bitStatus.passengerD); 
        std::cout << std::boolalpha << " RearLeft: " << static_cast<bool>(bits.bitStatus.rearLeftD); 
        std::cout << std::boolalpha << " RearRight: " << static_cast<bool>(bits.bitStatus.rearRightD) << std::endl;           

    std::cout << "Light status:" << std::endl;
        std::cout << std::boolalpha << "Front: " << static_cast<bool>(bits.bitStatus.front);
        std::cout << std::boolalpha << " Rear: " << static_cast<bool>(bits.bitStatus.rear); 
        std::cout << std::boolalpha << " Center: " << static_cast<bool>(bits.bitStatus.interior) << std::endl;                    

    return;
}