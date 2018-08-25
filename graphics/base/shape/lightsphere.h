#ifndef LIGHTSPHERE_H
#define LIGHTSPHERE_H
#include "sphere.h"
#include <vector>

class lightSphere:public sphere
{
public:
    lightSphere(const point3&position,float radius);
    virtual bool isLightObject();
    void lighting(std::vector<RTL::ray*>&vec);
    ~lightSphere();

private:
};

#endif // LIGHTSPHERE_H
