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

class PolarCoordinates {
public:
	PolarCoordinates() : radius(0), polar(0) {};
	PolarCoordinates(float radius, float polar) : radius(radius), polar(polar) {};
	PolarCoordinates(Vector2<float> cartisanCoords);
	virtual ~PolarCoordinates();

	float getRadius() const;
	float getPolar() const;

	void setRadius(float radius);
	void setPolar(float polar);

	Vector2<float> toCartisan();

private:
	float radius;
	float polar;
};

#endif /* POLARCOORDINATES_H_ */
