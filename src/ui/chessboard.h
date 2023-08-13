#pragma once

#include <QGraphicsScene>
#include <QPainter>
#include <QImage>
#include <QGraphicsSceneMouseEvent>
#include <QSize>

#include "../common.h"
#include "../chess/chessgame.h"
#include "sprite.h"

class ChessBoard : public QGraphicsScene
{
public:
    ChessBoard();

    void drawForeground(QPainter *, const QRectF&) override;

    void drawBackground(QPainter *, const QRectF&) override;

    void mousePressEvent(QGraphicsSceneMouseEvent* ) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *) override;

    void registerTextures();

    void resizeTextures();

    ~ChessBoard();



private:
    ChessGame game;

    Chess::SQUARE selectedSquare;

    bool reversed;

    bool mousePressed;

    Chess::Sprite * pieceTexturesRegistry;

    QSize previousSize;
};
