#ifndef CARTISANCOORDINATES3_H_
#define CARTISANCOORDINATES3_H_

#include <iostream>
#include <sstream>
#include <string>

template<typename T>
class CartisanCoordinates3 {
protected:
	T x;
	T y;
	T z;

	//constructors/destructor
	CartisanCoordinates3() :x(0), y(0), z(0){};
	CartisanCoordinates3(T x, T y, T z) :x(x), y(y), z(z) {};
	CartisanCoordinates3(const CartisanCoordinates3& c) : x(c.x), y(c.y), z(c.z){};
	virtual ~CartisanCoordinates3(){};

public:
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
	virtual CartisanCoordinates3& operator=(const CartisanCoordinates3& c);
	bool operator==(const CartisanCoordinates3& c) const;
	bool operator!=(const CartisanCoordinates3& c) const;


	//utilities
	std::string toString() const;
};

//operator overloading
template<typename T>
std::ostream& operator<< (std::ostream& s, const CartisanCoordinates3<T>& v);

/**********operator overloading**********/
template<typename T>
CartisanCoordinates3<T>& CartisanCoordinates3<T>::operator=(const CartisanCoordinates3& c){
	//if same object
	if(this == &c) return *this;

	x = c.x;
	y = c.y;
	z = c.z;
	return *this;
}

template<typename T>
bool CartisanCoordinates3<T>::operator==(const CartisanCoordinates3& c) const {
	return typeid(*this) == typeid(c) && (this->x==c.x) && (this->y==c.y) && (this->z==c.z);
}

template<typename T>
bool CartisanCoordinates3<T>::operator!=(const CartisanCoordinates3& c) const {
	return typeid(*this) != typeid(c) || (this->x!=c.x) || (this->y!=c.y) || (this->z!=c.z);
}


/**********getters**********/
template<typename T>
inline T CartisanCoordinates3<T>::getX() const {
	return x;
}


template<typename T>
inline T CartisanCoordinates3<T>::getY() const {
	return y;
}

template<typename T>
inline T CartisanCoordinates3<T>::getZ() const {
	return z;
}

/**********setters**********/
template<typename T>
inline void CartisanCoordinates3<T>::set(T x, T y, T z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

template<typename T>
inline void CartisanCoordinates3<T>::setX(T x) {
	this->x = x;
}

template<typename T>
inline void CartisanCoordinates3<T>::setY(T y) {
	this->y = y;
}

template<typename T>
inline void CartisanCoordinates3<T>::setZ(T z) {
	this->z = z;
}

template<typename T>
std::ostream& operator<< (std::ostream& s, const CartisanCoordinates3<T>& c) {
	return s<<"("<<c.getX()<<","<<c.getY()<<","<<c.getZ()<<")";
}

/**********utilities**********/
template<typename T>
std::string CartisanCoordinates3<T>::toString() const{
	std::ostringstream oss;
	oss << *this;
    return oss.str();
}



#endif /* CARTISANCOORDINATES3_H_ */