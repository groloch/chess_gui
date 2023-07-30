#pragma once

#include "../common.h"

class ChessPosition
{
public:
    ChessPosition();

    ChessPosition(FEN);

    ChessPiece getPiece(SQUARE) const;

    ChessPiece getPiece(COLUMN, ROW) const;

    void setPiece(SQUARE, ChessPiece);

    void setPiece(COLUMN, ROW, ChessPiece);

private:
    BITMAP rows01, rows23, rows45, rows67;
};

