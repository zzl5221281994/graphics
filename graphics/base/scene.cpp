#include "scene.h"
#include "shape/lightsphere.h"
#include <algorithm>
#include <fstream>

scene::scene()
{

}

void scene::addObject(object *obj)
{
    sceneObj.push_back(obj);
}

void scene::trace()
{
    std::cout<<__FUNCTION__<<std::endl;
    for(const auto&obj:sceneObj)
    {
        if(obj->isLightObject())
        {
            std::cout<<"lighting obj"<<std::endl;
            lightSphere *p=dynamic_cast<lightSphere*>(obj);
            p->lighting(sceneRays);
        }
    }
}

void scene::capture(std::vector<std::vector<int>> &vec)
{
    /*
     * [100*100]
    */
//    std::vector<std::vector<100>> vec;
//    vec.resize(100);
//    for(auto&v:vec)
//        std::fill_n(v.begin(),v.end(),0);
    for(const auto&ray:sceneRays)
    {
        point3 origin=ray->getOriginPoint();
        point3 normal=ray->getNormalDirection();
        float m=normal.x,n=normal.y,p=normal.z;
        float x0=origin.x,y0=origin.y,z0=origin.z;
        if(m==0)
            continue;
        else
        {
            float t=(100-x0)/m;
            float y=n*t+y0;
            float z=p*t+z0;
            if((y>-500&&y<500)&&(z>-500&&z<500))
            {
                vec[int(z)+500][int(y)+500]+=1;
            }
        }
    }
}

void scene::saveRay(const std::string &filename)
{
    std::ofstream openfile(filename, std::ios::out);
    for(const auto &c:sceneRays)
    {
        point3 p=c->getNormalDirection();
        openfile<<p.x<<" "<<p.y<<" "<<p.z;
        openfile<<std::endl;
    }
    openfile.close();
}
