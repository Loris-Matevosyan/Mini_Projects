#ifndef _MYTEXTURE_
#define _MYTEXTURE_

#include "raylib.h"


class MyTexture
{
    static inline MyTexture* myTexture{nullptr};
    Texture2D scarfyTexture = LoadTexture("textures/scarfy.png");
    Texture2D nebulaTexture = LoadTexture("textures/12_nebula_spritesheet.png");
    Texture2D backgroundTexture = LoadTexture("textures/far-buildings.png");
    Texture2D midgroundTexture = LoadTexture("textures/back-buildings.png");
    Texture2D foregroundTexture = LoadTexture("textures/foreground.png");
    bool isLoaded{true};
    
    MyTexture() = default;

public:

    static MyTexture& getMyTextures()
    {  
        if (myTexture == nullptr)
        {
            myTexture = new MyTexture();
        }
        return *myTexture;
    }   

    void unloadTextures() 
    {
        UnloadTexture(scarfyTexture);
        UnloadTexture(nebulaTexture);
        UnloadTexture(backgroundTexture);
        UnloadTexture(midgroundTexture);
        UnloadTexture(foregroundTexture);
        isLoaded = false;
    }

    Texture2D& scarfy()
    { 
        return scarfyTexture;
    }

    Texture2D& nebula()
    { 
        return nebulaTexture;
    }

    Texture2D& background()
    { 
        return backgroundTexture;
    }

    Texture2D& midground()
    { 
        return midgroundTexture;
    }
    
    Texture2D& foreground()
    { 
        return foregroundTexture;
    }
    

    MyTexture(const MyTexture& texture) = delete;
    MyTexture& operator=(const MyTexture& texture) = delete;
    MyTexture(MyTexture&& texture) = delete;
    MyTexture& operator=(MyTexture&& texture) = delete;
    
    ~MyTexture()
    {
        if(isLoaded)
        {
            unloadTextures();
        }
        delete myTexture;
        myTexture = nullptr;
    }

};



#endif //_MYTEXTURE_