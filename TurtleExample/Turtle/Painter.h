#pragma once

#include "Turtle.h"

class Painter
{
public:
    Painter(Turtle &turtle)
        : turtle_(turtle)
    {}

    void DrawRect(int x, int y, int height, int width)
    {
        turtle_.PenUp();
        turtle_.GoTo(x, y);
        turtle_.PenDown();
        turtle_.GoTo(x + width, y);
        turtle_.GoTo(x + width, y + height);
        turtle_.GoTo(x, y + height);
        turtle_.GoTo(x, y);
        turtle_.PenUp();
    }

private:
    Turtle &turtle_;
};