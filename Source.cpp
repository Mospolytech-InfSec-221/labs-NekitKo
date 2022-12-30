#include <iostream>
#include <list>
#include <map>
#include <string>
int main()
{
    setlocale(LC_ALL, "ru");
    std::map <std::string, std::string> p;
    std::list <std::string> data;
    std::string line;

    std::cout << "Введите номер группы, пробел, фамилия: \n";
    getline(std::cin, line);
    while (line != "-")
    {
        if (p.find(line.substr(0, line.find(' '))) != p.end())
        {
            auto num = ++find(data.begin(), data.end(), p[line.substr(0, line.find(' '))]);
            data.insert(num, line);

            p[line.substr(0, line.find(' '))] = line;
        }
        else
        {
            data.push_back(line);
            p.insert(std::pair<std::string, std::string>(line.substr(0, line.find(' ')), line));
        }
        std::cout << "Введите номер группы, пробел, фамилия: \n";
        getline(std::cin, line);
    }
    std::cout << "\nрезультат:\n";
    for (auto i = data.begin(); i != data.end(); i++)
    {
        std::cout << *i << '\n';
    }
}