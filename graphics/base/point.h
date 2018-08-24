#ifndef POINT_H
#define POINT_H
#include <iostream>
struct point3{
    float x;
    float y;
    float z;
    point3(){}
    point3(float x,float y,float z):x(x),y(y),z(z){}
    point3(const point3&)=default;
    void print()
    {
        printf("(%f,%f,%f)",x,y,z);
    }
};
struct point2{
    float x;
    float y;
    point2(){}
    point2(float x,float y):x(x),y(y){}
    point2(const point2&)=default;
};
#endif // POINT_H
