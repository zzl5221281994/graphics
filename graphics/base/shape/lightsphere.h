#ifndef LIGHTSPHERE_H
#define LIGHTSPHERE_H
#include "sphere.h"
#include "../ray.h"
#include <vector>

class lightSphere:public sphere
{
public:
    lightSphere(const point3 &position,float radius):sphere(position,radius){}
    virtual bool isLightObject(){return true;}
private:
};

#endif // LIGHTSPHERE_H
