/*[YZMT]::[YZMT]::Quaternion.inl*/
/*github.com/onemanteamsoftware*/
#include <cmath>
#include <string>

#include "Functions.hpp"

namespace YZMT {
    inline Quaternion::Quaternion()
        : x { 0.0f }, y { 0.0f }, z { 0.0f }, w { 0.0f } {
    }
    
    inline Quaternion::Quaternion(const vec4& v)
        : x { v.x }, y { v.y }, z { v.z }, w { v.w } {
    }
    
    inline Quaternion::Quaternion(const vec3& v, float w)
        : x { v.x }, y { v.y }, z { v.z }, w { w } {
    }
    
    inline Quaternion::Quaternion(float x, float y, float z, float w)
        : x { x }, y { y }, z { z }, w { w } {
    }
    
    inline Quaternion Quaternion::Identity() {
        return Quaternion { 0.0f, 0.0f, 0.0f, 1.0f };
    }
    
    inline Quaternion Quaternion::Rotate(float Angle, const vec3& v) {
        float Radians { ToRadians(Angle * 0.5f) };
        return Quaternion { v * std::sin(Radians), std::cos(Radians) };
    }
    
    inline Quaternion Quaternion::RotateX(float Angle) {
        float Radians { ToRadians(Angle * 0.5f) };
        return Quaternion { std::sin(Radians), 0.0f, 0.0f, std::cos(Radians) };
    }
    
    inline Quaternion Quaternion::RotateY(float Angle) {
        float Radians { ToRadians(Angle * 0.5f) };
        return Quaternion { 0.0f, std::sin(Radians), 0.0f, std::cos(Radians) };
    }
    
    inline Quaternion Quaternion::RotateZ(float Angle) {
        float Radians { ToRadians(Angle * 0.5f) };
        return Quaternion { 0.0f, 0.0f, std::sin(Radians), std::cos(Radians) };
    }
    
    inline Quaternion Quaternion::Conjugate() const {
        return Quaternion { -x, -y, -z, w };
    }
    
    inline float Quaternion::Dot(const Quaternion& q) const {
        return x * q.x + y * q.y + z * q.z + w * q.w;
    }
    
    inline mat3 Quaternion::Get3x3Matrix() const {
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
    
    inline mat4 Quaternion::Get4x4Matrix() const {
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
    
    inline Quaternion Quaternion::Inverse() const {
        return Conjugate() / (x * x + y * y + z * z + w * w);
    }
    
    inline float Quaternion::Magnitude() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }
    
    inline Quaternion Quaternion::Normalize() const {
        float m { Magnitude() };
        return Quaternion { x / m, y / m, z / m, w / m };
    }
    
    inline vec3 Quaternion::Transform(const vec3& v) const {
        const vec3& qv { reinterpret_cast<const vec3&>(x) };
        return v * (w * w - qv.MagnitudeSquared()) + qv * (v.Dot(qv) * 2.0f) + qv.Cross(v) * (w * 2.0f);
    }
    
    inline Quaternion Quaternion::operator-() const {
        return Quaternion { -x, -y, -z, -w };
    }
    
    inline Quaternion Quaternion::operator*(float s) const {
        return Quaternion { x * s, y * s, z * s, w * s };
    }
    
    inline Quaternion operator*(float s, const Quaternion& q) {
        return Quaternion { q.x * s, q.y * s, q.z * s, q.w * s };
    }
    
    inline Quaternion Quaternion::operator*(const Quaternion& q) const {
        return Quaternion {
            w * q.x + x * q.w + y * q.z - z * q.y,
            w * q.y - x * q.z + y * q.w + z * q.x,
            w * q.z + x * q.y - y * q.x + z * q.w,
            w * q.w - x * q.x - y * q.y - z * q.z
        };
    }
    
    inline Quaternion Quaternion::operator/(float s) const {
        return Quaternion { x / s, y / s, z / s, w / s };
    }
    
    inline Quaternion operator/(float s, const Quaternion& q) {
        return Quaternion { q.x / s, q.y / s, q.z / s, q.w / s };
    }
    
    inline Quaternion Quaternion::operator+(const Quaternion& q) const {
        return Quaternion { x + q.x, y + q.y, z + q.z, w + q.w };
    }
    
    inline Quaternion Quaternion::operator-(const Quaternion& q) const {
        return Quaternion { x - q.x, y - q.y, z - q.z, w - q.w };
    }
    
    inline bool Quaternion::operator==(const Quaternion& q) const {
        return x == q.x && y == q.y && z == q.z && w == q.w;
    }
    
    inline bool Quaternion::operator!=(const Quaternion& q) const {
        return !(*this == q);
    }
    
    inline Quaternion& Quaternion::operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    
    inline Quaternion& Quaternion::operator*=(const Quaternion& q) {
        *this = *this * q;
        return *this;
    }
    
    inline Quaternion& Quaternion::operator/=(float s) {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
        return *this;
    }
    
    inline Quaternion& Quaternion::operator+=(const Quaternion& q) {
        x += q.x;
        y += q.y;
        z += q.z;
        w += q.w;
        return *this;
    }
    
    inline Quaternion& Quaternion::operator-=(const Quaternion& q) {
        x -= q.x;
        y -= q.y;
        z -= q.z;
        w -= q.w;
        return *this;
    }
    
    inline std::ostream& operator<<(std::ostream& Stream, const Quaternion& q) {
        Stream << '('
        << std::to_string(q.w).substr(0, 8) << ", ("
        << std::to_string(q.x).substr(0, 8) << ", "
        << std::to_string(q.y).substr(0, 8) << ", "
        << std::to_string(q.z).substr(0, 8) << "))";
        return Stream;
    }
}
