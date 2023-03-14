#ifndef Det_H
#define Det_H

#define elem(t, x, y, n) t[(x)*(n)+(y)]

void free_memory(double* matr);

double* create(double* matr, int n, int iskI, int iskJ);

double det_Minors(double* matr, int n);

void swap_zero(double* matr, int iskI, int n);

double det_Gauss(double* matr, int n);

#endif