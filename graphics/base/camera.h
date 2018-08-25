#ifndef CAMERA_H
#define CAMERA_H
#include "vector3.h"

class camera
{
public:
    camera(const point3&leftBottom,const point3&rightTop,const vector3&direction):
        leftBottom(leftBottom),rightTop(rightTop),direction(direction){}
    point3 getLeftBottom()const {return leftBottom;}
    point3 getRightTop()const {return rightTop;}
private:
    point3 leftBottom;
    point3 rightTop;
    vector3 direction;
    float width,height;
};

#endif // CAMERA_H
