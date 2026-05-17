#include "../header/gui_menu.hpp"

void drawMainMenuButtons(Button &travelButton, Button &checkSuppliesButton, Button &mapButton, Button &changePaceButton, Button &changeRationsButton, Button &restButton, Button &huntButton, Button &shopButton, Button &backButton, Button &continueButton)
{
    travelButton.Draw();
    checkSuppliesButton.Draw();
    mapButton.Draw();
    changePaceButton.Draw();
    changeRationsButton.Draw();
    restButton.Draw();
    huntButton.Draw();
    shopButton.Draw();
    // backButton.Draw();
    // continueButton.Draw();
}

void handleButtons(Button &travelButton, Button &checkSuppliesButton, Button &mapButton, Button &changePaceButton, Button &changeRationsButton, Button &restButton, Button &huntButton, Button &shopButton, Button &backButton, Button &continueButton,Button& fillingButton, Button& meagerButton, Button& bareBonesButton, Vector2 mousePosition, bool mousePressed, GameScreen &currentScreen, SetSettings& settings, std::string& messageText, float& messageTimer)
{
    if (travelButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::Travel;
    }
    else if (checkSuppliesButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::CheckSupplies;
    }
    else if (mapButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::Map;
    }
    else if (changePaceButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::ChangePace;
    }
    else if (changeRationsButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::ChangeRations;
    }
    else if (restButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::Rest;
    }
    else if (huntButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::Hunt;
    }
    else if (shopButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::Shop;
    }

    else if(currentScreen == GameScreen::ChangeRations)
    {
        if (fillingButton.isPressed(mousePosition, mousePressed)){
            settings.setRations(RationSetting::Filling); 
            messageText = "rations set to filling.";
            messageTimer = 2.0f;
        }
        else if (meagerButton.isPressed(mousePosition, mousePressed)){
            settings.setRations(RationSetting::Meager); 
            messageText = "rations set to meager.";
            messageTimer = 2.0f;
        }
        else if (bareBonesButton.isPressed(mousePosition, mousePressed)){
            settings.setRations(RationSetting::BareBones); 
            messageText = "rations set to bare bones.";
            messageTimer = 2.0f;
        }
        else if( backButton.isPressed(mousePosition, mousePressed)){
            currentScreen = GameScreen::MainMenu;
        }
    }
    else{
        if (backButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::MainMenu;
    }
    else if (continueButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::MainMenu;
    } // back and continue are currently the same
    }
}

