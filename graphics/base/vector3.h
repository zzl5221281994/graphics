#ifndef VECTOR3_H
#define VECTOR3_H


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
    double pos[3];//v1,v2,v3
};

#endif // VECTOR3_H
