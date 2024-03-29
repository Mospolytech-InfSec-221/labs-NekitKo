#ifndef CIRCLEINSQUARE_H
#define CIRCLEINSQUARE_H

#include "Square.h"
#include "Circle.h"

class CircleInSquare :
    public Square, public Circle
{
private:
    double S() = delete;
    double P() = delete;
public:
    CircleInSquare();
    CircleInSquare(double x, double y, double side, double diameter);
    friend std::ostream& operator << (std::ostream& out, CircleInSquare& pos);
};

std::ostream& operator << (std::ostream& out, CircleInSquare& pos);

#endif