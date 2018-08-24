#ifndef COLOR_H
#define COLOR_H

namespace RTL {
class color{
public:
    color()=default;
    color(unsigned char R,unsigned char G,unsigned char B,unsigned char A):R(R),G(G),B(B),A(A){}
    color alphaBlend(const color &fore)
    {
        color newColor;
        unsigned char alpha=fore.getA();
        float normalAlpha=fore.normalAlpha();
        newColor.setR(this->getR()*(1-normalAlpha)+(normalAlpha)*fore.getR());
        newColor.setG(this->getG()*(1-normalAlpha)+(normalAlpha)*fore.getG());
        newColor.setB(this->getB()*(1-normalAlpha)+(normalAlpha)*fore.getB());
        newColor.setA(color::deNormalAlpha(normalAlpha+this->normalAlpha()*(1-normalAlpha)));
        return newColor;
    }
    inline void setR(unsigned char  v){R=v;}
    inline void setG(unsigned char  v){G=v;}
    inline void setB(unsigned char  v){B=v;}
    inline void setA(unsigned char  v){A=v;}
    inline unsigned char  getR() const{return R;}
    inline unsigned char  getG() const{return G;}
    inline unsigned char  getB() const{return B;}
    inline unsigned char  getA() const{return A;}
    inline float normalAlpha()const {return this->getA()/255.0f;}
    static unsigned char  deNormalAlpha(float alpha){return alpha*255;}
private:
    unsigned char R,G,B,A;
};
}
#endif // COLOR_H
