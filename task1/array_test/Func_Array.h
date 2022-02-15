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

void fill_array(int* array, int len);
int* CreateArrayInt(int len, int min, int max);
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