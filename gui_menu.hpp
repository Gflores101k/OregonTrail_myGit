#pragma once
#include <raylib.h>
#include "../header/button.hpp"
#include "../header/GameScreen.hpp"


void drawMainMenuButtons(Button& travelButton, 
    Button& checkSuppliesButton, 
    Button& mapButton, 
    Button& changePaceButton, 
    Button& changeRationsButton, 
    Button& restButton, 
    Button& huntButton, 
    Button& shopButton, 
    Button& backButton, 
    Button& continueButton
); 

void handleMainMenuButtons(Button& travelButton, 
    Button& checkSuppliesButton, 
    Button& mapButton, 
    Button& changePaceButton, 
    Button& changeRationsButton, 
    Button& restButton, 
    Button& huntButton, 
    Button& shopButton, 
    Button& backButton, 
    Button& continueButton, 
    Vector2 mousePosition, 
    bool mousePressed, 
    GameScreen& currentScreen);


