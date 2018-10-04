#include <iostream>
#include <sstream>
#include <string>

#include "Player.h"

Player wagon;
Player bucket;

int trackLength = 10;

void draw(){

    std::ostringstream oss;

    for(int i=0; i<trackLength; ++i){
        oss << "| ";
        oss << (i==wagon.getPosition().getY() ? "*" : " ");
        oss << " |";

        if(i==bucket.getPosition().getY() )
        {
            for(int j=0; j<bucket.getPosition().getX()-1; ++j)
                oss << " ";
            oss << "U";
        }

        oss << std::endl;
    }
    std::cout << oss.str();
}

int main(){
    wagon.setPosition(Point2<float>(0,0));
    wagon.setFrontDirection(Vector2<float>(0,1));

    bucket.setPosition(Point2<float>(7,7));
    std::cout << "*****Before*****"<<std::endl;
    draw();

    Vector2<float> bucketDirection = bucket.getPosition()-wagon.getPosition();
    Vector2<float> force = bucketDirection.projection(wagon.getFrontDirection());
    wagon.setPosition(wagon.getPosition()+force);

    std::cout << "\n*****After*****"<<std::endl;
    draw();

    return 0;
}