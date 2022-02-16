// array_test.cpp

#include <fstream>
#include "Func_Array.h"

using namespace std;

int main()
{
	setlocale(0, "");
	
	// Creating an array and filling with random numbers
	// The file (file1.txt) is overwritten at each programm startup
	// The lengh of the array is entered by the user from the keyboard
	// Writing this array to text file, numbers are separated by tabs
	cout << "Введите количество элементов в массиве: ";
	int len = 10;
	if (!(cin >> len))
	{
		len = 10;
	}
	int* array = new int[len];
	fill_array(array, len);
	ofstream outfile("file1.txt");
	if (outfile.is_open())
	{
		int k = 0;
		for (int i = 0; i < len; i++)
		{
			k++;
			outfile << array[i] << "\t";
			if (k == 10)
			{
				outfile << "\n";
				k = 0;
			}
		}
	}
	outfile.close();

	// Array output function to console
	// Parameters: pointer to array (array) and array length (len)
	print_array(array, len);

	delete[] array;
	/*ifstream infile("file1.txt");
	string in_str;
	vector<string> tfile;
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			getline(infile, in_str);
			tfile.push_back(in_str);
			cout << in_str << endl;
		}
		cout << endl;
	}

	infile.close();
	vector<string> change_v;
	int len_v = tfile.size();
	for (int i = 0; i < len_v; i++)
	{
		if (tfile[i] != "")
		{
			change_v.push_back(tfile[i]);
		}
	}
	string str_num = tfile[0];
	
	int count_value = 0;
	int** ar_v = new int*[change_v.size()];
	int* ar_vLen = new int[change_v.size()];
	int arrayLen = 0;
	for (int i = 0; i < change_v.size(); i++)
	{
		ar_v[i] = convertToInt(change_v[i]);
		count_value = CountNumberInString(change_v[i]);
		arrayLen += count_value;
		ar_vLen[i] = count_value;
	}

	int* arrayInt = new int[arrayLen];
	int k = 0;
	for (int i = 0; i < change_v.size(); i++)
	{
		for (int j = 0; j < ar_vLen[i]; j++)
		{
			arrayInt[k] = ar_v[i][j];
			k++;
		}
	}

	delete[] ar_v, ar_vLen;

	cout << endl << endl;
	print_array(arrayInt, arrayLen);
	cout << endl << endl;*/

	/*minMaxIndex element = FindMinMaxInArray(arrayInt, arrayLen);
	cout << endl << "Максимальный элемент массива " << arrayInt[element.maxIndex] << endl;
	cout << "Минимальный элемент массива " << arrayInt[element.minIndex] << endl;
	SortArrayBubble(arrayInt, arrayLen);
	cout << endl;
	print_array(arrayInt, arrayLen);
	ReversArray(arrayInt, arrayLen);
	cout << endl;
	print_array(arrayInt, arrayLen);*/

	//delete[] arrayInt;
	cout << endl << endl;
	int lenArray = 100, min = -200, max = 200;
	int* ptrArray = CreateArrayInt(lenArray, min, max);
	SortArrayBubble(ptrArray, lenArray);
	print_array(ptrArray, lenArray);

	delete[] ptrArray;
	
	return 0;
}
