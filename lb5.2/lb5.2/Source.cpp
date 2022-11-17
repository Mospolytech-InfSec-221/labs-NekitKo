#include <iostream>
#include <stdexcept>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;
using std::exception;

void input(int& n, int& m) {
	while (true) {
		cout << "������� ���������� ����� � �������: ";
		cin >> n;
		cout << "������� ���������� �������� � �������: ";
		cin >> m;
		if (n > 0 && m > 0) break;
		else {
			cout << "����������� ������� �� ����� ���� ������ ��� ����� ����.\n��������� ����. ������� ����� ������� ����� ����������...\n";
			system("pause > nul");
		}
	}
}

int main() {
	system("chcp 65001 > nul");
	int option;
	Matrix* matr1 = nullptr, * matr2 = nullptr;
	double mnoj;
	int n, m;
	while (true) {
		try {
			cout << "�������� ��������:\n"
				<< "1. ������ ����� �������\n"
				<< "2. ������ �������������� �������\n"
				<< "3. ������� �������\n"
				<< "4. ����� ����� ���� ������\n"
				<< "5. ����� ������������ ���� ������\n"
				<< "6. ���� �������\n"
				<< "7. ������������ �������\n"
				<< "8. �������� ������� �� �����\n"
				<< "9. ���������� ����� �������\n"
				<< "10. ���������� �������� �������\n"
				<< "11. ������� ������� i ������ j �������\n"
				<< "12. �����\n"
				<< "��� �����: ";
			cin >> option;
			switch (option) {
			case 1:
				input(n, m);
				matr1 = new Matrix(n, m);
				matr1->input();
				break;
			case 2:
				input(n, m);
				matr2 = new Matrix(n, m);
				matr2->input();
				break;
			case 3:
				if (matr1 == nullptr) throw exception("������� �1 �� ������");
				matr1->print();
				break;
			case 4:
				if (matr1 == nullptr) throw exception("������� �1 �� ������");
				if (matr2 == nullptr) throw exception("������� �2 �� ������");
				matr1->sum(matr2);
				matr1->print();
				break;
			case 5:
				if (matr1 == nullptr) throw exception("������� �1 �� ������");
				if (matr2 == nullptr) throw exception("������� �2 �� ������");
				matr1->mult(matr2);
				matr1->print();
				break;
			case 6:
				if (matr1 == nullptr) throw exception("������� �1 �� ������");
				cout << "���� ������� �����: " << matr1->trace() << endl;
				break;
			case 7:
				if (matr1 == nullptr) throw exception("������� �1 �� ������");
				cout << "������������ ������� �����: " << matr1->det() << endl;
				break;
			case 8:
				if (matr1 == nullptr) throw exception("������� �1 �� ������");
				cout << "������� ���������: ";
				cin >> mnoj;
				matr1->mult_by_num(mnoj);
				matr1->print();
				break;
			case 9:
				if (matr1 == nullptr) throw exception("������� �1 �� ������");
				cout << "���������� ����� � �������: " << matr1->get_rows() << endl;
				break;
			case 10:
				if (matr1 == nullptr) throw exception("������� �1 �� ������");
				cout << "���������� �������� � �������: " << matr1->get_columns() << endl;
				break;
			case 11:
				if (matr1 == nullptr) throw exception("������� �1 �� ������");
				cout << "������� ������� �������� �������� ����� ������: ";
				cin >> n >> m;
				cout << "������� matr1[" << n << ", " << m << "] = " << matr1->get_elem(n, m) << endl;
				break;
			case 12:
				return 0;
			default:
				break;
			}
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
		n = m = 0;
		system("pause");
		system("cls");
	}
}