#pragma once
#include "Piece.h"
class Piece;

class Rook :
    public Piece
{
public:

    Rook(Board* B, Position _P, COLOR _C);
    bool IsLegalMove(Board* B, Position S, Position  D);
    void Draw(int ri, int ci);
    bool IsThereLegalMove(Board* B, Position S);
    void HighLight_The_Legal_Move(Board* B, Position S);
    void Un_Highlight_The_Moves(Board* B, Position S, Position E);
    bool ISLEGAL(Board* B, Position S, COLOR C, Position  D);

};

