#include "Func_Array.h"

using namespace std;

void fill_array(int* array, int len)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(-100, 100);
	for (int i = 0; i < len; i++)
		*array++ = dist(gen);
}

int* CreateArrayInt(int len, int min, int max)
{
	int* ptrArray = new int[len];
	int* tmp = ptrArray;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	int temp = 0;
	*tmp++ = dist(gen);
	for (int i = 1; i < len; i++)
	{
		temp = dist(gen);
		if (IsOverlap(ptrArray, temp, i))
		{
			i--;
			continue;
		}
		else
		{
			*tmp++ = temp;
		}
	}
	cout << "указатель на выделенную память - " << ptrArray  << endl;
	cout << "указатель на массив - " << tmp - len << endl;
	return ptrArray;
}

bool IsOverlap(int* array, int value, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (value == array[i])
			return true;
	}
	return false;
}

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

int count_space(string str)
{
	int count = 0;
	int len = str.size();
	//cout << endl << len << " in count_space" << endl;
	for (int i = 0; i < len; i++)
	{
		if (IsSumbol(str[i]))
		{
			while (IsSumbol(str[i]))
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

int* convertToInt(string str)
{
	char tmp[10] = {};
	/*int len = count_space(str, sumbol);*/
	int len = CountNumberInString(str);
	int* ar = new int[len];
	int k = 0;
	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (IsSumbol(str[i]))
		{
			while (IsSumbol(str[i]))
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

bool IsSumbol(char letter)
{
	if (letter == '\t') return false;
	if (letter == ' ') return false;
	return true;
}

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

int CountNumberInString(string str)
{
	int len = str.size();
	bool isNumber = true;
	int countNumber = 0;
	for (int i = 0; i < len; i++)
	{
		if (IsSumbol(str[i]) && isNumber)
		{
			countNumber++;
			isNumber = false;
		}
		else
		{
			if (i != 0 && !IsSumbol(str[i]) && IsSumbol(str[i-1]))
			{
				isNumber = true;
			}
		}
	}
	return countNumber;
}

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