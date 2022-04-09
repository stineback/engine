#ifndef LINE3_H_
#define LINE3_H_

#include <cmath>

#include "Point3.h"
#include "Vector3.h"

template <typename T>
class Line3 {
private:
    Vector3<T> direction;
    Point3<T> origin;

public:
    //constructors/destructor
    Line3(Vector3<T> direction, Point3<T> origin) :direction(direction), origin(origin) {};
	Line3(const Line3& l) : direction(l.getDirection()), origin(l.getOrigin()){};
	virtual ~Line3(){};

	//getters
	Vector3<T> getDirection() const;
	Point3<T> getOrigin() const;

    //operator overloading
	Line3& operator=(const Line3& l);
	bool operator==(const Line3& l) const;
	bool operator!=(const Line3& l) const;

    //line operations
    Point3<T> pointOnLine(T parameter);
	static bool isCollinear(const Point3<T>& p0, const Point3<T>& p1, const Point3<T>& p2, T threshold = 0);
};

//operator overloading
template<typename T>
std::ostream& operator<< (std::ostream& s, const Line3<T>& v);

/**********getters**********/
template<typename T>
inline Vector3<T> Line3<T>::getDirection() const
{
	return direction;
}

template<typename T>
inline Point3<T>  Line3<T>::getOrigin() const
{
	return origin;
}

/**********operator overloading**********/
template<typename T>
Line3<T>& Line3<T>::operator=(const Line3& l)
{
	//if same object
	if(this == &l) return *this;

	this->direction = l.direction;
	this->origin = l.origin;
	return *this;
}


template<typename T>
bool Line3<T>::operator==(const Line3& l) const
{
    //is it same line if direction and/or origin is different but the parametizied line is the same?
	return (this->direction==l.direction) && (this->origin==l.origin);
}

template<typename T>
bool Line3<T>::operator!=(const Line3& l) const
{
	return (this->direction!=l.direction) || (this->origin!=l.origin);
}


template<typename T>
std::ostream& operator<< (std::ostream& s, const Line3<T>& l)
{
	return s<<"direction="<<l.getDirection()<<", origin="<<l.getOrigin();
}

/**********line operations**********/
template<typename T>
Point3<T> Line3<T>::pointOnLine(T parameter)
{
    return origin + parameter*direction;
}

template<typename T>
bool Line3<T>::isCollinear(const Point3<T>& p0, const Point3<T>& p1, const Point3<T>& p2, T threshold)
{
	Vector3<T> crossProduct = (p1 - p0).cross(p2 - p0);
	return abs(crossProduct.getX()) <= threshold && 
			abs(crossProduct.getY()) <= threshold && 
			abs(crossProduct.getZ()) <= threshold;
}
#endif /* LINE3_H_ */