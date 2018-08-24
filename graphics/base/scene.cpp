#include "scene.h"

scene::scene()
{

}

void scene::addObject(object *obj)
{
    sceneObj.push_back(obj);
}

