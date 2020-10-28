#ifndef _INCLUDE_H_
#define _INCLUDE_H_
#include <iostream>
#include <vector>

struct storagePacket {
    uint32_t timestamp = 0;
    uint32_t data = 0;
};

struct pointers {
    uint16_t readptr = 0;
    uint16_t writeptr = 0;
    bool wraparound = false;
};

uint16_t readItem(pointers&, std::vector<storagePacket>&);
uint16_t writeItem(pointers&, std::vector<storagePacket>&);

#endif