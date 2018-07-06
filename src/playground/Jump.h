#ifndef JUMPTEST_H_
#define JUMPTEST_H_

#include "Vector2.h"
class JumpTest{

private:
    static const Vector2<int> GRAVITY; 
    Vector2<int> position;
    Vector2<int> velocity;

};

#endif /* JUMPTEST_H_ */