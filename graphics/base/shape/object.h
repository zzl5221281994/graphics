#ifndef OBJECT_H
#define OBJECT_H
#include "../vector3.h"

class object
{
public:
    object(point3 position):position(position){}
    virtual ~object();
    virtual float SDF(const vector3 &vec)=0;
    virtual vector3 reflaction(const vector3 &vec)=0;
    virtual vector3 reflection(const vector3 &vec)=0;
    virtual bool    hitable(const vector3 &vec)=0;
    virtual bool    isLightObject()=0;
    point3 getPosition()const{return this->position;}
protected:
    point3 position;
};

#endif // OBJECT_H
