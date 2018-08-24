#ifndef INFRAS_H
#define INFRAS_H
#include "vector3.h"
#include "ray.h"
#include <cmath>
#include <tuple>

namespace RTL{
    float distance(const point3&p1,const point3 &p2);

    float dot(const point3&v1,const point3&v2);

    float distance_p3_line(const ray&r,const point3&p);

    std::tuple<float,float,float,float> ray_function(const ray&r);
}
#endif // INFRAS_H
