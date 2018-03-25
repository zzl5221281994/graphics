#ifndef IMAGE_H
#define IMAGE_H
#include "rgb.h"
#include "include.h"
class image
{
public:
    image(int width,int height);


    int width   ;
    int height  ;
    std::vector<unsigned char> data;
};


#endif // IMAGE_H
