/*
 * PolarCoordinates.h
 *
 *  Created on: 21 Apr 2018
 *      Author: sbl
 */

#ifndef POLARCOORDINATES_H_
#define POLARCOORDINATES_H_
#include <math.h>

#include "Vector2.h"

template<typename T>
class PolarCoordinates {
public:
	PolarCoordinates() : radius(0), polar(0) {};
	PolarCoordinates(T radius, T polar) : radius(radius), polar(polar) {};
	PolarCoordinates(Vector2<float> cartisanCoords);
	virtual ~PolarCoordinates();

	T getRadius() const;
	T getPolar() const;

	void setRadius(T radius);
	void setPolar(T polar);

	Vector2<T> toCartisan();

private:
	T radius;
	T polar;
};

template<typename T>
PolarCoordinates::PolarCoordinates(Vector2<T> cartisanCoords) {
	T x = cartisanCoords.getX();
	T y = cartisanCoords.getY();
	radius = sqrt(x*x+y*y);
	polar = atan2(y,x);
}

template<typename T>
PolarCoordinates::~PolarCoordinates() {
	// TODO Auto-generated destructor stub
}

template<typename T>
T PolarCoordinates::getRadius() const {
	return radius;
}

template<typename T>
void PolarCoordinates::setRadius(T radius) {
	this->radius = radius;
}

template<typename T>
T PolarCoordinates::getPolar() const {
	return polar;
}

template<typename T>
void PolarCoordinates::setPolar(T polar) {
	this->polar = polar;
}

template<typename T>
Vector2<T> PolarCoordinates::toCartisan() {
	return Vector2<Ts>(radius*cos(polar), radius*sin(polar));
}


#endif /* POLARCOORDINATES_H_ */
