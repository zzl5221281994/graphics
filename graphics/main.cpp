#include "base/vector3.h"
#include "base/color.h"
#include "base/lodepng.h"
#include "base/ray.h"
#include "base/infras.h"
#include "base/shape/shape.h"
#include "base/scene.h"
#include "base/Eigen/Dense.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;
void byteArray(vector<unsigned char>& vec,int w,int h,RTL::color *image)
{
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            vec.push_back(image[i*w+j].getR());
            vec.push_back(image[i*w+j].getG());
            vec.push_back(image[i*w+j].getB());
            vec.push_back(image[i*w+j].getA());
        }
}
void colorBlend(RTL::color *image,int w,int h)
{
    RTL::color foreColor1(0x00,0xff,0x00,0xff*0.4);
    RTL::color foreColor2(0x00,0x00,0xff,0xff/2);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            image[i*w+j]=image[i*w+j].alphaBlend(foreColor1);
        }
}
int main(int argc, char *argv[])
{
    std::vector<unsigned char> byteImg; //the raw pixels
    unsigned w, h;
    unsigned error = lodepng::decode(byteImg, w, h, "D:/testPng.png");
    lodepng::encode("D:/testRay.png",byteImg,w,h);
    cout<<w<<":"<<h<<":"<<byteImg.size()<<endl;
    RTL::color *image=new RTL::color[w*h];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            image[i*w+j].setR(byteImg[(i*w+j)*4+0]);
            image[i*w+j].setG(byteImg[(i*w+j)*4+1]);
            image[i*w+j].setB(byteImg[(i*w+j)*4+2]);
            image[i*w+j].setA(byteImg[(i*w+j)*4+3]);
        }
    byteImg.clear();
    colorBlend(static_cast<RTL::color*>(image),w,h);
    byteArray(byteImg,w,h,static_cast<RTL::color*>(image));
    lodepng::encode("D:/testRayBlend.png",byteImg,w,h);

    scene world;
    lightSphere light(point3(10,10,10),5);

    world.addObject(&light);
    world.trace();

    return 0;

}
