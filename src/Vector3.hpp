#ifndef _VECTOR_3_
#define _VECTOR_3_

#include <cmath>
#include <iostream>

struct Vector3 {
    double x;
    double y;
    double z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}

    Vector3 operator -() const {
        return Vector3(-x, -y, -z);
    }

    Vector3& operator +=(const Vector3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3& operator *=(double t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }

    Vector3& operator /=(double t) {
        return *this *= 1 / t;
    }

    double length() const {
        return std::sqrt(length_squared());
    }

    double length_squared() const {
        return x * x + y * y + z * z;
    }
};

using Point3 = Vector3;

inline std::ostream& operator <<(std::ostream& out, const Vector3& v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline Vector3 operator +(const Vector3& u, const Vector3& v) {
    return Vector3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline Vector3 operator -(const Vector3& u, const Vector3& v) {
    return Vector3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline Vector3 operator *(const Vector3& u, const Vector3& v) {
    return Vector3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline Vector3 operator *(double t, const Vector3& v) {
    return Vector3(t * v.x, t * v.y, t * v.z);
}

inline Vector3 operator *(const Vector3& v, double t) {
    return t * v;
}

inline Vector3 operator /(const Vector3& v, double t) {
    return (1 / t) * v;
}

inline double dot(const Vector3& u, const Vector3& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline Vector3 cross(const Vector3& u, const Vector3& v) {
    return Vector3(u.y * v.z - u.z * v.y,
                u.z * v.x - u.x * v.z,
                u.x * v.y - u.y * v.x);
}

inline Vector3 unit_vector(const Vector3& v) {
    return v / v.length();
}

#endif
