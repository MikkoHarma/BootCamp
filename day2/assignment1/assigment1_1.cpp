#include <iostream>
#include <string>

int main()
{
    int *dim1 = nullptr;
    int **dim2 = nullptr;
    int ***dim3 = nullptr;

    dim3 = new int**[4]; // no user input but dynamic ran out of time

    for(int y = 0; y < 4; y++){ //create array (allocate memory)
    
        dim2 = new int*[3];  
        *(dim3 + y) = dim2;
    
        for(int y = 0; y < 3; y++){
            int *dim1 = new int[3];   
            *(dim2 + y) = dim1;
        }
    }

    for(int y = 0; y < 4; y++){ //assign values

        dim2 = dim3[y];
        for(int y = 0; y < 3; y++){
            dim1 = *(dim2 + y);

            for(int y = 0; y < 3; y++){
                *(dim1+y) = rand() % 10;
            }
        }
    }

    for(int y = 0; y < 4; y++){ //print values

        dim2 = *(dim3 + y);
        std::cout << "Array{"<< y <<"}" << std::endl;
        for(int y = 0; y < 3; y++){

            dim1 = *(dim2 + y);
            std::cout << "{ ";
            for(int y = 0; y < 3; y++){
                std::cout << *(dim1 + y);
                if(y != 2 )
                    std::cout << ", ";
            }
            std::cout << " }";
        }
        std::cout << std::endl;
    }     
    std::cout <<std::endl;

    //do some delete, ran out of time
}