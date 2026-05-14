#include "../header/gui_menu.hpp"


void drawMainMenuButtons(  Button& travelButton, Button& checkSuppliesButton, Button& mapButton, Button& changePaceButton, Button& changeRationsButton, Button& restButton, Button& huntButton, Button& shopButton, Button& backButton, Button& continueButton  ) {
    travelButton.Draw();
    checkSuppliesButton.Draw();
    mapButton.Draw();
    changePaceButton.Draw();
    changeRationsButton.Draw();
    restButton.Draw();
    huntButton.Draw();
    shopButton.Draw();
    //backButton.Draw();
    //continueButton.Draw();
}

void handleMainMenuButtons(Button& travelButton, Button& checkSuppliesButton, Button& mapButton, Button& changePaceButton, Button& changeRationsButton, Button& restButton, Button& huntButton, Button& shopButton, Button& backButton, Button& continueButton, Vector2 mousePosition, bool mousePressed, GameScreen& currentScreen) {
    bool transitioning = false; 
    float alpha = 0.0f;
    int transitioningDirection = 1;

    if(travelButton.isPressed(mousePosition, mousePressed))
    {   transitioning = true;
        transitioningDirection = 1 ;
        currentScreen = GameScreen::Travel;
    }
    else if(checkSuppliesButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::CheckSupplies;
    }
    else if(mapButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::Map;
    }
    else if(changePaceButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::ChangePace;
    }
    else if(changeRationsButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::ChangeRations;
    }
    else if(restButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::Rest;
    }
    else if(huntButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::Hunt;
    }
    else if(shopButton.isPressed(mousePosition, mousePressed))
    {   transitioning = true;
        transitioningDirection = 1 ;
        currentScreen = GameScreen::Shop;
    }
    else if(backButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::MainMenu;
    }
    else if(continueButton.isPressed(mousePosition, mousePressed))
    {
        currentScreen = GameScreen::MainMenu;
    } //back and continue are currently the same 
    else{
        alpha += transitioningDirection * 0.05f;
        if (alpha > 1.0f && transitioningDirection==1){
            //switch screen at full fade
            transitioningDirection = -1 ; 
        }
        else if (alpha <=0.0f && transitioningDirection==-1){
            alpha = 0.0f;
            transitioning = false; 
        }
    }
}