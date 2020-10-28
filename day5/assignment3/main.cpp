/*
We want to generate 1024 random integers, then given a new random number;
find two integers which are the closest to the given number (smaller, and bigger)
with less than twelve lookups

Create a sorted container and populate it, then pick a random integer and look for
the boundaries – implement your own logarithmic search if you are in the mood for it
*/

#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
    int start = 1024;
    std::vector<int> v(start);  //define vector 1024 elems  
    int searchIndex = start / 2;
    int searchBit = start / 2;
    int x = 0;
    srand(time(NULL));       
    int searchNumber = rand(); //generate random number

    for(int i=0;i < v.size(); i++) //init array
        v[i] = rand();
 
    while(x != 1024){ // sort array
        if(v[x+1] < v[x]){ //acsending
            int c = v[x];
            v[x] = v[x+1];
            v[x+1] = c;
            x = 0;
        }
        else 
            x++;
    }

    for(int x = 0; x < 10; x++){ //binary search
        if (v[searchIndex] != searchNumber) {
            if (v[searchIndex] < searchNumber) {   
                searchIndex = searchIndex + (searchBit >> (x+1));
            }
            else {
                searchIndex = searchIndex - (searchBit >> (x+1));
            } 
        }
        else
            break;
        std::cout << std::setw(4) << " X: " << searchIndex << " "; //print search position (debug)
    }

    //print all values (debug)
    /*x = 0;
    for(auto i : v){
        std::cout << std::setw(3) << x << " : " << i << std::endl;
        x++;
    } */

    std::cout << std::endl << "Number to search: " << searchNumber << std::endl;

    if(v[searchIndex] > searchNumber){ //print min max boundaries
        std::cout << std::setw(3) << "Min: " << v[searchIndex-1] << std::endl;       
        std::cout << std::setw(3) << "Max: " << v[searchIndex] << std::endl; 
    }
    else {
        std::cout << std::setw(3) << "Min:" << v[searchIndex] << std::endl;
        std::cout << std::setw(3) << "Max:" << v[searchIndex+1] << std::endl;       
    }
    return 0;
}