#include <iostream>
#include "Piece.h"
#include "Board.h"
using namespace std;
Piece::Piece(Board*B,Position m_P, COLOR m_C)
{
	P = m_P;
	B= this->B;
	C = m_C;	 
}
void Piece::Draw(int i,int c)
{	
	return;
	//this->Draw(i,c);
	//gotoRowCol(i, c);
	////cout << sym;
}
bool Piece::PawnDiagonal(Board*B,Position S,Position D)
{

	Piece* P=B->getpiece(D.ri,D.ci);
	Piece* R= B->getpiece(S.ri,S.ci);
	if (P == nullptr)
	{
		return false;
	}
	COLOR DC=P->ColorOfPiece();
	COLOR DS = R->ColorOfPiece();
	if (DC==DS)
	{
		return false;
	}
	return true;
}
void Piece::UnDraw()
{
	gotoRowCol(P.ri*10,P.ci*10);
	for (int ri=0;ri<10;ri++)
	{
		for (int ci=0;ci<10;ci++)
		{
			gotoRowCol(P.ri * 10 + ri, P.ci * 10 + ci);
			if ((P.ri % 2 == 0 and P.ci % 2 == 0) or (P.ci % 2 != 0 and P.ri % 2 != 0))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			}
			cout << char(-37);		
		}
	}
	for (int i = P.ri * 10; i < ((P.ri * 10)+10); i++)
	{
		for (int j = P.ci * 10; j < ((P.ci * 10) + 10); j++)
		{
			gotoRowCol(i,j);
			if ((i == P.ri * 10) or (j == P.ci * 10))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << char(-37);
			}		
		}
	}
}
bool Piece::IsLegalMove(Board *B, Position S, Position D)
{
	return false;
}
void Piece::ChangePosition(Board*B,Position _P)
{
	P = _P;

}
bool Piece::IsThereLegalMove(Board* B, Position S)
{
	
	return false;
}
bool Piece::IsVertical(Position S, Position D)
{
	return(S.ci == D.ci);
}
bool Piece::SelfCheckPieceLegality(Board*B,Position S, COLOR Turn, Position D)
{
	return (B->SelfCheckLegal(S, Turn, D));
}
void Piece::HighLight_The_Legal_Move(Board*B,Position S)
{
	return;
}
bool Piece::ISLEGAL(Board* B, Position S, COLOR C, Position D)
{
	return false;
}
bool Piece::IsHorizontal(Position S, Position D)
{
	return(S.ri == D.ri);
}
bool Piece::IsDiagonal(Position S, Position D)
{
	return(abs(S.ci - D.ci) == abs(S.ri - D.ri));
}
bool Piece::IsWhitePiece(Board*B,Position S)
{

	Piece* P = B->getpiece(S.ri, S.ci);
	if (P==nullptr)
	{
		return false;
	}
	COLOR Q = P->ColorOfPiece();
	if (Q==White)
	{
		return true;
	}
	return false;
}
bool Piece::IsBlackPiece(Board* B, Position S)
{

	Piece* P = B->getpiece(S.ri, S.ci);
	if (P == nullptr)
	{
		return false;
	}
	COLOR Q = P->ColorOfPiece();
	if (Q == Black)
	{
		return true;
	}
	return false;
}
bool Piece::RookCheckEnemy(Board* B, Position S, Position  D)
{
	bool SourceWhite = IsWhitePiece(B, S);
	bool SourceBlack = IsBlackPiece(B, S);

	bool DestWhite = IsWhitePiece(B, D);
	bool DestBlack = IsBlackPiece(B, D);
	int temp = 0;
	if (IsHorizontal(S, D) and SourceWhite == true and DestBlack==true)
	{
		if (abs(S.ci - D.ci) == 1)
		{
			return true;
		}
		
		if (S.ci > D.ci)
		{
			temp = 0;
			for (int col = D.ci; col < S.ci; col++)
			{
				Piece* P = B->getpiece(S.ri, col);
				if (P == nullptr)
				{
					temp++;
					//return false;
				}
				
			}
			if (temp  ==abs(D.ci-S.ci) - 1)
			{
				return true;

			}

		}
		else
		{
			for (int col = S.ci; col < D.ci; col++)
			{
				temp = 0;
				Piece* P = B->getpiece(S.ri, col);
				if (P == nullptr)
				{
					temp++;

				}
				if (temp  == abs(D.ci - S.ci) - 1)
				{
					return true;

				}
				
			}
		}
	}
	if (IsHorizontal(S, D) and DestWhite == true and SourceBlack == true)
	{
		if (abs(S.ci - D.ci) == 1)
		{
			return true;
		}

		if (S.ci > D.ci)
		{
			temp = 0;
			for (int col = D.ci; col < S.ci; col++)
			{
				Piece* P = B->getpiece(S.ri, col);
				if (P == nullptr)
				{
					temp++;
				}
				
			}
			if (temp == abs(D.ci - S.ci) - 1)
			{
				return true;

			}
		}
		else
		{
			temp = 0;
			for (int col = S.ci; col < D.ci; col++)
			{
				Piece* P = B->getpiece(S.ri, col);
				if (P == nullptr)
				{
					temp++;
				}				

			}
			if (temp == abs(D.ci - S.ci) - 1)
			{
				return true;

			}
		}
	}
	if (IsVertical(S, D) and SourceWhite == true and  DestBlack == true)
	{
		if (abs(S.ri - D.ri) == 1)
		{
			return true;
		}
		if (S.ri > D.ri)
		{
			temp = 0;
			for (int row = D.ri; row < S.ri; row++)
			{
				Piece* P = B->getpiece(row,S.ci);
				if (P == nullptr)
				{
					temp++;
				}
			}
			if (temp == abs(D.ri - S.ri) - 1)
			{
				return true;

			}
		}
		else
		{
			temp = 0;
			for (int row = S.ri; row < D.ri; row++)
			{
				Piece* P = B->getpiece(row, S.ci);
				if (P == nullptr)
				{
					temp++;
				}
				
			
			}
			if (temp  == abs(D.ri - S.ri) - 1)
			{
				return true;

			}

		}

	}
	if (IsVertical(S, D) and DestWhite == true and SourceBlack == true)
	{
		if (abs(S.ci - D.ci) == 1)
		{
			return true;
		}

		if (S.ri > D.ri)
		{
			temp = 0;
			for (int row = D.ri; row < S.ri; row++)
			{
				Piece* P = B->getpiece(row, S.ci);
				if (P == nullptr)
				{
					temp++;
				}
			
			}
			if (temp  == abs(D.ri - S.ri) - 1)
			{
				return true;

			}
		}
		else
		{
			temp = 0;
			for (int row = S.ri; row < D.ri; row++)
			{
				Piece* P = B->getpiece(row, S.ci);
				if (P == nullptr)
				{
					temp++;
				}
			
			}
			if (temp == abs(D.ri - S.ri) - 1)
			{
				return true;

			}
		}

	}
	return false;

}
void Piece::Un_HighLight(Board* B, Position S)
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
bool Piece::IsHorizontalPathClear(Board* B,Position S, Position D)
{
	if (S.ci == D.ci)
	{
		return false;
	}
	if (S.ci > D.ci)
	{
		for (int col = D.ci; col < S.ci; col++)
		{
			Piece* P = B->getpiece(S.ri, col);
			if (P != nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		for (int col = D.ci; col > S.ci; col--)
		{	
			Piece* P = B->getpiece(S.ri, col);

			if (P != nullptr)
			{
				return false;
			}
		}
	}
		return true;
}
bool Piece::IsVerticalPathClear(Board* B, Position S, Position D)
{

	if (S.ri==D.ri and S.ci==D.ci)
	{
		return false;
	}
	if (S.ri> D.ri)
	{
		for (int row = S.ri-1; row >=D.ri ; row--)
		{
			Piece* P = B->getpiece(row, S.ci);

			if (P != nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		for (int row = S.ri + 1; row <= D.ri; row++)
		{
			Piece* P = B->getpiece(row, S.ci);

			if (P != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}
bool Piece::IsDiagonalPathClear(Board* B, Position S, Position D)
{
	if (D.ci>S.ci&&D.ri>S.ri)
	{
		
		for (int ri=S.ri+1, ci=S.ci+1;ri< D.ri;ri++,ci++)
		{
			Piece* P = B->getpiece(ri, ci);

			if (P!=nullptr)
			{
				return false;
			}
		}
		return true;

	}
	else if (S.ri<D.ri&&S.ci>D.ci)
	{
		for (int ri=S.ri + 1,ci=S.ci-1;ri< D.ri;ri++,ci--)
		{			
			Piece* P = B->getpiece(ri, ci);
			if (P != nullptr)
			{
				return false;
			}
		}
		return true;

	}
	else if (S.ri>D.ri&&S.ci>D.ci)
	{
		for (int ri = S.ri - 1, ci = S.ci - 1; ri > D.ri; ri--, ci--)
		{
			Piece* P = B->getpiece(ri, ci);
			if (P != nullptr)
			{
				return false;
			}
		}
		return true;

	}
	else if(S.ri>D.ri && S.ci<D.ci)
	{
		for (int ri = S.ri - 1,ci = S.ci + 1; ri > D.ri; ri--, ci++)
		{
			Piece* P = B->getpiece(ri, ci);
			if (P != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
COLOR Piece::ColorOfPiece()
{
	return this->C;
}
void Piece::HighLight_The_Dabba(Position D)
{
	for (int ri=D.ri*10;ri<= (D.ri * 10)+9;ri++)
	{		
		for (int ci = D.ci * 10; ci < (D.ci * 10) + 10; ci++)
		{
			if ((ri== D.ri * 10 or ri==(D.ri * 10)+9) or (ci == D.ci * 10 or ci == (D.ci * 10)+9))
			{
				gotoRowCol(ri, ci);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << char(-37);
			}
		}
	}
}
void Piece::Un_Highlight_The_Moves(Board* B, Position S, Position E)
{
	return;
}
bool Piece::IsKing(Board* B)
{
	return false;
}
Piece::~Piece()
{

}
