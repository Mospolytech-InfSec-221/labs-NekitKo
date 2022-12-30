#include <iostream>
#include <cstring>
#include <vector>

using std::distance;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

#pragma region structs

typedef struct {
	string Surname;
	uint16_t Age;
} SA_t;

typedef struct {
	string Surname;
	string Firstname;
	uint16_t Age;
} SNA_t;

#pragma endregion

#pragma region IO

void fix() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::ostream& operator << (std::ostream& out, SA_t& st) {
	out << st.Surname << " " << st.Age;
	return out;
}

std::istream& operator >> (std::istream& in, SA_t& st) {
	in >> st.Surname >> st.Age;
	fix();
	return in;
}

std::ostream& operator << (std::ostream& out, SNA_t& st) {
	out << st.Surname << " " << st.Firstname << " " << st.Age;
	return out;
}

std::istream& operator >> (std::istream& in, SNA_t& st) {
	in >> st.Surname >> st.Firstname >> st.Age;
	fix();
	return in;
}

#pragma endregion

#pragma region templates

#pragma region Input_templates

template <typename ArrType>
vector<ArrType> input(uint16_t count) {
	vector<ArrType> array;
	ArrType val;
	for (uint16_t i = (short)0U; i < count; i++) {
		cout << "Введите " << i + 1 << "-ый элемент массива: ";
		cin >> val;
		array.push_back(val);
	}
	return array;
}

template <>
vector<char*> input(uint16_t count) {
	vector<char*> array;
	char val[255];
	for (uint16_t i = (short)0U; i < count; i++) {
		cout << "Введите " << i + 1 << "-ый элемент массива: ";
		cin >> val;
		array.push_back(strcpy(new char[strlen(val) + 1U], val));
	}
	return array;
}

#pragma endregion

#pragma region Output_templates

template <typename T>
void output(vector<T> arr) {
	cout << typeid(T).name() << endl;
	for (T elem : arr) {
		cout << elem << endl;
	}
}

#pragma endregion

#pragma region compare_templates

template <typename X>
bool comp(X l, X r) {
	return l < r;
}

template <>
bool comp(SA_t l, SA_t r) {
	return l.Age < r.Age;
}

template <>
bool comp(SNA_t l, SNA_t r) {
	if (l.Surname < r.Surname) return true;
	else if (l.Surname == r.Surname) {
		if (l.Firstname < r.Firstname) return true;
		else if (l.Firstname == r.Firstname) {
			if (l.Age < r.Age) return true;
		}
	}
	return false;
}

#pragma endregion

#pragma region Qsort_template

template <typename ArrType,
	typename IterType = typename vector<ArrType>::Iterator
>
vector<ArrType>& Qsort(
	vector<ArrType>& array,
	IterType left,
	IterType right,
	bool (*f) (ArrType, ArrType) = comp<ArrType>
) {
	IterType left_o = left, right_o = right;
	ArrType piv = array.at(distance(array.begin(), right - distance(left, right) / 2));
	ArrType temp;
	while (left <= right) {
		while (f(*left, piv)) left++;
		while (f(piv, *right)) right--;
		if (left <= right) {
			temp = *left;
			*left = *right;
			*right = temp;
			left++;
			right--;
		}
	}
	if (left_o < right) array = Qsort<ArrType>(array, left_o, right);
	if (right_o > left) array = Qsort<ArrType>(array, left, right_o);
	return array;
}

#pragma endregion

#pragma region zadanie

template <typename T>
void z(uint16_t count) {
	vector<T> vec;
	vec = input<T>(count);
	cout << "Отсортированная последовательность:\n";
	output(Qsort<T>(vec, vec.begin(), --(vec.end())));
}

#pragma endregion

#pragma endregion

int main() {
	system("chcp 1251>nul");
	int option;
	uint16_t count = 0U;
	while (true) {
		cout << "Выберите действие:\n"
			<< "1. Массив int\n"
			<< "2. Массив unsigned int\n"
			<< "3. Массив short\n"
			<< "4. Массив unsigned short\n"
			<< "5. Массив long\n"
			<< "6. Массив long long\n"
			<< "7. Массив double\n"
			<< "8. Массив float\n"
			<< "9. Массив char\n"
			<< "10. Массив bool\n"
			<< "11. Массив с-строк\n"
			<< "12. Массив с++-строк\n"
			<< "13. Массив структуры с полями Фамилия и Возраст\n"
			<< "14. Массив структуры с полями Фамилия, Имя и Возраст\n"
			<< "15. Выход\n"
			<< "Ваш выбор: ";
		cin >> option;
		if (option >= 1 && option < 15) {
			cout << "Введите количество записей в массиве: ";
			cin >> count;
		}
		if (option >= 11 && option < 15) fix();
		switch (option) {
		case 1:
			z<int>(count);
			break;
		case 2:
			z<unsigned int>(count);
			break;
		case 3:
			z<short int>(count);
			break;
		case 4:
			z<unsigned short int>(count);
			break;
		case 5:
			z<long>(count);
			break;
		case 6:
			z<long long>(count);
			break;
		case 7:
			z<double>(count);
			break;
		case 8:
			z<float>(count);
			break;
		case 9:
			z<char>(count);
			break;
		case 10:
			z<bool>(count);
			break;
		case 11:
			z<char*>(count);
			break;
		case 12:
			z<string>(count);
			break;
		case 13:
			z<SA_t>(count);
			break;
		case 14:
			z<SNA_t>(count);
			break;
		case 15:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}