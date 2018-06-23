/*
 * SphericalCoordinates.h
 *
 *  Created on: 21 Apr 2018
 *      Author: sbl
 */

#ifndef SPHERICALCOORDINATES_H_
#define SPHERICALCOORDINATES_H_
#include <math.h>

#include "Vector3.h"

template<typename T>
class SphericalCoordinates {
public:
	SphericalCoordinates() : radius(0), polar(0), elevation(0) {};
	SphericalCoordinates(T radius, T polar, T elevation) : radius(radius), polar(polar), elevation(elevation) {};
	SphericalCoordinates(Vector3<T> cartisanCoords);
	virtual ~SphericalCoordinates();

	T getRadius() const;
	T getPolar() const;
	T getElevation() const;

	void setRadius(T radius);
	void setPolar(T polar);
	void setElevation(T elevation);

	Vector3<T> toCartisan();

private:
	T radius;
	T polar;
	T elevation;
};

template<typename T>
SphericalCoordinates::SphericalCoordinates(Vector3<T> cartisanCoords) {
	T x = cartisanCoords.getX();
	T y = cartisanCoords.getY();
	radius = sqrt(x*x+y*y);
	polar = atan2(y,x);
}

template<typename T>
T SphericalCoordinates::getRadius() const {
	return radius;
}

template<typename T>
void SphericalCoordinates::setRadius(T radius) {
	this->radius = radius;
}

template<typename T>
T SphericalCoordinates::getPolar() const {
	return polar;
}

template<typename T>
void SphericalCoordinates::setPolar(T polar) {
	this->polar = polar;
}

template<typename T>
T SphericalCoordinates::getElevation() const {
	return elevation;
}

template<typename T>
void SphericalCoordinates::setElevation(T elevation) {
	this->elevation = elevation;
}

template<typename T>
Vector3<T> SphericalCoordinates::toCartisan() {
	return Vector3<T>(radius*cos(polar)*sin(elevation), radius*sin(polar)*sin(elevation), radius*cos(elevation));
}


#endif /* SPHERICALCOORDINATES_H_ */
