#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct minMaxIndex
{
	int minIndex;
	int maxIndex;
};

// Function to fill an array with random numbers from -100 to 100
// Parameters: pointer to array (array) and array length (len)
void fill_array(int* array, int len);
// The function creates a dynamic array
// Parameters: array length (len), minimum range number to fill array (min), maximum range number (max)
// The length of the array must be less than the range of numbers to fill array (len <= max - min)
// Return value: pointer to dynamic array
// You need to free the memory occupied by a dynamic array, when it is no longer needed!!!
// To work, the function bool IsOverlap(int*, int , int) is used
int* CreateArrayInt(int len, int min, int max);
// Array output function to console
// Parameters: pointer to array (array) and array length (len)
void print_array(int* array, int len);
// The function counts the number of spaces occupied by spaces and tabs in a line
// Parameter: string (str)
// Return value: int
// Uses function: bool IsSymbol(char)
int count_space(string str);
// The function takes a string of numbers, returns a pointer to a dynamic arraay of numbers
// You need to free the memory occupied by a dynamic array, when it is no longer needed!!!
// Parameter: string of numbers separated by spaces and tabs (str)
// Return value: pointer to dynamic array
// Uses functions: int CountNumberInString(string), bool IsSymbol(char), int MyStringToInt(char*)
int* convertToInt(string str);
// The function takes a positive integer N, returns the number ten to the power of N
// Parameter: int (power)
// Return value: int
int MyPowerInt(int value);
// The function takes a symbol and returns a digit if the symbol is digit,
// -1 if the symbol is a minus or -100 if the symbol is not a digit and not a minus
// Parameter: char (c)
// Return value: int
int MyCharToInt(char c);
// The function takes a pointer to an array of characters of digits of a number, returns a number
// Parameter: pointer to characters array (str)
// Return value: int
// Uses functions: int MyCharToInt(char), int MyPowerInt(int)
int MyStringToInt(char* str);
// The function takes a string of numbers, returns the number of numbers in a string
// Parameter: string of numbers separated by spaces and tabs (str)
// Return value: int
// Uses function: bool IsSymbol(char)
int CountNumberInString(string str);
// The function takes a pointer to an array and it's length and returns a structure
// with the index of the maximum number and with the index of the minimum number
// Parameters: pointer to array (array), array length (len)
// Return value: struct minMaxIndex(int minIndex, int maxIndex)
minMaxIndex FindMinMaxInArray(int* array, int len);
// The function returns fals if the character is space or tab, otherwise it returns true
// Parameter: char (letter)
// Return value: bool
bool IsSymbol(char letter);
void SortArrayBubble(int* array, int len);
void ReversArray(int* array, int len);
// The function returns true if the desired number is in the array, otherwise - false
// Parameters: pointer to array (array), desired value (value), array length (len)
// Return value: bool (true or false)
bool IsOverlap(int* array, int value, int len);