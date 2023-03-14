#include <iostream>
int* task1(int* arr, int* size)
{
	delete[] arr;
	int k;
	std::cout << "Enter lenght of array: " << std::endl;
	std::cin >> *size;
	int* arri = new int[*size];
	for (int i = 0; i < *size; i++)
	{
		std::cin >> k;
		arri[i] = k;
	}
	return arri;
}
void task2(int* arr, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "" << '\n';
}
int* task3(int* arr, int* size)
{
	int num;
	int num1;
	int numc;
	int cp;
	int cp1;
	int* arrii = new int[*size];
	arrii = arr;

	for (int j = 0; j < *size - 1; j++)
	{
		for (int i = 0; i < *size - 1; i++)
		{
			num = arrii[i];
			num1 = arrii[i + 1];
			cp = 0;
			cp1 = 0;
			numc = 0;
			while (num > 0)
			{
				num = num / 10;
				numc++;
			}
			num = arrii[i];
			if (numc % 2 == 0)
			{
				for (num; num > 0; num)
				{
					cp = cp + (num % 10);
					num = num / 10;
					num = num / 10;
				}
			}
			else
			{
				while (num > 0)
				{
					num = num / 10;
					cp = cp + (num % 10);
					num = num / 10;
				}
			}
			numc = 0;
			while (num1 > 0)
			{
				num1 = num1 / 10;
				numc++;
			}
			num1 = arrii[i + 1];
			if (numc % 2 == 0)
			{
				for (num1; num1 > 0; num1)
				{
					cp1 = cp1 + (num1 % 10);
					num1 = num1 / 10;
					num1 = num1 / 10;
				}
			}
			else
			{
				for (num1; num1 > 0; num1)
				{
					num1 = num1 / 10;
					cp1 = cp1 + (num1 % 10);
					num1 = num1 / 10;
				}
			}
			num = arrii[i];
			num1 = arrii[i + 1];
			if (cp > cp1)
			{
				arrii[i] = num1;
				arrii[i + 1] = num;
			}
			else
			{
				arrii[i] = num;
				arrii[i + 1] = num1;
			}
		}
	}
	return arrii;
}
int* task4(int* arr, int* size)
{
	int* arriii = new int[*size];
	int	num2;
	int num3;
	arriii = arr;
	for (int j = 0; j < *size - 1; j++)
	{
		for (int i = 0; i < *size - 1; i++)
		{
			num2 = arriii[i];
			num3 = arriii[i + 1];
			if (num2 % 10 < num3 % 10)
			{
				num2 = arriii[i];
				num3 = arriii[i + 1];
				arriii[i] = num3;
				arriii[i + 1] = num2;
			}
			else
			{
				num2 = arriii[i];
				num3 = arriii[i + 1];
				arriii[i + 1] = num3;
				arriii[i] = num2;
			}
		}
	}
	for (int j = 0; j < *size - 1; j++)
	{
		for (int i = 0; i < *size - 1; i++)
		{
			num2 = arriii[i];
			num3 = arriii[i + 1];
			if (num2 % 10 == num3 % 10)
			{
				if (num2 < num3)
				{
					arriii[i] = num3;
					arriii[i + 1] = num2;
				}

			}
		}
	}
	return arriii;
}
int main()
{
	int choice = 0;
	int* size;
	int pi;
	pi = 1;
	size = &pi;
	int* arr = new int[*size];
	arr = task1(arr, size);

	while (true)
	{
		std::cout << "What do u want to do? " << std::endl;
		std::cout << "1.Enter array: " << std::endl;
		std::cout << "2.Array output in console: " << std::endl;
		std::cout << "3.Sorting by the sum of the digits standing in even places: " << std::endl;
		std::cout << "4.Sort the array first in ascending order of the last digit, and if the last digits match, in descending order: " << std::endl;
		std::cout << "5.Quit " << std::endl;
		std::cin >> choice;
		if (choice == 5)
		{
			break;
		}
		switch (choice)
		{
		case 1:
		{
			arr = task1(arr, size);
			break;
		}
		case 2:
		{
			task2(arr, size);
			break;
		}
		case 3:
		{
			arr = task3(arr, size);
			break;
		}
		case 4:
		{
			arr = task4(arr, size);
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}