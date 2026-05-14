#include <raylib.h>
#include <iostream>
#include "../header/button.hpp"
#include "../header/GameScreen.hpp"
#include "../header/gui_menu.hpp"
#include <vector>



int main()
{
    InitWindow(1672, 941, "Oregon Trail");
    //InitWindow(1920,1080, "Oregon Trail");
    SetTargetFPS(20);



    GameScreen currentScreen = GameScreen::MainMenu; //set to mainmenu right away
    //GameScreen currentScreen = GameScreen::TitleScreen; // test later 

    Texture2D independence_missouri = LoadTexture("Graphics/town_missouri.png");
    Texture2D general_store_Missouri = LoadTexture("Graphics/shop_missouri.png"); 
 
    Button travelButton{"Graphics/travel_t_button.png", {0, 0}, 0.25};
    Button checkSuppliesButton{"Graphics/supplies_t_button.png", {0, 115}, 0.25};
    Button mapButton{"Graphics/map_t_button.png", {0, 230}, 0.25};
    Button changePaceButton{"Graphics/pace_t_button.png", {0, 345}, 0.25};
    Button changeRationsButton{"Graphics/rations_t_button.png", {0, 460},0.25};
    Button restButton{"Graphics/rest_t_button.png", {0, 575}, 0.25};
    Button huntButton{"Graphics/hunt_t_button.png", {0, 690}, 0.25};
    Button shopButton{"Graphics/shop_t_button.png", {0, 805}, 0.25};
    Button continueButton{"Graphics/continue_t_button.png", {0, 650}, 0.25};
    Button backButton{"Graphics/back_t_button.png", {0, 920}, 0.25};

    //bool exit = false;

    while(!WindowShouldClose())
    {  
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if(currentScreen == GameScreen::MainMenu){
            handleMainMenuButtons(travelButton, checkSuppliesButton, mapButton, changePaceButton, changeRationsButton, restButton, huntButton, shopButton, backButton, continueButton, mousePosition, mousePressed, currentScreen); 
        }
        else if(currentScreen == GameScreen::Shop)
        {
            if(backButton.isPressed(mousePosition, mousePressed))
            {
                currentScreen = GameScreen::MainMenu;
            
            }
        }


        //Draw 
        BeginDrawing();
        ClearBackground(BLACK);
        if(currentScreen == GameScreen::MainMenu)
        {   DrawTexture(independence_missouri, 0, 0, WHITE);
            drawMainMenuButtons(travelButton, checkSuppliesButton, mapButton, changePaceButton, changeRationsButton, restButton, huntButton, shopButton, backButton, continueButton);
        }
        else if(currentScreen == GameScreen::Shop)
        {   DrawTexture(general_store_Missouri, 0, 0, WHITE);
            shopButton.Draw();
            backButton.Draw();
        }

        EndDrawing();

    }
    CloseWindow();
    return 0;
}
