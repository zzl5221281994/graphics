#ifndef IMAGE_H
#define IMAGE_H
#include "rgb.h"
#include "include.h"
class image
{
public:
    image(int width,int height);
    inline void drawPixel(uint32_t x,uint32_t y,const RGB &c);
    inline void drawLine (uint32_t x0,uint32_t y0,uint32_t x1,uint32_t y1,const RGB &c);

    int width   ;
    int height  ;
    std::vector<unsigned char> data;
};

inline void image::drawPixel(uint32_t x, uint32_t y, const RGB &c)
{
    uint32_t startPos=3*(width*y+x);
    this->data[startPos]    =c.r;
    this->data[startPos+1]  =c.g;
    this->data[startPos+2]  =c.b;
}
inline void image::drawLine(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, const RGB &c)
{

}


#endif // IMAGE_H
