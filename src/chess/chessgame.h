#pragma once

#include <vector>

#include "chessposition.h"


class ChessGame
{
public:
    ChessGame();

    Chess::ChessPiece getPiece(Chess::SQUARE) const;

    Chess::ChessPiece getPiece(Chess::COLUMN, Chess::ROW) const;

    bool hasCheck(Chess::SQUARE) const;

    void update();

    std::vector<Chess::ChessMove> getPossibleMoves() const;

    bool getHand() const;

private:
    ChessPosition current;

    bool hand;

};

