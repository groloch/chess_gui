#pragma once

#include <vector>

#include "chessposition.h"


class ChessGame
{
public:
    ChessGame();

    ChessPiece getPiece(SQUARE) const;

    ChessPiece getPiece(COLUMN, ROW) const;

    bool hasCheck(SQUARE) const;

    void update();

    std::vector<ChessMove> getPossibleMoves() const;

private:
    ChessPosition current;

};

