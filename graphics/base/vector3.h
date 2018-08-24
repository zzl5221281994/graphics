#ifndef VECTOR3_H
#define VECTOR3_H
#include <functional>
#include "point.h"

class vector3
{
public:
    vector3();
    vector3(float x,float y,float z,const point3&direction,float length);
    vector3(const point3&p,const point3 &direction,float length):
        vector3(p.x,p.y,p.z,direction,length){}


    point3 getOriginPoint()const{return this->originPoint;}
    point3 getNormalDirection()const {return this->normalDirection;}

private:
    void normalizeDirection();
//    vector3(const vector3 &v);
//    vector3& operator=(const vector3 &v);

//    vector3  operator+(const vector3 &v);//
//    vector3  operator-(const vector3 &v);//
//    vector3  operator/(const vector3 &v);//
//    vector3  operator*(const float  &k);//标量乘法
//    float   operator*(const vector3 &v);//点积
//    float&  operator[](int pos        );
//    vector3  crossProduct(const vector3 &v);
private:
    float len;
    point3 originPoint;
    point3 direction;
    point3 normalDirection;
};

#endif // VECTOR3_H
