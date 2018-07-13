#include "Player.h"

const Vector2<float> Player::DEFAULT_FRONT_DIRECTION(1,0);

void Player::setPosition(const Vector2<float>& p){
    this->position = p;
}

void Player::setVelocity(const Vector2<float>& v){
    this->velocity = v;
}

void Player::setFrontDirection(const Vector2<float>& f){
    this->frontDirection = f != Vector2<float>() ? f : DEFAULT_FRONT_DIRECTION;
}

Vector2<float> Player::getPosition() const{
    return this->position;
}

Vector2<float> Player::getVelocity() const{
    return this->velocity;
}

Vector2<float> Player::getFrontDirection() const{
    return this->frontDirection;
}