#include "Bishop.h"
#include"Piece.h"
Bishop::Bishop(Board* B,Position _P, COLOR _C) :Piece(B, _P, _C)
{
	//sym = ((_C == Black) ? 'B' : 'b');

}
bool Bishop::IsLegalMove(Board* B, Position S, Position  D)
{
	if (S.ri==D.ri and S.ci==D.ci)
	{
		return false;		
	}
	
	bool Dest = IsWhitePiece(B, D);
	bool source = IsWhitePiece(B, S);
	bool DestBlack= IsBlackPiece(B, D);
	bool sourceBlack = IsBlackPiece(B, S);

	if (source == true and Dest!= true)
	{
		if (IsDiagonalPathClear(B,S, D) and IsDiagonal(S,D))
		{
			return true;
		}
	}
	else if (sourceBlack == true and DestBlack!=true)
	{
		if (IsBlackPiece(B, D) != true)
		{
			if (IsDiagonalPathClear(B, S, D) and IsDiagonal(S, D))
			{
				return true;
			}			
		}
	}



	
	return false;
}
void Bishop::Draw(int ri, int ci)
{
	if (C == White)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	}
	//3 4 
	char ch = char(-37);

	gotoRowCol(ri-1,ci);
	cout << ch;
	gotoRowCol(ri, ci-1);
	cout << ch<<ch<<ch;

	
	gotoRowCol(ri+1,ci+1);
	cout << ch;
	


	gotoRowCol(ri + 1, ci - 1);
	cout << ch;

	gotoRowCol(ri+2,ci);
	cout << ch;


	gotoRowCol(ri+3, ci-1);
	cout << ch;


	gotoRowCol(ri+3, ci+1);
	cout << ch;
	gotoRowCol(ri+4, ci-2);
	cout << ch<<ch<<ch<<ch<<ch;
}
void Bishop::HighLight_The_Legal_Move(Board* B, Position S)
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
bool Bishop::IsThereLegalMove(Board* B, Position S)
{

	Position D;
	
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{

			D.ri = ri;
			D.ci = ci;
			if (IsLegalMove(B,S,D))
			{
				return true;
			}
		}
	}
	return false;
}
void Bishop::Un_Highlight_The_Moves(Board* B, Position S, Position E)
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
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
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
bool Bishop::ISLEGAL(Board* B, Position S, COLOR C, Position  D)
{
	if (SelfCheckPieceLegality(B, S, C, D) and IsLegalMove(B, S, D))
	{
		return true;
	}
}