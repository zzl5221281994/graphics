#ifndef RGB_H
#define RGB_H


class RGB
{
public:
    RGB();
    RGB(const unsigned char &r,const unsigned char &g,const unsigned char &b);
    RGB(const RGB &c);
    RGB& operator=(const RGB &c);

    RGB  operator +(const RGB &c);
    RGB  operator -(const RGB &c);
    RGB  operator *(const double &k);


    unsigned char r;
    unsigned char g;
    unsigned char b;
};

#endif // RGB_H
