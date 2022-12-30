﻿#include <iostream>
#include <stack>

using std::string;
using std::cout;
using std::cin;
using std::endl;

bool checkSym(char sym1, char sym2) {
	switch (sym1) {
	case '[':
		return ']' == sym2;
	case '(':
		return ')' == sym2;
	case '{':
		return '}' == sym2;
	default:
		return false;
	}
}

bool check(string s) {
	std::stack<char> st;
	for (char sym : s) {
		if (sym == '(' || sym == '[' || sym == '{') st.push(sym);
		else if (sym == ')' || sym == ']' || sym == '}') {
			if (!st.empty() && checkSym(st.top(), sym)) st.pop();
			else return false;
		}
	}
	if (!st.empty()) {
		while (!st.empty()) st.pop();
		return false;
	}
	return true;
}

int main() {
	system("chcp 65001 > nul");
	int option;
	string s;
	while (true) {
		cout << "Выберите действие:\n"
			<< "1. Ввести строку\n"
			<< "2. Вывести строку\n"
			<< "3. Проверить скобки на правильность встроенным классом стека\n"
			<< "4. Выход\n"
			<< "Ваш выбор: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Введите строку: ";
			cin >> s;
			break;
		case 2:
			cout << "Строка: " << s << endl;
			break;
		case 3:
			if (check(s)) cout << "Скобки в строке расставлены верно\n";
			else cout << "Скобки в строке расставлены неверно\n";
			break;
		case 4:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}