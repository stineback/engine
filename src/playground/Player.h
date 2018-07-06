#ifndef PLAYER_H_
#define PLAYER_H_
#include "Vector2.h"

class Player
{
    public:
        Player() : position(Vector2<int>(0,0)), velocity(Vector2<int>(0,0)){};

        void setPosition(const Vector2<int>&);
        void setVelocity(const Vector2<int>&);

        Vector2<int> getPosition() const;
        Vector2<int> getVelocity() const;

    private:
        Vector2<int> position;
        Vector2<int> velocity;

};

#endif /* PLAYER_H_ */
