/*
 * Vector2.h
 *
 *  Created on: 2 Oct 2017
 *      Author: sbl
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

template<typename T>
class Vector2 {
public:
	//constructors/destructor
	Vector2() : x(0), y(0){};
	Vector2(T x, T y) :x(x), y(y) {};
	Vector2(const Vector2& v) : x(v.x), y(v.y){};
	virtual ~Vector2(){};

	//getters
	T getX() const;
	T getY() const;

	//setters
	void set(T x, T y);
	void setX(T x);
	void setY(T y);

	//operator overloading
	Vector2& operator=(const Vector2& v);
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator-(const Vector2& v) const;
	Vector2 operator-() const;
	Vector2 operator*(const float& s) const;
	Vector2 operator/(const float& s) const;
	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;

	//vector operations
	T dot(const Vector2& v) const;
	T perpDot(const Vector2& v) const;
	T magnitude() const;
	T magnitudeSquared() const;
	Vector2 normalized() const;
	T angle(const Vector2& v) const;
	static bool isBasis(const Vector2& a, const Vector2& b);

	//point operations
	T distance(const Vector2& p)  const;
	T distanceSquared(const Vector2& p) const;

	//utilities
	string toString() const;

private:
	T x;
	T y;
};

//operator overloading
template<typename T>
Vector2<T> operator*(const float& s, const Vector2<T>& v);

template<typename T>
std::ostream& operator<< (std::ostream& s, const Vector2<T>& v);


/**********getters**********/
template<typename T>
inline T Vector2<T>::getX() const {
	return x;
}


template<typename T>
inline T Vector2<T>::getY() const {
	return y;
}

/**********setters**********/
template<typename T>
inline void Vector2<T>::set(T x, T y) {
	this->x = x;
	this->y = y;
}

template<typename T>
inline void Vector2<T>::setX(T x) {
	this->x = x;
}

template<typename T>
inline void Vector2<T>::setY(T y) {
	this->y = y;
}

/**********operator overloading**********/
template<typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2& v){

	//if same object
	if(this == &v) return *this;

	x = v.x;
	y = v.y;
	return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2& v) const{
	return Vector2(x+v.x,y+v.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2& v) const{
	return Vector2(x-v.x,y-v.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator-() const{
	return Vector2(-x,-y);
}

template<typename T>
Vector2<T> Vector2<T>::operator*(const float& s) const{
	return Vector2<T>(x*s,y*s);
}

template<typename T>
Vector2<T> operator*(const float& s, const Vector2<T>& v) {
	return Vector2<T>(s*v.getX(),s*v.getY());
}

template<typename T>
Vector2<T> Vector2<T>::operator/(const float& s) const{
	return Vector2(x/s,y/s);
}

template<typename T>
bool Vector2<T>::operator==(const Vector2& v) const {
	return (x==v.x) && (y==v.y);
}

template<typename T>
bool Vector2<T>::operator!=(const Vector2& v) const {
	return (x!=v.x) || (y!=v.y);
}

template<typename T>
std::ostream& operator<< (std::ostream& s, const Vector2<T>& v) {
	return s<<"("<<v.getX()<<","<<v.getY()<<")";
}

/**********vector operations**********/
template<typename T>
T Vector2<T>::dot(const Vector2& v) const{
	return x*v.x + y*v.y;
}

template<typename T>
T Vector2<T>::perpDot(const Vector2& v) const{
	return x*v.y - y*v.x;
}

template<typename T>
T Vector2<T>::magnitude() const{
	return sqrt(this->magnitudeSquared());
}

template<typename T>
T Vector2<T>::magnitudeSquared() const{
	return x*x + y*y;
}

template<typename T>
Vector2<T> Vector2<T>::normalized() const{
	float magnitude = this->magnitude();
	Vector2 result;
	if(magnitude != 0){
		result.set(x/magnitude, y/magnitude);
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

/**********point operations**********/
template<typename T>
T Vector2<T>::distance(const Vector2<T>& p) const{
	return sqrt(this->distanceSquared(p));
}

template<typename T>
T Vector2<T>::distanceSquared(const Vector2<T>& p) const{
	T xDist = x-p.x;
	T yDist = y-p.y;
	return xDist*xDist + yDist*yDist;
}

/**********utilities**********/
template<typename T>
string Vector2<T>::toString() const{
	ostringstream oss;
	oss << *this;
    return oss.str();
}


#endif /* VECTOR2_H_ */
