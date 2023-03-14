#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position
{
private:
	double x;
	double y;
public:
	Position();
	Position(double x, double y);
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	void setXY(double x, double y);
	void increaseX(double x);
	void increaseY(double y);
	void increaseXY(double x, double y);
	friend std::ostream& operator << (std::ostream& out, Position& pos);
};

std::ostream& operator << (std::ostream& out, Position& pos);

#endif