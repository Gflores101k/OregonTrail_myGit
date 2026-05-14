#include <raylib.h>
#include <iostream>
#include "../header/button.hpp"
#include "../header/GameScreen.hpp"
#include "../header/gui_menu.hpp"
#include "../header/transition.hpp"
#include <vector>




int main()
{
    InitWindow(1672, 941, "Oregon Trail");
    //InitWindow(1920,1080, "Oregon Trail");
    SetTargetFPS(60);



    GameScreen currentScreen = GameScreen::MainMenu; //set to mainmenu right away
    ScreenTransition transition; 

    Texture2D independence_missouri = LoadTexture("Graphics/town_missouri.png");
    Texture2D shop_Missouri = LoadTexture("Graphics/shop_missouri.png"); 
    Texture2D leaving_missouri = LoadTexture("Graphics/leaving_missouri.png");
    Texture2D check_supplies = LoadTexture("Graphics/check_supplies.png");
    Texture2D check_supplies_night = LoadTexture("Graphics/check_supplies_night.png");
    Texture2D change_pace = LoadTexture("Graphics/change_pace.png");
    Texture2D change_rations = LoadTexture("Graphics/change_rations.png");
    Texture2D rest=LoadTexture("Graphics/rest.png");

    Button travelButton{"Graphics/travel_t_button.png", {0, 0}, 0.15};
    Button checkSuppliesButton{"Graphics/supplies_t_button.png", {0, 115}, 0.15};
    Button mapButton{"Graphics/map_t_button.png", {0, 230}, 0.15};
    Button changePaceButton{"Graphics/pace_t_button.png", {0, 345}, 0.15};
    Button changeRationsButton{"Graphics/rations_t_button.png", {0, 460},0.15};
    Button restButton{"Graphics/rest_t_button.png", {0, 575}, 0.15};
    Button huntButton{"Graphics/hunt_t_button.png", {0, 690}, 0.15};
    Button shopButton{"Graphics/shop_t_button.png", {0, 805}, 0.15};
    Button continueButton{"Graphics/continue_t_button.png", {0, 650}, 0.15};
    Button backButton{"Graphics/back_t_button.png", {300, 805}, 0.15};
    Button bareBonesButton{"Graphics/bare_bones_button.png", {1200,575},0.15};
    Button meagerButton{"Graphics/meager_button.png", {700,575},0.15};
    Button fillingButton{"Graphics/filling_button.png", {200,575},0.15};
    //bool exit = false;

    while(!WindowShouldClose())
    {   
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        GameScreen requestedScreen = currentScreen; 
        if(!transition.transition) {handleButtons(travelButton, checkSuppliesButton, mapButton, changePaceButton, changeRationsButton, restButton, huntButton, shopButton, backButton, continueButton, mousePosition, mousePressed, requestedScreen);}   
        //fade to black
        if(requestedScreen != currentScreen){
            transition.ScreenEffect(requestedScreen);
        }
        //fade back to new picture
        transition.UpdateEffect(currentScreen); 
        
        
        //Draw 
        BeginDrawing();
        ClearBackground(BLACK);
        if(currentScreen == GameScreen::MainMenu)
        {           
            DrawTexture(independence_missouri, 0, 0, WHITE);
            drawMainMenuButtons(travelButton, checkSuppliesButton, mapButton, changePaceButton, changeRationsButton, restButton, huntButton, shopButton, backButton, continueButton);
        }

        else if(currentScreen == GameScreen::Travel)
        {   
            DrawTexture(leaving_missouri, 0,0 ,WHITE);
            backButton.Draw();
        }
        else if(currentScreen == GameScreen::Map)
        {   
            //DrawTexture(map, 0,0 ,WHITE);
            backButton.Draw();
        }
        else if(currentScreen == GameScreen::CheckSupplies){
            //DrawTexture(check_supplies,0,0,WHITE);
            DrawTexture(check_supplies_night,0,0,WHITE);
            backButton.Draw();
        }
        else if(currentScreen == GameScreen::ChangePace){
            DrawTexture(change_pace,0,0,WHITE);
            backButton.Draw();
        }
        else if(currentScreen == GameScreen::ChangeRations){
            DrawTexture(change_rations,0,0,WHITE);
            backButton.Draw();
            bareBonesButton.Draw();
            meagerButton.Draw();
            fillingButton.Draw();
            //need to add these 3 buttons to handler 
        }
            else if(currentScreen == GameScreen::Rest){
            DrawTexture(rest,0,0,WHITE);
            backButton.Draw();
        }
            else if(currentScreen == GameScreen::Hunt)
        {   
            //DrawTexture(hunt, 0,0 ,WHITE);
            backButton.Draw();
        }
           else if(currentScreen == GameScreen::Shop)
        {  
            DrawTexture(shop_Missouri, 0, 0, WHITE);
            shopButton.Draw();
            backButton.Draw();
        }

        //end Drawing 
        transition.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
