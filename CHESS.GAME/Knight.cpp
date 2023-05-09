#include "Knight.h"

Knight::Knight(Board* B, Position _P, COLOR _C):Piece(B, _P, _C)
{
	
	//sym = ((_C== Black) ? 'H' : 'h');
}
bool Knight::IsLegalMove(Board* B, Position S, Position  D)
{	
	bool Dest = IsWhitePiece(B, D);
	bool source = IsWhitePiece(B, S);

	if (source==true and Dest!=true)
	{
		if (!(IsVertical(S, D) and IsHorizontal(S, D) and IsDiagonal(S, D)))
		{
			if (abs(S.ri - D.ri) == 2 and abs(S.ci - D.ci) == 1)
			{
				return true;
			}
			else if (abs(S.ri - D.ri) == 1 and abs(S.ci - D.ci) == 2)
			{
				return true;
			}
		}
	}
	else if(source==false)
	{
		if (IsBlackPiece(B,D)!=true)
		{
			if (!(IsVertical(S, D) and IsHorizontal(S, D) and IsDiagonal(S, D)))
			{
				if (abs(S.ri - D.ri) == 2 and abs(S.ci - D.ci) == 1)
				{
					return true;
				}
				else if (abs(S.ri - D.ri) == 1 and abs(S.ci - D.ci) == 2)
				{
					return true;
				}
			}
		}

	}

	return false;
}
void Knight::Draw(int ri, int ci)
{
	if (C == White)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	}
	char ch = -37;
	gotoRowCol(ri - 1, ci);
	cout << ch<< ch<< ch;

	gotoRowCol(ri, ci-1);
	cout << ch;
	gotoRowCol(ri, ci +2);
	cout << ch;
	gotoRowCol(ri+1, ci-2);
	cout << ch;
	gotoRowCol(ri+1, ci + 1);
	cout << ch;
	gotoRowCol(ri, ci + 2);
	cout << ch;

	gotoRowCol(ri+2, ci -1);
	cout << ch;
	gotoRowCol(ri+2, ci + 1);
	cout << ch;

	gotoRowCol(ri+3, ci - 2);
	cout << ch;

	gotoRowCol(ri+3, ci + 2);
	cout << ch;

	//3 4

	gotoRowCol(ri + 4, ci - 2);
	cout << ch << ch<<ch<< ch<< ch;

}
bool Knight::IsThereLegalMove(Board* B, Position S)
{
	Position D;
	bool source = IsWhitePiece(B, S);
	bool Dest;



	for (int ri=0;ri<8;ri++)
	{
		for (int ci=0;ci<8;ci++)
		{
			D.ri = ri;
			D.ci = ci;
			Dest = IsWhitePiece(B,D);

			if (IsLegalMove(B,S,D)and Dest!=source)
			{
				return true;
			}
		}
	}
}
void Knight::HighLight_The_Legal_Move(Board* B, Position S)
{
	Position D;
	bool Dest;
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
void Knight::Un_Highlight_The_Moves(Board* B, Position S, Position E)
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
bool Knight::ISLEGAL(Board* B, Position S, COLOR C, Position  D)
{
	if (SelfCheckPieceLegality(B, S, C, D) and IsLegalMove(B, S, D))
	{
		return true;
	}
}

