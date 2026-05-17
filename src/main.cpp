#include <raylib.h>
#include <iostream>
#include "../header/button.hpp"
#include "../header/GameScreen.hpp"
#include "../header/gui_menu.hpp"
#include "../header/transition.hpp"
#include "../header/setsettings.hpp"
#include <vector>
#include <string>




int main()
{
    InitWindow(1672, 941, "Oregon Trail");
    //InitWindow(1920,1080, "Oregon Trail");
    SetTargetFPS(60);
   

    GameScreen currentScreen = GameScreen::MainMenu; //set to mainmenu right away
    ScreenTransition transition; 
    SetSettings settings;
    
    std::string messageText="";
    float messageTimer = 0.0f;

    Texture2D independence_missouri = LoadTexture("Graphics/town_missouri.png");
    Texture2D shop_Missouri = LoadTexture("Graphics/shop_missouri.png"); 
    Texture2D leaving_missouri = LoadTexture("Graphics/leaving_missouri.png");
    Texture2D check_supplies = LoadTexture("Graphics/check_supplies.png");
    
    Texture2D change_pace = LoadTexture("Graphics/change_pace.png");
    Texture2D change_rations = LoadTexture("Graphics/change_rations.png");
    Texture2D rest=LoadTexture("Graphics/rest.png");
    Texture2D hunt_screen = LoadTexture("Graphics/hunt_screen.png");
    /*
    Texture2D landmark_alcove_spring = LoadTexture("Graphics/landmark_alcove_spring.png");
    Texture2D check_supplies_night = LoadTexture("Graphics/check_supplies_night.png");
    Texture2D travel_caulk_river_disasater = LoadTexture("Graphics/travel_caulk_disaster.png"); 
    Texture2D travel_caulk_river_success = LoadTexture("Graphics/travel_caulk_success.png"); 
    Texture2D travel_caulk_ford_disasater = LoadTexture("Graphics/travel_ford_disaster.png"); 
    Texture2D travel_caulk_ford_success = LoadTexture("Graphics/travel_ford_success.png");
    Texture2D travel_ferry_river = LoadTexture("Graphics/travel_ferry_river.png"); 
    */
    
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
   

    while(!WindowShouldClose())
    {   
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        GameScreen requestedScreen = currentScreen; 
        if(!transition.transition) {handleButtons(travelButton, checkSuppliesButton, mapButton, changePaceButton, changeRationsButton, restButton, huntButton, shopButton, backButton, continueButton, fillingButton, meagerButton, bareBonesButton, mousePosition, mousePressed, requestedScreen, settings, messageText, messageTimer);}   
        //fade to black
        if(requestedScreen != currentScreen){
            transition.ScreenEffect(requestedScreen);
        }
        //fade back to new picture
        transition.UpdateEffect(currentScreen); 
        if(messageTimer>0.0f){
            messageTimer -= GetFrameTime();
            if(messageTimer<=0.0f){
                messageTimer = 0.0f;
                messageText = "";
            }
        }
        
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
            //if (time?) { 
            //DrawTexture(check_supplies_night,0,0,WHITE);
                //} else{
            DrawTexture(check_supplies,0,0,WHITE);
                //}
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
            std::string currentRations = "Current Rations: " + settings.getRationName();
            DrawRectangle(460,20,750,50,Fade(BLACK,0.65f));
            DrawText(currentRations.c_str(),490,32,28,LIGHTGRAY);
        }
            else if(currentScreen == GameScreen::Rest){
            DrawTexture(rest,0,0,WHITE);
            backButton.Draw();
        }
            else if(currentScreen == GameScreen::Hunt)
        {   
           DrawTexture(hunt_screen, 0,0 ,WHITE);
            backButton.Draw();
        }
           else if(currentScreen == GameScreen::Shop)
        {  
            DrawTexture(shop_Missouri, 0, 0, WHITE);
            shopButton.Draw();
            backButton.Draw();
        }
        
       if(messageTimer>0.0f && messageText !=""){
        DrawRectangle(460,90,750,90,Fade(BLACK,0.85f));
        DrawRectangleLinesEx({460,90,750,90},4,GOLD);
        DrawText(messageText.c_str(),500,120,30,LIGHTGRAY);
       } 
        //end Drawing 
        transition.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
