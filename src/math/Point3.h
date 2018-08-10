#ifndef POINT2_H_
#define POINT2_H_

#include <math.h>
#include "CartisanCoordinates3.h"
#include "Vector3.h"

template<typename T>
class Point3 : public CartisanCoordinates3<T> {
public:
    //constructors/destructor
	Point3() {};
	Point3(T x, T y, T z) : CartisanCoordinates3<T>(x, y, z) {};
	Point3(const Point3& p) : CartisanCoordinates3<T>(p.x, p.y, p.z) {};
	virtual ~Point3(){};

	//operator overloading
	Point3& operator=(const Point3& p);
    Point3 operator+(const Vector3<T>& p) const;
	Vector3<T> operator-(const Point3& v) const;

	//point operations
	T distance(const Point3& p)  const;
	T distanceSquared(const Point3& p) const;
};


/**********operator overloading**********/

//Base class assignment operator is always hidden by the copy assignment operator of the derived class,
//so needs to explict implement move assignment operator
template<typename T>
Point3<T>& Point3<T>::operator=(const Point3& p){
	CartisanCoordinates3<T>::operator=(p);
	return *this;
}

template<typename T>
Point3<T> Point3<T>::operator+(const Vector3<T>& v) const{
	return Point3<T>(this->x+v.getX(), this->y+v.getY(), this->z+v.getZ());
}

template<typename T>
Vector3<T> Point3<T>::operator-(const Point3& p) const{
	return Vector3<T>(this->x-p.x, this->y-p.y, this->z-p.z);
}

/**********point operations**********/
template<typename T>
T Point3<T>::distance(const Point3<T>& p) const{
	return sqrt(this->distanceSquared(p));
}

template<typename T>
T Point3<T>::distanceSquared(const Point3<T>& p) const{
	T xDist = this->x-p.x;
	T yDist = this->y-p.y;
	T zDist = this->z-p.z;
	return xDist*xDist + yDist*yDist + zDist*zDist;
}

#endif /* POINT2_H_ */