#ifndef _INCLUDE_H_
#define _INCLUDE_H_
#include <iostream>

class Shape {
    public:
        Shape(){};
        int height;
        int width;
        void setSize(int h, int w){ height = h; width = w; }; //std::cout << "W:" << width << " H:" << height << std::endl; }
        virtual int area() = 0;
        virtual int perimeter() = 0;
        
        void printArea(int area, int child);
        void printPerimeter(int perimeter){ std::cout << "Perimeter:" << perimeter << std::endl; return;}

        bool operator>(Shape& sh);
        bool operator<(Shape& sh);
        bool operator==(Shape& sh);      

        virtual ~Shape() = 0; //interface
};

class Circle : public Shape{
    public:
    int area(){ return width/2 * width/2 * 3; };
    int perimeter(){ return width * 3; };
};

class Rectangle : public Shape{
    public:
    int area (){ return width * height; };
    int perimeter(){ return (width * 2) + (height * 2); };
};

class Triangle : public Shape{
    public:
    int area (){ return (width * height) / 2; };
    int perimeter(){ return width * 3; };
};

class Square : public Shape{
    public:
    int area (){ return width * height; };
    int perimeter(){ return width * 4; };
};

#endif