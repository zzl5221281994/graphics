#ifndef VECTOR2_H
#define VECTOR2_H


class vector2
{
public:
    vector2();
    vector2(const double &x,const double &y);
    vector2(const vector2 &v);
    vector2& operator=(const vector2 &v);

    vector2  operator+(const vector2 &v);//
    vector2  operator-(const vector2 &v);//
    vector2  operator/(const vector2 &v);//
    vector2  operator*(const double  &k);//标量乘法
    double   operator*(const vector2 &v);//点积
    double&  operator[](int pos        );//
    vector2  crossProduct(const vector2 &v);
private:
    double pos[2];//v1,v2
};

#endif // VECTOR2_H
