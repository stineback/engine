/*
 * Vector3.h
 *
 *  Created on: 2 Oct 2017
 *      Author: sbl
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <math.h>

#include "CartisanCoordinates3.h"

using namespace std;

template<typename T>
class Vector3 : public CartisanCoordinates3<T> {
public:
	//constructors/destructor
	Vector3() {};
	Vector3(T x, T y, T z) : CartisanCoordinates3<T>(x, y, z)  {};
	Vector3(const Vector3& v) : CartisanCoordinates3<T>(v.x, v.y, v.z){};
	virtual ~Vector3(){};

	//operator overloading
	Vector3& operator=(const Vector3& v);
	Vector3 operator+(const Vector3& v) const;
	Vector3 operator-(const Vector3& v) const;
	Vector3 operator-() const;	
	Vector3 operator*(const float& s) const;
	Vector3 operator/(const float& s) const;

	//vector operations
	T dot(const Vector3& v) const;
	Vector3 cross(const Vector3& v) const;
	T magnitude() const;
	T magnitudeSquared() const;
	Vector3 normalized() const;
	float angle(const Vector3& v, const Vector3& normal) const;
	Vector3 projection(Vector3& w) const;
	static bool isRightHanded(const Vector3& a,const Vector3& b, const Vector3& c);
	static bool isBasis(const Vector3& a, const Vector3& b, const Vector3& c);
};

//operator overloading
template<typename T>
Vector3<T> operator*(const float& s, const Vector3<T>& v);

/**********operator overloading**********/

//Base class assignment operator is always hidden by the copy assignment operator of the derived class,
//so needs to explict implement move assignment operator
template<typename T>
Vector3<T>& Vector3<T>::operator=(const Vector3& v){
	CartisanCoordinates3<T>::operator=(v);
	return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3& v) const{
	return Vector3(this->x+v.x,this->y+v.y, this->z+v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3& v) const{
	return Vector3(this->x-v.x,this->y-v.y,this->z-v.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-() const{
	return Vector3(-this->x,-this->y,-this->z);
}


template<typename T>
Vector3<T> Vector3<T>::operator*(const float& s) const{
	return Vector3<T>(this->x*s,this->y*s,this->z*s);
}

template<typename T>
Vector3<T> operator*(const float& s, const Vector3<T>& v){
	return Vector3<T>(s*v.getX(),s*v.getY(),s*v.getZ());
}

template<typename T>
Vector3<T> Vector3<T>::operator/(const float& s) const{
	return Vector3(this->x/s,this->y/s,this->z/s);
}
/**********vector operations**********/
template<typename T>
T Vector3<T>::dot(const Vector3& v) const{
	return this->x*v.x + this->y*v.y + this->z*v.z;
}

template<typename T>
Vector3<T> Vector3<T>::cross(const Vector3& v) const{
	return Vector3<T>(this->y*v.z-v.y*this->z, this->z*v.x-v.z*this->x, this->x*v.y-v.x*this->y);
}

template<typename T>
T Vector3<T>::magnitude() const{
	return sqrt(this->magnitudeSquared());
}

template<typename T>
T Vector3<T>::magnitudeSquared() const{
	return this->x*this->x + this->y*this->y + this->z*this->z;
}

template<typename T>
Vector3<T> Vector3<T>::normalized() const{
	float magnitude = this->magnitude();
	Vector3 result;
	if(magnitude != 0){
		result.set(this->x/magnitude, this->y/magnitude, this->z/magnitude);
	}

	return result;
}

template<typename T>
float Vector3<T>::angle(const Vector3<T>& v, const Vector3<T>& normal) const{
	Vector3<T> cross = this->cross(v);
	int sign = cross.dot(normal) < 0 ? -1 : 1;
	T dot = this->dot(v);
	return atan2(sign*cross.magnitude(),dot);
}

template<typename T>
Vector3<T> Vector3<T>::projection(Vector3& w) const{
	return this->dot(w)/w.magnitudeSquared()*w;
}

template<typename T>
bool Vector3<T>::isRightHanded(const Vector3& a, const Vector3& b, const Vector3& c){
	return a.dot(b.cross(c)) > 0;
}

template<typename T>
bool Vector3<T>::isBasis(const Vector3& a, const Vector3& b, const Vector3& c){
	Vector3<T> zero(0,0,0);

	return a.cross(b) != zero && a.cross(c) != zero && b.cross(c) != zero;
}

#endif /* VECTOR3_H_ */
