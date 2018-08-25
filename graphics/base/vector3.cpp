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

point3 vector3::getDestination()const
{
    point3 normal=this->getNormalDirection();
    float m_2=std::pow(normal.x,2);
    float n_2=std::pow(normal.y,2);
    float p_2=std::pow(normal.z,2);

    float tDesc=this->len/(std::sqrt(m_2+n_2+p_2));
    float x1=normal.x*tDesc+originPoint.x;
    float y1=normal.y*tDesc+originPoint.y;
    float z1=normal.z*tDesc+originPoint.z;
    return point3(x1,y1,z1);
}
