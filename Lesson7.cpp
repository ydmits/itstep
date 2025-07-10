// Lesson7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include <time.h>
#include <ctime>

using namespace std;

int main()
{
    // генерация случайных чисел
	srand(time(NULL));
	// случайное число из диапазона 0-99 
	cout << rand() % 100 << endl;
	// случайное число из диапазона 0-999 
	cout << rand() % 1000 << endl;

	// случайное число в заданном диапазоне
	int min_range, max_range;
	setlocale(LC_ALL, "rus");
	cout << "Введите начало диапазона для генерации числа - ";
	cin >> min_range;
	cout << "Введите конец диапазона для генерации числа - ";
	cin >> max_range;

	int number = rand() % (max_range - min_range) + min_range;

	cout << "new number - " << number << endl;

	// число от -10 до 10
	number = rand() % (10 - (-10)) + (-10);
	cout << "new number - " << number << endl;

	// создание одномерного массива из случайных чисел
	const int max_size = 100;
	int arr[max_size] = {};
	int size;
	cout << "Введите размер массива - ";
	cin >> size;
	// заполнение массива случайными числами от 0 до 99
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}

	// вывод массива
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	// подсчитать количество элементов после максимального
	// 1. найти максимальный
	// 2. узнать его номер
	// 3. от размера массива отнять его номер

	// для массива максимальное и минимальное значение инициализируется первым элементом массива
	int max = arr[0];
	// переменная для запоминания номера 
	int index_max = 0;
	// находим макимальный элемент и запоминаем его номер
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
			index_max = i;
		}
	}
	cout << "Максимальный элемент - " << max << ", его индекс - " << index_max << endl;
	cout << "Количество элементов после максимального - " << (size - index_max - 1) << endl;
	
	// Сумма элемнтов на местах, кратных трем
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if ((i + 1) % 3 == 0)
		{
			sum += arr[i];
		}
	}

	cout << "Сумма - " << sum << endl;

	// количество минимальных элементов
	int count_min = 0;
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == min)
		{
			count_min++;
		}
	}
	cout << "Количество минимальных - " << count_min << endl;

	// запомнить индексы максимальных элементов в новом массиве
	int indexes[max_size] = {};
	int current_index = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == max) {
			indexes[current_index++] = i;
		}
	}
	cout << "Индексы максимальных элементов\n";
	for (int i = 0; i < current_index; i++)
	{
		cout << indexes[i] << "\t";
	}
	cout << endl;


	

	system("pause");
}

