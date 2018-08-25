#include "vector3.h"
#include "ray.h"
#include <cmath>
#include <tuple>
#include <base/Eigen/Dense.h>
#include <ctime>

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

    float distance_p3_ray(const ray&r,const point3&Q)
    {
        point3 O=r.getOriginPoint(),A=r.getOriginPoint();
        A.x=A.x+r.getNormalDirection().x;
        A.y=A.y+r.getNormalDirection().y;
        A.z=A.z+r.getNormalDirection().z;
        point3 vecQ(Q.x-O.x,Q.y-O.y,Q.z-O.z);
        point3 vecAO(A.x-O.x,A.y-O.y,A.z-O.z);

        Eigen::Vector3f x0_x1(Q.x-A.x,Q.y-A.y,Q.z-A.z);
        Eigen::Vector3f x0_x2(Q.x-O.x,Q.y-O.y,Q.z-O.z);
        Eigen::Vector3f crossVec=x0_x1.cross(x0_x2);
        float numerator=std::sqrt(crossVec.dot(crossVec));
        float denumerator=std::sqrt(RTL::dot(vecAO,vecAO));
        return numerator/denumerator;
    }

    float random(float left,float right,std::vector<float> &vec,int size)
    {
        srand((unsigned)time(NULL));
        for(int i=0;i<size;i++)
        {
            float res=rand()/float(RAND_MAX);
            res=(right-left)*res+left;
            vec.push_back(res);
        }
    }
}
