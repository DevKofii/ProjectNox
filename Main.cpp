#include "Menu.h"
#include "Game.h"

int main(int argc, char** argv)
{   
    //Display Res
    signed int dis_x = 1280;
    signed int dis_y = 720;
    //Center Point
    signed int ss_x = dis_x / 2;
    signed int ss_y = dis_y / 2;

    Menu menu;
    sf::Glyph;
   
    while (menu.getWindowIsOpen())
    {
        menu.update();
        menu.render();
    }
    if (menu.getState() == 3)
    {
        Game game;
        while (game.getWindowIsOpen())
        {
            // Update
            game.update();

            // Render
            game.render();
        }
    }
    return 0;
}