#include "image.h"

image::image(int width, int height):width(width),height(height)
{
    data.reserve(3*width*height);
    std::fill(data.begin(),data.end(),0);
}
