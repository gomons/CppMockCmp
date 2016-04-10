#include <gtest/gtest.h>
#include <Turtle/Painter.h>
#include "Turtle_mock.h"

TEST(TestPainter, DrawRect)
{
    MockTurtle turtle;

    turtle.penUpCounter_.setExpected(2);
    turtle.penDownCounter_.setExpected(1);
    turtle.goToCounter_.setExpected(5);

    Painter painter(turtle);
    painter.DrawRect(5, 5, 10, 30);

    turtle.verify();
}