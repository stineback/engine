#ifndef PLANE_H_
#define PLANE_H_

#include "Point3.h"
#include "Vector3.h"

template<typename T>
class Plane {
public: 
    //constructors/destructor
    Plane(Vector3<T> normal, Point3<T> origin) : normal(normal), origin(origin){};
	Plane(const Plane& p) : normal(p.getNormal()), origin(p.getOrigin()){};
	virtual ~Plane(){};

    //getters
    Vector3<T> getNormal() const;
    Point3<T> getOrigin() const;

    //operator overloading
	Plane& operator=(const Plane& l);
	bool operator==(const Plane& l) const;
	bool operator!=(const Plane& l) const;

    //plane operations
	static bool isCoplanar(const Point3<T>& p0, const Point3<T>& p1, const Point3<T>& p2, const Point3<T>& p3, T threshold = 0);
private:
    Vector3<T> normal;
    Point3<T> origin;
};


//operator overloading
template<typename T>
std::ostream& operator<< (std::ostream& s, const Plane<T>& v);

/**********getters**********/
template<typename T>
inline Vector3<T> Plane<T>::getNormal() const
{
	return normal;
}

template<typename T>
inline Point3<T>  Plane<T>::getOrigin() const
{
	return origin;
}

/**********operator overloading**********/
template<typename T>
Plane<T>& Plane<T>::operator=(const Plane& p)
{
	//if same object
	if(this == &p) return *this;

	this->normal = p.normal;
	this->origin = p.origin;
	return *this;
}


template<typename T>
bool Plane<T>::operator==(const Plane& p) const
{
    //is it same line if normal and/or origin is different but the parametizied line is the same?
	return (this->normal==p.normal) && (this->origin==p.origin);
}

template<typename T>
bool Plane<T>::operator!=(const Plane& p) const
{
	return (this->normal!=p.normal) || (this->origin!=p.origin);
}


template<typename T>
std::ostream& operator<< (std::ostream& s, const Plane<T>& p) {
	return s<<"normal="<<p.getNormal()<<", origin="<<p.getOrigin();
}

/**********plane operations**********/
template<typename T>
bool Plane<T>::isCoplanar(const Point3<T>& p0, const Point3<T>& p1, const Point3<T>& p2, const Point3<T>& p3, T threshold)
{
	T result = (p1-p0).dot((p2-p0).cross(p3-p0));
	return result == threshold;
}
#endif /* PLANE_H_ */