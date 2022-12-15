#ifndef DET_H
#define DET_H

#define elem(t, x, y, n) t[(x)*(n)+(y)]

double* create(double* matr, int n, int iskI, int iskJ);

void swap_zero(double* matr, int iskI, int n);

double det_Gauss(double* matr, int n);

#endif