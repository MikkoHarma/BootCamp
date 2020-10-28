/*
Generate random numbers between 0-33, ten thousand times, then print how 
many duplicates of each number you have generated -- print in ascending order

Hint: results should be stored in ascending order in your container
*/
#include <iostream>
#include <map>
#include <time.h>
#include <vector>

int main(){

    srand(time(NULL)); 
    std::vector<int> vs(34); //source vector to store occurances
    std::multimap<int,int> vr; //destination map for sorting  

    for(int i = 0; i < 10000; i++) //generate 10000 values on add to index position corresponding to value
        vs[rand()%34]++;

    for(int i = 0; i < 34; i++) //insert occuranses as key (gets sorted by key) into destination multimap together with value 
        vr.insert(std::pair<int,int>(vs[i], i));  

    for(auto i: vr) //print sorted multimap
        std::cout << "Occurance: " << i.first << ", Value: " << i.second << " " << std::endl;

    return 0;
}