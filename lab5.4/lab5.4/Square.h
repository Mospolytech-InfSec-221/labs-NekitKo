#ifndef SQUARE_H
#define SQUARE_H

#include "Position.h"

class Square :
	virtual public Position
{
private:
	double side;
public:
	Square();
	Square(double x, double y, double side);
	void setSize(double size);
	double getSize();
	double S();
	double P();
	friend std::ostream& operator << (std::ostream& out, Square& pos);
};

std::ostream& operator << (std::ostream& out, Square& pos);

#endif