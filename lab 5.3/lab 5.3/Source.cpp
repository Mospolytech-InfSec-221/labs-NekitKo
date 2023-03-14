#include <iostream>
#include <stdexcept>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;
using std::exception;

int main() {
	system("chcp 65001 > nul");
	int option;
	Matrix matr1, matr2, prom;
	double mnoj;
	int n, m;
	while (true) {
		try {
			cout << "�������� ��������:\n"
				<< "1. ������ ����� �������\n"
				<< "2. ������ �������������� �������\n"
				<< "3. ������� �������\n"
				<< "4. ����� ����� ���� ������\n"
				<< "5. ����� ������� ���� ������\n"
				<< "6. �������� ���� ��������� �������\n"
				<< "7. �������� �������� ������� �� ���������������\n"
				<< "8. �������� ������� �� �����\n"
				<< "9. ������������ �������\n"
				<< "10. ���� �������\n"
				<< "11. ���������� �������� �������\n"
				<< "12. ������� ������� i ������ j �������\n"
				<< "13. �����\n"
				<< "��� �����: ";
			cin >> option;
			switch (option) {
			case 1:
				cout << "������� ���� �������� �������: ";
				cin >> matr1;
				break;
			case 2:
				cout << "������� ���� ��������������� �������: ";
				cin >> matr2;
				break;
			case 3:
				cout << "����� ������� �� ������ �������?\n"
					<< "1. ��������\n"
					<< "2. ���������������\n"
					<< "��� �����: ";
				cin >> m;
				if (m == 1) cout << matr1;
				else cout << matr2;
				break;
			case 4:
				cout << matr1 + matr2;
				break;
			case 5:
				cout << matr1 - matr2;
				break;
			case 6:
				cout << -matr1;
				break;
			case 7:
				cout << matr1 * matr2;
				break;
			case 8:
				cout << "������� ���������: ";
				cin >> mnoj;
				cout << matr1 * mnoj;
				break;
			case 9:
				cout << "������������ ������� �����: " << matr1.det() << endl;
				break;
			case 10:
				cout << "���� ������� �����: " << matr1.tr() << endl;
				break;
			case 11:
				cout << "���������� �������� � �������: " << matr1.get_columns() << endl;
				break;
			case 12:
				cout << "������� ������� �������� �������� ����� ������: ";
				cin >> n >> m;
				cout << "������� matr1[" << n << ", " << m << "] = " << matr1.get_elem(n, m) << endl;
				break;
			case 13:
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