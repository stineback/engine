/*
 * Chapter2.h
 *
 *  Created on: 5 Oct 2017
 *      Author: sbl
 */

#ifndef CHAPTER2_H_
#define CHAPTER2_H_

#include "Vector2.h"
#include "Vector3.h"
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

class Chapter2 {
private:
	int exersiceNumber;
	ostringstream resultStream;

	void streamExercise1(int number, Vector3<float>& v, Vector3<float>& w);
	void streamExercise2(int number, Vector3<float>& u, Vector3<float>& v, Vector3<float>& w);
public:
	Chapter2() : exersiceNumber(0), resultStream(string()) {cout << "**********Chapter 2**********"<<endl;};
	Chapter2(const Chapter2& ch2) : exersiceNumber(ch2.exersiceNumber), resultStream(ch2.resultStream.str()) {};
	virtual ~Chapter2(){};

	Chapter2 exercise1();
	Chapter2 exercise2();

	void print();
};

#endif /* CHAPTER2_H_ */
