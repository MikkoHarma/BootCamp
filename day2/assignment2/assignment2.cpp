//linked list
#include <iostream>
#include <string>

struct listItem //declare
{
    int id;
    int data;
    listItem *NextItem;
};
    void printlist(listItem *firstentry);
    void addnewitem(listItem *firstentry, int data);
    listItem* removeitem(listItem *firstentry);
    listItem* lastentry(listItem *firstentry);

int main(int argc ,char* argv[]){

    int numberOfItems = 5; //number items to initialize
    int addentries = 0, removeentries = 0;
    listItem *listheader;
    listItem *nextitem;
    listItem *previtem;

    for(int x = 0; x < numberOfItems; x++) //initialize list
    {
        listItem *newlist = new listItem; //create new item
    
        if(x == 0)
            listheader = newlist;  //store header
        
        newlist->id = x; //store id
        newlist->data = rand() % 10000; //store some data

        if(x == (numberOfItems - 1))
            newlist->NextItem = nullptr; //if last item , next item ptr null
        
        if (x > 0) 
            previtem->NextItem = newlist; // store previous item

        previtem = newlist; // update new link in previous item
    }
    
    printlist(listheader); // print after init

    std::cout << "Number of added entries" << std::endl;
    std::cin >> addentries;

    for(int z = 0; z < addentries; z++)
    {
        addnewitem(listheader, rand() % 10000); // add three new items
        printlist(listheader);      
    }

    std::cout << "Number of removed entries" << std::endl;
    std::cin >> removeentries;    

    for(int z = 0; z < removeentries; z++)
    {
        listheader = removeitem(listheader); // remove to items
        printlist(listheader);      
    }

    std::cout << "Last Entry" << lastentry(listheader) << std::endl;

    return 0;
}

void printlist(listItem *listheader)
{
    std::cout << "Header:" << listheader << std::endl << std::endl;

    for(;;)
    {
        std::cout << "Item id:" << listheader->id << std::endl;
        std::cout << "Item data:" << listheader->data << std::endl;
        std::cout << "Item nextlink:" << listheader->NextItem << std::endl;
        std::cout << "----------------------------" << std::endl;
        
        if(listheader->NextItem == nullptr)
            break;

        listheader = listheader->NextItem;
    }
}
void addnewitem(listItem *listheader, int data)
{
    listheader = lastentry(listheader);

    listItem *newitem = new listItem; //create new item
       
    newitem->id = listheader->id+1; //store id
    newitem->data = data; //store some data
    newitem->NextItem = nullptr; //new last item
        
    listheader->NextItem = newitem; //update previou last item
}

listItem* removeitem(listItem *listheader) //remove item from end
{
    listItem *removeditem;

    removeditem = listheader->NextItem;

    delete listheader; // clean upp item

    return removeditem; 
}

listItem* lastentry(listItem *lastentry)
{
    for(;;) //find last entry
    {
        if(lastentry->NextItem == nullptr)
            break;    
        
        lastentry = lastentry->NextItem;
    }

    return lastentry; 
}