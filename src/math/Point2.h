#ifndef POINT2_H_
#define POINT2_H_

#include <math.h>
#include "CartisanCoordinates2.h"
#include "Vector2.h"

template<typename T>
class Point2 : public CartisanCoordinates2<T> {
public:
    //constructors/destructor
	Point2() {};
	Point2(T x, T y) : CartisanCoordinates2<T>(x, y) {};
	Point2(const Point2& p) : CartisanCoordinates2<T>(p.x, p.y) {};
	virtual ~Point2(){};

	//operator overloading
	Point2& operator=(const Point2& p);
    Point2 operator+(const Vector2<T>& p) const;
	Vector2<T> operator-(const Point2& v) const;

	//point operations
	T distance(const Point2& p)  const;
	T distanceSquared(const Point2& p) const;
};


/**********operator overloading**********/

//Base class assignment operator is always hidden by the copy assignment operator of the derived class,
//so needs to explict implement move assignment operator
template<typename T>
Point2<T>& Point2<T>::operator=(const Point2& p){
	CartisanCoordinates2<T>::operator=(p);
	return *this;
}

template<typename T>
Point2<T> Point2<T>::operator+(const Vector2<T>& v) const{
	return Point2<T>(this->x+v.getX(), this->y+v.getY());
}

template<typename T>
Vector2<T> Point2<T>::operator-(const Point2& p) const{
	return Vector2<T>(this->x-p.x, this->y-p.y);
}

/**********point operations**********/
template<typename T>
T Point2<T>::distance(const Point2<T>& p) const{
	return sqrt(this->distanceSquared(p));
}

template<typename T>
T Point2<T>::distanceSquared(const Point2<T>& p) const{
	T xDist = this->x-p.x;
	T yDist = this->y-p.y;
	return xDist*xDist + yDist*yDist;
}


#endif /* POINT2_H_ */