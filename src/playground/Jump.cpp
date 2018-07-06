#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

#include "Player.h"

const Vector2<int> GRAVITY(0,-1);
const Vector2<int> START_VELOCITY(20,20);
Player mario;

void update(double dt){
    mario.setPosition(mario.getPosition() + mario.getVelocity()*dt);
    mario.setVelocity(mario.getVelocity() + GRAVITY*dt);
}

void draw(){
    std::cout<<mario.getPosition()<<std::endl;
}

bool endJump(){
    return mario.getPosition().getY() < 0;
}

int main(){

    mario.setVelocity(START_VELOCITY);

    std::time_t prevTime = 0;
    std::time_t curTime = time_t(0);
    draw();
    while(true){
        prevTime = curTime;
        curTime = time_t(0);
        double dt =std::min(std::max(std::difftime(curTime, prevTime), 0.001), 0.15)*1000;//calculates in milliseconds
        update(dt);

        if(endJump()) break;
        
        draw();
    }

    return 0;
}