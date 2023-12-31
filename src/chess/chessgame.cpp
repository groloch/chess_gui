#include "chessgame.h"

using namespace Chess;

ChessGame::ChessGame() : current(), hand(true)
{

}

ChessPiece ChessGame::getPiece(SQUARE sq) const{
    return current.getPiece(sq);
}

ChessPiece ChessGame::getPiece(COLUMN col, ROW row) const{
    return current.getPiece(col, row);
}

bool ChessGame::hasCheck(SQUARE sq) const{
    return false;
}

void ChessGame::update(){
    return;
}

std::vector<ChessMove> ChessGame::getPossibleMoves() const{
    std::vector<ChessMove> pm;
    return pm;
}

bool ChessGame::getHand() const{
    return hand;
}
