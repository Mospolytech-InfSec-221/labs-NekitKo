#include <iostream>
#include <stdexcept>
#include "Matrix.h"
#include "Det.h"

void check(int n, int m) {
	if (n != m) throw std::exception("������� �� ����������");
}

Matrix::Matrix(int n, int m) {
	this->rows = n;
	this->columns = m;
	this->Vector = new double[n * m];
}

Matrix::Matrix(int n, int m, double* matr) {
	this->rows = n;
	this->columns = m;
	this->Vector = matr;
}

Matrix::~Matrix() {
	delete[] this->Vector;
}

int Matrix::get_columns() const {
	return this->columns;
}

int Matrix::get_rows() const {
	return this->rows;
}

double Matrix::get_elem(int i, int j) const {
	if (i >= this->rows || i < 0 || j < 0 || j >= this->columns) throw std::exception("��������� ������� �������");
	else return getElem(this, i, j);
}

double Matrix::det() {
	int method;
	check(this->rows, this->columns);
	std::cout << "������������ ����� ��������� ����� ��������. �������� ���� �� ���������:\n"
		<< "1. ����� ��������� �������;\n"
		<< "2. ����� ������.\n"
		<< "��� �����: \n";
	std::cin >> method;
	double determinant;
	if (method == 1) determinant = det_Minors(this->Vector, this->columns);
	else {
		double* save = new double[this->rows * this->rows];
		for (int i = 0; i < this->rows * this->rows; i++) save[i] = this->Vector[i];
		determinant = det_Gauss(save, this->rows);
		free_memory(save);
	}
	return determinant;
}

void Matrix::mult_by_num(double num) {
	for (int i = 0; i < this->rows * this->columns; i++) {
		this->Vector[i] *= num;
	}
}

void Matrix::print() {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			std::cout << this->get_elem(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix::input() {
	std::cout << "������� ������� ������� " << this->rows << "x" << this->columns << "." << std::endl;
	std::cout << "������� �������� ������� ��������� (�������� �������� ���������)\n";
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			std::cin >> getElem(this, i, j);
		}
	}
}

double Matrix::trace() {
	check(this->rows, this->columns);
	double sum = 0;
	for (int i = 0; i < this->rows; i++) {
		sum += this->get_elem(i, i);
	}
	return sum;
}

void Matrix::mult(const Matrix* mat2) {
	if (this->columns != mat2->get_rows()) throw std::exception("���������� �������� ������ ������� �� ��������� � ����������� ����� ������");
	double sum;
	double* prom = new double[this->rows * mat2->get_columns()];
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < mat2->get_columns(); j++) {
			sum = 0.0;
			for (int k = 0; k < this->columns; k++) {
				sum += this->get_elem(i, k) * mat2->get_elem(k, j);
			}
			prom[i * mat2->columns + j] = sum;
		}
	}
	this->columns = mat2->get_columns();
	this->Vector = prom;
}

void Matrix::sum(const Matrix* mat2) {
	if (this->rows != mat2->get_rows() || this->columns != mat2->get_columns()) throw std::exception("������� �� �����");
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			getElem(this, i, j) += getElem(mat2, i, j);
		}
	}
}