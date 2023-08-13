#include "chessboard.h"

#include <QBrush>
#include <iostream>
#include <typeinfo>

using namespace Chess;

ChessBoard::ChessBoard() : selectedSquare(64), reversed(false), mousePressed(0), game(), previousSize(0, 0), QGraphicsScene(){
    pieceTexturesRegistry = new Sprite[64];
    registerTextures();
}


void ChessBoard::drawForeground(QPainter * painter, const QRectF &rect) {
    game.update();
    float a = rect.width(), b = rect.height();
    if(previousSize.width() != rect.width() || previousSize.height() != rect.height()){
        previousSize.setWidth(rect.width());
        previousSize.setHeight(rect.height());
        resizeTextures();
    }
    float size =(a < b ? a : b) / 9;
    QBrush black(QColor(136, 99, 56)), white(QColor(220, 220, 220));

    std::vector<SQUARE> todraw;
    for(ChessMove& move : game.getPossibleMoves()){
        if(move.from == selectedSquare){
            todraw.push_back(move.to);
        }
    }

    for(COLUMN c = 0; c < 8; c++){
        for(ROW r = 0; r < 8; r++){

            painter->fillRect(size*(c-4) - 1, size*(r-4) - 1, size + 2, size + 2, (c + r) % 2 ? black : white);
            if((7 - r) * 8 + c == selectedSquare){
                QBrush selected((c + r) % 2 ? QColor(96, 59, 16) : QColor(140, 140, 140));
                painter->fillRect(size*(c-4), size*(r-4), size, size, selected);
            }
            if(std::find(todraw.begin(), todraw.end(), (7 - r) * 8 + c) != todraw.end()){
                QBrush pm_brush(QColor(0, 0, 0));
                painter->setBrush(pm_brush);
                painter->drawEllipse(QPointF(size * (c - 3.5), size * (r - 3.5)), 15, 15);
            }
            if(game.hasCheck((reversed ? 7-c : c) + 8 * (reversed ? r : 7-r))){
                QBrush check_brush((c + r) % 2 ? QColor(150, 59, 16) : QColor(200, 140, 140));
                painter->fillRect(size*(c-4), size*(r-4), size, size, check_brush);
            }

        }
    }
    for(COLUMN c = 0; c < 8; c++){
        for(ROW r = 0; r < 8; r++){
            Sprite* sprite = &pieceTexturesRegistry[r * 8 +  c];
            if(sprite->getSquare() != NULL_SQUARE){
                painter->drawImage(QPoint(sprite->getX(), sprite->getY()), * sprite->getTexture());
            }
        }
    }
    QGraphicsScene::drawForeground(painter, rect);
}

void ChessBoard::drawBackground(QPainter * painter, const QRectF& rect){
}

void ChessBoard::mousePressEvent(QGraphicsSceneMouseEvent * event) {
    mousePressed = true;
    float a = previousSize.width(), b = previousSize.height();
    float size =(a < b ? a : b) / 9;
    QPointF pos = event->scenePos();
    int bx = (int)(4 + pos.x() / size), by = (int)(4 - pos.y() / size);
    if(bx >= 0 and bx <= 7 and by >= 0 and by <= 7){
        if(event->button() == 1){
            mousePressed = true;
        }
    }

    QGraphicsScene::mouseReleaseEvent(event);
}

void ChessBoard::mouseReleaseEvent(QGraphicsSceneMouseEvent * event) {
    mousePressed = false;
}

void ChessBoard::mouseMoveEvent(QGraphicsSceneMouseEvent * event) {
    if(mousePressed){

    }
}

void ChessBoard::registerTextures(){
    for(COLUMN c = 0; c < 8; c++){
        for(ROW r = 0; r < 8; r++){
            ChessPiece piece = game.getPiece(c, r);
            const char* name;
            if(piece.piece == 0){
                continue;
            }
            switch(piece.piece + (piece.color ? 0 : 6)){
            case 1:
                name = "wp";
                break;
            case 2:
                name = "wr";
                break;
            case 3:
                name = "wn";
                break;
            case 4:
                name = "wb";
                break;
            case 5:
                name = "wq";
                break;
            case 6:
                name = "wk";
                break;
            case 7:
                name = "bp";
                break;
            case 8:
                name = "br";
                break;
            case 9:
                name = "bn";
                break;
            case 10:
                name = "bb";
                break;
            case 11:
                name = "bq";
                break;
            case 12:
                name = "bk";
                break;
            default:
                name = "wp";
                break;
            }
            Sprite sprite(name, r * 8 + c, 0, 0, 0, 0);
            pieceTexturesRegistry[r * 8 + c] = sprite;
        }
    }
}

void ChessBoard::resizeTextures(){
    float a = previousSize.width(), b = previousSize.height();
    float size =(a < b ? a : b) / 9;
    for(COLUMN c = 0; c < 8; c++){
        for(ROW r = 0; r < 8; r++){
            if(pieceTexturesRegistry[r*8+c].getSquare() != NULL_SQUARE){
                pieceTexturesRegistry[r*8+c].resize(size, size);
                pieceTexturesRegistry[r*8+c].move(size*((reversed ? 7-c : c)-4), size*((reversed ? r : 7-r)-4));
            }
        }
    }
}


ChessBoard::~ChessBoard(){
    delete[] pieceTexturesRegistry;
}
