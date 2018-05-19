/*
 * PolarCoordinates.cpp
 *
 *  Created on: 21 Apr 2018
 *      Author: sbl
 */

#include "SphericalCoordinates.h"
SphericalCoordinates::SphericalCoordinates(Vector3<float> cartisanCoords) {
	float x = cartisanCoords.getX();
	float y = cartisanCoords.getY();
	radius = sqrt(x*x+y*y);
	polar = atan2(y,x);
}

SphericalCoordinates::~SphericalCoordinates() {
	// TODO Auto-generated destructor stub
}

float SphericalCoordinates::getRadius() const {
	return radius;
}

void SphericalCoordinates::setRadius(float radius) {
	this->radius = radius;
}

float SphericalCoordinates::getPolar() const {
	return polar;
}

void SphericalCoordinates::setPolar(float polar) {
	this->polar = polar;
}

float SphericalCoordinates::getElevation() const {
	return elevation;
}

void SphericalCoordinates::setElevation(float elevation) {
	this->elevation = elevation;
}

Vector3<float> SphericalCoordinates::toCartisan() {
	return Vector3<float>(radius*cos(polar)*sin(elevation), radius*sin(polar)*sin(elevation), radius*cos(elevation));
}
