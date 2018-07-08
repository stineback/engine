#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <vector>

#include "Player.h"

const Vector2<int> GRAVITY(0,-1);
const Vector2<int> START_VELOCITY(2 ,10);
Player mario;

void update(double dt){
    mario.setPosition(mario.getPosition() + mario.getVelocity()*dt);
    mario.setVelocity(mario.getVelocity() + GRAVITY*dt);
}

void draw(int lastX){
    //std::cout<<mario.getPosition()<<std::endl;
    std::ostringstream oss;

    for(int i=lastX; i<mario.getPosition().getX(); ++i)
        oss<<"|"<<std::endl;

    oss<<"|";
    for(int i = 0; i<mario.getPosition().getY(); ++i)
        oss<<" ";
    oss<<"*";
    
    std::cout<<oss.str()<<std::endl;
}

bool endJump(){
    return mario.getPosition().getY() < 0;
}

int main(){

    mario.setVelocity(START_VELOCITY);

    std::ostringstream oss;
    oss<<"+";
    for(int i = 0; i<10; ++i)
        oss <<"-";
    oss<<"y";
    std::cout<<oss.str()<<std::endl;

    std::time_t prevTime = 0;
    std::time_t curTime = time_t(0);
    draw(mario.getPosition().getX());
    while(true){
        prevTime = curTime;
        curTime = time_t(0);
        double dt =std::min(std::max(std::difftime(curTime, prevTime), 0.001), 0.15)*1000;
        
        int lastX = mario.getPosition().getX();
        update(dt);

        if(endJump()) break;
        
        draw(lastX);
    }
    std::cout<<"x"<<std::endl;

    return 0;
}