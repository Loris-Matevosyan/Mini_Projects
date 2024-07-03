#ifndef _ANIMATION_
#define _ANIMATION_

#include "raylib.h"
#include <initializer_list>


struct Animation
{
    Rectangle rec;
    Vector2 pos;
    int currentFrame{0};
    float runningTime{0.0};
    float updateTime;

    Animation() = default;
    
    Animation( const std::initializer_list<float>& recList, 
               const std::initializer_list<float>& posList,
               float updateTimeSetup)
    {
        rec.x = *recList.begin();
        rec.y = *(recList.begin() + 1);
        rec.width = *(recList.begin() + 2);
        rec.height = *(recList.begin() + 3);
        pos.x = *posList.begin();
        pos.y = *(posList.begin() + 1);
        updateTime = updateTimeSetup;
    }

    Animation(const Animation& object) = default;
    Animation& operator=(const Animation& object) = default;
    Animation(Animation&& object) = default;
    Animation& operator=(Animation&& object) = default;
    ~Animation() = default;
};



void updateAnimation(Animation& animation, float deltaTime, int maxFrame)
{
    animation.runningTime += deltaTime;
    if (animation.runningTime >= animation.updateTime)
    {
        animation.rec.x = animation.rec.width * animation.currentFrame;

        ++animation.currentFrame;
        animation.runningTime = 0.0;
        
        if (animation.currentFrame > maxFrame)
        {
            animation.currentFrame = 0;
        }
    }
}



#endif //_ANIMATION_