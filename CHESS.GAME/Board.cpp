#include "Board.h"
#include"Pawn.h"
#include"King.h"
#include"Header.h"
#include"Queen.h"
#include"Pawn.h"
#include"Knight.h"
#include"Bishop.h"
#include"Rook.h"
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
Board::Board()
{

	Dim = 8;
	InIt();
}
void Board::Play()
{
	Draw();
}
Piece* Board::getpiece(int row,int col)
{
	return this->Ps[row][col];
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void Board::InIt()
{
	Ps = new Piece **[8];
	for (int ri = 0; ri < 8; ri++)
	{
		Ps[ri] = new Piece * [Dim] {};
		for (int c=0;c<Dim;c++)
		{
			if (ri==1)
			{
				Ps[ri][c] = new Pawn(this,Position{ ri,c }, Black);
			}
			else if (ri==6)
			{
				Ps[ri][c] = new Pawn(this, Position{ ri,c }, White);
			}
			else if (ri == 0 or ri==Dim-1)
			{
				int row=0;
				string color = "Black";
				int dimension = Dim-1;
				if (ri == 7)
				{
					row = ri;
				}			
				if (c == 0 or c==dimension)
				{
					if (row==0)
					{
						if (c == 0)
						{
							Ps[row][c] = new Rook(this, Position{ ri,c }, Black);
						}
						else
						{
							Ps[row][c] = new Rook(this, Position{ ri,c }, Black);
						}
					}
					else
					{
						if (c == 0)
						{
							Ps[row][c] = new Rook(this, Position{ ri,c }, White);
						}
						else
						{
							Ps[row][c] = new Rook(this, Position{ ri,c }, White);
						}
					}
				}
				else if (c== 1 or c==dimension-1)
				{
					if (row==0)
					{

						if (c == 1)
						{
							Ps[row][c] = new Knight(this, Position{ ri,c }, Black);
						}
						else
						{
							Ps[row][c] = new Knight(this, Position{ ri,c }, Black);
						}
					}
					else
					{
						if (c == 1)
						{
							Ps[row][c] = new Knight(this, Position{ ri,c }, White);
						}
						else
						{
							Ps[row][c] = new Knight(this, Position{ ri,c }, White);
						}

					}
				}
				else if (c ==2  or c == dimension - 2)
				{
					if (row==0)
					{

						if (c == 2)
						{
							Ps[row][c] = new Bishop(this, Position{ ri,c }, Black);
						}
						else
						{
							Ps[row][c] = new Bishop(this, Position{ ri,c }, Black);
						}
					}
					else
					{
						if (row==0)
						{
							if (c == 2)
							{
								Ps[row][c] = new Bishop(this, Position{ ri,c }, Black);
							}
							else
							{
								Ps[row][c] = new Bishop(this, Position{ ri,c }, Black);
							}
						}
						else
						{
							if (c == 2)
							{
								Ps[row][c] = new Bishop(this, Position{ ri,c }, White);
							}
							else
							{
								Ps[row][c] = new Bishop(this, Position{ ri,c},White);
							}
						}
					}

				}
				else if (c == 3 or c == dimension - 3)
				{
					if (row==0)
					{

						if (c == dimension - 3)
						{
							Ps[row][c] = new King(this, Position{ ri,c }, Black);
						}
						else
						{

							Ps[row][c] = new Queen(this, Position{ ri,c }, Black);
						}
					}
					else
					{

						
						if (c == dimension - 3)
						{
							Ps[row][c] = new King(this, Position{ ri,c }, White);
						}
						else
						{

							Ps[row][c] = new Queen(this, Position{ ri,c }, White);
						}
					}
				}
			}
		}
	}
}
void Board::Draw()
{
	int rows = 5, cols = 0;
	for (int i=0;i<Dim;i++)
	{
		cols = 5;
		for (int c = 0; c < Dim; c++)
		{
			if (Ps[i][c]==nullptr)
			{
				cols = 10 + cols;
			}
			else
			{
				gotoRowCol(rows, cols);
				Ps[i][c]->Draw(rows-1,cols);
				cols =10+cols;
			}			
		}
		rows = rows+10;
	}

}
void Board::Castling()
{


}
void Board::TurnChange(COLOR& turn)
{
	if (turn == 0)
	{
		turn = White;
	}
	else
	{
		turn = Black;
	}
}
void Board::PrintGrid()
{

	int k = 0;
	for (int i = 0; i < 8; i++)
	{
		k = i * 10;
		gotoRowCol(k, 0);

		for (int j = 0; j < 8; j++)
		{

			if ((j % 2 == 0 and i % 2 == 0) or (j % 2 != 0 and i % 2 != 0))
			{
				for (int ri = 0; ri <= 9; ri++)
				{
					gotoRowCol(k, j * 10);
					
					for (int ci = 0; ci <= 9; ci++)
					{
						
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << char(-37);
					}
					k++;
					cout << endl;
				}
			}
			else
			{

				for (int ri = 0; ri <= 9; ri++)
				{
					gotoRowCol(k, j * 10);

					for (int ci = 0; ci <=9; ci++)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
						cout << char(-37);
					}
					k++;
					cout << endl;
				}

			}
			k = i * 10;
		}

		cout << endl;


	}

	cout << "\n\n";
}
void Board::SelectSource(Position &S,COLOR Turn)
{
	
	

	getRowColbyLeftClick(S.ri, S.ci);
	S.ci = S.ci / 10;
	S.ri = S.ri / 10;	
}
bool Board::IsLegalSource(Position S, COLOR Source, COLOR Turn)
{
	//return(Turn == Source and Ps[S.ri][S.ci] != nullptr);
	if (S.ri<=8 and S.ci<=8)
	{
		if (Ps[S.ri][S.ci] != nullptr)
		{
			Source = Ps[S.ri][S.ci]->ColorOfPiece();
			return Turn == Source;
		}
	}
	return false;
}
bool Board::IsLegalDestination(Position D, COLOR Source, COLOR Turn)
{
	if (D.ri<8 and D.ci<8)
	{
		return true;
	}
	return false;
}
void Board::SelectDestination(Position& D, COLOR Turn)
{

	
	gotoRowCol(66, 0);
	getRowColbyLeftClick(D.ri, D.ci);
	D.ci = D.ci / 10;
	D.ri = D.ri / 10;
}
void Board::Out_Line()
{
	for (int ri=0;ri<8;ri++)
	{
		for (int ci=0;ci<8;ci++)
		{
		
			
			for (int i = ri * 10; i < (ri * 10) + 10; i++)
			{
				for (int j = ci * 10; j < (ci * 10) + 10; j++)
				{

					if (i == ri * 10 or j == ci * 10)
					{
						gotoRowCol(i, j);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
						cout << char(-37);

					}

				}
			}

		}
	}

	for (int i = 0; i <=(8 * 10) ; i=i++)
	{
		for (int j = 0 * 10; j <=80; j++)
		{
 			if (j == 80 or i==80)
			{
				gotoRowCol(i, j);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				cout << char(-37);
			}
		}
	}
}
void Board::PrintFunctions()
{
	//Saved
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	int ri, ci;
	char ch = -37;
	for (ri=0;ri<= 10;ri++)
	{
		for (ci=0;ci<=10;ci++)
		{
			if ((ri==0 or ri==10)or(ci == 0 or ci == 10))
			{
				gotoRowCol(ri + 30, ci + 90);
				cout << ch;
			}
		}
	}
	int rc = 35;
	int cc = 93;

	gotoRowCol(rc, cc);
	cout << "SAVE";
	//Replay
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	int r=0, c=0;
	for (r= 0; r<= 10; r++)
	{
		for (c = 0; c <= 10; c++)
		{
			if ((r == 0 or r == 10) or (c == 0 or c == 10))
			{
				gotoRowCol(r + 30, c + 100);
				cout << ch;
			}
		}
	}
	rc = 35;
	cc = 103;
	gotoRowCol(rc, cc);
	cout << "REPLAY";
	//Undo
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (r = 0; r <= 10; r++)
	{
		for (c = 0; c <= 10; c++)
		{
			if ((r == 0 or r == 10) or (c == 0 or c == 10))
			{
				gotoRowCol(r + 40, c + 90);
				cout << ch;
			}
		}
	}
	rc = 45;
	cc = 93;
	gotoRowCol(rc, cc);
	cout << "UNDO";
	//Redo
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (r = 0; r <= 10; r++)
	{
		for (c = 0; c <= 10; c++)
		{
			if ((r == 0 or r == 10) or (c == 0 or c == 10))
			{
				gotoRowCol(r + 40, c + 100);
				cout << ch;
			}
		}
	}
	rc = 45;
	cc = 103;
	gotoRowCol(rc, cc);
	cout << "REDO";
}
char IdentifyPiece(Piece* Ps)
{
	Pawn* IsPawn = dynamic_cast<Pawn*>(Ps);
	if (IsPawn!=nullptr)
	{
		if (IsPawn->ColorOfPiece() == Black)
		{
			return 'P';
		}
		return 'p';

	}
	Bishop* IsBishop = dynamic_cast<Bishop*>(Ps);
	if (IsBishop != nullptr)
	{
		if (IsBishop->ColorOfPiece() == Black)
		{
			return 'B';
		}
		return 'b';
	}
	King* IsKing = dynamic_cast<King*>(Ps);
	if (IsKing != nullptr)
	{
		if (IsKing->ColorOfPiece() == Black)
		{
			return 'K';
		}
		return 'k';
	}
	Knight* IsKnight = dynamic_cast<Knight*>(Ps);
	if (IsKnight != nullptr)
	{
		if (IsKnight->ColorOfPiece() == Black)
		{
			return 'H';
		}
		return 'h';
	}
	Queen* IsQueen = dynamic_cast<Queen*>(Ps);
	if (IsQueen != nullptr)
	{
		if (IsQueen->ColorOfPiece() == Black)
		{
			return 'Q';
		}
		return 'q';
	}
	Rook* IsRook = dynamic_cast<Rook*>(Ps);
	if (IsRook != nullptr)
	{
		if (IsRook->ColorOfPiece() == Black)
		{
			return 'R';
		}
		return 'r';
	}
}
void Board::SaveGame(string name)
{
	ofstream file(name);
	gotoRowCol(43, 92);

	for (int ri=0;ri<8;ri++)
	{
		for (int ci=0;ci<8;ci++)
		{
			if (Ps[ri][ci]==nullptr)
			{
				file << "-";

			}
			else
			{
				char ch = IdentifyPiece(Ps[ri][ci]);
				file << ch;
			}
		}
		file << endl;
	}
	
}
void Board::UndoMove(COLOR Turn)
{
	Position S, D,P;
	S.ri = AllMoves[MoveCount][0];
	S.ci = AllMoves[MoveCount][1];
	D.ri = AllMoves[MoveCount][2];
	D.ci = AllMoves[MoveCount][3];
	DoMove(S, D);
}
void Board::DoMove(Position S,Position D)
{
	Ps[S.ri][S.ci] = PieceMove[MoveCount][0];
	Ps[D.ri][D.ci] = PieceMove[MoveCount][1];
	if (Ps[D.ri][D.ci] == nullptr)
	{
		Ps[D.ri][D.ci] = PieceMove[MoveCount][0];
		Ps[D.ri][D.ci]->ChangePosition(this, D);
		Ps[D.ri][D.ci]->UnDraw();
		Ps[D.ri][D.ci] = nullptr;
		Ps[S.ri][S.ci]->ChangePosition(this, S);
		Ps[S.ri][S.ci]->Draw(S.ri * 10 + 4, S.ci * 10 + 5);
	}
	else
	{
		Ps[D.ri][D.ci]->UnDraw();
		Ps[D.ri][D.ci]->ChangePosition(this, D);
		Ps[S.ri][S.ci]->ChangePosition(this, S);
		Ps[D.ri][D.ci]->Draw(D.ri * 10 + 4, D.ci * 10 + 5);
		Ps[S.ri][S.ci]->Draw(S.ri * 10 + 4, S.ci * 10 + 5);
	}
}
void Board::RedoMove(COLOR Turn)
{
	Position S, D, P;
	D.ri = AllMoves[MoveCount][0];
	D.ci = AllMoves[MoveCount][1];
	S.ri = AllMoves[MoveCount][2];
	S.ci = AllMoves[MoveCount][3];
	Ps[S.ri][S.ci] = PieceMove[MoveCount][0];
	Ps[D.ri][D.ci] = PieceMove[MoveCount][1];
	
	if (Ps[D.ri][D.ci] == nullptr)
	{
		Ps[D.ri][D.ci] = PieceMove[MoveCount][0];
		Ps[D.ri][D.ci]->ChangePosition(this, D);
		Ps[D.ri][D.ci]->UnDraw();
		Ps[D.ri][D.ci] = nullptr;
		Ps[S.ri][S.ci]->ChangePosition(this, S);
		Ps[S.ri][S.ci]->Draw(S.ri * 10 + 4, S.ci * 10 + 5);
	}
	else
	{
		Ps[D.ri][D.ci]->ChangePosition(this, D);
		Ps[D.ri][D.ci]->UnDraw();
		Ps[S.ri][S.ci]->ChangePosition(this, S);
		Ps[S.ci][S.ci]->UnDraw();
		Ps[D.ri][D.ci] = nullptr;
		Ps[S.ri][S.ci]->Draw(S.ri * 10 + 4, S.ci * 10 + 5);

	}
}
void Board::IfFunctions(Position S,COLOR &Turn,Board* B)
{
	if (S.ri == 3 && S.ci == 9)
	{
		SaveGame("Save.txt");
		gotoRowCol(28, 82);
		cout << "Game Saved....\r";
	}
	else if (S.ri==3 && S.ci==10)
	{
		system("cls");
		Board Temp;
		Temp.PrintGrid();
		Temp.Out_Line();
		Temp.ReplayAllMoves(B);
		system("cls");
		B->PrintGrid();
		B->Out_Line();
		B->Draw();
		B->PrintFunctions();
	}	
	else if (S.ri==4 and S.ci==9)
	{
		if (MoveCount>0)
		{
			MoveCount--;
			UndoMove(Turn);
			TurnChange(Turn);
			UndoCount++;
		}
	}
	else if (S.ri == 4 and S.ci == 10)
	{
		if (UndoCount>0)
		{
			RedoMove(Turn);
			MoveCount++;
			TurnChange(Turn);
			UndoCount--;
		}
	}
}
Piece* Board::IfPawnPromotion(Position S,COLOR Turn, Position D)
{
	if (S.ri == 6 or S.ri == 1)
	{
		Piece* s = Ps[S.ri][S.ci];

		Pawn* IsPawn = dynamic_cast<Pawn*>(s);
		if (IsPawn != nullptr)
		{
			if (IsPawn->ColorOfPiece() == Turn)
			{
				if ((Turn==0 and S.ri==6) or (Turn == 1 and S.ri == 1))
				{
					gotoRowCol(24, 82);
					cout << "Change Pawn to ....\r";
					gotoRowCol(26, 82);
					cout << "(B)ishop,(R)ook,(Q)ueen,(K)night\r";
					char ch = _getch();
					Ps[D.ri][D.ci] = nullptr;
					switch (ch)
					{

					case 'b':
						Ps[D.ri][D.ci] = new Bishop(this, Position{ D.ri,D.ci}, Turn);
						break;
					case 'r':
						Ps[D.ri][D.ci] = new Rook(this, Position{ D.ri,D.ci}, Turn);
						break;
					case 'q':
						Ps[D.ri][D.ci] = new Queen(this, Position{ D.ri,D.ci}, Turn);
						break;

					case 'k':
						Ps[D.ri][D.ci] = new Knight(this, Position{ D.ri,D.ci }, Turn);
						break;

					default:
						break;
					}
				}



			}
		}
	}
	return Ps[D.ri][D.ci];

}
void Board::LoadGame(string name)
{
	ifstream Rdr(name);
	char ch;
	for (int ri=0;ri<8;ri++)
	{
		for (int ci=0;ci<8;ci++)
		{
			Rdr >> ch;
			switch (ch)
			{
			case 'k':
				Ps[ri][ci] = new King(this, Position{ ri,ci }, White);
				break;
			case 'K':
				Ps[ri][ci] = new King(this, Position{ ri,ci }, Black);
				break;
			case 'p':
				Ps[ri][ci] = new Pawn(this, Position{ ri,ci }, White);
				break;

			case 'P':
				Ps[ri][ci] = new Pawn(this, Position{ ri,ci }, Black);
				break;

			case 'B':

				Ps[ri][ci] = new Bishop(this, Position{ ri,ci }, Black);
				break;

			case 'b':
				Ps[ri][ci] = new Bishop(this, Position{ ri,ci }, White);
				break;


			case 'H':
				Ps[ri][ci] = new Knight(this, Position{ ri,ci }, Black);
				break;

			case 'h':
				Ps[ri][ci] = new Knight(this, Position{ ri,ci }, White);
				break;

			case 'R':
				Ps[ri][ci] = new Rook(this, Position{ ri,ci }, Black);
				break;

			case 'r':
				Ps[ri][ci] = new Rook(this, Position{ ri,ci }, White);
				break;

			case 'q':
				Ps[ri][ci] = new Queen(this, Position{ ri,ci }, White);
				break;

			case 'Q':
				Ps[ri][ci] = new Queen(this, Position{ ri,ci },Black);
				break;
			case '-':
				Ps[ri][ci] = nullptr;
				break;
			}
			
		}
	}
}
void Board::SaveBoardInitially()
{
	ofstream file("Initial_Board.txt");
	gotoRowCol(43, 92);
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (Ps[ri][ci] == nullptr)
			{
				file << "-";

			}
			else
			{
				char ch = IdentifyPiece(Ps[ri][ci]);
				file << ch;
			}
		}
		file << endl;
	}
}
void Board::LoadBoardReplay()
{
	ifstream Rdr("InitialBoard.txt");
	char ch;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			Rdr >> ch;
			switch (ch)
			{
			case 'k':
				Ps[ri][ci] = new King(this, Position{ ri,ci }, White);
				break;
			case 'K':
				Ps[ri][ci] = new King(this, Position{ ri,ci }, Black);
				break;
			case 'p':
				Ps[ri][ci] = new Pawn(this, Position{ ri,ci }, White);
				break;

			case 'P':
				Ps[ri][ci] = new Pawn(this, Position{ ri,ci }, Black);
				break;

			case 'B':

				Ps[ri][ci] = new Bishop(this, Position{ ri,ci }, Black);
				break;

			case 'b':
				Ps[ri][ci] = new Bishop(this, Position{ ri,ci }, White);
				break;


			case 'H':
				Ps[ri][ci] = new Knight(this, Position{ ri,ci }, Black);
				break;

			case 'h':
				Ps[ri][ci] = new Knight(this, Position{ ri,ci }, White);
				break;

			case 'R':
				Ps[ri][ci] = new Rook(this, Position{ ri,ci }, Black);
				break;

			case 'r':
				Ps[ri][ci] = new Rook(this, Position{ ri,ci }, White);
				break;

			case 'q':
				Ps[ri][ci] = new Queen(this, Position{ ri,ci }, White);
				break;

			case 'Q':
				Ps[ri][ci] = new Queen(this, Position{ ri,ci }, Black);
				break;
			case '-':
				Ps[ri][ci] = nullptr;
				break;
			}

		}
	}

}
void Board::AllMovesSave(Position S,Position D)
{
	PieceMove[MoveCount][0] = Ps[S.ri][S.ci];
	PieceMove[MoveCount][1] = Ps[D.ri][D.ci];
	AllMoves[MoveCount][0]=S.ri;
	AllMoves[MoveCount][1] = S.ci;
	AllMoves[MoveCount][2] = D.ri;
	AllMoves[MoveCount][3] = D.ci;
	MoveCount++;
}
void Board::ReplayAllMoves(Board* B)
{
	LoadBoardReplay();
	Draw();
	Position S, D, P{0};
	gotoRowCol(33, 82);
	cout << "=====================";
	gotoRowCol(36, 82);
	cout << "\tREPLAY---MODE";
	gotoRowCol(38, 82);
	cout << "=====================";

	for (int r = 0; r < (B->MoveCount); r++)
	{
		S.ri = B->AllMoves[r][0];
		S.ci = B->AllMoves[r][1];
		D.ri = B->AllMoves[r][2];
		D.ci = B->AllMoves[r][3];
		Ps[S.ri][S.ci]->HighLight_The_Legal_Move(this, S);
		Sleep(1500);
		Ps[S.ri][S.ci]->UnDraw();
		Ps[S.ri][S.ci]->Un_Highlight_The_Moves(this, S, D);
		Ps[D.ri][D.ci] = Ps[S.ri][S.ci];
		P.ri = D.ri;
		P.ci = D.ci;
		Ps[D.ri][D.ci]->ChangePosition(this,P);
		Ps[D.ri][D.ci]->Draw(D.ri * 10 + 4, D.ci * 10 + 5);
		Ps[S.ri][S.ci] = nullptr;	
	}
}
bool Board::SelfCheckLegal(Position S, COLOR Turn, Position D)
{
	Position P;
	Board Temp;
	if (Ps[D.ri][D.ci]!=nullptr)
	{
		if (Ps[D.ri][D.ci]->IsKing(this))
		{
			return false;
		}
	}
	SaveGame("SaveFileForSelfCheck.txt");
	Temp.LoadGame("SaveFileForSelfCheck.txt");
	Temp.MovePiece(S, D);
	if (Temp.IsCheck(Turn))
	{
		return false;
	}		
	return true;
}
void Board::GameCondition(COLOR Turn)
{
	if (IsCheck(Turn))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoRowCol(20, 82);
		cout << "The King of Player " << Turn << " is in check ";
	}
	if (CheckMate(Turn) and IsCheck(Turn))
	{
		system("cls");
		TurnChange(Turn);
		gotoRowCol(40, 40);
		cout << "==================================";
		gotoRowCol(42, 50);
		cout << "Player " << Turn << " Won...";
		gotoRowCol(44, 40);
		cout << "==================================";

	}
	if (CheckMate(Turn) and !IsCheck(Turn))
	{
		system("cls");
		gotoRowCol(40, 40);
		cout << "==================================";
		gotoRowCol(42, 50);
		cout << "Player " << Turn << " Stalemated...";
		gotoRowCol(44, 40);
		cout << "==================================";
	}
}
void Board::SelectSourceAndDestination(Position&S,Position &D,COLOR Turn,bool FirstTime,string Valid,COLOR Source,bool &Castling)
{
	do
	{
		if (FirstTime == false)
		{
			
			cout << "\a";
			Valid = "valid";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		gotoRowCol(24, 82);
		cout << "Player " << Turn << " Turn's \r";
		gotoRowCol(26, 82);
		cout << "Please Select " << Valid << " Source Position\r";
		SelectSource(S, Turn);
		IfFunctions(S, Turn, this);
		FirstTime = false;
	} while (!(IsLegalSource(S, Source, Turn) and Ps[S.ri][S.ci]->IsThereLegalMove(this, S)));
	gotoRowCol(26, 100);
	cout << "                 ";
	Ps[S.ri][S.ci]->HighLight_The_Legal_Move(this, S);
	FirstTime = true;
	Valid = "";
	do
	{
		if (FirstTime == false)
		{
			Valid = "valid";
		}
		gotoRowCol(26, 82);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "Please Select " << Valid << " Destination.\r";
		SelectDestination(D, Turn);
		IfFunctions(D, Turn, this);
	
		if (Ps[D.ri][D.ci] != nullptr)
		{
			if (Ps[D.ri][D.ci]->ColorOfPiece() == Turn)
			{
				if (IsLegalSource(D, Turn, Turn) and Ps[D.ri][D.ci]->IsThereLegalMove(this, D))
				{
					gotoRowCol(20, 82);
					cout << "                               \r";
					Ps[S.ri][S.ci]->Un_HighLight(this, S);
					S.ri = D.ri;
					S.ci = D.ci;
					Ps[S.ri][S.ci]->HighLight_The_Legal_Move(this, S);
					SelectDestination(D, Turn);
					IfFunctions(D, Turn, this);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					gotoRowCol(20, 82);

					cout << "                               \r";
					gotoRowCol(20, 82);
					cout << "This is not a Valid Source.\r";
				}
			}
		}
		FirstTime = false;
	} while (!(IsLegalDestination(D, Source, Turn) and Ps[S.ri][S.ci]->ISLEGAL(this, S, Turn, D)));
}

void Board::Move(COLOR& Turn)
{
	bool FirstTime = true,Castling=false;
	Position P, S, D;										
	string Valid = "";
	COLOR Source = White;
	GameCondition(Turn);	
	SelectSourceAndDestination(S, D, Turn, FirstTime, Valid, Source,Castling);
	if (Castling == true)
	{
		return;
	}

	if (Ps[S.ri][S.ci]->ISLEGAL(this, S,Turn,D))
	{
		AllMovesSave(S, D);
		Ps[S.ri][S.ci]->UnDraw();
		Ps[S.ri][S.ci]->Un_Highlight_The_Moves(this, S, D);
		Ps[D.ri][D.ci] = Ps[S.ri][S.ci];
		Ps[D.ri][D.ci] = IfPawnPromotion(S, Turn, D);
		P.ri = D.ri;
		P.ci = D.ci;
		Ps[D.ri][D.ci]->ChangePosition(this,P);
		Ps[S.ri][S.ci] = nullptr;
		Ps[D.ri][D.ci]->Draw(D.ri * 10 + 4, D.ci * 10 + 5);
		gotoRowCol(28, 82);
		cout << "              \r";
		gotoRowCol(20, 82);
		cout << "                                 \r";
	}
	gotoRowCol(22, 82);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "Player " << Turn << " Move : (" << S.ri + 1 << ", " << S.ci + 1 << ")-->(" << D.ri + 1 << ", " << D.ci + 1 << ")\r";
	TurnChange(Turn);
	UndoCount = 0;
}
void Board::MovePiece(Position S,Position D)
{
	Position P;
	Ps[D.ri][D.ci] = Ps[S.ri][S.ci];
	P.ri = D.ri;
	P.ci = D.ci;
	Ps[D.ri][D.ci]->ChangePosition(this,P);
	Ps[S.ri][S.ci] = nullptr;
}
void Board::FindKing(Position &K,COLOR Turn)
{
	for (int ri=0;ri<8;ri++)
	{
		for (int ci=0;ci<8;ci++)
		{
			if (this->Ps[ri][ci]!=nullptr)
			{
				if (this->Ps[ri][ci]->ColorOfPiece() == Turn)
				{

					if (this->Ps[ri][ci]->IsKing(this))
					{

						K.ri = ri;
						K.ci = ci;
						return;
					}
				}
			}
		}
	}
}
bool Board::CheckMate(COLOR Turn)
{
	Position D,P,S;
	for (int ri=0;ri<8;ri++)
	{
		for (int ci=0;ci<8;ci++)
		{
			if (Ps[ri][ci]!=nullptr)
			{
				if (Ps[ri][ci]->ColorOfPiece() == Turn)
				{
					S.ri = ri;
					S.ci = ci;
					for (int i = 0; i < 8; i++)
					{
						for (int c = 0; c < 8; c++)
						{
							D.ri = i;
							D.ci = c;
							if (Ps[ri][ci]->ISLEGAL(this, S, Turn, D))
							{
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
bool Board::IsCheck(COLOR Turn)
{
	Position K,S;
	FindKing(K,Turn);
	TurnChange(Turn);
	for (int ri=0;ri<8;ri++)
	{
		for (int ci=0;ci<8;ci++)
		{
			if (Ps[ri][ci]!=nullptr)
			{
				if (Ps[ri][ci]->ColorOfPiece() == Turn)
				{
					S.ri = ri;
					S.ci = ci;
					if (Ps[ri][ci]->IsLegalMove(this, S, K))
					{
						return true;
					}
				}
			}
		}
	}
	TurnChange(Turn);
	return false;
}
Board::~Board()
{
}
