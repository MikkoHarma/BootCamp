#include "include.h"
#include "pcapOpenner.h"

int main(){

    pcapOpenner pcap;
    _pcap_packet packet;
    
    (pcap.initPCAP("../data/dump")) == true ? std::cout << "Initialized: ok" << std::endl : std::cout << "Initialization failed" << std::endl;

    packet = pcap.getPacket();

    std::cout << "Packet size: " << packet.data_len << std::endl;

    return 0;
}