#ifndef LINE2_H_
#define LINE2_H_

#include <Point3.h>

template <typename T>
class Triangle {
public:
    Triangle() {};
    Triangle(const Triangle & triangle) {};
    Triangle(const Point3<T> &v0, const Point3<T> &v1, const Point3<T> &v2) {};
    virtual ~Triangle(){};

    std::vector<Point3<T>> getVertices() const;
private:
    Point3<T> v0_, v1_, v2_;

};

template <typename T>
Triangle<T>::Triangle(const Triangle & triangle) {
    std::vector<Point3<T>> vertices = triangle.getVertices();
    v0_ = vertices[0];
    v1_ = vertices[1];
    v2_ = vertices[2];
}

template <typename T>
Triangle<T>::Triangle(const Point3<T> &v0, const Point3<T> &v1, const Point3<T> &v2) : v0_(v0), v1_(v1), v2_(v2) {
}

template <typename T>
std::vector<Point3<T>> Triangle<T>::getVertices() const{
    std::vector<Point3<T>> vertices = {v0_, v1_, v2_};
    return vertices;
}

#endif /* LINE2_H_ */