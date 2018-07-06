#include "Player.h"

void Player::setPosition(const Vector2<int>& p){
    this->position = p;
}

void Player::setVelocity(const Vector2<int>& v){
    this->velocity = v;
}

Vector2<int> Player::getPosition() const{
    return this->position;
}

Vector2<int> Player::getVelocity() const{
    return this->velocity;
}