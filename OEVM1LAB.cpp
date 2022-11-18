#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "Rus");

	int choise = -1;

	while (choise != 0)
	{
		cout << "\n1: просмотр бинарного представления double\n2: просмотр бинарного представления unsigned int\n3: установить количество рядом стоящих бит\n";
		cin >> choise;
		cout << "";

		if (choise == 1)
		{
			double number;
			cout << "введите число типа double: ";
			cin >> number;
			cout << "введенное число: " << number << endl;

			long long int* cast_number = (long long int*)(&number);

			cout << "полное бинарное представление: ";
			for (int i = sizeof(long long int) * 8 - 1; i >= 0; --i)
			{
				cout << ((*cast_number >> i) & 1);
			}

			cout << "знак: ";
			cout << ((*cast_number >> sizeof(long long int) * 8 - 1) & 1);
			cout << "степень: ";
			for (int i = sizeof(long long int) * 8 - 2; i >= sizeof(long long int) * 8 - 2 - 8; --i)
			{
				cout << ((*cast_number >> i) & 1);
			}
			cout << "мантисса: ";
			for (int i = sizeof(long long int) * 8 - 2 - 8 - 1; i >= 0; --i)
			{
				cout << ((*cast_number >> i) & 1);
			}
			cout << endl;
		}
		else if (choise == 2)
		{
			unsigned int number;
			cout << "введите число типа unsigned int (0-255): ";
			cin >> number;
			cout << "введенное число: " << number << endl;

			cout << "полное бинарное представление: ";
			for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; --i)
			{
				cout << ((number >> i) & 1);
			}

			cout << endl;
		}
		else if (choise == 3)
		{
			long long int number, origNumber;
			cout << "введите целое число: ";
			cin >> number;
			origNumber = number;
			if (cin.fail())
			{
				cout << "число не целое" << endl;
				return 0;
			}
			cout << endl;;

			cout << "полное бинарное представление: ";
			for (int i = sizeof(long long int) * 8 - 1; i >= 0; --i)
			{
				cout << ((origNumber >> i) & 1);
			}
			cout << endl;

			int count;
			cout << "введите кол-во бит, которые хотите изменить: ";
			cin >> count;
			cout << endl;

			unsigned int index;
			cout << "введите номер младшего бита, который хотите изменить (с конца, отсчет начинается с 0): ";
			cin >> index;
			cout << "";

			for (int bit_i = 0; bit_i < count; ++bit_i)
			{

				unsigned int new_bit_state;
				cout << "введите новое значение бита (0 / 1, любое другое значение будет интерпретированно как 1): ";
				cin >> new_bit_state;
				cout << endl;

				if (new_bit_state != 0 && new_bit_state != 1)
				{
					new_bit_state = 1;
				}

				if (((number >> index) & 1) != new_bit_state)
				{
					long long int to_add = 1;
					for (int i = 0; i < index; ++i)
					{
						to_add *= 2;
					}

					if (new_bit_state == 0)
					{
						number -= to_add;
					}
					else
					{
						number += to_add;
					}
				}
				index += 1;

			}

			for (int i = sizeof(long long int) * 8 - 1; i >= 0; --i)
			{
				cout << ((origNumber >> i) & 1);
			}
			cout << endl;

			for (int i = sizeof(long long int) * 8 - 1; i >= 0; --i)
			{
				if (index-1 == i && count > 0)
				{
					cout << "|";
					index -= 1;
					count -= 1;
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;

			
			for (int i = sizeof(long long int) * 8 - 1; i >= 0; --i)
			{
				cout << ((number >> i) & 1);
			}
			cout << endl;
			cout << "\nчисло после изменения указанных бит: " << number << endl << endl;
		}
		else if (choise != 0)
		{
			cout << "такой команды не существует!" << endl;
		}

	}

	return 0;
}