#ifndef _NEBULA_
#define _NEBULA_

#include "Constants.h"
#include "Animation.h"



Animation createNebula(const Texture2D& texture, int indent = 0)
{
    std::initializer_list<float> rectangleList{
        0.0, 
        0.0, 
        texture.width/8,
        texture.height/8 
    };
    std::initializer_list<float> positionList{
        windowWidth + 300 * indent,
        windowHeight - texture.height/8
    };
    float updateTime = 1.0/16.0;

    return Animation(rectangleList, positionList, updateTime);
}



#endif //_NEBULA_