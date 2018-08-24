#include "vector3.h"
#include "ray.h"
#include <cmath>

namespace RTL{
    template<typename T1,typename IterType>
    IterType map(std::function<T1(T1)> func,const IterType& iter)
    {
        IterType res;
        for(const auto &c:iter)
            res.push_back(func(c));
        return res;
    }
    float distance(const point3&p1,const point3 &p2)
    {
        float x=std::pow((p1.x-p2.x),2);
        float y=std::pow((p1.y-p2.y),2);
        float z=std::pow((p1.z-p2.z),2);
        return std::sqrt(x+y+z);
    }

    float dot(const point3&v1,const point3&v2)
    {
        return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
    }

    float distance_p3_line(const ray&r,const point3&p)
    {
        point3 direction=r.getNormalDirection();
        float D=dot(direction,r.getOriginPoint());
        float numerator=std::abs(dot(direction,p)-D);
        float denominator=std::sqrt(dot(direction,direction));
        return numerator/denominator;
    }
}
