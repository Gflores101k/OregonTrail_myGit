#pragma once

#include<raylib.h>
#include "GameScreen.hpp"

struct ScreenTransition{
    bool transition = false;
    bool fadingOut = false;
    float opacity = 0.0f;
    float speed = 5.0f;
    GameScreen nextScreen = GameScreen::MainMenu;

    void ScreenEffect(GameScreen destination){ //starts affect 
        if(transition == true) return;
        transition = true; 
        fadingOut = true; //initiates Update (sets fadeout to true)
        opacity = 0.0f;
        nextScreen = destination; //prep for Updateeffect 
    }
    void UpdateEffect(GameScreen &currentScreen)
    {
        if (!transition){return;} //break out 
        float dt = GetFrameTime();

        if (fadingOut == true)
        {   opacity += speed * dt;
            if (opacity >= 1.0f)
            { // if faded to dark
                opacity = 1.0f;
                currentScreen = nextScreen;
                fadingOut = false; // breaks this fadeout (transition is still true)
            }
        }
        else
        {
            opacity -= speed * dt;
            if (opacity <= 0.0f)
            {
                opacity = 0.0f;
                transition = false;
            }
        }
    }

    void Draw() const
    {
        if (transition == true)
        {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, opacity));
        }
    }

};