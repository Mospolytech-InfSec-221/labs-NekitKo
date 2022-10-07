#include <iostream>
#include <limits>
#include <bitset>
using std::cout;
using std::cin;
int main() {
	//Задание 1
	cout << "Bashkatov Nikita Valer'evich, 221-351" << '\n';
	//Задание 2
	cout 
	<< "max int = " << std::numeric_limits<int>::max() << '\n'
	<< "min int = " << std::numeric_limits<int>::min() << '\n'
	<< "size of int = "<<sizeof(int)<<'\n'
	<<"max unsigned int = "<<std::numeric_limits<unsigned int>::max()<<'\n'
	<<"min unsigned int = "<<std::numeric_limits<unsigned int>::min()<<'\n'
	<<"size of unsigned int = "<<sizeof(unsigned int)<<'\n'
	<<"max short = " << std::numeric_limits<short>::max() << '\n'
	<<"min short = " << std::numeric_limits<short>::min() << '\n'
	<<"size of short = "<<sizeof(short)<<'\n'
	<<"max unsigned short = " << std::numeric_limits<unsigned short>::max() << '\n'
	<<"min unsigned short = " << std::numeric_limits<unsigned short>::min() << '\n'
	<<"size of unsigned short = "<<sizeof(unsigned short)<<'\n'
	<<"max long = " << std::numeric_limits<long>::max() << '\n'
	<<"min long = " << std::numeric_limits<long>::min() << '\n'
	<<"size of long = "<<sizeof(long)<<'\n'
	<<"max long long = " << std::numeric_limits<long long>::max() << '\n'
	<<"min long long = " << std::numeric_limits<long long>::min() << '\n'
	<<"size of long long = "<<sizeof(long long)<<'\n'
	<<"max double = " << std::numeric_limits<double>::max() << '\n'
	<<"min double = " << std::numeric_limits<double>::min() << '\n'
	<<"size of double = "<<sizeof(double)<<'\n'
	<<"max char = " << (int)std::numeric_limits<char>::max() << '\n'
	<<"min char = " << (int)std::numeric_limits<char>::min() << '\n'
	<<"size of char = "<<sizeof(char)<<'\n'
	<<"max bool = " << std::numeric_limits<bool>::max() << '\n'
	<<"min bool = " << std::numeric_limits<bool>::min() << '\n'
	<<"size of bool = "<<sizeof(bool)<<'\n';
	//Задание 3
	int x;
	cout<<"Enter the number: ";
	cin >> x;
	cout<<'\n';
	cout
	<<"bin: "<<std::bitset<8*sizeof(x)>(x)<<'\n'
	<<"hex: "<<std::hex<<x<<'\n'
	<<"bool: "<<bool(x)<<'\n'
	<<"double: "<<double(x)<<'\n'
	<<"char: "<<char(x)<<std::dec<<'\n';
	//Задание 4
	int a,b;
	cout<<"Enter coefficients a*x=b: ";
	cin>>a>>b;
	cout
	<<a<<" * x = "<<b<<'\n';
	if ((a==0)and(b==0)) {
	    cout<<"x in R"<<'\n';
	} else if ((a==0)and(b!=0)) {
	    cout<<"U can't divide by 0"<<'\n';
	} else if ((a!=0)and(b!=0)) {
	    cout
	    <<"x = "<<b<<" / "<<a<<'\n'
	    <<"x = "<<double(b)/a<<'\n';
	}
	//Задание 5
	int c,d;
	cout<<"Enter coordinates of segment: ";
	cin>>c>>d;
	cout<<(c+d)/2.;
}
