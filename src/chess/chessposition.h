#pragma once

#include "../common.h"

class ChessPosition
{
public:
    ChessPosition();

    ChessPosition(Chess::FEN);

    Chess::ChessPiece getPiece(Chess::SQUARE) const;

    Chess::ChessPiece getPiece(Chess::COLUMN, Chess::ROW) const;

    void setPiece(Chess::SQUARE, Chess::ChessPiece);

    void setPiece(Chess::COLUMN, Chess::ROW, Chess::ChessPiece);

private:
    Chess::BITMAP rows01, rows23, rows45, rows67;
};

