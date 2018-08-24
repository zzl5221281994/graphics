#ifndef SPHERE_H
#define SPHERE_H
#include "object.h"

class sphere:public object
{
public:
    sphere(const point3&position,float radius):radius(radius),object(position)
    {

    }
    virtual float SDF(const vector3 &vec);
    virtual bool hitable(const vector3 &vec);
    virtual bool isLightObject(){return false;}
    float getRadius()const{return this->radius;}
private:
    float radius;
};

#endif // SPHERE_H
