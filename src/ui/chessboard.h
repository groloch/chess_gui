#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QImage>

#include "../common.h"
#include "../chess/chessgame.h"

class ChessBoard : public QGraphicsScene
{
public:
    ChessBoard(QGraphicsView*);

    void drawForeground(QPainter *, const QRectF&) override;




private:
    QGraphicsView * parent;

    ChessGame game;

    SQUARE selectedSquare;

    bool reversed;

};
