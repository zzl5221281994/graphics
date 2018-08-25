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
    std::cout<<__FUNCTION__<<std::endl;
    std::vector<float> randomTheta,randomFai;
    RTL::random(0,2*PI,randomTheta,360*5);
    RTL::random(0,PI,randomFai,180*10);
    for(auto theta:randomTheta)
        for(auto fai:randomFai)
        {
            float costheta=std::cos(theta);
            float sintheta=std::sin(theta);
            float cosFai=std::cos(fai);
            float cosHalfFai=std::cos(PI/2-fai);
            point3 direcVec(costheta*cosHalfFai,sintheta*cosHalfFai,cosFai);
            RTL::ray hitRay(position.x,position.y,position.z,direcVec,1);
            point3 hitpoint;
            this->hitable(hitRay,hitpoint);
            RTL::ray *sendRay=new RTL::ray(hitpoint.x,hitpoint.y,hitpoint.z,direcVec,1);
            //sendRay->getNormalDirection().print();
            //std::cout<<std::endl;
            vec.push_back(sendRay);
        }
}

bool lightSphere::isLightObject()
{
    return true;
}
