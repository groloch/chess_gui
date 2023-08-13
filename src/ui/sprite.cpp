#include "sprite.h"

#include <string>

namespace Chess{

    Sprite::Sprite(const char * n, Chess::SQUARE sq, float a, float b, float as, float bs) : name(n), x(a), y(b), sizeX(as), sizeY(bs), square(sq), texture(QString::fromStdString(std::string(":resources/") + std::string(n) + std::string(".png"))){
        resizedTexture = texture.scaled(sizeX, sizeY, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    Sprite::Sprite(): name(""), x(0), y(0), sizeX(0), sizeY(0), texture(), square(Chess::NULL_SQUARE), resizedTexture(){

    }

    const char* Sprite::getName() const{
        return name;
    }
    void Sprite::move(float a, float b){
        x = a;
        y = b;
    }
    SQUARE Sprite::getSquare() const{
        return square;
    }

    void Sprite::resize(float x, float y){
        sizeX = x;
        sizeY = y;
        resizedTexture = texture.scaled(QSize(sizeX, sizeY), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    float Sprite::getX() const{
        return x;
    }
    float Sprite::getY() const{
        return y;
    }
    float Sprite::x_size() const{
        return sizeX;
    }
    float Sprite::y_size() const{
        return sizeY;
    }

    const QImage* Sprite::getTexture() const{
        return &resizedTexture;
    }

    Sprite::~Sprite(){
    }
}
bool operator==(Chess::Sprite const& s1, Chess::Sprite const& s2){
    return s1.getSquare() == s2.getSquare();
}
