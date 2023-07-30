#pragma once

namespace Chess{
    using SQUARE = unsigned char;
    using ROW = unsigned char;
    using COLUMN = unsigned char;

    using PIECE = unsigned char;

    using BITMAP = unsigned long long;

    using FEN = char const*;

    using SPECS = unsigned short;

    struct ChessPiece{
        bool color;
        PIECE piece;
    };

    struct ChessMove{
        SQUARE from;
        SQUARE to;

        SPECS changes;

        ChessPiece moved;
        ChessPiece taken;

        ChessMove* associated;

        ChessMove() : from(0), to(0), changes(0), moved({0, 0}), taken({0, 0}), associated(0)
        {}

    };
}
