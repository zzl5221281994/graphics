#ifndef GRAPHIC_ALGORITHM_H
#define GRAPHIC_ALGORITHM_H
#include "include.h"
#include "image.h"
inline void drawPixel(image &img,uint32_t x,uint32_t y,const RGB &c);
void drawLine (image &img,uint32_t x0,uint32_t y0,uint32_t x1,uint32_t y1,const RGB &c);


#endif // GRAPHIC_ALGORITHM_H
