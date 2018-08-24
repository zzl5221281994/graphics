#include "vector3.h"
#include <cmath>
vector3::vector3(float x, float y, float z, const point3 &direc, float length):len(length)
{
    originPoint=point3(x,y,z);
    direction=direc;
    this->normalizeDirection();
}

void vector3::normalizeDirection()
{
    float normalX=std::pow(this->direction.x,2);
    float normalY=std::pow(this->direction.y,2);
    float normalZ=std::pow(this->direction.z,2);
    float sum=std::sqrt(normalX+normalY+normalZ);
    this->normalDirection=point3(this->direction.x/sum,this->direction.y/sum,this->direction.z/sum);
}
