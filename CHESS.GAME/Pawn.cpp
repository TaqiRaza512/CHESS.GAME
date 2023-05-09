#include "Pawn.h"
Pawn::Pawn(Board* B, Position _P, COLOR _C):Piece(B, _P,_C)
{
	//sym = ((_C == Black) ? 'P' : 'p');
}
bool Pawn::ISLEGAL(Board* B, Position S,COLOR C,Position  D)
{
	if (SelfCheckPieceLegality(B, S, C, D) and IsLegalMove(B,S,D))
	{
		return true;
	}
}
bool Pawn::IsLegalMove(Board* B, Position S, Position  D)
{

	int sum = 0;
	if (S.ri==D.ri and S.ci==D.ci)
	{
		return false;
	}
	bool v = IsWhitePiece(B, S);
	if (v== true)
	{
		sum = S.ri - D.ri;
	}
	else
	{
		sum = D.ri - S.ri;
	}
	if (IsVertical(S,D)and IsVerticalPathClear(B,S, D))
	{	
			if (S.ri==6 and v==true and sum > 0 and sum<=2)
			{

				return true;
			}
			else if (S.ri==1 and v!=true and sum > 0 and sum<=2)
			{
				return true;
			}
			else if (sum>0 and sum < 2)
			{
				
				return true;
			}			
	}
	else if (IsDiagonal(S,D))
	{

		bool Value = PawnDiagonal(B,S,D);
		if ((abs(D.ri - S.ri)==1) and  abs(D.ci - S.ci)==1 and Value==true)
		{
			if ((S.ri>D.ri) and C==White)
			{
				return true;
			}
			else if(S.ri < D.ri and C == Black)
			{
				return true;
			}
		}		
	}
	return false;
}
void Pawn::Draw(int ri,int ci)
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
	gotoRowCol(ri, ci);
	cout << ch;

	gotoRowCol(ri , ci-1);
	cout << ch;

	gotoRowCol(ri , ci+1);
	cout << ch;

	gotoRowCol(ri+1, ci);
	cout << ch;

	gotoRowCol(ri+1, ci + 2);
	cout << ch;

	gotoRowCol(ri+1, ci -1);
	cout << ch;

	gotoRowCol(ri + 1, ci - 2);
	cout << ch;


	gotoRowCol(ri + 2, ci - 1);
	cout << ch;

	gotoRowCol(ri + 2, ci+1);
	cout << ch;

	gotoRowCol(ri + 3, ci -1);
	cout << ch;

	gotoRowCol(ri + 3, ci + 1);
	cout << ch;
	//===3 4 

	gotoRowCol(ri + 4, ci -2);
	cout << ch;
	
	gotoRowCol(ri + 4, ci - 1);
	cout << ch;

	gotoRowCol(ri -1, ci);
	cout << ch;

	gotoRowCol(ri + 4, ci);
	cout << ch;

	gotoRowCol(ri + 4, ci + 1);
	cout << ch;
	gotoRowCol(ri + 1, ci + 1);
	cout << ch;

	gotoRowCol(ri + 4, ci + 2);
	cout << ch;
}
void Pawn::HighLight_The_Legal_Move(Board*B,Position S)
{
	Position D,K;
	for (int ri=0;ri<8;ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			D.ri = ri;
			D.ci = ci;

			if (!(ri==S.ri and ci==S.ci))
			{
				if (ISLEGAL(B, S, C, D))
				{
					HighLight_The_Dabba(D);
				}
			}
		}
	}
}
bool Pawn::IsThereLegalMove(Board* B, Position S)
{

	Position D;
	if (C==White)
	{
		D.ri = S.ri - 1;
		D.ci = S.ci;


	}
	else
	{
		D.ri = S.ri + 1;
		D.ci = S.ci;

	}	
	if ((ISLEGAL(B, S,C,D)))
	{
		return true;
	}

	for (int ri=0;ri<8;ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{

			D.ri = ri;
			D.ci = ci;
			bool Value = PawnDiagonal(B, S, D);
			if (((abs(D.ri - S.ri) == 1) and abs(D.ci - S.ci) == 1 and Value == true))
			{
				return true;
			}
		}
	}
	return false;	
}
void Pawn::Un_Highlight_The_Moves(Board* B, Position S, Position E)
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
