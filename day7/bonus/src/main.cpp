/*
Use libpcap to open a network dump file and print the Ethernet header

Hint : Use tcpdump to dump one packet. Then open the file using libpcap APIs.
*/
#include <pcap.h>
#include "include.h"

int main(){
    
    pcap_file_header fheader;
    char error_buffer[PCAP_ERRBUF_SIZE];

    pcap_t *handle = pcap_open_offline("../tcp/dump", error_buffer);

    return 0;
}