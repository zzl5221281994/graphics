#ifndef SCENE_H
#define SCENE_H
#include "shape/object.h"
#include "camera.h"
#include <vector>

class scene
{
public:
    scene();
    void addObject(object*obj);
    void capture(const camera&camera);
private:
    std::vector<object*> sceneObj;
};

#endif // SCENE_H
