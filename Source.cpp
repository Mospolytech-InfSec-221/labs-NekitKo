#include <iostream>
#include <fstream>
#include <map>

#define russianIO(x)	system("chcp 1251>nul");\
						x;\
						system("chcp 65001>nul")

using std::ifstream;
using std::ofstream;
using std::string;
using std::map;
using std::cout;
using std::cin;
using std::endl;

void fix() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char toLower(char symb) {
	if ((int)symb < -32 && (int)symb > -65 || (int)symb < 91 && (int)symb > 64) return (char)((int)symb + 32);
	else return symb;
}

string to_lower(string word) {
	for (size_t i = 0; i < word.size(); i++) {
		word[i] = toLower(word[i]);
	}
	return word;
}

bool isLetter(char symb) {
	if ((symb >= (char)65 && symb <= (char)90) || (symb >= (char)97 && symb <= (char)122)) return true;
	if (symb >= (char)-64 && symb <= (char)-1) return true;
	else return false;
}

map<string, int> countWords(string filename, int& wordsCount) {
	map<string, int> words;
	string word;
	string error;
	ifstream input(filename);
	if (input.is_open()) {
		while (input >> word) {
			if (isLetter(word[0])) {
				while (!isLetter(word[word.length() - 1])) word.erase(word.length() - 1);
				word = to_lower(word);
				if (words.find(word) == words.end()) words[word] = 1;
				else words[word]++;
				wordsCount++;
			}
		}
		return words;
	}
	else error = "Файла с указанным именем не существует";
	input.close();
	wordsCount = 0;
	if (!error.empty()) throw std::exception(error.data());
}

int main() {
	system("chcp 65001>nul");
	map<string, int> words;
	ofstream out;
	string filename = "";
	int count = 0;
	int option;
	while (true) {
		cout << "Выберите действие:\n"
			<< "1. Выбрать файл\n"
			<< "2. Показать статистику\n"
			<< "3. Выход\n"
			<< "Ваш выбор: ";
		cin >> option;
		switch (option) {
		case 1:
			fix();
			cout << "Введите полное имя файла: ";
			russianIO(cin >> filename);
			try {
				words = countWords(filename, count);
			}
			catch (const std::exception& e) {
				cout << e.what();
			}
			break;
		case 2:
			out.open("D:\\results.txt");
			if (out.is_open()) {
				out << "Всего слов: " << count << endl;
				for (auto word : words) out << word.first << ": " << word.second << ", " << word.second / (double)count * 100.0 << "%\n";
				out.close();
			}
			cout << "Запись в файл окончена. Ознакомиться с результатами вы сможете по следующему пути: D:\\results.txt\n";
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