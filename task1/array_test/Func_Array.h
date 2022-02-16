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
// Parameter: array length (len), minimum range number to fill array (min), maximum range number (max)
// Return value: pointer to array
// You need to free the memory occupied by a dynamic array, when it is no longer needed!!!
int* CreateArrayInt(int len, int min, int max);
// Array output function to console
// Parameters: pointer to array (array) and array length (len)
void print_array(int* array, int len);
int count_space(string str);
int* convertToInt(string str);
int MyPowerInt(int value);
int MyCharToInt(char c);
int MyStringToInt(char* str);
int CountNumberInString(string str);
minMaxIndex FindMinMaxInArray(int* array, int len);
bool IsSumbol(char letter);
void SortArrayBubble(int* array, int len);
void ReversArray(int* array, int len);
bool IsOverlap(int* array, int value, int len);