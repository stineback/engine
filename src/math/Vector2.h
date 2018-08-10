/*
 * Vector2.h
 *
 *  Created on: 2 Oct 2017
 *      Author: sbl
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <math.h>
#include <vector>

#include "CartisanCoordinates2.h"

template<typename T>
class Vector2 : public CartisanCoordinates2<T> {
public:
	//constructors/destructor
	Vector2() {};
	Vector2(T x, T y) : CartisanCoordinates2<T>(x, y) {};
	Vector2(const Vector2& v) : CartisanCoordinates2<T>(v.x, v.y) {};
	virtual ~Vector2(){};

	//operator overloading
	Vector2& operator=(const Vector2& v);
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator-(const Vector2& v) const;
	Vector2 operator-() const;
	Vector2 operator*(const float& s) const;
	Vector2 operator/(const float& s) const;

	//vector operations
	T dot(const Vector2& v) const;
	T perpDot(const Vector2& v) const;
	T magnitude() const;
	T magnitudeSquared() const;
	Vector2 normalized() const;
	T angle(const Vector2& v) const;
	static bool isBasis(const Vector2& a, const Vector2& b);
};

//operator overloading
template<typename T>
Vector2<T> operator*(const float& s, const Vector2<T>& v);

/**********operator overloading**********/

//Base class assignment operator is always hidden by the copy assignment operator of the derived class,
//so needs to explict implement move assignment operator
template<typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2& v){
	CartisanCoordinates2<T>::operator=(v);
	return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2& v) const{
	return Vector2(this->x+v.x,this->y+v.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2& v) const{
	return Vector2(this->x-v.x,this->y-v.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator-() const{
	return Vector2(-this->x,-this->y);
}

template<typename T>
Vector2<T> Vector2<T>::operator*(const float& s) const{
	return Vector2<T>(this->x*s,this->y*s);
}

template<typename T>
Vector2<T> operator*(const float& s, const Vector2<T>& v) {
	return Vector2<T>(s*v.getX(),s*v.getY());
}

template<typename T>
Vector2<T> Vector2<T>::operator/(const float& s) const{
	return Vector2(this->x/s,this->y/s);
}


/**********vector operations**********/
template<typename T>
T Vector2<T>::dot(const Vector2& v) const{
	return this->x*v.x + this->y*v.y;
}

template<typename T>
T Vector2<T>::perpDot(const Vector2& v) const{
	return this->x*v.y - this->y*v.x;
}

template<typename T>
T Vector2<T>::magnitude() const{
	return sqrt(this->magnitudeSquared());
}

template<typename T>
T Vector2<T>::magnitudeSquared() const{
	return this->x*this->x + this->y*this->y;
}

template<typename T>
Vector2<T> Vector2<T>::normalized() const{
	float magnitude = this->magnitude();
	Vector2 result;
	if(magnitude != 0){
		result.set(this->x/magnitude, this->y/magnitude);
	}

	return result;
}

template<typename T>
T Vector2<T>::angle(const Vector2& v) const{
	return asin(this->normalized().perpDot(v.normalized()));
}

template<typename T>
bool Vector2<T>::isBasis(const Vector2& a, const Vector2& b) {
	Vector2<T> zero(0,0);

	return a.perpDot(b) != 0;
}

#endif /* VECTOR2_H_ */
