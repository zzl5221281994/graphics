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
    for(float i=0;i<2*PI;i+=2*PI/3600)
        randomTheta.push_back(i);
    for(float i=0;i<PI;i+=PI/3600)
        randomFai.push_back(i);
    //RTL::random(0,2*PI,randomTheta,3600);
    //RTL::random(0,PI,randomFai,3600);
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

            /*************/
//            std::vector<float> randomTheta1,randomFai1;
//            RTL::random(0,2*PI,randomTheta1,36000);
//            RTL::random(0,PI/2,randomFai1,18000);
//            for(auto theta1:randomTheta1)
//                for(auto fai1:randomFai1)
//                {
//                    float costheta=std::cos(theta1);
//                    float sintheta=std::sin(theta1);
//                    float cosFai=std::cos(fai1);
//                    float cosHalfFai=std::cos(PI/2-fai1);
//                    float x1=costheta*cosHalfFai;
//                    float y1=sintheta*cosHalfFai;
//                    float z1=cosFai;
//                    RTL::ray *sendRay=new RTL::ray(hitpoint.x,hitpoint.y,hitpoint.z,point3(x1,y1,z1),100);
//                    vec.push_back(sendRay);
//                }
            /*************/
            //sendRay->getNormalDirection().print();
            //std::cout<<std::endl;
            RTL::ray *sendRay=new RTL::ray(hitpoint.x,hitpoint.y,hitpoint.z,direcVec,10);
            vec.push_back(sendRay);
        }
}

bool lightSphere::isLightObject()
{
    return true;
}
