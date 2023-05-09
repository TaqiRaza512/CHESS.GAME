#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
using namespace std;

struct Position
{
	int ri;
	int ci;
};
enum COLOR
{
	Black, White
};
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
