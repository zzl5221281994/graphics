#ifndef VECTOR3_H
#define VECTOR3_H
#include "point.h"

class vector3
{
public:
    vector3();
    vector3(const double &x,const double &y,const double &z);
    vector3(const vector3 &v);
    vector3& operator=(const vector3 &v);

    vector3  operator+(const vector3 &v);//
    vector3  operator-(const vector3 &v);//
    vector3  operator/(const vector3 &v);//
    vector3  operator*(const double  &k);//标量乘法
    double   operator*(const vector3 &v);//点积
    double&  operator[](int pos        );
    vector3  crossProduct(const vector3 &v);
private:
    double len;
    point3 originPoint;
    point3 normalizeDirection;


};

#endif // VECTOR3_H
