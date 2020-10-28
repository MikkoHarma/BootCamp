/*
Write a function template which receives two of any shapes from yesterday’s assignment,
 compares them, and prints out the result.
*/

#include "include.h"
#include "templates.h"

int main(){

    Shape *circ1 = new Circle(5);     Shape *circ2 =  new Circle(100);
    Shape *triang1 = new Triangle(5,6);    Shape *triang2 = new Triangle(6,5);
    Shape *rectangle1 = new Rectangle(23,1);    Shape *rectangle2 = new Rectangle(2,1);

    std::cout << "Compare graeter:" << compareGreater(1,2) << std::endl;
    std::cout << "Compare graeter:" << compareGreater(4,2) << std::endl;  
    std::cout << "Compare graeter:" << compareGreater('a','b') << std::endl;
    std::cout << "Compare graeter:" << compareGreater('b','a') << std::endl;  
    std::cout << "Compare graeter:" << compareGreater(circ1, circ2) << std::endl;
    std::cout << "Compare graeter:" << compareGreater(circ2, circ1) << std::endl;   
    std::cout << "Compare graeter:" << compareGreater(rectangle1, rectangle2) << std::endl;
    std::cout << "Compare graeter:" << compareGreater(rectangle2, rectangle1) << std::endl;     

    std::cout << "Compare Equal:" << compareEqual(2,2) << std::endl;
    std::cout << "Compare Equal:" << compareEqual(4,2) << std::endl;  
    std::cout << "Compare Equal:" << compareEqual('a','b') << std::endl;
    std::cout << "Compare Equal:" << compareEqual('b','b') << std::endl;  
    std::cout << "Compare Equal:" << compareEqual(circ1, circ2) << std::endl;
    std::cout << "Compare Equal:" << compareEqual(circ2, circ1) << std::endl;   
    std::cout << "Compare Equal:" << compareEqual(rectangle1, rectangle1) << std::endl;
    std::cout << "Compare Equal:" << compareEqual(rectangle2, rectangle1) << std::endl;  

    std::cout << "Compare Less:" << compareLess(rectangle1, rectangle2) << std::endl;
    std::cout << "Compare Less:" << compareLess(rectangle2, rectangle1) << std::endl;            

    delete circ1, circ2, triang1, triang2, rectangle1, rectangle2; //clean up

    return 0;
}