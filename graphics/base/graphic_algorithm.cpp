#include "graphic_algorithm.h"
inline void drawPixel(image &img,uint32_t x, uint32_t y, const RGB &c)
{
    assert(x<width&&y<height);
    uint32_t startPos=3*(width*y+x);
    this->data[startPos]    =c.r;
    this->data[startPos+1]  =c.g;
    this->data[startPos+2]  =c.b;
}
void drawLine(image &img,uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, const RGB &c)
{
    int drawType=DRAWLINE_TYPE::TYPE_DRAWLINE_INVALID;
    int iterateVar,iterateLimit,incVar,incLimit;
    if((x0<x1&&y0<=y1)||(x1<x0&&y1<=y0))  //case 0<m<+inf
    {
        int minx=MIN(x0,x1),maxx=MAX(x0,x1);
        int miny=MIN(y0,y1),maxy=MAX(y0,y1);
        if(maxx-minx>maxy-miny) //case 0<=m<1 (y1>=y0 and x1-x0>y1-y0)
        {
            iterateVar  =minx;
            iterateLimit=maxx;
            incVar      =miny;
            drawType    =DRAWLINE_TYPE::TYPE_DRAWLINE_MP01;
        }
        else                    //case 1<=m<inf (y1>=y0 and x1-x0<=y1-y0)
        {
            iterateVar  =miny;
            iterateLimit=maxy;
            incVar      =minx;
            drawType    =DRAWLINE_TYPE::TYPE_DRAWLINE_MP1I;
        }
    }
    else                                    //case -inf<m<0
    {
        int minx=MIN(x0,x1),maxx=MAX(x0,x1);
        int miny=MIN(y0,y1),maxy=MAX(y0,y1);
        if(maxx-minx>abs(miny-maxy))// case -1<m<0
        {
            iterateVar  =minx;
            iterateLimit=maxx;
            incVar      =maxy;
            incLimit    =miny;
            drawType    =DRAWLINE_TYPE::TYPE_DRAWLINE_MN10;
        }
        else                        // case -inf<m<=-1
        {
            iterateVar  =miny;
            iterateLimit=maxy;
            incVar      =maxx;
            incLimit    =minx;
            drawType    =DRAWLINE_TYPE::TYPE_DRAWLINE_MNI1;
        }
    }
    if(drawType==DRAWLINE_TYPE::TYPE_DRAWLINE_MP01)
    {
        //double d=f();
        for(int i=iterateVar;i<=iterateLimit;i++)
        {
            drawPixel(img,i,incVar,c);
            if(d<0)
            {
                incVar+=1;
                //d+=;
            }
            else
            {

            }
        }
    }
    else if(drawType==DRAWLINE_TYPE::TYPE_DRAWLINE_MN10)
    {
        //double d=f();
        for(int i=iterateVar;i<=iterateLimit;i++)
        {
            drawPixel(img,i,incVar,c);
            if(d<0)
            {
                incVar-=1;
                //d=
            }
            else
            {

            }
        }
    }
    else if(drawType==DRAWLINE_TYPE::TYPE_DRAWLINE_MP1I)
    {
        double d=f();
        for(int i=iterateVar;i<iterateLimit;i++)
        {
            drawPixel(img,incVar,i,c);
            if(d<0)
            {
                incVar+=1;
                //d=
            }
            else
            {

            }
        }
    }
    else
    {
        double d=f();
        for(int i=iterateVar;i<iterateLimit;i++)
        {
            drawPixel(img,incVar,i,c);
            if(d<0)
            {
                incVar-=1;
                //d=
            }
            else
            {

            }
        }
    }


}
