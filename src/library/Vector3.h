/*
 * Vector3.h
 *
 *  Created on: 2 Oct 2017
 *      Author: sbl
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

template<typename T>
class Vector3 {
public:
	//constructors/destructor
	Vector3(){};
	Vector3(T x, T y, T z) :x(x), y(y), z(z) {};
	Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z){};
	virtual ~Vector3(){};

	//getters
	T getX() const;
	T getY() const;
	T getZ() const;

	//setters
	void set(T x, T y, T z);
	void setX(T x);
	void setY(T y);
	void setZ(T z);

	//operator overloading
	Vector3& operator=(const Vector3& v) const;
	Vector3 operator+(const Vector3& v) const;
	Vector3 operator-(const Vector3& v) const;
	Vector3 operator-() const;	
	Vector3 operator*(const float& s) const;
	Vector3 operator/(const float& s) const;
	bool operator==(const Vector3& v) const;
	bool operator!=(const Vector3& v) const;

	//vector operations
	T dot(const Vector3& v) const;
	Vector3 cross(const Vector3& v) const;
	T magnitude() const;
	T magnitudeSquared() const;
	Vector3 normalized() const;
	float angle(const Vector3& v) const;
	Vector3 projection(Vector3& w) const;
	Vector3 projectionOntoNormalized(Vector3& wNormalized) const;
	Vector3 perpendicular(Vector3& w) const;
	Vector3 perpendicularOntoNormalized(Vector3& wNormalized) const;
	static void gramSchmidtOrthogonalization(Vector3& a, Vector3& b, Vector3& c);
	static bool isRightHanded(Vector3& a, Vector3& b, Vector3& c);
	static bool isBasis(Vector3& a, Vector3& b, Vector3& c);

	//point operations
	T distance(const Vector3& p) const;
	T distanceSquared(const Vector3& p) const;

	//utilities
	string toString();


private:
	T x;
	T y;
	T z;
};

//operator overloading
template<typename T>
Vector3<T> operator*(const float& s, const Vector3<T>& v);

template<typename T>
std::ostream& operator<< (std::ostream& s, const Vector3<T>& v);


/**********getters**********/
template<typename T>
inline T Vector3<T>::getX() const {
	return x;
}


template<typename T>
inline T Vector3<T>::getY() const {
	return y;
}


template<typename T>
inline T Vector3<T>::getZ() const {
	return z;
}


/**********setters**********/
template<typename T>
inline void Vector3<T>::set(T x, T y, T z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

template<typename T>
inline void Vector3<T>::setX(T x) {
	this->x = x;
}

template<typename T>
inline void Vector3<T>::setY(T y) {
	this->y = y;
}

template<typename T>
inline void Vector3<T>::setZ(T z) {
	this->z = z;
}

/**********operator overloading**********/
template<typename T>
Vector3<T>& Vector3<T>::operator=(const Vector3& v) const{

	//if same object
	if(this == &v) return *this;

	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3& v) const{
	return Vector3(x+v.x,y+v.y, z+v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3& v) const{
	return Vector3(x-v.x,y-v.y,z-v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-() const{
	return Vector3(-x,-y,-z);
}


template<typename T>
Vector3<T> Vector3<T>::operator*(const float& s) const{
	return Vector3<T>(x*s,y*s,z*s);
}

template<typename T>
Vector3<T> operator*(const float& s, const Vector3<T>& v){
	return Vector3<T>(s*v.getX(),s*v.getY(),s*v.getZ());
}

template<typename T>
Vector3<T> Vector3<T>::operator/(const float& s) const{
	return Vector3(x/s,y/s,z/s);
}

template<typename T>
bool Vector3<T>::operator==(const Vector3& v) const{
	return (x==v.x) && (y==v.y) && (z==v.z);
}

template<typename T>
bool Vector3<T>::operator!=(const Vector3& v) const{
	return (x!=v.x) || (y!=v.y) || (z!=v.z);
}

template<typename T>
std::ostream& operator<< (std::ostream& s, const Vector3<T>& v) {
	return s<<"("<<v.getX()<<","<<v.getY()<<","<<v.getZ()<<")";
}

/**********vector operations**********/
template<typename T>
T Vector3<T>::dot(const Vector3& v) const{
	return x*v.x + y*v.y + z*v.z;
}

template<typename T>
Vector3<T> Vector3<T>::cross(const Vector3& v) const{
	return Vector3<T>(y*v.z-v.y*z, z*v.x-v.z*x, x*v.y-v.x*y);
}

template<typename T>
T Vector3<T>::magnitude() const{
	return sqrt(this->magnitudeSquared());
}

template<typename T>
T Vector3<T>::magnitudeSquared() const{
	return x*x + y*y + z*z;
}

template<typename T>
Vector3<T> Vector3<T>::normalized() const{
	float magnitude = this->magnitude();
	Vector3 result;
	if(magnitude != 0){
		result.set(x/magnitude, y/magnitude, z/magnitude);
	}

	return result;
}

template<typename T>
float Vector3<T>::angle(const Vector3<T>& v) const{
	Vector3<T> thisNormalized = this->normalized();
	Vector3<T> vNormalized = v->normalized();
	T crossMagnitude = thisNormalized.cross(vNormalized).magnitude();
	T dot = thisNormalized->dot(vNormalized);
	return arctan(crossMagnitude/dot);
}

template<typename T>
Vector3<T> Vector3<T>::projection(Vector3& w) const{
	return this->dot(w)/w.magnitudeSquared()*w;
}

template<typename T>
Vector3<T> Vector3<T>::projectionOntoNormalized(Vector3& wNormalized) const{
	return this->dot(wNormalized)*wNormalized;
}


template<typename T>
Vector3<T> Vector3<T>::perpendicular(Vector3& w) const{
	return this->operator -(this->projection(w));
}

template<typename T>
Vector3<T> Vector3<T>::perpendicularOntoNormalized(Vector3& wNormalized) const{
	return this->operator-(this->projectionOntoNormalized(wNormalized));
}

template<typename T>
void Vector3<T>::gramSchmidtOrthogonalization(Vector3& a, Vector3& b, Vector3& c){
	a = a.normalized();
	b = b.perpendicularOntoNormalized(a).normalized();
	c = c.perpendicularOntoNormalized(b).normalized();
}

template<typename T>
bool Vector3<T>::isRightHanded(Vector3& a, Vector3& b, Vector3& c){
	return a.dot(b.cross(c)) > 0;
}

template<typename T>
bool Vector3<T>::isBasis(Vector3& a, Vector3& b, Vector3& c){
	Vector3<T> zero(0,0,0);

	return a.cross(b) != zero && a.cross(c) != zero && b.cross(c) != zero;
}

/**********point operations**********/
template<typename T>
T Vector3<T>::distance(const Vector3<T>& p) const{
	return sqrt(this->distanceSquared(p));
}

template<typename T>
T Vector3<T>::distanceSquared(const Vector3<T>& p) const{
	T xDist = x-p.x;
	T yDist = y-p.y;
	T zDist = z-p.z;
	return xDist*xDist + yDist*yDist + zDist*zDist;
}


/**********utilities**********/
template<typename T>
string Vector3<T>::toString()
{
	ostringstream oss;
	oss << *this;
    return oss.str();
}


#endif /* VECTOR3_H_ */
