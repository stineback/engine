#ifndef PLAYER_H_
#define PLAYER_H_
#include "Vector2.h"

class Player
{
    public:
        Player() : position(Vector2<int>(0,0)), velocity(Vector2<int>(0,0)){};

        void setPosition(const Vector2<float>&);
        void setVelocity(const Vector2<float>&);
        
        Vector2<float> getPosition() const;
        Vector2<float> getVelocity() const;

    private:

        Vector2<float> position;
        Vector2<float> velocity;
};

#endif /* PLAYER_H_ */
