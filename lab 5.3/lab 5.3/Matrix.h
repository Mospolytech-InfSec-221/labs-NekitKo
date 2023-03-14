#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include "Det.h"

#define getElem(t,x, y) t->Vector[(x)*t->columns+(y)] 

class Matrix
{
private:
	int columns;
	double* Vector;
public:
	Matrix();
	Matrix(int m);
	Matrix(int m, double* matr);
	Matrix(const Matrix& matr);
	~Matrix();
	int get_columns() const;
	double get_elem(int i, int j) const;
	void input(int m);
	void input(int m, double* matr);
	void input(const Matrix& matr);
	std::string print();
	Matrix sum(const Matrix& mat2) const;
	Matrix sum(const Matrix& mat2, int size) const;
	Matrix mult(const Matrix& mat2) const;
	double* mult(const double* matr, int m) const;
	double tr() const;
	double det() const;
	Matrix mult_by_num(double num) const;
	Matrix operator - ();
	Matrix operator += (Matrix matr2);
	Matrix operator -= (Matrix matr2);
	friend Matrix operator * (Matrix matr1, double num);
	friend Matrix operator + (Matrix matr1, Matrix matr2);
	friend Matrix operator - (Matrix matr1, Matrix matr2);
	friend Matrix operator * (Matrix matr1, Matrix matr2);
	friend std::ostream& operator << (std::ostream& out, Matrix matr);
	friend std::istream& operator >> (std::istream& in, Matrix matr);
};

Matrix operator * (Matrix matr1, double num);
Matrix operator + (Matrix matr1, Matrix matr2);
Matrix operator - (Matrix matr1, Matrix matr2);
Matrix operator * (Matrix matr1, Matrix matr2);
std::ostream& operator << (std::ostream& out, Matrix matr);
std::istream& operator >> (std::istream& in, Matrix matr);

#endif