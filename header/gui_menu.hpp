#pragma once
#include <raylib.h>
#include <string>
#include "../header/button.hpp"
#include "../header/GameScreen.hpp"
#include "../header/setsettings.hpp"


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

void handleButtons(Button& travelButton, 
    Button& checkSuppliesButton, 
    Button& mapButton, 
    Button& changePaceButton, 
    Button& changeRationsButton, 
    Button& restButton, 
    Button& huntButton, 
    Button& shopButton, 
    Button& backButton, 
    Button& continueButton,
    Button& fillingButton,
    Button& meagerButton,
    Button& bareBonesButton, 
    Vector2 mousePosition, 
    bool mousePressed, 
    GameScreen& currentScreen,
    SetSettings& settings,
    std::string& messageText, 
     float& messageTimer);

struct ScreenTransition;