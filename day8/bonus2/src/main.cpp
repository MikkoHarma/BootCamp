#include "include.h"
#include "pcapOpenner.h"
#include <iomanip>

int main(){

    pcapOpenner pcap;
    _pcap_packet packet;
    
    (pcap.initPCAP("../data/dump")) == true ? std::cout << "Initialized: ok" << std::endl : std::cout << "Initialization failed" << std::endl;

    packet = pcap.getPacket();

    std::cout << "Packet size: " << packet.data_len << std::endl;
    std::cout << "MAC destination address: ";    
    for(int i = 0; i < 6; i++){
         std::cout << std::setfill('0') << std::setw(2) << std::hex <<(int)(packet.data[i]);   
         i < 5 ? std::cout << ":" : std::cout << "";
    }
    std::cout << std::endl;  

    std::cout << "MAC source address: ";    
    for(int i = 6; i < 12; i++){
         std::cout << std::setfill('0') << std::setw(2) << std::hex <<(int)(packet.data[i]);   
         i < 11 ? std::cout << ":" : std::cout << "";
    }
    std::cout << std::endl;        
    
    std::cout << "Ether Type: " << std::setfill('0') << std::setw(2) << std::hex << (int)(packet.data[12]) << " " 
        << std::setfill('0') << std::setw(2) << std::hex << (int)(packet.data[13]) << std::endl; 

    return 0;
}