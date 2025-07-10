#include<iostream>
#include<ctime>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "rus");
	int matrix[2][3] = { 1,2,3,4 };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	//
	int user_matrix[10][10];
	int rows, colums;
	cout << "дите строк и столбцов ";
	cin >> rows >> colums;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			user_matrix[i][j] = rand() % 11 + (-5);
		}
		
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			cout << user_matrix[i][j] << "\t";
		}
		cout << endl;
	}
	int count_positive = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			if (user_matrix[i][j] > 0)
			{
				count_positive++;
			}
		}

	}
	cout << "Количество положительных элементов матрицы " << count_positive << endl;
	//
	for (int j = 0; j < colums; j++)
	{
		int sum = 0;
		for (int i = 0; i < rows; i++)
		{
			sum += user_matrix[i][j];
		}
		cout << "Сумма " << j << "-го столбца- " << sum << endl;
	}
	//
	if (2 > colums)
	{
		cout << "Кол столб меньше 2" << endl;
	}
	else
	{
		int sum = 0;
		for (int i = 0; i < rows; i++)
		{
			sum += user_matrix[i][1];
		}
		cout << "Сумма 2-го столбца- " << sum << endl;
	}
	//
	cout << "----------------------------------"<< endl;
	for (int i = 0; i < rows; i++)
	{
		int min = user_matrix[i][0];
		for (int j = 1; j < colums; j++)
		{
			if (user_matrix[i][j] < min)
			{
				min = user_matrix[i][j];
			}
			
		}
		cout << "Мин эл " << i << "-й строки- " << min << endl;
	}
	///
	for (int j = 0; j < colums; j++)
	{
		int count_negative = 0;
		for (int i = 0; i < rows; i++)
		{
			if (user_matrix[i][j] < 0)
			{
				count_negative++;
			}

		}
		user_matrix[2][j] = count_negative;
	}
	//for azeroth
	cout << "----------------------------------" << endl;
	int max, min, max_row, max_col, min_row, min_col;
	min = max = user_matrix[0][0];
	max_row = max_col = min_row = min_col = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			if (user_matrix[i][j] > max)
			{
				max = user_matrix[i][j];
				max_row = i;
				max_col = j;
			}
			if (user_matrix[i][j] < min)
			{
				min = user_matrix[i][j];
				min_row = i;
				min_col = j;
			}
		}
	}
	cout << max << endl << max_row << endl << max_col << endl << min << endl << min_row << endl << min_col << endl<<endl;
	user_matrix[max_row][max_col] = min;
	user_matrix[min_row][min_col] = max;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			cout << user_matrix[i][j] << "\t";
		}
		cout <<endl;
	}



	return 0;
}