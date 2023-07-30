#include "chessboard.h"

#include <QBrush>
#include <iostream>

using namespace Chess;

ChessBoard::ChessBoard(QGraphicsView * view) : parent(view), selectedSquare(64), reversed(false), mousePressed(0), QGraphicsScene()
{
}


void ChessBoard::drawForeground(QPainter * painter, const QRectF &rect) {
    game.update();
    float a = parent->width(), b = parent->height();
    float size =(a < b ? a : b) / 9;
    QBrush black(QColor(136, 99, 56)), white(QColor(220, 220, 220));

    std::vector<char> todraw;
    for(ChessMove& move : game.getPossibleMoves()){
        if(move.from == selectedSquare){
            todraw.push_back(move.to);
        }
    }

    for(char i = 0; i < 8; i++){
        for(char j = 0; j < 8; j++){

            painter->fillRect(size*(i-4) - 1, size*(j-4) - 1, size + 2, size + 2, (i + j) % 2 ? black : white);
            if((7 - j) * 8 + i == selectedSquare){
                QBrush selected((i + j) % 2 ? QColor(96, 59, 16) : QColor(140, 140, 140));
                painter->fillRect(size*(i-4), size*(j-4), size, size, selected);
            }
            if(std::find(todraw.begin(), todraw.end(), (7 - j) * 8 + i) != todraw.end()){
                QBrush pm_brush(QColor(0, 0, 0));
                painter->setBrush(pm_brush);
                painter->drawEllipse(QPointF(size * (i - 3.5), size * (j - 3.5)), 15, 15);
            }
            if(game.hasCheck((reversed ? 7-i : i) + 8 * (reversed ? j : 7-j))){
                QBrush check_brush((i + j) % 2 ? QColor(150, 59, 16) : QColor(200, 140, 140));
                painter->fillRect(size*(i-4), size*(j-4), size, size, check_brush);
            }

            ChessPiece piece = game.getPiece(reversed ? 7-i : i, reversed ? j : 7-j);

            QString a("");
            if(piece.color){
                a += "w";
            }else{
                a += "b";
            }
            switch(piece.piece){
            case 0:
                continue;
                break;
            case 1: a += "p";
                break;
            case 2: a += "r";
                break;
            case 3: a += "n";
                break;
            case 4: a += "b";
                break;
            case 5: a += "q";
                break;
            case 6: a += "k";
                break;
            }

            QString loc(":resources/" + a + ".png");
            QImage image(loc);
            QImage resized = image.scaled(QSize(size*.9, size*.9), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            painter->drawImage(QPoint(size*(i-3.95), size*(j-3.95)), resized);
        }
    }
    QGraphicsScene::drawForeground(painter, rect);
}

void ChessBoard::mousePressEvent(QMouseEvent * event) {
    mousePressed = true;
    float a = parent->width(), b = parent->height();
    float size =(a < b ? a : b) / 9;
}

void ChessBoard::mouseReleaseEvent(QMouseEvent * event) {
    mousePressed = false;
}

void ChessBoard::mouseMoveEvent(QMouseEvent * event) {
    if(mousePressed){

    }
}


ChessBoard::~ChessBoard(){
    delete parent;
}
