#include "include.h"

int main() {

    Shape **shapeptr; // create pointer to instance pointer of type shape
    shapeptr = new Shape*[4]; //create array of empty shape pointers

    shapeptr[0] = new Rectangle; //create new intance and assing address to instance array slot X
    shapeptr[1] = new Circle;
    shapeptr[2] = new Triangle;
    shapeptr[3] = new Square;

    for(int x = 0; x < 4; x++)
    {
        shapeptr[x]->setSize(2,3); //some size
        shapeptr[x]->printArea(shapeptr[x]->area(), x); //print object area
        shapeptr[x]->printPerimeter(shapeptr[x]->perimeter()); // print object perimeter
    }

    // example test to find equal shapes
    if((*shapeptr[0] == *shapeptr[1])) //need comparison between two same type of object 
        std::cout << "Rect == Cirle" << std::endl;
    if((*shapeptr[0] == *shapeptr[2]))
        std::cout << "Rect == Triangle" << std::endl;  
    if((*shapeptr[0] == *shapeptr[3]))
        std::cout << "Rect == Square" << std::endl;     
    if((*shapeptr[1] == *shapeptr[2]))
        std::cout << "Circle == Triangle" << std::endl;  
    if((*shapeptr[1] == *shapeptr[3]))
        std::cout << "Circle == Square" << std::endl; 
    if((*shapeptr[2] == *shapeptr[3]))
        std::cout << "Triangle == Square" << std::endl;       
    //Smaller bigger etc..
    if((*shapeptr[0] < *shapeptr[1]))
        std::cout << "Rectangle < Circle" << std::endl;           
    if((*shapeptr[0] > *shapeptr[1]))
        std::cout << "Rectangle > Circle" << std::endl;  

    //clean up
    for(int x = 0; x < 4; x++)
        delete shapeptr[x]; //array
    delete shapeptr; // pointer

    return 0;
}