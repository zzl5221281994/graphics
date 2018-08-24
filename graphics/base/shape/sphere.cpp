#include "sphere.h"
#include "../infras.h"

float sphere::SDF(const vector3 &vec)
{
    return RTL::distance(vec.getOriginPoint(),this->position)-radius;
}

bool sphere::hitable(const vector3 &vec)
{

}

