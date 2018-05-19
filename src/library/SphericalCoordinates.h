/*
 * SphericalCoordinates.h
 *
 *  Created on: 21 Apr 2018
 *      Author: sbl
 */

#ifndef POLARCOORDINATES_H_
#define POLARCOORDINATES_H_
#include <math.h>

#include "Vector3.h"

class SphericalCoordinates {
public:
	SphericalCoordinates() : radius(0), polar(0), elevation(0) {};
	SphericalCoordinates(float radius, float polar, float elevation) : radius(radius), polar(polar), elevation(elevation) {};
	SphericalCoordinates(Vector3<float> cartisanCoords);
	virtual ~SphericalCoordinates();

	float getRadius() const;
	float getPolar() const;
	float getElevation() const;

	void setRadius(float radius);
	void setPolar(float polar);
	void setElevation(float elevation);

	Vector3<float> toCartisan();

private:
	float radius;
	float polar;
	float elevation;
};

#endif /* POLARCOORDINATES_H_ */
