/*
 * Chapter2.cpp
 *
 *  Created on: 5 Oct 2017
 *      Author: sbl
 */

#include "Chapter2.h"


void Chapter2::print(){
	cout << "Exercise " << exersiceNumber << endl;
	cout << resultStream.str() << endl;
	cout << endl;
}

Chapter2 Chapter2::exercise1(){
	exersiceNumber = 1;
	resultStream.str(string());
	resultStream.clear();


	//part 1
	Vector3<float> v(-2,5,10);
	Vector3<float> w(1,-2,4);
	streamExercise1(1, v, w);

	//part 2
	v.set(6,-7,4);
	w.set(-6,7,-4);
	streamExercise1(2, v, w);

	//part 3
	v.set(4,8,-1);
	w.set(-2,2,8);
	streamExercise1(3, v, w);

	//part 4
	v.set(1,3,-2);
	w.set(-4,-12,8);
	streamExercise1(4, v, w);

	return *this;
}

void Chapter2::streamExercise1(int number, Vector3<float>& v, Vector3<float>& w){
	resultStream << endl;
	resultStream << number <<". v="<< v << " w="<<w << endl;
	resultStream << "v+w="<<v+w << endl;
	resultStream << "v.w=" << v.dot(w)<<endl;
	resultStream << "vXw=" << v.cross(w) << " wXv=" << w.cross(v) << endl;
	resultStream << "|v|=" << v.magnitude() << " |w|=" << w.magnitude() << endl;
	resultStream << "|v|^2=" << v.magnitudeSquared() << " |w|^2=" << w.magnitudeSquared() << endl;
	resultStream << "v^=" << v.normalized() << " w^=" << w.normalized() << endl;
}


Chapter2 Chapter2::exercise2(){
	exersiceNumber = 2;
	resultStream.str(string());
	resultStream.clear();

	//part 1
	Vector3<float> u(-6,1,6);
	Vector3<float> v(-5,-9,-2);
	Vector3<float> w(3,-6,1);
	streamExercise2(1, u, v, w);

	//part 2
	u.set(4,-10,4);
	v.set(9,1,5);
	w.set(2,-3,-3);
	streamExercise2(2, u, v, w);

	//part 3
	u.set(1,-2,-5);
	v.set(-10,3,7);
	w.set(-7,-3,-9);
	streamExercise2(3, u, v, w);

	//part 4
	u.set(0,3,0);
	v.set(-9,6,10);
	w.set(-8,3,5);
	streamExercise2(4, u, v, w);

	return *this;
}

void Chapter2::streamExercise2(int number, Vector3<float>& u, Vector3<float>& v, Vector3<float>& w){
	resultStream << endl;
	resultStream << number <<". u="<< u << " v="<<v << " w=" << w << endl;
	resultStream << "Can be used as basis? " << (Vector3<float>::isBasis(u, v, w) ? "Yes" : "No") << endl;
	Vector3<float>::gramSchmidtOrthogonalization(u, v, w);
	resultStream << "Orthogonalization: u="<< u << " v="<<v << " w=" << w << endl;
	resultStream << (Vector3<float>::isRightHanded(u, v, w) ? "Right-handed" : "Left-handed") << endl;
}
