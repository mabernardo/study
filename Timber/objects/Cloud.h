//
// Created by nitewolf on 6/28/18.
//

#ifndef TIMBER_CLOUD_H
#define TIMBER_CLOUD_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Cloud {
public:
    Cloud(const Texture& texture);
    Cloud(const Texture& texture, float posX, float posY, float speed);

    bool isActive();
    void setActive(bool active);

    float getSpeed();
    void setSpeed(float speed);

    const Vector2f& getPosition();
    void setPosition(float posX, float posY);

    Sprite& getSprite();
private:
    Sprite sprite;
    bool active;
    float speed;
};

#endif //TIMBER_CLOUD_H
