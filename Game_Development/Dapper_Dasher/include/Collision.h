#ifndef _COLLISION_
#define _COLLISION_

#include "raylib.h"


void checkCollision(const Animation& animationOne, const auto& animations, 
                    bool& hasCollided, float texturePad = 0.0)
{   
    for (auto animationTwo : animations)
    {
        Rectangle recOne {
            animationOne.pos.x,
            animationOne.pos.y,
            animationOne.rec.width,
            animationOne.rec.height,
        };

        Rectangle recTwo {
            animationTwo.pos.x + texturePad,
            animationTwo.pos.y + texturePad,
            animationTwo.rec.width - 2 * texturePad,
            animationTwo.rec.height - 2 * texturePad,
        };

        if (CheckCollisionRecs(recOne, recTwo))
        {
            hasCollided = true;
        }
    }
}



#endif //_COLLISION_