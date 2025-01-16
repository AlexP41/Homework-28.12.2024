/*
БАГАТОВИМІРНІ ДИНАМІЧНІ МАСИВИ
==============================

Обов'язково до опрацювання навчальний матеріал
https://fsx1.itstep.org/api/v1/files/XUktlJsLKP_gytLegZ8WrOEc_IJ7aJgy?inline=true

РЕЗУЛЬТАТ РОБОТИ: посилання на GitHub
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <locale>
#include <string>
#include <cstdarg>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <type_traits>
#include <utility>

#define LOW_BOARD_FOR_GENERATION_NUMBERS -10
#define HIGH_BOARD_FOR_GENERATION_NUMBERS 10


using namespace std;

#pragma region Functions Prototypes for exercises 1 , 2 , 3 , 4

void exercise(int exerciseNumber);

void fullArray(int rows, int columns, int** arr);

void outputArray(int rows, int columns, bool ChangedArray, int** arr, int newCol = 0);

int userInputNumber(string arrayName);

template <typename T>
int addColumn(int& numberOfColumns, int numberOfRows, T**& arr);

template <typename T>
int removeColumn(int& numberOfColumns, int numberOfRows, T**& arr);

template <typename Type>
void userChoiceForExThree(int amountRows, int amountColumns, Type& array);

template <typename T>
void shiftArray(int rows, int columns, T**& arr);

void clearArray(int**& arr, int rows);

template <typename T>
pair<T*, int> oneDimensionalArrayOfUniqueNumbers(int amountOfArrays, ...);

template <typename T>
pair<T*, int> commonValuesOfArrays(int amountOfArrays, ...);

template <typename T>
pair <T*, int> negativeNumbersOfArrays(int  amountOfArrays, ...);

#pragma endregion


int main()
{
	system("chcp 1251>null");
	srand(time(NULL));

	/*
	№1
	Написати функцію, що додає стовпчик двовимірному масиву в зазначену позицію.
	*/

#pragma region Exercise 1

	exercise(1);

	int row, col;

	row = userInputNumber("рядків");
	col = userInputNumber("стовпчиків");


	int** Array_1 = new int* [row];

	fullArray(row, col, Array_1);

	cout << endl;

	cout << "\033[033mВиведення масиву: \033[0m" << endl;

	outputArray(row, col, false, Array_1);

	int userColumn = addColumn(col, row, Array_1);

	cout << "\033[033mВиведення масиву з новим \033[035m" << to_string(userColumn) << "\033[33m стовпчиком: \033[0m" << endl;

	outputArray(row, col, true, Array_1, userColumn);

#pragma endregion

	/*
	№2
	Написати функцію, що видаляє стовпчик двовимірного масиву за вказаним номером.
	*/

#pragma region Exercise 2

	exercise(2);

	int row2, col2;

	row2 = userInputNumber("рядків");
	col2 = userInputNumber("стовпчиків");


	int** Array_2 = new int* [row2];

	fullArray(row2, col2, Array_2);

	cout << endl;

	cout << "\033[033mВиведення масиву: \033[0m" << endl;

	outputArray(row2, col2, false, Array_2);

	int userColumn2 = removeColumn(col2, row2, Array_2);

	cout << "\033[033mВиведення масиву з видаленим \033[035m" << to_string(userColumn2) << "\033[33m стовпчиком: \033[0m" << endl;

	outputArray(row2, col2, false, Array_2);

#pragma endregion

	/*
	№3
	Дано матрицю порядку MxN (M рядків, N стовпців). Необхідно заповнити її значеннями і написати функцію,
	що здійснює циклічний зсув рядків та/або стовпчиків масиву вказану кількість разів і в зазначену сторону.
	*/

#pragma region Exercise 3

	exercise(3);

	int M, N;

	M = userInputNumber("рядків");
	N = userInputNumber("стовпчиків");

	int** Array_3 = new int* [M];

	fullArray(M, N, Array_3);

	cout << endl;

	cout << "\033[033mВиведення масиву: \033[0m" << endl;

	outputArray(M, N, false, Array_3);

	userChoiceForExThree(M, N, Array_3);

#pragma endregion

	/*
	№4
	Є 3 двовимірні масиви A, B, C. Для кожного з них користувач вводить із клавіатури кількість рядків і стовпців.
	Заповніть масиви випадковими числами [-10, 10]. Створіть:
		Одновимірний масив, який містить унікальні значення для A, B, C;
		Одновимірний масив, який містить спільні значення для A і C;
		Одновимірний масив, який містить від'ємні значення для A, B, C без повторень.
	*/

#pragma region Exercise 4

	exercise(4);

	int M1, N1, M2, N2, M3, N3;


	/* ------------------------------- Array A ----------------------------------------*/

	cout << endl << "\t\t\033[035mВвід масиву А\033[0m" << endl;

	M1 = userInputNumber("рядків");
	N1 = userInputNumber("стовпчиків");

	int** A = new int* [M1];

	fullArray(M1, N1, A);

	/* --------------------------------------------------------------------------------*/



	/* ------------------------------- Array B ----------------------------------------*/

	cout << endl << "\t\t\033[035mВвід масиву B\033[0m" << endl;

	M2 = userInputNumber("рядків");
	N2 = userInputNumber("стовпчиків");

	int** B = new int* [M2];

	fullArray(M2, N2, B);

	/* --------------------------------------------------------------------------------*/



	/* ------------------------------- Array C ----------------------------------------*/

	cout << endl << "\t\t\033[035mВвід масиву C\033[0m" << endl;

	M3 = userInputNumber("рядків");
	N3 = userInputNumber("стовпчиків");

	int** C = new int* [M3];

	fullArray(M3, N3, C);

	/* --------------------------------------------------------------------------------*/



	/* ----------------------------- Output filled arrays ---------------------------- */

	cout << endl << "\t\t\033[035mВивід масиву A\033[0m" << endl;
	outputArray(M1, N1, false, A);

	cout << endl << "\t\t\033[035mВивід масиву B\033[0m" << endl;
	outputArray(M2, N2, false, B);

	cout << endl << "\t\t\033[035mВивід масиву C\033[0m" << endl;
	outputArray(M3, N3, false, C);

	/* --------------------------------------------------------------------------------*/



	/* ---------------------- Unique numbers  ----------------------------------------*/

	auto result = oneDimensionalArrayOfUniqueNumbers<int>(	3, 
															M1, N1, A, 
															M2, N2, B,
															M3, N3, C
														);
	cout << endl << "\033[033mУнікальні значення масивів А, B, C.\033[0m" << endl;
	int* uniqueNumbers = result.first;
	int size = result.second;

	if (size == 0)
	{
		cout << endl << "\t\t\033[034mУнікальних значень не знайдено.\033[0m" << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << setw(4) << uniqueNumbers[i];
		}
		cout << endl;
	}

	/* --------------------------------------------------------------------------------*/



	/* --------------------- Common values for A and C arrays -------------------------*/

	auto resultOfCommonArrays = commonValuesOfArrays<int>(  2,
															M1, N1, A,
															M3, N3, C
														);

	cout << endl << "\033[033mСпільні значення масивів А і C.\033[0m" << endl;
	int* commonVal = resultOfCommonArrays.first;
	int sizeOfCommonValArray = resultOfCommonArrays.second;

	if (sizeOfCommonValArray == 0) 
	{
		cout << endl << "\t\t\033[036mСпільних значень не знайдено.\033[0m" << endl;
	}
	else 
	{
		for (int i = 0; i < sizeOfCommonValArray; i++)
		{
			cout << setw(4) << commonVal[i];
		}
		cout << endl;
	}
	/* --------------------------------------------------------------------------------*/



	/* --------------------- Negative values for A, B and C arrays ---------------------*/

	auto negativeNumbersForABCandArrSize = negativeNumbersOfArrays<int>(	3,
																M1, N1, A,
																M2, N2, B,
																M3, N3, C
															);

	cout << endl << "\033[033mВід'ємні значення масивів А, B і C.\033[0m" << endl;
	int* negativeNumbersForABC = negativeNumbersForABCandArrSize.first;
	int negativeArraySize = negativeNumbersForABCandArrSize.second;

	if (negativeArraySize == 0)
	{
		cout << endl << "\t\t\033[036mВід'ємних значень не знайдено.\033[0m" << endl;
	}
	else 
	{
		for (int i = 0; i < negativeArraySize; i++)
		{
			cout << setw(4) << negativeNumbersForABC[i];
		}
		cout << endl;
	}

	/* --------------------------------------------------------------------------------*/

	
#pragma endregion

    /* Deleting block for all arrays */
#pragma region Deleting Arrays

	clearArray(Array_1, row);

	clearArray(Array_2, row2);

	clearArray(Array_3, M);

	clearArray(A, M1);

	clearArray(B, M2);

	clearArray(C, M3);

	delete[] uniqueNumbers;

	delete[] commonVal;

	delete[] negativeNumbersForABC;
 
	return 0;

#pragma endregion
}




#pragma region Functions for exercise 1 , 2 , 3 , 4

void exercise(int exerciseNumber)
{
	cout << endl << endl << "\t\t\t\t\033[032m Завдання  " << exerciseNumber << "\033[0m" << endl;
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
		cout << endl << "\033[033mВведіть ціле число для кількості \033[035m" << arrayName << "\033[033m масиву: \033[0m" << endl;
		cout << "\033[033mВведіть ваш вибір: \033[0m";
		cin >> userNum;

		if (cin.fail())
		{
			cout << endl << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (userNum < 1)
		{
			cout << endl << "\033[031m Помилка! Будь ласка, введіть ціле число більше за 0.\033[0m\n" << endl;
			continue;
		}

		break;

	}

	return userNum;
}

template <typename T>
void shiftArray(int rows, int columns, T**& arr)
{
	int choice;
	while (true) {
		cout << endl
			<< "\033[033mВиберіть тип зсуву:\033[0m" << endl
			<< "\t\t1 - Зсув рядка (вправо/вліво)" << endl
			<< "\t\t2 - Зсув стовпця (вниз/вгору)" << endl;
		cout << "\033[033mВаш вибір: \033[0m";
		cin >> choice;

		if (cin.fail() || (choice != 1 && choice != 2)) {
			cout << endl << "\033[031mПомилка! Введіть 1 або 2.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	}

	if (choice == 1) {
		int userRow, direction;
		while (true) {
			cout << endl << "\033[033mВведіть номер рядка для зсуву (1-" << rows << "): \033[0m";
			cin >> userRow;

			if (cin.fail() || userRow < 1 || userRow > rows) {
				cout << endl << "\033[031mПомилка! Введіть коректний номер рядка.\033[0m\n" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			break;
		}

		while (true) {
			cout << endl
				<< "\033[033mВиберіть напрямок зсуву:\033[0m" << endl
				<< "\t\t1 - Вправо" << endl
				<< "\t\t2 - Вліво" << endl;
			cout << "\033[033mВаш вибір: \033[0m";
			cin >> direction;

			if (cin.fail() || (direction != 1 && direction != 2)) {
				cout << endl << "\033[031mПомилка! Виберіть 1 або 2.\033[0m\n" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			break;
		}

		userRow -= 1;

		if (direction == 1) {
			T temp = arr[userRow][columns - 1]; 
			for (int col = columns - 1; col > 0; col--) {
				arr[userRow][col] = arr[userRow][col - 1];
			}
			arr[userRow][0] = temp; 
		}
		else if (direction == 2) {
			T temp = arr[userRow][0]; 
			for (int col = 0; col < columns - 1; col++) {
				arr[userRow][col] = arr[userRow][col + 1];
			}
			arr[userRow][columns - 1] = temp; 
		}
	}
	else if (choice == 2) {
		int userColumn, direction;
		while (true) {
			cout << endl << "\033[033mВведіть номер стовпця для зсуву (1-" << columns << "): \033[0m";
			cin >> userColumn;

			if (cin.fail() || userColumn < 1 || userColumn > columns) {
				cout << endl << "\033[031mПомилка! Введіть коректний номер стовпця.\033[0m\n" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			break;
		}

		while (true) {
			cout << endl
				<< "\033[033mВиберіть напрямок зсуву:\033[0m" << endl
				<< "\t\t1 - Вниз" << endl
				<< "\t\t2 - Вгору" << endl;
			cout << "\033[033mВаш вибір: \033[0m";
			cin >> direction;

			if (cin.fail() || (direction != 1 && direction != 2)) {
				cout << endl << "\033[031mПомилка! Виберіть 1 або 2.\033[0m\n" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			break;
		}

		userColumn -= 1; 

		if (direction == 1) {
			T temp = arr[rows - 1][userColumn]; 
			for (int row = rows - 1; row > 0; row--) {
				arr[row][userColumn] = arr[row - 1][userColumn];
			}
			arr[0][userColumn] = temp; 
		}
		else if (direction == 2) {
			T temp = arr[0][userColumn]; 
			for (int row = 0; row < rows - 1; row++) {
				arr[row][userColumn] = arr[row + 1][userColumn];
			}
			arr[rows - 1][userColumn] = temp; 
		}
	}

	cout << "\n\033[032mОновлений масив:\033[0m\n";
	outputArray(rows, columns, false, arr, 0);
}

template <typename Type>
void userChoiceForExThree(int amountRows, int amountColumns, Type& array)
{
	int userNum;
	int countOfChanges = 0;

	while (true)
	{
		countOfChanges++;
		if (countOfChanges != 1) 
		{
			cout << endl << "\033[032mБажаєте продовжити робиту з масивом?\033[0m" << endl <<
				"\t\t1 - Так;" << endl <<
				"\t\t2 - Ні;" << endl;
			cout << "\033[032mВведіть ваш вибір: \033[0m";
			cin >> userNum;
		}
		else
		{
			userNum = 1;
		}

		if (cin.fail())
		{
			cout << endl << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		
		if (userNum == 1) 
		{
			shiftArray(amountRows, amountColumns, array);
		}
		else 
		{
			break;
		}
	}
}

template <typename T>
int addColumn(int& numberOfColumns, int numberOfRows, T**& arr) {

	int column;
	while (true) {
		
		cout << endl << "\033[033mВведіть номер стовпчика для додавання: \033[0m" << endl;
		cout << "\033[033mВведіть ваш вибір: \033[0m";
		cin >> column;

		if (cin.fail())
		{
			cout << endl << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (column < 1)
		{
			cout << endl << "\033[031m Помилка! Будь ласка, введіть ціле число більше за 0.\033[0m\n" << endl;
			continue;
		}
		if (column > numberOfColumns+1 || column < 1) {
			cout << endl << "\033[031mПомилка! Ви ввели некоректний номер стовпчика. Всього " << to_string(numberOfColumns) << " стовпчиків\033[0m\n";
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

		cout << endl << "\033[033mВведіть номер стовпчика для видалення: \033[0m" << endl;
		cout << "\033[033mВведіть ваш вибір: \033[0m";
		cin >> column;

		if (cin.fail())
		{
			cout << endl << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (column < 1)
		{
			cout << endl << "\033[031m Помилка! Будь ласка, введіть ціле число більше за 0.\033[0m\n" << endl;
			continue;
		}
		if (column > numberOfColumns || column < 1) {
			cout << endl << "\033[031mПомилка! Ви ввели некоректний номер стовпчика. Всього " << to_string(numberOfColumns) << " стовпчиків\033[0m\n";
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

void clearArray(int**& arr, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr; // Уникнення "висячих" вказівників
}

template <typename T>
pair<T*, int> oneDimensionalArrayOfUniqueNumbers(int amountOfArrays, ...)
{
	static_assert(is_arithmetic_v<T>, "The template type T must be a numeric type.");

	/*T resultArray[maxSize];*/
	vector<T>allNumbers;

	va_list args;
	va_start(args, amountOfArrays);
	for (int i = 0; i < amountOfArrays; i++)
	{
		int rows = va_arg(args, int);
		int cols = va_arg(args, int);
		T** currentArray = va_arg(args, T**);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				allNumbers.push_back(currentArray[i][j]);
			}
		}
	}

	va_end(args);

	unordered_map<T, int> frequency;
	for (const T& num : allNumbers)
	{
		frequency[num]++;
	}

	vector<T> uniqueNumbers;
	for (const T& num : allNumbers)
	{
		if (frequency[num] == 1)
		{
			uniqueNumbers.push_back(num);
		}
	}

	int uniqueSize = uniqueNumbers.size();

	T* resultArray = new T[uniqueSize];

	int index = 0;
	for (int i = 0; i < uniqueSize; ++i)
	{
		resultArray[i] = uniqueNumbers[i];
	}

	return make_pair(resultArray, uniqueSize);
}

template <typename T>
pair<T*, int> commonValuesOfArrays(int amountOfArrays, ...)
{
	static_assert(is_arithmetic_v<T>, "The template type T must be a numeric type.");

	va_list args;
	va_start(args, amountOfArrays);

	unordered_map<T, int>valueCount;
	for (int i = 0; i < amountOfArrays; i++)
	{
		unordered_set<T>seenInCurrentArray;

		int rows = va_arg(args, int);
		int cols = va_arg(args, int);
		T** currentArray = va_arg(args, T**);

		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				if (seenInCurrentArray.find(currentArray[r][c]) == seenInCurrentArray.end())
				{
					valueCount[currentArray[r][c]]++;
					seenInCurrentArray.insert(currentArray[r][c]);
				}
			}
		}
	}

	va_end(args);

	unordered_set<T>commonValues;
	for (const auto& pair : valueCount)
	{
		if (pair.second == amountOfArrays)
		{
			commonValues.insert(pair.first);
		}
	}

	int resultSize = commonValues.size();
	T* resultArray = new T[resultSize];
	int index = 0;
	/*for (auto it = commonValues.begin(); it != commonValues.end(); it++)
	{
		resultArray[index] = *it;
		index++;
	}*/
	for (const T& num : commonValues) {
		// THis code snippet I took from Chat-GPT to fix "buffer overrun" warning
		if (index >= resultSize) {
			cerr << "Index out of bounds! Exceeding resultSize." << endl;
			break; // Stop if overrun happens
		}
		resultArray[index++] = num;
	}

	return make_pair(resultArray, index);
}

template <typename T>
pair <T*, int> negativeNumbersOfArrays(int  amountOfArrays, ...)
{
	static_assert(is_arithmetic_v<T>, "The template type T must be a numeric type.");

	va_list args;
	va_start(args, amountOfArrays);

	unordered_set<T>negNumbers;
	for (int i = 0; i < amountOfArrays; i++)
	{
		int rows = va_arg(args, int);
		int cols = va_arg(args, int);
		T** currentArray = va_arg(args, T**);

		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				if (currentArray[r][c] < 0)
				{
					negNumbers.insert(currentArray[r][c]);
				}
			}
		}
	}

	int resSize = negNumbers.size();
	T* resArray = new T[resSize];

	int index = 0;
	for (const T& num : negNumbers)
	{
		if (index >= resSize)
		{
			cerr << "Index out of bounds! Exceeding resultSize." << endl;
			break; // Stop if overrun happens
		}

		resArray[index++] = num;
	}

	return make_pair(resArray, resSize);
}

#pragma endregion
