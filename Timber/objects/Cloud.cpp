//
// Created by nitewolf on 6/28/18.
//

#include "Cloud.h"

Cloud::Cloud(const Texture& texture) : Cloud(texture, 0.0f, 0.0f, 0.0f) {}

Cloud::Cloud(const Texture& texture, float posX, float posY, float speed) : speed(speed), active(false)
{
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}

bool Cloud::isActive()
{
    return active;
}

void Cloud::setActive(bool active)
{
    this->active = active;
}

float Cloud::getSpeed()
{
    return speed;
}

void Cloud::setSpeed(float speed)
{
    this->speed = speed;
}

const Vector2f& Cloud::getPosition()
{
    return sprite.getPosition();
}

void Cloud::setPosition(float posX, float posY)
{
    sprite.setPosition(posX, posY);
}

Sprite& Cloud::getSprite()
{
    return sprite;
}