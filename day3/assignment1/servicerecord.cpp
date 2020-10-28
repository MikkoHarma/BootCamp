#include "assignment1.h"

serviceRecord::serviceRecord(std::string name, std::string date, float amount) //construct with data
{
    this->customerName = name;
    this->serviceDate = date;
    this->paymentAmount = amount; 
    this->isEmpty = false;
    return;
}

std::string serviceRecord::getCustomerName()
{
    return this->customerName;
}

std::string serviceRecord::getServiceDate()
{
    return this->serviceDate;
}

float serviceRecord::getPaymentAmount()
{
    return this->paymentAmount;
}

enum ServiceType serviceRecord::getServiceType()
{
    return this->servicePerformed;
}

enum CarPart serviceRecord::getPartType()
{
    return this->partsChanged;
}

enum PaymentType serviceRecord::getPaymentType()
{
    return this->paymentMethod;
}

void serviceRecord::setServiceType(ServiceType servtype)
{
    servicePerformed = servtype;
    return;
}

void serviceRecord::setPartType(CarPart parts)
{
    partsChanged = parts;
    return;
}

void serviceRecord::setPaymentType(PaymentType paytype)
{
    paymentMethod = paytype;
    return;
}