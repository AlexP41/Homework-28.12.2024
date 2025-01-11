/*
��������̲�Ͳ ����̲�Ͳ ������
==============================

�3
	���� ������� ������� MxN (M �����, N ��������). ��������� ��������� �� ���������� � �������� �������,
	�� ������� �������� ���� ����� ��/��� ��������� ������ ������� ������� ���� � � ��������� �������.

�4
	� 3 �������� ������ A, B, C. ��� ������� � ��� ���������� ������� �� ��������� ������� ����� � ��������.
	�������� ������ ����������� ������� [-10, 10]. �������:
		����������� �����, ���� ������ ������� �������� ��� A, B, C;
		����������� �����, ���� ������ ����� �������� ��� A � C;
		����������� �����, ���� ������ ��'��� �������� ��� A, B, C ��� ���������.


����'������ �� ����������� ���������� �������
https://fsx1.itstep.org/api/v1/files/XUktlJsLKP_gytLegZ8WrOEc_IJ7aJgy?inline=true

��������� ������: ��������� �� GitHub
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <locale>
#include <string>

#define LOW_BOARD_FOR_GENERATION_NUMBERS -10
#define HIGH_BOARD_FOR_GENERATION_NUMBERS 10


using namespace std;

void exercise(int exerciseNumber);

void fullArray(int rows, int columns, int** arr);

void outputArray(int rows, int columns, bool ChangedArray, int** arr, int newCol = 0);

int userInputNumber(string arrayName);

template <typename T>
int addColumn(int& numberOfColumns, int numberOfRows, T**& arr);

template <typename T>
int removeColumn(int& numberOfColumns, int numberOfRows, T**& arr);

void userChoiceForExThree();


int main()
{
	system("chcp 1251>null");
	srand(time(NULL));

	/*
	�1
	�������� �������, �� ���� �������� ����������� ������ � ��������� �������.
	*/

	exercise(1);

	int row, col;

	row = userInputNumber("�����");
	col = userInputNumber("���������");


	int** Array_1 = new int* [row];

	fullArray(row, col, Array_1);

	cout << endl;

	cout << "\033[033m��������� ������: \033[0m" << endl;

	outputArray(row, col, false, Array_1);

	int userColumn = addColumn(col, row, Array_1);

	cout << "\033[033m��������� ������ � ����� \033[035m" << to_string(userColumn) << "\033[33m ����������: \033[0m" << endl;

	outputArray(row, col, true, Array_1, userColumn);

	/*
	�2
	�������� �������, �� ������� �������� ����������� ������ �� �������� �������.
	*/

	exercise(2);

	int row2, col2;

	row2 = userInputNumber("�����");
	col2 = userInputNumber("���������");


	int** Array_2 = new int* [row2];

	fullArray(row2, col2, Array_2);

	cout << endl;

	cout << "\033[033m��������� ������: \033[0m" << endl;

	outputArray(row2, col2, false, Array_2);

	int userColumn2 = removeColumn(col2, row2, Array_2);

	cout << "\033[033m��������� ������ � ��������� \033[035m" << to_string(userColumn2) << "\033[33m ����������: \033[0m" << endl;

	outputArray(row2, col2, false, Array_2);

	/*
	�3
	���� ������� ������� MxN (M �����, N ��������). ��������� ��������� �� ���������� � �������� �������,
	�� ������� �������� ���� ����� ��/��� ��������� ������ ������� ������� ���� � � ��������� �������.
	*/


	exercise(3);

	int M, N;

	M = userInputNumber("�����");
	N = userInputNumber("���������");

	int** Array_3 = new int* [M];

	fullArray(M, N, Array_3);

	cout << endl;

	cout << "\033[033m��������� ������: \033[0m" << endl;

	outputArray(M, N, false, Array_3);

	/*while(true)
	{
		
	}*/

	userChoiceForExThree();



	for (int i = 0; i < row; i++) {
		delete[] Array_1[i];
	}
	delete[] Array_1;

	for (int i = 0; i < row; i++) {
		delete[] Array_2[i];
	}
	delete[] Array_2;

	for (int i = 0; i < row; i++) {
		delete[] Array_3[i];
	}
	delete[] Array_3;

	return 0;
}

void exercise(int exerciseNumber)
{
	cout << endl << endl << "\t\t\t\t\033[032m ��������  " << exerciseNumber << "\033[0m" << endl;
}

void fullArray(int rows, int columns, int** arr)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			arr[i][j] = LOW_BOARD_FOR_GENERATION_NUMBERS + rand() % (HIGH_BOARD_FOR_GENERATION_NUMBERS - LOW_BOARD_FOR_GENERATION_NUMBERS + 1);

		}
	}
}

void outputArray(int rows, int columns, bool ChangedArray, int** arr, int newCol)
{
	if (!ChangedArray) 
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << setw(4) << arr[i][j];

			}
			cout << endl;
		}
	}
	else 
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (j == newCol-1)
				{
					string valueWithoutColor = to_string(arr[i][j]);
					string coloredValue = "\033[035m" + valueWithoutColor + "\033[0m";

					size_t lengthValueWithoutColor = valueWithoutColor.length();
					size_t lengthColoredValue = coloredValue.length();
					
					cout << setw(4+ lengthColoredValue - lengthValueWithoutColor) << coloredValue;
				}
				else cout << setw(4) << arr[i][j];
			}
			cout << endl;
		}
	}
	
}

int userInputNumber(string arrayName)
{
	int userNum;

	while (true)
	{
		cout << endl << "\033[033m������ ���� ����� ��� ������� \033[035m" << arrayName << "\033[033m ������: \033[0m" << endl;
		cout << "\033[033m������ ��� ����: \033[0m";
		cin >> userNum;

		if (cin.fail())
		{
			cout << endl << "\033[031m �������! ���� �����, ������ �����.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (userNum < 1)
		{
			cout << endl << "\033[031m �������! ���� �����, ������ ���� ����� ����� �� 0.\033[0m\n" << endl;
			continue;
		}

		break;

	}

	return userNum;
}

void userChoiceForExThree()
{
	int userNum;
	int amountsOfOptions = 3;
	int* arrayOfPossibleOptions = new int[amountsOfOptions];
	bool menuOn = true;

	for (int i = 0; i < amountsOfOptions; i++)
	{
		arrayOfPossibleOptions[i] = i;
	}

	while (menuOn)
	{
		bool isNotValid = false;
		cout << endl << "\033[033m�� ������ ������ � �������: \033[0m" << endl <<
				         "\t\t0 - ����� � ����;" << endl << 
						 "\t\t1 - ������� ���� �� ������;" << endl << 
						 "\t\t2 - ������� ���� �� ��������;" << endl;
		cout << "\033[033m������ ��� ����: \033[0m";
		cin >> userNum;


		if (cin.fail())
		{
			cout << endl << "\033[031m �������! ���� �����, ������ �����.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		for (int i = 0; i < amountsOfOptions; i++)
		{
			if (userNum == arrayOfPossibleOptions[i])
			{
				isNotValid = true;
				break;
			}
			else { continue; }
		}

		if (!isNotValid)
		{
			cout << endl << "\033[031m �������! ���� �����, �������������� �� �� ������ �������� ������ � ����.\033[0m\n" << endl;
			continue;
		}

		switch (userNum)
		{
		case 0:
			menuOn = false;
			break;
		case 1:
			cout << endl << "Example 1 has been completed" << endl;
			break;
		case 2:
			cout << endl << "Example 2 has been completed" << endl;
			break;
		default:
			break;
		}
		
	}
}

template <typename T>
int addColumn(int& numberOfColumns, int numberOfRows, T**& arr) {

	int column;
	while (true) {
		
		cout << endl << "\033[033m������ ����� ��������� ��� ���������: \033[0m" << endl;
		cout << "\033[033m������ ��� ����: \033[0m";
		cin >> column;

		if (cin.fail())
		{
			cout << endl << "\033[031m �������! ���� �����, ������ �����.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (column < 1)
		{
			cout << endl << "\033[031m �������! ���� �����, ������ ���� ����� ����� �� 0.\033[0m\n" << endl;
			continue;
		}
		if (column > numberOfColumns+1 || column < 1) {
			cout << endl << "\033[031m�������! �� ����� ����������� ����� ���������. ������ " << to_string(numberOfColumns) << " ���������\033[0m\n";
			continue;
		}

		break;
	}

	T** newArray = new T * [numberOfRows];
	for (int row = 0; row < numberOfRows; row++) {
		newArray[row] = new T[numberOfColumns + 1]; 
	}

	for (int row = 0; row < numberOfRows; row++) {
		for (int col = 0; col < numberOfColumns + 1; col++) {
			if (col < column-1) {
				newArray[row][col] = arr[row][col];
			}
			else if (col == column-1) {
				newArray[row][col] = LOW_BOARD_FOR_GENERATION_NUMBERS +
					rand() % (HIGH_BOARD_FOR_GENERATION_NUMBERS - LOW_BOARD_FOR_GENERATION_NUMBERS + 1);
			}
			else {
				newArray[row][col] = arr[row][col - 1];
			}
		}
	}

	for (int row = 0; row < numberOfRows; row++) {
		delete[] arr[row];
	}
	delete[] arr;


	arr = newArray;
	numberOfColumns++;

	return column;
}

template <typename T>
int removeColumn(int& numberOfColumns, int numberOfRows, T**& arr) {

	int column;
	while (true) {

		cout << endl << "\033[033m������ ����� ��������� ��� ���������: \033[0m" << endl;
		cout << "\033[033m������ ��� ����: \033[0m";
		cin >> column;

		if (cin.fail())
		{
			cout << endl << "\033[031m �������! ���� �����, ������ �����.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (column < 1)
		{
			cout << endl << "\033[031m �������! ���� �����, ������ ���� ����� ����� �� 0.\033[0m\n" << endl;
			continue;
		}
		if (column > numberOfColumns || column < 1) {
			cout << endl << "\033[031m�������! �� ����� ����������� ����� ���������. ������ " << to_string(numberOfColumns) << " ���������\033[0m\n";
			continue;
		}

		break;
	}

	T** newArray = new T * [numberOfRows];
	for (int row = 0; row < numberOfRows; row++) {
		newArray[row] = new T[numberOfColumns - 1];
	}

	for (int row = 0; row < numberOfRows; row++) {
		for (int col = 0, newCol = 0; col < numberOfColumns; col++) {
			if (col != column - 1) {
				newArray[row][newCol++] = arr[row][col];
			}
		}
	}

	for (int row = 0; row < numberOfRows; row++) {
		delete[] arr[row];
	}
	delete[] arr;


	arr = newArray;
	numberOfColumns--;

	return column;
}