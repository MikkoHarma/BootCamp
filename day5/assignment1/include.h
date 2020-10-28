#ifndef _INCLUDE_H_
#define _INCLUDE_H_
#include <iostream>
//Copy from Slack slightly modified

class Shape {
public:
    Shape() = default;
    Shape(const int &_p, const int &_a):Perimiter(_p),Area(_a){}
    virtual ~Shape() = 0;
    bool operator <(const Shape &s);  //"used" by template
    bool operator >(const Shape &s);    //"used" by template
    bool operator ==(const Shape &s); //"used" by template
    void print() {
        std::cout << Perimiter << " " << Area << std::endl;
    }
private:
    int Perimiter = 0, Area = 0;
};

class Circle : public Shape {
public:
    ~Circle() = default;
    Circle(const int &radius):Shape((2*radius*3),(radius*radius,2)){}
};

class Rectangle : public Shape {
  public:
    ~Rectangle() = default;
    Rectangle(const int &height,const int &width):Shape((2*height)+(2*width),(height*width)){}
};

class Triangle : public Shape {
  public:
    ~Triangle() = default;
    Triangle(const int &width,const int &height):Shape(3*width,height*width/2){}
};

#endif // _INCLUDE_H_