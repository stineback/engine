#include <iostream>
#include <sstream>
#include "Player.h"


Player hitman;
Player enemy;
int roomSize = 10;
void draw(){
    int hX = hitman.getPosition().getX();
    int hY = hitman.getPosition().getY();
    int eX = enemy.getPosition().getX();
    int eY = enemy.getPosition().getY();
    
    std::ostringstream oss;
    for(int i=-roomSize; i<roomSize+2; ++i)
        oss <<"-";
    oss << std::endl;

    for(int i=roomSize; i>=-roomSize; --i){
        oss << "|";
        for(int j=-roomSize; j<=roomSize; ++j){
            bool hSymbol = i == hY && j == hX;
            bool eSymbol = i == eY && j == eX;

            std::string symbol = " ";
            if(hSymbol && eSymbol) symbol = "*";
            else if(hSymbol) symbol = "•";
            else if(eSymbol) symbol = "^";
            oss << symbol;
        }
        oss <<"|"<< std::endl;
    }

    for(int i=-roomSize; i<roomSize+2; ++i)
        oss <<"-";
    oss << std::endl;

    std::cout << oss.str();
}

bool canBackstab(){
    Vector2<float> direction = hitman.getPosition() - enemy.getPosition();
    return enemy.getFrontDirection().normalized().dot(direction.normalized()) < -0.5;
}

void canBackstabMsg(){
    std::string answer = canBackstab() ? "Yes" : "No";
    std::cout << "Can backstab? " << answer << std::endl;
}

int main(){
    enemy.setPosition(Point2<float>(0,0));
    enemy.setFrontDirection(Vector2<float>(0,1));

    hitman.setPosition(Point2<float>(0,roomSize));
    draw();
    canBackstabMsg();

    hitman.setPosition(Point2<float>(roomSize,roomSize));
    draw();
    canBackstabMsg();

    hitman.setPosition(Point2<float>(roomSize,0));
    draw();
    canBackstabMsg();

    hitman.setPosition(Point2<float>(roomSize,-roomSize));
    draw();
    canBackstabMsg();

    hitman.setPosition(Point2<float>(0,-roomSize));
    draw();
    canBackstabMsg();

    hitman.setPosition(Point2<float>(-roomSize,-roomSize));
    draw();
    canBackstabMsg();

    hitman.setPosition(Point2<float>(-roomSize,0));
    draw();
    canBackstabMsg();

    hitman.setPosition(Point2<float>(-roomSize,roomSize));
    draw();
    canBackstabMsg();

    hitman.setPosition(Point2<float>(0,0));
    draw();
    canBackstabMsg();

    return 0;
}