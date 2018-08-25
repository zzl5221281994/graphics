#include "scene.h"
#include "shape/lightsphere.h"

scene::scene()
{

}

void scene::addObject(object *obj)
{
    sceneObj.push_back(obj);
}

void scene::trace()
{
    for(const auto&obj:sceneObj)
    {
        if(obj->isLightObject())
        {
            lightSphere *p=dynamic_cast<lightSphere*>(obj);
            p->lighting(sceneRays);
        }
    }
}

void scene::capture(const camera &camera)
{

}
