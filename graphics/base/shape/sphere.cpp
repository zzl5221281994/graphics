#include "sphere.h"
#include "../infras.h"

sphere::sphere(const point3&position,float radius):radius(radius),object(position)
{

}

float sphere::SDF(const RTL::ray &vec)
{
    return RTL::distance(vec.getDestination(),this->position)-radius;
}

bool sphere::isLightObject()
{
    return false;
}

RTL::ray sphere::reflaction(const RTL::ray &vec)
{

}

RTL::ray sphere::reflection(const RTL::ray &vec)
{

}

float sphere::getRadius()const
{
    {return this->radius;}
}

bool sphere::hitable(const RTL::ray &vec, point3 &hit)
{
    if(RTL::distance_p3_ray(vec,this->position)>this->radius)
        return false;
    point3 normalVec=vec.getNormalDirection();
    point3 origin=vec .getOriginPoint();
    float m=normalVec.x;
    float n=normalVec.y;
    float p=normalVec.z;
    float x0=origin.x,y0=origin.y,z0=origin.z;
    float R=this->radius;
    float r1=position.x,r2=position.y,r3=position.z;
    float A=m*m+n*n+p*p;
    float B=2*(m*x0+n*y0+p*z0-r1*m-r2*n-r3*p);
    float C=x0*x0+y0*y0+z0*z0+r1*r1+r2*r2+r3*r3-2*(r1*x0+r2*y0+r3*z0)-radius*radius;

    float det=B*B-4*A*C;
    if(det<0)
        return false;
    else
    {
        det=std::sqrt(det);
        float t1=(det-B)/(2*A);
        float t2=-(det+B)/(2*A);
        if(t1>0&&t2>0)
        {
            point3 res=vec.getPoint(std::min(t1,t2));
            hit=res;
            return true;
        }
        else if(t1<0&&t2<0)
        {
            return false;
        }
        else
        {
            point3 res=vec.getPoint(std::max(t1,t2));
            hit=res;
            return true;
        }
    }
}

