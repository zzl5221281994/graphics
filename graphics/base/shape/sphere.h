#ifndef SPHERE_H
#define SPHERE_H
#include "object.h"

class sphere:public object
{
public:
    sphere(const point3&position,float radius);
    virtual float SDF(const RTL::ray &vec);
    virtual bool hitable(const RTL::ray &vec,point3&hit);
    virtual bool isLightObject();
    virtual RTL::ray reflaction(const RTL::ray &vec);
    virtual RTL::ray reflection(const RTL::ray &vec);
    float getRadius()const;
private:
    float radius;
};

#endif // SPHERE_H
