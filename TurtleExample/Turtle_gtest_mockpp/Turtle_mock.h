#pragma once

#include <tuple>
#include <Turtle/Turtle.h>
#include <mockpp/ExpectationCounter.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/MockObject.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/visiting/VisitableMockObject.h>

class MockTurtle: public Turtle, public mockpp::MockObject
{
public:
    MockTurtle()
        : MockObject("MockTurtle", nullptr),
        penUpCounter_("MockTurtle/PenUp()", this),
        penDownCounter_("MockTurtle/PenDown()", this),
        forwardCounter_("MockTurtle/Forward()", this),
        forwardArgs_("MockTurtle/Forward()", this),
        turnCounter_("MockTurtle/Turn()", this),
        turnArgs_("MockTurtle/Turn()", this),
        goToCounter_("MockTurtle/GoTo()", this),
        //goToArgs_("MockTurtle/goToArgs_", this),
        getXCounter_("MockTurtle/GetX()", this),
        getXReturns_("MockTurtle/GetX()", this),
        getYCounter_("MockTurtle/GetY()", this),
        getYReturns_("MockTurtle/GetY()", this)
    {}

    void PenUp() override
    {
        penUpCounter_.inc();
    }

    void PenDown() override
    {
        penDownCounter_.inc();
    }

    void Forward(int distance) override
    {
        forwardCounter_.inc();
        return forwardArgs_.addActual(distance);
    }

    void Turn(int degrees) override
    {
        turnCounter_.inc();
        turnArgs_.addActual(degrees);
    }

    void GoTo(int x, int y) override
    {
        //goToArgs_.addActual(std::make_tuple(x, y));
        goToCounter_.inc();
    }

    int GetX() const override
    {
        getXCounter_.inc();
        return getXReturns_.nextReturnObject();
    }

    int GetY() const override
    {
        getYCounter_.inc();
        return getYReturns_.nextReturnObject();
    }

    mockpp::ExpectationCounter penUpCounter_;

    mockpp::ExpectationCounter penDownCounter_;

    mockpp::ExpectationCounter forwardCounter_;
    mockpp::ExpectationList<int> forwardArgs_;

    mockpp::ExpectationCounter turnCounter_;
    mockpp::ExpectationList<int> turnArgs_;
    
    mockpp::ExpectationCounter goToCounter_;
    //mockpp::ExpectationList<std::tuple<int, int>> goToArgs_;

    mutable mockpp::ExpectationCounter getXCounter_;
    mutable mockpp::ReturnObjectList<int> getXReturns_;

    mutable mockpp::ExpectationCounter getYCounter_;
    mutable mockpp::ReturnObjectList<int> getYReturns_;
};

//class MockTurtle2 : public Turtle, public mockpp::VisitableMockObject
//{
//public:
//    MockTurtle2()
//        : VisitableMockObject("MockTurtle2", nullptr),
//        MOCKPP_CONSTRUCT_MEMBERS_FOR_VOID_VISITABLE0(PenUp),
//        MOCKPP_CONSTRUCT_MEMBERS_FOR_VOID_VISITABLE0(PenDown),
//        MOCKPP_CONSTRUCT_MEMBERS_FOR_VOID_VISITABLE_EXT1(write, ext)
//    {}
//
//    MOCKPP_VOID_VISITABLE0(MockTurtle2, PenUp);
//    MOCKPP_VOID_VISITABLE0(MockTurtle2, PenDown);
//
//    MOCKPP_VOID_VISITABLE_EXT1(MockTurtle2, Forward, int, ext, int);
//
//    void Forward(int distance) override
//    {}
//
//    void Turn(int degrees) override
//    {}
//
//    void GoTo(int x, int y) override
//    {}
//
//    int GetX() const override
//    {}
//
//    int GetY() const override
//    {}
//};