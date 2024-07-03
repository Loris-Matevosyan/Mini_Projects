#ifndef _DRAWING_
#define _DRAWING_

#include "raylib.h"
#include "Constants.h"


Vector2 createBackGroundVector(float positionX);
void drawBack( const Texture2D& texture, Vector2 position );


void drawBackGround( const Texture2D& texture, float positionX )
{
    Vector2 positionOne = createBackGroundVector(positionX);
    drawBack(texture, positionOne);

    Vector2 positionTwo = createBackGroundVector(positionX + texture.width*2);
    drawBack(texture, positionTwo);
}


Vector2 createBackGroundVector(float positionX)
{
    return Vector2{positionX, 0.0};
}


void drawBack( const Texture2D& texture, Vector2 position )
{
    DrawTextureEx(texture, position, 0.0, 2.0, WHITE);
}


void drawingCollection( const Texture2D& texture, const auto& animations ) 
{
    for (auto animation : animations)
    {
        DrawTextureRec(texture, animation.rec, animation.pos, WHITE);
    }
}


void drawingAnimation( const Texture2D& texture, const Animation& animation ) 
{
    DrawTextureRec(texture, animation.rec, animation.pos, WHITE);
}


void drawingEndText(const char* text)
{
    DrawText(text, windowWidth/2 - 40, windowHeight/2, 20, RED);
}



#endif //_DRAWING_