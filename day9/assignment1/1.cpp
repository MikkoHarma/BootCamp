/*
In the course demo repository, there is a file under Day 9 /Assignment folder called 1.cpp –
fix its issues
*/
#include <iostream>

const size_t SIZE = 10;

int function() {
    return std::rand();
}
int *fillArray(int a[SIZE]) { // pass pointer to array
    //int a[SIZE];   declared in main
    size_t i = SIZE;// YOU ARE NOT SUPPOSE TO CHANGE THIS  
    for (; i > 0; --i) {          //ADDED  comparison > 0 to remove comparison of unsigned long with -1 (signed)
        a[i-1] = function();       //ADDED -1 to match with array 0-9
    }
    return a;    
}
void printArray(int a[SIZE]) {        //same as (int *a)
    for (size_t i = 0; i < SIZE; i++) {
        std::cout << *(a+i) << std::endl; //missing  * has presedence
    }    
}
void printBool (bool _b) {
    if (_b == true) {       //changed to comparison operator = -> ==
        std::cout << "VALUE is TRUE" << std::endl;        
    } else if (_b == false)    {            //changed to comparison oprator = -> ==
        std::cout << "VALUE is FALSE" << std::endl;        
    }    
}
// YOU ARE NOT ALLOWED TO CHANGE THE RETURN TYPE
void resizeForMe(char *&a, size_t _newSize) { //*&a a is a reference to a char pointer
    delete [] a;  //[] for deleteing array
    a = new char[_newSize];
}

int main() {
    
    int b[SIZE]; //new array variable

    printArray( fillArray(b) ); //pass new variable

    printBool(false);

    char *a = new char[SIZE];        
    for (size_t i = 0; i<SIZE; i++) i%2 ? a[i] = 'A' : a[i] = 'D';    
    std::cout << "Array: " << a << std::endl; //to print size of array change to content of array

    resizeForMe(a,100);
    for (size_t i = 0; i<100; i++) i%2 ? a[i] = 'B' : a[i] = 'C'; //wrong array fill size 1000 -> 1000

    std::cout << "Array: " << a << std::endl; //to print size of array change to content of array

    delete [] a; //delte resized array

    return 0;
}