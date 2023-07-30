#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>

#include "../common.h"
#include "../chess/chessgame.h"

class ChessBoard : public QGraphicsScene
{
public:
    ChessBoard(QGraphicsView*);

    void drawForeground(QPainter *, const QRectF&) override;

    void mousePressEvent(QMouseEvent* ) override;

    void mouseReleaseEvent(QMouseEvent*) override;

    void mouseMoveEvent(QMouseEvent *) override;

    ~ChessBoard();



private:

    QGraphicsView * parent;

    ChessGame game;

    Chess::SQUARE selectedSquare;

    bool reversed;

    bool mousePressed;

};
