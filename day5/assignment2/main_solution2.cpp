/*
Generate random numbers between 0-33, ten thousand times, then print how 
many duplicates of each number you have generated -- print in ascending order

Hint: results should be stored inascending order in your container
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>

struct pair{
    int key;
    int value;
};

int main(){

    int x = 0;
    srand(time(NULL));
    std::vector<pair> v(34); //vector with key, value

    for(int i=0;i < v.size(); i++) //init array with keys
        v[i].key = i;

    for(int i = 0; i < 10000; i++) //generate random numbers to each key value
        v[rand()%34].value++;
 
    while(x != 33) // sort array
    { 
        if(v[x+1].value < v[x].value) //acsending
        {
            pair c = v[x];
            v[x] = v[x+1];
            v[x+1] = c;
            x = 0;
        }
        else 
            x++;
    }
    //print
    for(auto i : v) //print header
        std::cout << std::setw(3) << i.key << " ";  

    std::cout << std::endl;

    for(auto i : v) //print values occurance
        std::cout << std::setw(3) << i.value << " ";  

    std::cout << std::endl;

    return 0;
}