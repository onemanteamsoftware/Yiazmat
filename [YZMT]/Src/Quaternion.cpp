/*[YZMT]::[YZMT]::Quaternion.cpp*/
/*github.com/onemanteamsoftware*/
#include "Quaternion.hpp"

namespace YZMT {
    Quaternion::Quaternion()
        : x { 0.0f }, y { 0.0f }, z { 0.0f }, w { 0.0f } {
    }
    
    Quaternion::Quaternion(const vec4& v)
        : x { v.x }, y { v.y }, z { v.z }, w { v.w } {
    }
    
    Quaternion::Quaternion(const vec3& v, float w)
        : x { v.x }, y { v.y }, z { v.z }, w { w } {
    }
    
    Quaternion::Quaternion(float x, float y, float z, float w)
        : x { x }, y { y }, z { z }, w { w } {
    }
    
    Quaternion Quaternion::Identity() {
        return Quaternion { 0.0f, 0.0f, 0.0f, 1.0f };
    }
    
    Quaternion Quaternion::Conjugate() const {
        return Quaternion { -x, -y, -z, w };
    }
    
    Quaternion Quaternion::operator-() const {
        return Quaternion { -x, -y, -z, -w };
    }
    
    Quaternion Quaternion::operator*(float s) const {
        return Quaternion { x * s, y * s, z * s, w * s };
    }
    
    Quaternion operator*(float s, const Quaternion& q) {
        return Quaternion { q.x * s, q.y * s, q.z * s, q.w * s };
    }
    
    Quaternion Quaternion::operator*(const Quaternion& q) const {
        return Quaternion {
            w * q.x + x * q.w + y * q.z - z * q.y,
            w * q.y - x * q.z + y * q.w + z * q.x,
            w * q.z + x * q.y - y * q.x + z * q.w,
            w * q.w - x * q.x - y * q.y - z * q.z
        };
    }
    
    Quaternion Quaternion::operator/(float s) const {
        return Quaternion { x / s, y / s, z / s, w / s };
    }
    
    Quaternion operator/(float s, const Quaternion& q) {
        return Quaternion { q.x / s, q.y / s, q.z / s, q.w / s };
    }
    
    Quaternion Quaternion::operator+(const Quaternion& q) const {
        return Quaternion { x + q.x, y + q.y, z + q.z, w + q.w };
    }
    
    Quaternion Quaternion::operator-(const Quaternion& q) const {
        return Quaternion { x - q.x, y - q.y, z - q.z, w - q.w };
    }
    
    bool Quaternion::operator==(const Quaternion& q) const {
        return x == q.x && y == q.y && z == q.z && w == q.w;
    }
    
    bool Quaternion::operator!=(const Quaternion& q) const {
        return !(*this == q);
    }
    
    Quaternion& Quaternion::operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    
    Quaternion& Quaternion::operator*=(const Quaternion& q) {
        *this = *this * q;
        return *this;
    }
    
    Quaternion& Quaternion::operator/=(float s) {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
        return *this;
    }
    
    Quaternion& Quaternion::operator+=(const Quaternion& q) {
        x += q.x;
        y += q.y;
        z += q.z;
        w += q.w;
        return *this;
    }
    
    Quaternion& Quaternion::operator-=(const Quaternion& q) {
        x -= q.x;
        y -= q.y;
        z -= q.z;
        w -= q.w;
        return *this;
    }
}
