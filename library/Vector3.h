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
	Vector3& operator=(const Vector3& v);
	Vector3 operator+(const Vector3& v);
	Vector3 operator-(const Vector3& v);
	Vector3 operator*(const float& s);
	Vector3 operator/(const float& s);
	bool operator==(const Vector3& v);
	bool operator!=(const Vector3& v);

	//special math operations
	T dot(const Vector3& v);
	Vector3 cross(const Vector3& v);
	T magnitude();
	T magnitudeSquared();
	Vector3 normalized();
	Vector3 projection(Vector3& w);
	Vector3 projectionOntoNormalized(Vector3& wNormalized);
	Vector3 perpendicular(Vector3& w);
	Vector3 perpendicularOntoNormalized(Vector3& wNormalized);
	static void gramSchmidtOrthogonalization(Vector3& a, Vector3& b, Vector3& c);
	static bool isRightHanded(Vector3& a, Vector3& b, Vector3& c);

	//utilities
	string toString();
	static bool isBasis(Vector3& a, Vector3& b, Vector3& c);


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
Vector3<T>& Vector3<T>::operator=(const Vector3& v){

	//if same object
	if(this == &v) return *this;

	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3& v) {
	return Vector3(x+v.x,y+v.y, z+v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3& v) {
	return Vector3(x-v.x,y-v.y,z-v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator*(const float& s) {
	return Vector3<T>(x*s,y*s,z*s);
}

template<typename T>
Vector3<T> operator*(const float& s, const Vector3<T>& v) {
	return Vector3<T>(s*v.getX(),s*v.getY(),s*v.getZ());
}

template<typename T>
Vector3<T> Vector3<T>::operator/(const float& s) {
	return Vector3(x/s,y/s,z/s);
}

template<typename T>
bool Vector3<T>::operator==(const Vector3& v) {
	return (x==v.x) && (y==v.y) && (z==v.z);
}

template<typename T>
bool Vector3<T>::operator!=(const Vector3& v) {
	return (x!=v.x) || (y!=v.y) || (z!=v.z);
}

template<typename T>
std::ostream& operator<< (std::ostream& s, const Vector3<T>& v) {
	return s<<"("<<v.getX()<<","<<v.getY()<<","<<v.getZ()<<")";
}

/**********special math operations**********/
template<typename T>
T Vector3<T>::dot(const Vector3& v){
	return x*v.x + y*v.y + z*v.z;
}

template<typename T>
Vector3<T> Vector3<T>::cross(const Vector3& v){
	return Vector3<T>(y*v.z-v.y*z, z*v.x-v.z*x, x*v.y-v.x*y);
}

template<typename T>
T Vector3<T>::magnitude(){
	return sqrt(this->magnitudeSquared());
}

template<typename T>
T Vector3<T>::magnitudeSquared(){
	return x*x + y*y + z*z;
}

template<typename T>
Vector3<T> Vector3<T>::normalized(){
	float magnitude = this->magnitude();
	if(magnitude == 0){
		x = y = z = 0;
	}
	else{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}

	return *this;
}

template<typename T>
Vector3<T> Vector3<T>::projection(Vector3& w){
	return this->dot(w)/w.magnitudeSquared()*w;
}

template<typename T>
Vector3<T> Vector3<T>::projectionOntoNormalized(Vector3& wNormalized){
	return this->dot(wNormalized)*wNormalized;
}


template<typename T>
Vector3<T> Vector3<T>::perpendicular(Vector3& w){
	return this->operator -(this->projection(w));
}

template<typename T>
Vector3<T> Vector3<T>::perpendicularOntoNormalized(Vector3& wNormalized){
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

/**********utilities**********/
template<typename T>
string Vector3<T>::toString()
{
	ostringstream oss;
	oss << *this;
    return oss.str();
}

template<typename T>
bool Vector3<T>::isBasis(Vector3& a, Vector3& b, Vector3& c){
	Vector3<T> zero(0,0,0);

	return a.cross(b) != zero && a.cross(c) != zero && b.cross(c) != zero;
}

#endif /* VECTOR3_H_ */
