#include <iostream>
#include "Det.h"

void free_memory(double* matr) {
	delete[] matr;
}

double* create(double* matr, int n, int iskI, int iskJ) {
	double* matrix = new double[n * (n - 2) + 1];
	int k, l = 0;
	for (int i = 0; i < n; i++) {
		k = 0;
		if (i != iskI) {
			for (int j = 0; j < n; j++) {
				if (j != iskJ) {
					elem(matrix, l, k, n - 1) = elem(matr, i, j, n);
					k++;
				}
			}
			l++;
		}
	}
	return matrix;
}

double det_Minors(double* matr, int n) {
	if (n == 1) return matr[0];
	double S = 0;
	double el = 1.0;
	double* minor;
	for (int j = 0; j < n; j++) {
		if (elem(matr, 0, j, n) != 0) {
			minor = create(matr, n, 0, j);
			S += el * elem(matr, 0, j, n) * det_Minors(minor, n - 1);
			free_memory(minor);
		}
		el = -el;
	}
	return S;
}

void swap_zero(double* matr, int iskI, int n) {
	double temp = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (elem(matr, i, 0, n) != 0 && !flag) {
			for (int j = 0; j < n; j++) {
				temp = elem(matr, iskI, j, n);
				elem(matr, iskI, j, n) = elem(matr, i, j, n);
				elem(matr, i, j, n) = temp;
			}
			flag = true;
		}
	}
}

double det_Gauss(double* matr, int n) {
	if (n == 1) return matr[0];
	double* minor = nullptr;
	double mnoj;
	double P = 1.0;
	if (elem(matr, 0, 0, n) == 0) {
		swap_zero(matr, 0, n);
		P *= -1;
	}
	for (int i = 1; i < n; i++) {
		if (elem(matr, i, 0, n) != 0) {
			mnoj = elem(matr, i, 0, n) / elem(matr, 0, 0, n);
			for (int j = 0; j < n; j++) elem(matr, i, j, n) -= elem(matr, 0, j, n) * mnoj;
		}
	}
	minor = create(matr, n, 0, 0);
	P *= elem(matr, 0, 0, n) * det_Gauss(minor, n - 1);
	free_memory(minor);
	return P;
}