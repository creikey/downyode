#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <exception>

#include "system.hpp"
#include "color.hpp"
#include "button.hpp"
#include "vector2.hpp"
#include "button.hpp"

int main(int argc, char **argv)
{
    Config gameConf;
    gameConf.dims = Vector2<int>(500, 500);
    gameConf.bgColor = SafeColor(220, 220, 220);
    gameConf.fps = 30.0;
    gameConf.displayFlags = ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE | ALLEGRO_OPENGL;
    System *sys;
    try
    {
        sys = new System(gameConf);
    }
    catch (std::exception &err)
    {
        std::cerr << "ERROR: " << err.what() << std::endl;
        return 1;
    }
    Button *dlButton;
    dlButton = new Button(sys, Vector2<int>(200, 200), SafeColor(50, 50, 50));
    dlButton->pressedCol = SafeColor(100, 100, 100);
    while (true)
    {
        try
        {
            sys->runEvents();
        }
        catch (std::exception &err)
        {
            std::cerr << "Event Error: " << err.what() << std::endl;
        }
        if (sys->exit)
        {
            break;
        }
        if (sys->redraw)
        {
            al_clear_to_color(sys->conf.bgColor.al_c());
            dlButton->draw();
            al_flip_display();
        };
    }
    std::cout << "Done!" << std::endl;
    delete sys;
    delete dlButton;
}
