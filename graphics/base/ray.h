#ifndef RAY_H
#define RAY_H
#include "vector3.h"
#include "color.h"

namespace RTL {
class ray:public vector3
{
public:
    ray(float x,float y,float z,const point3&direction,float length):vector3(x,y,z,direction,length)
    {
        intensity=1.0;
        decayRate=0.1;
        c=RTL::color(0xff,0xff,0xff,0xff);

    }
    void setIntensity(float inten)
    {
        intensity=inten;
    }
    void setDecayRate(float decay)
    {
        decayRate=decay;
    }

    point3 getPoint(float t)const
    {
        point3 originPoint=getOriginPoint();
        point3 normal=getNormalDirection();
        return point3(originPoint.x+normal.x*t,
                      originPoint.y+normal.y*t,
                      originPoint.z+normal.z*t);
    }
    float getIntensity()const {return intensity;}
    float getDecayRate()const {return decayRate;}
private:
    float decayRate;
    float intensity;
    RTL::color c;
};
}

#endif // RAY_H
