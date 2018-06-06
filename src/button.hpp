#ifndef HPP_BUTTON
#define HPP_BUTTON

#include <vector>
#include <memory>

#include "vector2.hpp"
#include "color.hpp"
#include "system.hpp"

class Pressable
{
  public:
    virtual void onPressed() = 0;
};

class Button
{
  public:
    Vector2<int> size;
    SafeColor col;
    SafeColor pressedCol;
    void draw();
    void onMousePressed();
    void addPressor(std::shared_ptr<Pressable>);
    Button(System *inSys, Vector2<int> inSize, SafeColor inColor);

  private:
    System *sys;
    bool pressed;
    std::vector<std::shared_ptr<Pressable>> pressers;
    Vector2<int> getUpperLeft();
    Vector2<int> getLowerRight();
};

#endif // HPP_BUTTON