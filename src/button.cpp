#include <vector>
#include <memory>
#include <iostream>
#include <allegro5/allegro_primitives.h>

#include "button.hpp"
#include "system.hpp"

void Button::addPressor(std::shared_ptr<Pressable> inPressor)
{
    pressers.push_back(inPressor);
}

void Button::draw()
{
    //std::cout << "Drawing..." << std::endl;
    if (pressed)
    {
        al_draw_filled_rectangle(getUpperLeft().x, getUpperLeft().y, getLowerRight().x, getLowerRight().y, pressedCol.al_c());
    }
    else
    {
        al_draw_filled_rectangle(getUpperLeft().x, getUpperLeft().y, getLowerRight().x, getLowerRight().y, col.al_c());
    }
}

Vector2<int> Button::getUpperLeft()
{
    return Vector2<int>(sys->conf.dims.x / 2 - size.x, sys->conf.dims.y / 2 - size.y);
}

Vector2<int> Button::getLowerRight()
{
    return Vector2<int>(sys->conf.dims.x / 2 + size.x, sys->conf.dims.y / 2 + size.y);
}

void Button::onMousePressed()
{
    /*for (auto i = pressers.begin; i != pressers.end; i++)
    {
        i.get()->onPressed();
    }*/
}

Button::Button(System *inSys, Vector2<int> inSize, SafeColor inColor) : sys(inSys), size(inSize), col(inColor)
{
    std::cout << "Created!..." << std::endl;
}