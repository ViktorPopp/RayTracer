#ifndef _RAY_H_
#define _RAY_H_

#include "Vector3.hpp"

class Ray {
public:
    Ray() {}
    Ray(const Point3& origin, const Vector3& direction) : m_Origin(origin), m_Direction(direction) {}

    const Point3& origin() const  { return m_Origin; }
    const Vector3& direction() const { return m_Direction; }

    Point3 at(double t) const {
        return m_Origin + t*m_Direction;
    }

private:
    Point3 m_Origin;
    Vector3 m_Direction;
};

#endif
