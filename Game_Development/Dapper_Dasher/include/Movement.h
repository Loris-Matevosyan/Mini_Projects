#ifndef _MOVEMENT_
#define _MOVEMENT_

#include "raylib.h"
#include "Constants.h"
#include "GlobalVariables.h"
#include "Animation.h"
#include <array>



void moveBackGround( const Texture2D& texture, float& positionX, const float& deltaTime, int far )
{
    positionX -= (20 * deltaTime) * far;

    if (positionX <= -texture.width*2)
    {
        positionX = 0;
    }
}


void moveScarfy(Animation& scarfy, const float& deltaTime, bool& isOnTheGround)
{
    if (scarfy.pos.y >= (windowHeight - scarfy.rec.height)) 
    {
        scarfyVelocity = 0;
        isOnTheGround = true;
    }
    else
    {
        scarfyVelocity += gravity * deltaTime;
    }
   
    if (IsKeyDown(KEY_SPACE) && isOnTheGround) 
    {
        scarfyVelocity += jumpVelocity;
        isOnTheGround = false;
    }

    scarfy.pos.y += scarfyVelocity * deltaTime;
}


void moveNebulae(auto& nebulae, const float& deltaTime)
{
    for (auto& nebula: nebulae) 
    {
        nebula.pos.x += nebulaVelocity * deltaTime;
    }
}



#endif //_MOVEMENT_