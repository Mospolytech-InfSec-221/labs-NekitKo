#include <iostream>
#include <deque>
#include <set>

using std::deque;
using std::set;
using std::string;
using std::cout;
using std::cin;
using std::endl;

string getstring() {
	string s;
	system("chcp 1251>nul");
	cin >> s;
	system("chcp 65001>nul");
	return s;
}

struct _test_data {
	string username;
	uint16_t mark;
};

int main() {
	_test_data test;
	deque<_test_data> tests;
	set<string> tests_usernames;
	system("chcp 65001 > nul");
	int option;
	while (true) {
		cout << "Выберите действие:\n"
			<< "1. Введите данные\n"
			<< "2. Просмотреть базу данных\n"
			<< "3. Выход\n"
			<< "Ваш выбор: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Введите имя пользователя и результаты теста:\nИмя пользователя: ";
			test.username = getstring();
			cout << "Оценка: ";
			cin >> test.mark;
			if (tests_usernames.find(test.username) == tests_usernames.end()) {
				tests_usernames.insert(test.username);
				tests.push_back(test);
			}
			else cout << "Данный пользователь уже сдавал тест, результаты более не учитываются\n";
			break;
		case 2:
			for (auto x : tests) {
				cout << "Имя пользователя: ";
				system("chcp 1251>nul");
				cout << x.username;
				system("chcp 65001>nul");
				cout << "\nОценка: " << x.mark << endl;
			}
			break;
		case 3:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}