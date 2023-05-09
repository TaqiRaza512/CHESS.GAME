#pragma once
#include"Header.h"

class Board;

class Piece
{
protected:
	Position P;
	Board* B;
	COLOR C;

public:	
	Piece(Board*B,Position m_P,COLOR m_C);
	bool RookCheckEnemy(Board* B, Position S, Position  D);
	void UnDraw();
	bool IsVertical(Position S,Position D );
	bool IsHorizontal(Position S, Position D);
	bool IsDiagonal(Position S, Position D);
	bool IsHorizontalPathClear(Board* B, Position S, Position D);
	bool IsVerticalPathClear(Board* B, Position S, Position D);
	bool IsDiagonalPathClear(Board* B, Position S, Position D);
	COLOR ColorOfPiece();
	bool IsWhitePiece(Board* B, Position S);
	bool IsBlackPiece(Board* B, Position S);
	bool IsNullPtr(Position D);
	bool SelfCheckPieceLegality(Board*B, Position S, COLOR Turn, Position D);
	bool PawnDiagonal(Board *B,Position S, Position D);
	void HighLight_The_Dabba(Position D);
	void Un_HighLight(Board *B,Position S);
	void ChangePosition(Board*B,Position _P);


	virtual void Un_Highlight_The_Moves(Board* B,Position S, Position E);
	virtual bool ISLEGAL(Board* B, Position S, COLOR C, Position D);
	virtual void Draw(int i,int c);
	virtual bool IsLegalMove(Board* B, Position S, Position  D);
	virtual void HighLight_The_Legal_Move(Board*B,Position S);
	virtual bool IsKing(Board* B);
	virtual bool IsThereLegalMove(Board* B, Position S);
	~Piece();
};

