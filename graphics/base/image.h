#ifndef IMAGE_H
#define IMAGE_H
#include "rgb.h"

class image
{
public:
    image(int width,int height);
private:
    int width   ;
    int height  ;
    RGB *data   ;
};

#endif // IMAGE_H
