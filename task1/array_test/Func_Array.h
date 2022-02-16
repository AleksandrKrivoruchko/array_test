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
int count_space(string str);
// The function takes a string of numbers, returns a pointer to a dynamic arraay of numbers
// You need to free the memory occupied by a dynamic array, when it is no longer needed!!!
// Parameter: string of numbers separated by spaces and tabs (str)
// Return value: pointer to dynamic array
// Uses functions: int CountNumberInString(string), bool IsSumbol(char), int MyStringToInt(char*)
int* convertToInt(string str);
int MyPowerInt(int value);
int MyCharToInt(char c);
// The function takes a pointer to an array of characters of digits of a number, returns a number
// Parameter: pointer to characters array (str)
// Return value: int
// Uses functions: int MyCharToInt(char), int MyPowerInt(int)
int MyStringToInt(char* str);
int CountNumberInString(string str);
minMaxIndex FindMinMaxInArray(int* array, int len);
// The function returns fals if the character is space or tab, otherwise it returns true
// Parameter: char (letter)
// Return value: bool
bool IsSumbol(char letter);
void SortArrayBubble(int* array, int len);
void ReversArray(int* array, int len);
// The function returns true if the desired number is in the array, otherwise - false
// Parameters: pointer to array (array), desired value (value), array length (len)
// Return value: bool (true or false)
bool IsOverlap(int* array, int value, int len);