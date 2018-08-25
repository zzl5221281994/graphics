#ifndef INFRAS_H
#define INFRAS_H
#include "vector3.h"
#include "ray.h"
#include <cmath>
#include <tuple>
#include <vector>

namespace RTL{
#define PI 3.1415926
    float distance(const point3&p1,const point3 &p2);

    float dot(const point3&v1,const point3&v2);

    float distance_p3_ray(const ray&r,const point3&p);

    std::tuple<float,float,float,float> ray_function(const ray&r);

    inline float random(float left,float right,std::vector<float> &vec,int size);
}
#endif // INFRAS_H
