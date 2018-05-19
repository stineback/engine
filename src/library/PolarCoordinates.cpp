/*
 * PolarCoordinates.cpp
 *
 *  Created on: 21 Apr 2018
 *      Author: sbl
 */

#include "PolarCoordinates.h"
PolarCoordinates::PolarCoordinates(Vector2<float> cartisanCoords) {
	float x = cartisanCoords.getX();
	float y = cartisanCoords.getY();
	radius = sqrt(x*x+y*y);
	polar = atan2(y,x);
}

PolarCoordinates::~PolarCoordinates() {
	// TODO Auto-generated destructor stub
}

float PolarCoordinates::getRadius() const {
	return radius;
}

void PolarCoordinates::setRadius(float radius) {
	this->radius = radius;
}

float PolarCoordinates::getPolar() const {
	return polar;
}

void PolarCoordinates::setPolar(float polar) {
	this->polar = polar;
}


Vector2<float> PolarCoordinates::toCartisan() {
	return Vector2<float>(radius*cos(polar), radius*sin(polar));
}
