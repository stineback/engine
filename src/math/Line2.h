#ifndef LINE2_H_
#define LINE2_H_

#include <cmath>

#include "Point2.h"
#include "Vector2.h"

template <typename T>
class Line2 {
private:
    Vector2<T> direction;
    Point2<T> origin;

public:
    //constructors/destructor
    Line2(Vector2<T> direction, Point2<T> origin) :direction(direction), origin(origin) {};
	Line2(const Line2& l) : direction(l.getDirection()), origin(l.getOrigin()){};
	virtual ~Line2(){};

	//getters
	Vector2<T> getDirection() const;
	Point2<T> getOrigin() const;

    //operator overloading
	Line2& operator=(const Line2& l);
	bool operator==(const Line2& l) const;
	bool operator!=(const Line2& l) const;

    //line operations
    Point2<T> pointOnLine(T parameter);
    T positionAccordingToLine(Point2<T> p);
    T distanceToLine(Point2<T> p);
};

//operator overloading
template<typename T>
std::ostream& operator<< (std::ostream& s, const Line2<T>& v);

/**********getters**********/
template<typename T>
inline Vector2<T> Line2<T>::getDirection() const {
	return direction;
}

template<typename T>
inline Point2<T>  Line2<T>::getOrigin() const {
	return origin;
}

/**********operator overloading**********/
template<typename T>
Line2<T>& Line2<T>::operator=(const Line2& l){
	//if same object
	if(this == &l) return *this;

	this->direction = l.direction;
	this->origin = l.origin;
	return *this;
}


template<typename T>
bool Line2<T>::operator==(const Line2& l) const {
    //is it same line if direction and/or origin is different but the parametizied line is the same?
	return (this->direction==l.direction) && (this->origin==l.origin);
}

template<typename T>
bool Line2<T>::operator!=(const Line2& l) const {
	return (this->direction!=l.direction) || (this->origin!=l.origin);
}


template<typename T>
std::ostream& operator<< (std::ostream& s, const Line2<T>& l) {
	return s<<"direction="<<l.getDirection()<<", origin="<<l.getOrigin();
}

/**********line operations**********/
template<typename T>
Point2<T> Line2<T>::pointOnLine(T parameter){
    return origin + parameter*direction;
}

//Return value is:
//Equal to 0 when p lies on the line
//Greater than 0 when p lines on the same side of the line of which the perpendicular vector of the direction points
//Less than 0 when p lines on the oppesite side of the line of which the perpendicular vector of the direction points
template<typename T>
T Line2<T>::positionAccordingToLine(Point2<T> p){
    T a = -direction.getY();
    T b = direction.getX();
    T c = -a*origin.getX()-b*origin.getY();
    return a*p.getX() + b*p.getY() + c;
}

template<typename T>
T Line2<T>::distanceToLine(Point2<T> p){
    return abs(positionAccordingToLine(p));
}

#endif /* LINE2_H_ */