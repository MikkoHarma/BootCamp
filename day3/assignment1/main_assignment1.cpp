#include "assignment1.h"

    void printRecord(serviceRecord* ); //print one item
    void printRecordList(serviceRecord** ); //print complete list
    int createRecord(std::string name, std::string date, float amount, serviceRecord** ); //create one entry
    void deleteRecord(serviceRecord*);
    int listSize = 10; //list size
    int currency = 2.1; //currency modifier

int main()
{
    //new list
    serviceRecord** serviceRecordList = new serviceRecord*[listSize];
    //initialize list
    for (int x=0 ; x < listSize; x++)
        serviceRecordList[x] = nullptr;

    //create some records
    for(int x = 0; x < listSize; x++)
        createRecord("Test person","2020-10-21", x, serviceRecordList);
    
    //print created records
    printRecordList(serviceRecordList);
    //modify some data
    serviceRecordList[1]->setServiceType(ServiceType::Maintenance);     
    serviceRecordList[1]->setPaymentType(PaymentType::Cash);
    //serviceRecordList[5]->setPaymentType(PaymentType::Cash);
    //print modified record
    printRecord(serviceRecordList[1]);
    //delete some records (fake not possible to delete object in array??)
    deleteRecord(serviceRecordList[3]);
    deleteRecord(serviceRecordList[5]);

    printRecordList(serviceRecordList);

    //clean up array + objects
    for(int x=0; x < listSize; x++)
        delete serviceRecordList[x];

    delete serviceRecordList;

    return 0;   
}

void printRecord(serviceRecord *recordToPrint) // print one record item
{
    if(recordToPrint != nullptr)
    {
        if(!recordToPrint->getEmpty())
        {
            std::cout << "-Record print------------------------------" << std::endl;     
            std::cout << "Name: " << recordToPrint->getCustomerName() << std::endl;
            std::cout << "Date: " << recordToPrint->getServiceDate() << std::endl;
            std::cout << "Service Type: " << recordToPrint->getServiceType() << std::endl;
            std::cout << "Parts: " << recordToPrint->getPartType() << std::endl;
            std::cout << "Part desc: " << recordToPrint->parts.getPartDescription() << std::endl;    
            std::cout << "Part price: " << recordToPrint->parts.getPartPrice(currency) << std::endl;
            std::cout << "Payment method: " << recordToPrint->getPaymentType() << std::endl;    
            std::cout << "Total amount: " << recordToPrint->getPaymentAmount() << std::endl; 
            std::cout << "-End print---------------------------------" << std::endl;
        }
        else
        {
            std::cout << "Deleted record" << std::endl;
        }
    }
    else
        std::cout << "Empty record" << std::endl;
    return; 
}
void printRecordList(serviceRecord **listToPrint) //print all records
{
    std::cout << "-List print--------------------------------" << std::endl;
    for(int x = 0; x < listSize ;x++)
    {
        std::cout << "-------------------------------------------" << std::endl; 
        if(listToPrint[x] != nullptr)
        {
            if(!listToPrint[x]->getEmpty())
            {
                std::cout << "Name: " << listToPrint[x]->getCustomerName() << std::endl;
                std::cout << "Date: " << listToPrint[x]->getServiceDate() << std::endl;
                std::cout << "Service Type: " << listToPrint[x]->getServiceType() << std::endl;
                std::cout << "Parts: " << listToPrint[x]->getPartType() << std::endl;
                std::cout << "Part desc: " << listToPrint[x]->parts.getPartDescription() << std::endl;
                std::cout << "Part price: " << listToPrint[x]->parts.getPartPrice(currency) << std::endl;        
                std::cout << "Payment method: " << listToPrint[x]->getPaymentType() << std::endl;    
                std::cout << "Total amount: " << listToPrint[x]->getPaymentAmount() << std::endl;  
            } 
            else
            {
                std::cout << "Deleted record" << std::endl;
            }
            
        }
        else
            std::cout << "Empty record" << std::endl;
    }
    std::cout << "-End print---------------------------------" << std::endl;
    return;
}

int createRecord(std::string name, std::string date, float amount, serviceRecord **recordList) // create service records
{
    for(int z=0; z < listSize; z++) //next available slot
    {
        if(recordList[z] == nullptr)
        {
            serviceRecord *newrecord = new serviceRecord(name, date, amount);
            recordList[z] = newrecord;
            std::cout << "Record created " << newrecord << std::endl;
            return 1;
        }
    }
    return 0;
}

void deleteRecord(serviceRecord *recordList) //set to Empty
{
    recordList->setEmpty();
    std::cout << "Record deleted" << std::endl;
    return;
}