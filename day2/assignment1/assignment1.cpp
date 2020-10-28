#include <iostream>
#include <string>

int main(int argc ,char* argv[])
{
    int user_input, arraysize1, arraysize2, arraysize3;

    std::cout << "Input array1 size 1-15:" << std::endl;
    std::cin >> arraysize1;

    std::cout << "Input array2 size 1-15:" << std::endl;
    std::cin >> arraysize2;

    std::cout << "Input array3 size 1-15:" << std::endl;
    std::cin >> arraysize3; 

    int ***number_array1 = new int**[arraysize1]; // { 0,0,0,0,} - pointer to array of pointers holding pointer to array of int pointers
    int **number_array2 = new int*[arraysize2];   // {         } - pointer to array of int pointers
    int *number_array3 = new int[arraysize3];     // { 0,0,0,0,} - pointer to array of ints

    if (arraysize1 < 1 && arraysize2 < 1 && arraysize3 < 1)  
        return 2;    
    if (arraysize1 > 15 && arraysize2 >15 && arraysize3 > 15) 
        return 3;

    std::cout << "Input a positive number:" << std::endl;
    std::cin >> user_input;

    if(user_input > 0 && user_input <= 65335) //check value range
    {
        for(int a = 0; a < arraysize1; a++)
        {   
            for (int aa = 0; aa < arraysize2; aa++)
            {
                for(int aaa = 0; aaa < arraysize3; aaa++)
                {
                     number_array3[aaa] = rand() % user_input;
                }
            }
        }

        for(int b = 0; b < arraysize1; b++)
        {
            std::cout << std::endl << "Array : " << "{" << b << "}" << std::endl;

            for(int bb = 0; bb < arraysize2; bb++)
            {   
                std::cout << "{";
                for(int bbb = 0; bbb < arraysize3;  bbb++)
                {
                    //std::cout << "[" << number_array[b][bb][bbb] << "]"; 
                    std::cout << "[" << *(number_array3 + bbb) << "]"; 

                }
                std::cout << "}, " << std::endl;
            }

        }
        
    }
    else
    {
        std::cout << "Number out of range (0-65335): " << user_input << std::endl;    
    }

    //clean up
    delete [] number_array1;
    delete [] number_array2;
    delete [] number_array3;
    
    return 1;
}