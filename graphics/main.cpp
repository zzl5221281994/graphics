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
#include <fstream>
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

void normalize(std::vector<std::vector<int>> &vec)
{
    int max=INT_MIN,min=INT_MAX;
    for(const auto&v:vec)
        for(const auto c:v)
        {
            if(c<min)
                min=c;
            if(c>max)
                max=c;
        }
    for(auto &v:vec)
        for(auto &c:v)
            c=255*(c-min)/(max-min);
}
int main(int argc, char *argv[])
{
    std::vector<unsigned char> byteImg; //the raw pixels
//    unsigned w, h;
//    unsigned error = lodepng::decode(byteImg, w, h, "D:/testPng.png");
//    lodepng::encode("D:/testRay.png",byteImg,w,h);
//    cout<<w<<":"<<h<<":"<<byteImg.size()<<endl;
//    RTL::color *image=new RTL::color[w*h];
//    for(int i=0;i<h;i++)
//        for(int j=0;j<w;j++)
//        {
//            image[i*w+j].setR(byteImg[(i*w+j)*4+0]);
//            image[i*w+j].setG(byteImg[(i*w+j)*4+1]);
//            image[i*w+j].setB(byteImg[(i*w+j)*4+2]);
//            image[i*w+j].setA(byteImg[(i*w+j)*4+3]);
//        }
//    byteImg.clear();
//    colorBlend(static_cast<RTL::color*>(image),w,h);
//    byteArray(byteImg,w,h,static_cast<RTL::color*>(image));
//    lodepng::encode("D:/testRayBlend.png",byteImg,w,h);

    scene world;
    lightSphere light1(point3(10,10,10),50);
    lightSphere light2(point3(100,100,100),30);

    world.addObject(&light1);
    world.addObject(&light2);
    world.trace();

    std::vector<std::vector<int>> vec;
    vec.resize(1000);
    for(auto&v:vec)
    {
        v.resize(1000);
        std::fill(v.begin(),v.end(),0);
    }
    //world.saveRay("D:/ray.txt");
    world.capture(vec);
    //normalize(vec);
    RTL::color *image=new RTL::color[1000*1000];
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
        {
            auto c=vec[i][j];
            if(c>255)
            {
                image[i*1000+j].setR(0xff);
                image[i*1000+j].setG(0xff);
                image[i*1000+j].setB(0xff);
                image[i*1000+j].setA(0xff);
            }
            else
            {
                image[i*1000+j].setR(c);
                image[i*1000+j].setG(c);
                image[i*1000+j].setB(c);
                image[i*1000+j].setA(0xff);
            }
        }

    byteImg.clear();
    //colorBlend(static_cast<RTL::color*>(image),w,h);
    byteArray(byteImg,1000,1000,static_cast<RTL::color*>(image));
    lodepng::encode("D:/testRayTrace1.png",byteImg,1000,1000);

//    std::ofstream openfile("d:/myfile.txt", std::ios::out);
//    for(const auto &c:vec)
//    {
//        for(const auto v:c)
//            openfile<<v<<" ";
//        openfile<<endl;
//    }
//    openfile.close();
    return 0;

}
