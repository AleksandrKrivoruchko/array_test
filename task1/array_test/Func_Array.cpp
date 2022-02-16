#include "Func_Array.h"

using namespace std;

// Function to fill an array with random numbers from -100 to 100
// Parameters: pointer to array (array) and array length (len)
void fill_array(int* array, int len)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(-100, 100);
	for (int i = 0; i < len; i++)
		*array++ = dist(gen);
}

// The function creates a dynamic array
// Parameters: array length (len), minimum range number to fill array (min), maximum range number (max)
// The length of the array must be less than the range of numbers to fill array (len <= max - min)
// Return value: pointer to dynamic array
// You need to free the memory occupied by a dynamic array, when it is no longer needed!!!
// To work, the function bool IsOverlap(int*, int , int) is used
int* CreateArrayInt(int len, int min, int max)
{
	int* ptrArray = new int[len];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	int temp = 0;
	*(ptrArray++) = dist(gen);
	for (int i = 1; i < len; i++)
	{
		temp = dist(gen);
		if (IsOverlap(ptrArray-i, temp, i))
		{
			i--;
			continue;
		}
		else
		{
			*(ptrArray++) = temp;
		}
	}

	return ptrArray - len;
}

// The function returns true if the desired number is in the array, otherwise - false
// Parameters: pointer to array (array), desired value (value), array length (len)
// Return value: bool (true or false)
bool IsOverlap(int* array, int value, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (value == array[i])
			return true;
	}
	return false;
}

// Array output function to console
// Parameters: pointer to array (array) and array length (len)
void print_array(int* array, int len)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		cout << *array++ << "\t";
		k++;
		if (k == 10)
		{
			cout << endl;
			k = 0;
		}
	}
	cout << endl;
}

// The function counts the number of spaces occupied by spaces and tabs in a line
// Parameter: string (str)
// Return value: int
// Uses function: bool IsSymbol(char)
int count_space(string str)
{
	int count = 0;
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		if (IsSymbol(str[i]))
		{
			while (IsSymbol(str[i]))
			{
				i++;
				if (i == len)
				{
					break;
				}
			}
			count++;
		}
	}
	return count;
}

// The function takes a string of numbers, returns a pointer to a dynamic arraay of numbers
// You need to free the memory occupied by a dynamic array, when it is no longer needed!!!
// Parameter: string of numbers separated by spaces and tabs (str)
// Return value: pointer to dynamic array
// Uses functions: int CountNumberInString(string), bool IsSymbol(char), int MyStringToInt(char*)
int* convertToInt(string str)
{
	char tmp[10] = {};
	int len = CountNumberInString(str);
	int* ar = new int[len];
	int k = 0;
	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (IsSymbol(str[i]))
		{
			while (IsSymbol(str[i]))
			{
				tmp[j] = str[i];
				j++;
				i++;
				if (i == str.size())
				{
					break;
				}
			}
			tmp[j] = '\0';
			ar[k] = MyStringToInt(tmp);
			k++;
			j = 0;
		}
	}
	return ar;
}

// The function returns fals if the character is space or tab, otherwise it returns true
// Parameter: char (letter)
// Return value: bool
bool IsSymbol(char letter)
{
	if (letter == '\t') return false;
	if (letter == ' ') return false;
	return true;
}

// The function takes a pointer to an array of characters of digits of a number, returns a number
// Parameter: pointer to characters array (str)
// Return value: int
// Uses functions: int MyCharToInt(char), int MyPowerInt(int)
int MyStringToInt(char* str) {
	int len = strlen(str);
	int k = 0, sum = 0;
	bool sing = false;
	for (int i = len - 1; i >= 0; i--)
	{
		if (MyCharToInt(str[i]) < 0)
		{
			sing = true;
		}
		else
		{
			sum += MyCharToInt(str[i]) * MyPowerInt(k);
		}
		k++;

	}
	if (sing)
	{
		sum *= -1;
	}
	return sum;
}

// The function takes a symbol and returns a digit if the symbol is digit,
// -1 if the symbol is a minus or -100 if the symbol is not a digit and not a minus
// Parameter: char (c)
// Return value: int
int MyCharToInt(char c)
{
	switch (c)
	{
	case '-':
		return -1;
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return -100;
	}
}

// The function takes a positive integer N, returns the number ten to the power of N
// Parameter: int (power)
// Return value: int
int MyPowerInt(int power)
{
	int multi = 1;
	if (power == 0) return multi;
	while (power--)
	{
		multi *= 10;
	}
	return multi;
}

// The function takes a string of numbers, returns the number of numbers in a string
// Parameter: string of numbers separated by spaces and tabs (str)
// Return value: int
// Uses function: bool IsSymbol(char)
int CountNumberInString(string str)
{
	int len = str.size();
	bool isNumber = true;
	int countNumber = 0;
	for (int i = 0; i < len; i++)
	{
		if (IsSymbol(str[i]) && isNumber)
		{
			countNumber++;
			isNumber = false;
		}
		else
		{
			if (i != 0 && !IsSymbol(str[i]) && IsSymbol(str[i-1]))
			{
				isNumber = true;
			}
		}
	}
	return countNumber;
}

// The function takes a pointer to an array and it's length and returns a structure
// with the index of the maximum number and with the index of the minimum number
// Parameters: pointer to array (array), array length (len)
// Return value: struct minMaxIndex(int minIndex, int maxIndex)
minMaxIndex FindMinMaxInArray(int* array, int len)
{
	minMaxIndex index = { 0, 0 };
	for (int i = 1; i < len; i++)
	{
		if (array[i] > array[index.maxIndex])
		{
			index.maxIndex = i;
		}
		else
		{
			if (array[i] < array[index.minIndex])
			{
				index.minIndex = i;
			}
		}
	}
	return index;
}

void SortArrayBubble(int* array, int len)
{
	int tmp = 0;
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < len - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

void ReversArray(int* array, int len)
{
	int tmp;
	for (int i = 0; i < len / 2; i++)
	{
		tmp = array[i];
		array[i] = array[len - i - 1];
		array[len - i - 1] = tmp;
	}
}