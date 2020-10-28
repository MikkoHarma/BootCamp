#include "include.h"

bool Shape::operator>(Shape& sh)
{
    return (this->area() > sh.area());
}

bool Shape::operator<(Shape& sh)
{
    return (this->area() < sh.area());
}

bool Shape::operator==(Shape& sh)
{
    return ((this->area() == sh.area()) && (this->perimeter() == sh.perimeter()));
}   

void Shape::printArea(int area, int child)
{
    switch(child)
    {
        case 0:
            std::cout << "Rect:";
            break;
        case 1:
            std::cout << "Circle:";
            break;
        case 2:
            std::cout << "Triangle:";
            break;
        case 3:
            std::cout << "Square:";
            break;
        default:
            std::cout << "No shape:";
    }
    std::cout << " Area:" << area << std::endl; 
    return;
}
Shape::~Shape()
{
    
};