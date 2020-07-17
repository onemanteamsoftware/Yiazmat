/*[YZMT]::[YZMT]::Quaternion.cpp*/
/*github.com/onemanteamsoftware*/
#include "Quaternion.hpp"

#include "Functions.hpp"

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
    
    Quaternion Quaternion::Rotate(float Angle, const vec3& v) {
        float Radians { ToRadians(Angle * 0.5f) };
        return Quaternion { v * std::sin(Radians), std::cos(Radians) };
    }
    
    Quaternion Quaternion::RotateX(float Angle) {
        float Radians { ToRadians(Angle * 0.5f) };
        return Quaternion { std::sin(Radians), 0.0f, 0.0f, std::cos(Radians) };
    }
    
    Quaternion Quaternion::RotateY(float Angle) {
        float Radians { ToRadians(Angle * 0.5f) };
        return Quaternion { 0.0f, std::sin(Radians), 0.0f, std::cos(Radians) };
    }
    
    Quaternion Quaternion::RotateZ(float Angle) {
        float Radians { ToRadians(Angle * 0.5f) };
        return Quaternion { 0.0f, 0.0f, std::sin(Radians), std::cos(Radians) };
    }
    
    Quaternion Quaternion::Conjugate() const {
        return Quaternion { -x, -y, -z, w };
    }
    
    float Quaternion::Dot(const Quaternion& q) const {
        return x * q.x + y * q.y + z * q.z + w * q.w;
    }
    
    mat3 Quaternion::Get3x3Matrix() const {
        mat3 Result {};
        Result.Elements[0 + 0 * 3] = 1.0f - 2.0f * (y * y + z * z);
        Result.Elements[1 + 0 * 3] = 2.0f * (x * y + z * w);
        Result.Elements[2 + 0 * 3] = 2.0f * (x * z - y * w);
        Result.Elements[0 + 1 * 3] = 2.0f * (x * y - z * w);
        Result.Elements[1 + 1 * 3] = 1.0f - 2.0f * (x * x + z * z);
        Result.Elements[2 + 1 * 3] = 2.0f * (y * z + x * w);
        Result.Elements[0 + 2 * 3] = 2.0f * (x * z + y * w);
        Result.Elements[1 + 2 * 3] = 2.0f * (y * z - x * w);
        Result.Elements[2 + 2 * 3] = 1.0f - 2.0f * (x * x + y * y);
        return Result;
    }
    
    mat4 Quaternion::Get4x4Matrix() const {
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = 1.0f - 2.0f * (y * y + z * z);
        Result.Elements[1 + 0 * 4] = 2.0f * (x * y + z * w);
        Result.Elements[2 + 0 * 4] = 2.0f * (x * z - y * w);
        Result.Elements[0 + 1 * 4] = 2.0f * (x * y - z * w);
        Result.Elements[1 + 1 * 4] = 1.0f - 2.0f * (x * x + z * z);
        Result.Elements[2 + 1 * 4] = 2.0f * (y * z + x * w);
        Result.Elements[0 + 2 * 4] = 2.0f * (x * z + y * w);
        Result.Elements[1 + 2 * 4] = 2.0f * (y * z - x * w);
        Result.Elements[2 + 2 * 4] = 1.0f - 2.0f * (x * x + y * y);
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    Quaternion Quaternion::Inverse() const {
        return Conjugate() / (x * x + y * y + z * z + w * w);
    }
    
    float Quaternion::Magnitude() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }
    
    Quaternion Quaternion::Normalize() const {
        float m { Magnitude() };
        return Quaternion { x / m, y / m, z / m, w / m };
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
