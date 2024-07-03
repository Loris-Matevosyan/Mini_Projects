#include "include/Includes.h"


int main() 
{
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    MyTexture& texture = MyTexture::getMyTextures();

    std::array<Animation, nebulaeSize> nebulae;
    for (int i = 0; i < nebulaeSize; ++i)
          nebulae[i] = createNebula(texture.nebula(), i);
    Animation scarfy = createScarfy(texture.scarfy());

    finishLine += nebulae[nebulaeSize - 1].pos.x;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);

        moveBackGround(texture.background(), bgPosX, deltaTime, 1);
        moveBackGround(texture.midground(), mgPosX, deltaTime, 2);
        moveBackGround(texture.foreground(), fgPosX, deltaTime, 4);
        
        drawBackGround(texture.background(), bgPosX);
        drawBackGround(texture.midground(), mgPosX);
        drawBackGround(texture.foreground(), fgPosX);

        moveScarfy(scarfy, deltaTime, isOnTheGround);
        moveNebulae(nebulae, deltaTime);

        checkCollision(scarfy, nebulae, collided, nebulaTexturePad);

        if (isOnTheGround)
        {
           updateAnimation(scarfy, deltaTime, scarfyMaxFrame);
        }

        for (int i = 0; i < nebulaeSize; ++i) 
        {
            updateAnimation(nebulae[i], deltaTime, nebulaMaxFame);
        }
        
        finishLine += nebulaVelocity * deltaTime;

        if (collided)
        {
            drawingEndText("Game Over");
        }
        else if (scarfy.pos.x >= finishLine)
        {
            drawingEndText("You Win");
        }
        else 
        {
            drawingCollection( texture.nebula(), nebulae );
            drawingAnimation( texture.scarfy(), scarfy );
        }

        EndDrawing();
    }

    texture.unloadTextures();

    CloseWindow();
    
}