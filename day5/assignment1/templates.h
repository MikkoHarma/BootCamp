#ifndef _TEMPLATES_H_
#define _TEMPLATES_H_
//Mine

template <typename A> bool compareGreater(const A &a, const A &b) //generic template typename A, return boolean, takes two input parameters
{
    bool result  = false;

    if (a > b)
        result = true;

    return result;
}

template <typename A> bool compareEqual(const A &a, const A &b)
{
    bool result = false;

    if (a == b)
        result = true;
    
    return result;
}

template <typename A> bool compareLess(const A &a, const A &b)
{
    bool result = false;

    if (a < b)
        result = true;
    
    return result;
}

#endif