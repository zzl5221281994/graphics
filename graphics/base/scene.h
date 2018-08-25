#ifndef SCENE_H
#define SCENE_H
#include "shape/object.h"
#include "camera.h"
#include <vector>
#include <string>
class scene
{
public:
    scene();
    void addObject(object*obj);
    void trace();
    void capture(std::vector<std::vector<int>> &vec);

    void saveRay(const std::string&filename);
private:
    std::vector<object*> sceneObj;
    std::vector<RTL::ray*> sceneRays;
};

#endif // SCENE_H
