#ifndef _SCARFY_
#define _SCARFY_

#include "Constants.h"
#include "Animation.h"



Animation createScarfy(const Texture2D& texture)
{
    std::initializer_list<float> rectangleList{
        0.0, 
        0.0, 
        texture.width/6,
        texture.height 
    };
    std::initializer_list<float> positionList{
        windowWidth/2 - (texture.width/6) /2,
        windowHeight - texture.height 
    };
    float updateTime = 1.0/12.0;

    return Animation(rectangleList, positionList, updateTime);
}



#endif //_SCARFY_