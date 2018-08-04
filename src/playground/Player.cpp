#include "Player.h"

void Player::setPosition(const Vector2<float>& p){
    this->position = p;
}

void Player::setVelocity(const Vector2<float>& v){
    this->velocity = v;
}

Vector2<float> Player::getPosition() const{
    return this->position;
}

Vector2<float> Player::getVelocity() const{
    return this->velocity;
}