#ifndef OBJECT_H
#define OBJECT_H
#include "../vector3.h"
#include "../ray.h"

class object
{
public:
    object(point3 position):position(position){}
    virtual ~object();
    virtual float SDF(const RTL::ray &vec)=0;
    virtual RTL::ray reflaction(const RTL::ray &vec)=0;
    virtual RTL::ray reflection(const RTL::ray &vec)=0;
    virtual bool    hitable(const RTL::ray &vec,point3&hit)=0;
    virtual bool    isLightObject()=0;
    point3 getPosition()const{return this->position;}
protected:
    point3 position;
};

#endif // OBJECT_H
