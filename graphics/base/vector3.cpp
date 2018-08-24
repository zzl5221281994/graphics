#include "vector3.h"
#include <functional>


namespace RTL{
    template<typename T1,typename IterType>
    IterType map(std::function<T1(T1)> func,const IterType& iter)
    {
        IterType res;
        for(const auto &c:iter)
            res.push(func(c));
        return res;
    }
}
vector3::vector3(double x, double y, double z, const point3 &direction, double length):originPoint(x,y,z),len(length)
{
    normalizeDirection=direction;

}
//
