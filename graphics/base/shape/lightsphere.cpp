#include "lightsphere.h"
#include "base/Eigen/Dense.h"
#include "base/infras.h"

lightSphere::lightSphere(const point3&position,float radius):sphere(position,radius)
{

}

lightSphere::~lightSphere()
{

}

void lightSphere::lighting(std::vector<RTL::ray *> &vec)
{
    std::vector<float> randomTheta,randomFai;
    RTL::random(0,2*PI,randomTheta,360*3);
    RTL::random(0,PI,randomFai,180*3);
    for(auto theta:randomTheta)
        for(auto fai:randomFai)
        {
            float costheta=std::cos(theta);
            float sintheta=std::sin(theta);
            float cosFai=std::cos(fai);
            float sinFai=std::sin(fai);
            point3 direcVec(costheta*cosFai,sintheta*sinFai,sinFai);
            RTL::ray hitRay(position.x,position.y,position.z,direcVec,1);
            point3 hitpoint;
            this->hitable(hitRay,hitpoint);
            RTL::ray *sendRay=new RTL::ray(hitpoint.x,hitpoint.y,hitpoint.z,direcVec,1);
            vec.push_back(sendRay);
        }
}
