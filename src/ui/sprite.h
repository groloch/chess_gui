#pragma once

#include <QImage>
#include "../common.h"

namespace Chess{
    class Sprite
    {
    public:
        Sprite(const char *, Chess::SQUARE, float, float, float, float);

        Sprite();

        ~Sprite();

        const char* getName() const;

        void move(SQUARE);

        void move(float, float);

        void resize(float, float);

        Chess::SQUARE getSquare() const;
        float getX() const;
        float getY() const;
        float x_size() const;
        float y_size() const;

        const QImage* getTexture() const;

    private:
        const char * name;
        float x, y;
        float sizeX, sizeY;
        Chess::SQUARE square;
        QImage texture;
        QImage resizedTexture;
    };
}
