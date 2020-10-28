//Implement ring buffer 
//some bugs remaining in buffer access/wraparound

#include <time.h>
#include "include.h"
#include <chrono>
#include <thread>
#include <iomanip>

int main(){

    uint16_t bufferSize = 50;
    std::vector<storagePacket> ringBuffer(bufferSize);
    storagePacket packet;
    pointers ptr;
    uint16_t selector = 0;

    while(1){

        selector = rand() % 4; //randomize read/write access and frequency

        switch (selector)
        {
            case 0: //write twice the the read rate (buffer will be full at some point)
            case 1:
                if(!writeItem(ptr, ringBuffer))
                {
                    std::cout << "Buffer full" << std::endl;
                } 
                break;
            //case 0: //read twice the the write rate (buffer will be empty at some point)
            case 2:
                if(!readItem(ptr, ringBuffer)){
                    std::cout << "Nothing to read" << std::endl;
                }
                break;
            default:
                std::this_thread::sleep_for(std::chrono::milliseconds(200)); //randomized read/write update rate 
                break;
        }
    }
    return 0;
}
//read item from buffer
//input pointer package and buffer address
//output ok/no data
uint16_t readItem(pointers& _ptr, std::vector<storagePacket>& ringBuffer){

    int result;
    if(_ptr.readptr < _ptr.writeptr || _ptr.wraparound == true) { //check if data available (readptr less than write or write wrap around)
        std::cout << "Read  pointer: " << std::setfill('0') << std::setw(3) << _ptr.readptr << " Time: " << ringBuffer[_ptr.readptr].timestamp << " Data: " << std::setw(10) << ringBuffer[_ptr.readptr].data << std::endl;
        if(_ptr.readptr < ringBuffer.size())
            _ptr.readptr++;
        else {
            _ptr.readptr = 0; 
            _ptr.wraparound = false;
        }
        result = 1;   //data read 
    }
    else {
        result = 0; //no data to read
    }
    return result;
}
//write item to buffer
//input pointer package and buffer address
//output ok/buffer full
uint16_t writeItem(pointers& _ptr, std::vector<storagePacket>& ringBuffer ){

    int result;
    if(_ptr.readptr - _ptr.writeptr != 1) //check if buffer full
    {
        //write some random data
        time_t myTime = time(NULL);
        ringBuffer[_ptr.writeptr].timestamp = myTime;
        ringBuffer[_ptr.writeptr].data = rand();        

        if(_ptr.writeptr < ringBuffer.size()) //wrap around to beginning
            _ptr.writeptr++;
        else
        {
            _ptr.writeptr = 0; 
            _ptr.wraparound = true;
        }
        result =  1; //ok

        std::cout << "Write pointer: " << std::setfill('0') << std::setw(3) << _ptr.writeptr << " Time: " << myTime << std::endl ;
    }
    else {
        result = 0;   //full 
    }
    
    return result;
}