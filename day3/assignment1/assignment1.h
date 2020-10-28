#include <iostream>
#include "supportclasses.h"

enum CarPart {None, Tire, Oil, Washerfluid};
enum ServiceType {NoService, Tuning, Maintenance, Others};
enum PaymentType {Free, Cash, Card, Other};

class serviceRecord {
    public:
        //serviceRecord(std::string name, std::string date, float amount):customerName(name),serviceDate(date),paymentAmount(amount){}; //initialize default values
        serviceRecord(std::string name, std::string date, float amount);        
        void setCustomerName(std::string name);
        void setServiceDate(std::string date);
        void setPartType(CarPart parttype);
        void setServiceType(ServiceType servtype);
        void setPaymentType(PaymentType paytype);
        void setPaymentAmount(int value);
        void setEmpty(){ this-> isEmpty = true; };
        bool getEmpty(){ return isEmpty; };
        std::string getCustomerName();
        std::string getServiceDate();
        CarPart getPartType();
        ServiceType getServiceType();
        PaymentType getPaymentType();
        float getPaymentAmount();  
        Date date; //composition not used test only
        Parts parts; // composition 
        ~serviceRecord(){}      
    private:
        bool isEmpty = true;
        std::string customerName = "";
        std::string serviceDate = "";
        ServiceType servicePerformed = ServiceType::NoService; 
        CarPart partsChanged = CarPart::None;
        float paymentAmount = 0.0;
        PaymentType paymentMethod = PaymentType::Free;
};