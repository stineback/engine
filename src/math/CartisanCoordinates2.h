#ifndef CARTISANCOORDINATES2_H_
#define CARTISANCOORDINATES2_H_

#include <iostream>
#include <sstream>
#include <string>

template<typename T>
class CartisanCoordinates2 {
protected:
	T x;
	T y;

	//constructors/destructor
	CartisanCoordinates2() : x(0), y(0){};
    CartisanCoordinates2(T x, T y) :x(x), y(y) {};
	CartisanCoordinates2(const CartisanCoordinates2& v) : x(v.x), y(v.y){};
	virtual ~CartisanCoordinates2(){};

public:
	//getters
	T getX() const;
	T getY() const;

	//setters
	void set(T x, T y);
	void setX(T x);
	void setY(T y);

	//operator overloading
	virtual CartisanCoordinates2& operator=(const CartisanCoordinates2& c);
	bool operator==(const CartisanCoordinates2& c) const;
	bool operator!=(const CartisanCoordinates2& c) const;

	//utilities
	std::string toString() const;
};

//operator overloading
template<typename T>
std::ostream& operator<< (std::ostream& s, const CartisanCoordinates2<T>& v);

/**********getters**********/
template<typename T>
inline T CartisanCoordinates2<T>::getX() const {
	return x;
}

template<typename T>
inline T CartisanCoordinates2<T>::getY() const {
	return y;
}

/**********setters**********/
template<typename T>
inline void CartisanCoordinates2<T>::set(T x, T y) {
	this->x = x;
	this->y = y;
}

template<typename T>
inline void CartisanCoordinates2<T>::setX(T x) {
	this->x = x;
}

template<typename T>
inline void CartisanCoordinates2<T>::setY(T y) {
	this->y = y;
}

/**********operator overloading**********/
template<typename T>
CartisanCoordinates2<T>& CartisanCoordinates2<T>::operator=(const CartisanCoordinates2& c){
	//if same object
	if(this == &c) return *this;

	this->x = c.x;
	this->y = c.y;
	return *this;
}

template<typename T>
bool CartisanCoordinates2<T>::operator==(const CartisanCoordinates2& c) const {
	return typeid(*this) == typeid(c) && (this->x==c.x) && (this->y==c.y);
}

template<typename T>
bool CartisanCoordinates2<T>::operator!=(const CartisanCoordinates2& c) const {
	return typeid(*this) != typeid(c) || (this->x!=c.x) || (this->y!=c.y);
}


template<typename T>
std::ostream& operator<< (std::ostream& s, const CartisanCoordinates2<T>& c) {
	return s<<"("<<c.getX()<<","<<c.getY()<<")";
}

/**********utilities**********/
template<typename T>
std::string CartisanCoordinates2<T>::toString() const{
	std::ostringstream oss;
	oss << *this;
    return oss.str();
}

#endif /* CARTISANCOORDINATES2_H_ */