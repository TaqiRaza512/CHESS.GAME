#include<iostream>
#include "Board.h"
using namespace std;
int main()
{
	Board B,Temp;
	COLOR P = White;
	int opt;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "\t\nDO you want to continue";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << " with New Game(1)"; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout <<" OR Saved Game(2)\n";
	cin >> opt;
	switch (opt)
	{
		
	case 1:
		B.PrintGrid();
		B.Out_Line();
		B.Play(); break;
	case 2:		
		B.PrintGrid();
		B.Out_Line();
		B.LoadGame("Save.txt"); B.Draw(); break;
	default:
		cout << "Enter Valid option\n";
		break;
	}
	B.SaveBoardInitially();
	B.PrintFunctions();
	while (true)
	{		
		B.Move(P);
	}
}