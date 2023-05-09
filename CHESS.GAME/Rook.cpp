#include "Rook.h"
Rook::Rook(Board*B,Position _P, COLOR _C) :Piece(B,_P, _C)
{

}


bool Rook::IsLegalMove(Board* B, Position S, Position  D)
{	
	Position Temp;
	if (IsVertical(S, D) and IsVerticalPathClear(B, S, D))
	{
		return true;

	}
	if(IsHorizontal(S,D) and IsHorizontalPathClear(B,S,D))
	{
		return true;
	}

	if (RookCheckEnemy(B, S, D))
	{
		return true;
	}
	return false;

}
void Rook::Draw(int ri, int ci)
{
	char ch = char(-37);

	if (C == White)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	}

	gotoRowCol(ri-2, ci - 1);
	cout << ch<<ch;
	gotoRowCol(ri - 1, ci - 3);
	cout << ch << ch<<ch<<ch<<ch<<ch;

	

	gotoRowCol(ri, ci-2 );
	//cout << "*";
	cout << ch;


	gotoRowCol(ri, ci +1);
	//cout << "*";
	cout << ch;


	gotoRowCol(ri + 1, ci-1);
	//cout << "**";
	cout << ch<<ch;

	gotoRowCol(ri + 2, ci-1);
	//cout << "**";
	cout << ch << ch;

	gotoRowCol(ri + 3, ci-1);
	//cout << "**";
	cout << ch << ch;


	gotoRowCol(ri + 4, ci - 2);
	//cout << "****";
	cout << ch << ch<<ch<<ch;

	//3 4 



}

bool Rook::IsThereLegalMove(Board* B, Position S)
{
	Position D;
	/*bool source = IsWhitePiece(B, S);
	bool Dest;*/

	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
 			D.ri = ri;
			D.ci = ci;

			if ((ISLEGAL(B, S, C, D)))
			{
				return true;
			}			
		}
	}
	return false;
}

void Rook::HighLight_The_Legal_Move(Board* B, Position S)
{

	Position D;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			D.ri = ri;
			D.ci = ci;


			if (ISLEGAL(B, S, C, D))
			{
				HighLight_The_Dabba(D);
			}
		}
	}

}

void Rook::Un_Highlight_The_Moves(Board* B, Position S, Position E)
{
	Position D;
	int colour;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			D.ri = ri;
			D.ci = ci;
			if (IsLegalMove(B, S, D))
			{
				if (D.ri == E.ri and D.ci == E.ci)
				{
					if ((ci % 2 == 0 and ri % 2 == 0) or (ci % 2 != 0 and ri % 2 != 0))
					{
						colour = 15;
					}
					else
					{
						colour = 0;
					}
					for (int i = (ri * 10); i < (ri * 10) + 10; i++)
					{

						for (int j = (ci * 10); j < (ci * 10) + 10; j++)
						{
							gotoRowCol(i, j);

							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
							cout << char(-37);

						}
					}

					for (int i = (ri * 10); i < (ri * 10) + 10; i++)
					{
						for (int j = (ci) * 10; j < (ci * 10) + 10; j++)
						{
							if ((i == ri * 10) or (j == ci * 10))
							{
								gotoRowCol(i, j);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
								cout << char(-37);
							}
						}
					}
				}
				else
				{
					for (int i = (ri * 10); i < (ri * 10) + 10; i++)
					{
						for (int j = (ci) * 10; j < (ci * 10) + 10; j++)
						{

							if ((i == ri * 10) or (j == ci * 10))
							{


								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
								gotoRowCol(i, j);
								cout << char(-37);


							}
							else
							{
								if ((i == (ri * 10) + 9) or (j == (ci * 10) + 9))
								{
									if ((ci % 2 == 0 and ri % 2 == 0) or (ci % 2 != 0 and ri % 2 != 0))
									{
										gotoRowCol(i, j);
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
										cout << char(-37);

									}
									else
									{
										gotoRowCol(i, j);
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
										cout << char(-37);
									}
								}
							}

						}

					}
				}
			}

		}
	}

}

bool Rook::ISLEGAL(Board* B, Position S, COLOR C, Position  D)
{
	if (SelfCheckPieceLegality(B, S, C, D) and IsLegalMove(B, S, D))
	{
		return true;
	}
}