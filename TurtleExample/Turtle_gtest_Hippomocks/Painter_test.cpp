#include <gtest/gtest.h>
#include <Hippomocks/hippomocks.h>
#include <Turtle/Painter.h>

TEST(TestPainter, DrawRect)
{
    MockRepository mocks;
    Turtle *turtle = mocks.Mock<Turtle>();
    mocks.ExpectCall(turtle, Turtle::PenUp);
    mocks.ExpectCall(turtle, Turtle::GoTo);
    mocks.ExpectCall(turtle, Turtle::PenDown);
    mocks.ExpectCall(turtle, Turtle::GoTo);
    mocks.ExpectCall(turtle, Turtle::GoTo);
    mocks.ExpectCall(turtle, Turtle::GoTo);
    mocks.ExpectCall(turtle, Turtle::GoTo);
    mocks.ExpectCall(turtle, Turtle::PenUp);

    Painter painter(*turtle);
    painter.DrawRect(5, 5, 10, 30);
}