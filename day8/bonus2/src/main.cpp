#include "include.h"
#include "pcapOpenner.h"

int main(){

    pcapOpenner pcap;

    std::cout << pcap.initPCAP("../data/dump") << std::endl;
    
    return 0;
}