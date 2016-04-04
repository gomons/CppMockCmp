#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "mock_Turtle.h"
#include "Painter.h"

using ::testing::_;

TEST(TestPainter, DrawRect)
{
    MockTurtle turtle;
    EXPECT_CALL(turtle, PenDown()).Times(1);
    EXPECT_CALL(turtle, PenUp()).Times(2);
    EXPECT_CALL(turtle, GoTo(_, _)).Times(5);

    Painter painter(turtle);
    painter.DrawRect(5, 5, 10, 30);
}