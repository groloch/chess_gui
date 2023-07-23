#include "chessposition.h"

ChessPosition::ChessPosition() : rows01 (0), rows23(0), rows45(0), rows67(0)
{
    setPiece(0, 0, { 1, 2 });
    setPiece(1, 0, { 1, 3 });
    setPiece(2, 0, { 1, 4 });
    setPiece(3, 0, { 1, 5 });
    setPiece(4, 0, { 1, 6 });
    setPiece(5, 0, { 1, 4 });
    setPiece(6, 0, { 1, 3 });
    setPiece(7, 0, { 1, 2 });

    setPiece(0, 1, { 1, 1 });
    setPiece(1, 1, { 1, 1 });
    setPiece(2, 1, { 1, 1 });
    setPiece(3, 1, { 1, 1 });
    setPiece(4, 1, { 1, 1 });
    setPiece(5, 1, { 1, 1 });
    setPiece(6, 1, { 1, 1 });
    setPiece(7, 1, { 1, 1 });

    setPiece(0, 6, { 0, 1 });
    setPiece(1, 6, { 0, 1 });
    setPiece(2, 6, { 0, 1 });
    setPiece(3, 6, { 0, 1 });
    setPiece(4, 6, { 0, 1 });
    setPiece(5, 6, { 0, 1 });
    setPiece(6, 6, { 0, 1 });
    setPiece(7, 6, { 0, 1 });

    setPiece(0, 7, { 0, 2 });
    setPiece(1, 7, { 0, 3 });
    setPiece(2, 7, { 0, 4 });
    setPiece(3, 7, { 0, 5 });
    setPiece(4, 7, { 0, 6 });
    setPiece(5, 7, { 0, 4 });
    setPiece(6, 7, { 0, 3 });
    setPiece(7, 7, { 0, 2 });

}

ChessPosition::ChessPosition(FEN fen) : rows01(0), rows23(0), rows45(0), rows67(0)
{

}

ChessPiece ChessPosition::getPiece(SQUARE square) const{
    return getPiece(square & 0b111, square >> 3);
}

ChessPiece ChessPosition::getPiece(COLUMN col, ROW row) const{
    if(col < 0 || col > 7 || row < 0 || row > 7){
        return {0 ,0};
    }
    char offset = (row & 1) == 0 ? 0 : 32;

    if (row < 2) {
        PIECE p = ((rows01 >> (offset + col * 4)) & 0b1111);
        return { (bool)((p >> 3) & 1), (PIECE)(p & 0b111)};
    }
    else if (row < 4) {
        PIECE p = ((rows23 >> (offset + col * 4)) & 0b1111);
        return { (bool)((p >> 3) & 1), (PIECE)(p & 0b111)};
    }
    else if (row < 6) {
        PIECE p = ((rows45 >> (offset + col * 4)) & 0b1111);
        return { (bool)((p >> 3) & 1), (PIECE)(p & 0b111)};
    }
    else {
        PIECE p = ((rows67 >> (offset + col * 4)) & 0b1111);
        return { (bool)((p >> 3) & 1), (PIECE)(p & 0b111)};
    }
}

void ChessPosition::setPiece(SQUARE square, ChessPiece piece){
    setPiece(square & 0b111, square >> 3, piece);
}

void ChessPosition::setPiece(COLUMN col, ROW row, ChessPiece piece){
    if (col < 0 || col > 7 || row < 0 || row > 7) {
        return;
    }
    char offset = row % 2 == 0 ? 0 : 32;
    if (row < 2) {
        if (piece.color) {
            rows01 |= (BITMAP)1 << (offset + col * 4 + 3);
        }
        else {
            rows01 &= ~((BITMAP)1 << (offset + col * 4 + 3));
        }
        rows01 &= ~((BITMAP)1 << (offset + col * 4));
        rows01 &= ~((BITMAP)1 << (offset + col * 4 + 1));
        rows01 &= ~((BITMAP)1 << (offset + col * 4 + 2));

        rows01 += (BITMAP)piece.piece << (offset + col * 4);
    }
    else if (row < 4) {
        if (piece.color) {
            rows23 |= (BITMAP)1 << (offset + col * 4 + 3);
        }
        else {
            rows23 &= ~((BITMAP)1 << (offset + col * 4 + 3));
        }
        rows23 &= ~((BITMAP)1 << (offset + col * 4));
        rows23 &= ~((BITMAP)1 << (offset + col * 4 + 1));
        rows23 &= ~((BITMAP)1 << (offset + col * 4 + 2));

        rows23 += (BITMAP)piece.piece << (offset + col * 4);
    }
    else if (row < 6) {
        if (piece.color) {
            rows45 |= (BITMAP)1 << (offset + col * 4 + 3);
        }
        else {
            rows45 &= ~((BITMAP)1 << (offset + col * 4 + 3));
        }
        rows45 &= ~((BITMAP)1 << (offset + col * 4));
        rows45 &= ~((BITMAP)1 << (offset + col * 4 + 1));
        rows45 &= ~((BITMAP)1 << (offset + col * 4 + 2));

        rows45 += (BITMAP)piece.piece << (offset + col * 4);
    }
    else {
        if (piece.color) {
            rows67 |= (BITMAP)1 << (offset + col * 4 + 3);
        }
        else {
            rows67 &= ~((BITMAP)1 << (offset + col * 4 + 3));
        }
        rows67 &= ~((BITMAP)1 << (offset + col * 4));
        rows67 &= ~((BITMAP)1 << (offset + col * 4 + 1));
        rows67 &= ~((BITMAP)1 << (offset + col * 4 + 2));

        rows67 += (BITMAP)piece.piece << (offset + col * 4);
    }
}
