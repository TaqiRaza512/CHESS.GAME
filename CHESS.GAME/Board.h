#pragma once
#include"piece.h"
#include"Header.h"
class Piece;
class Board
{
private:
	int Dim;	
	int AllMoves[300][4];
	Piece* PieceMove[300][2];
	int MoveCount = 0;
	int UndoCount = 0;
	Piece*** Ps;
public:
	Board();
	void InIt();
	Piece* getpiece(int row,int col);
	void Draw();
	void Play();
	void PrintGrid();
	void PrintFunctions();
	void SelectSource(Position &S, COLOR Turn);
	bool IsLegalSource(Position S, COLOR Source, COLOR Turn);
	void SelectDestination(Position& S, COLOR Turn);
	bool IsLegalDestination(Position S, COLOR Source, COLOR Turn);
	void Move(COLOR &Turn);
	void AllMovesSave(Position S, Position D);
	void TurnChange(COLOR& turn);
	void ReplayAllMoves(Board* B);
	void Out_Line();
	void SaveBoardInitially();
	void LoadBoardReplay();
	void SaveGame(string name);
	void IfFunctions(Position S,COLOR &Turn,Board* B);
	Piece* IfPawnPromotion(Position S, COLOR Turn, Position D);
	void Castling();
	bool IsCastling(Position S, Position D,COLOR Turn);
	void FindKing(Position &K,COLOR Turn);
	bool IsCheck(COLOR Turn);
	bool CheckMate(COLOR Turn);
	void GameCondition(COLOR Turn);
	void LoadGame(string name);
	bool SelfCheckLegal(Position S, COLOR Turn, Position D);
	void MovePiece(Position S, Position D);
	void UndoMove(COLOR Turn);
	void DoMove(Position S, Position D);
	void RedoMove(COLOR Turn);
	void SelectSourceAndDestination(Position& S, Position& D, COLOR Turn,bool FirstTime,string Valid, COLOR Source,bool &Castling);

	~Board();
};

