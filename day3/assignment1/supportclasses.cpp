#include "assignment1.h"

float Parts::getPartPrice(float currency)
{
    return this->price * currency;
}

std::string Parts::getPartDescription()
{
    return this->description;
}