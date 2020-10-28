#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>

int main(){

    int x = 0; int y = 0;
    std::vector<std::vector<int>> v(34,std::vector<int> (2, 0)); //initialize vecto 34 cols, 2 rows
    srand(time(NULL));

    for(int i=0;i < v.size(); i++)
        v[i][0] = i;

    for(int i = 0; i < 10000; i++)
        v[rand()%34][1]++;
 
    while(x < 33){
        
        if(v[x+1][1] > v[x][1])
        {
            int c = v[x][1];
            int r = v[x][0];
            v[x][1] = v[x+1][1];
            v[x][0] = v[x+1][0];
            v[x+1][1] = c;
            v[x+1][0] = r;
            x = 0;
        }
        else 
            x++;

        y++;
    }
    std::cout << y << std::endl;
    
    //print
    for(int i=0;i < v.size(); i++ ) //header
        std::cout << std::setw(3) << (v[i][0]) << " ";  

    std::cout << std::endl;
    
    for(int i=0;i < v.size(); i++ ) //values occurance
        std::cout << std::setw(3) << (v[i][1]) << " ";  

    std::cout << std::endl;
}