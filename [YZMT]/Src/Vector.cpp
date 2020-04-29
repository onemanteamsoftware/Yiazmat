/*[YZMT]::[YZMT]::Vector.cpp*/
/*github.com/onemanteamsoftware*/
#include "Vector.hpp"

namespace YZMT {
    inline vec2::vec2()
        : x { 0.0f }, y { 0.0f } {
    }
    
    inline vec2::vec2(float x, float y)
        : x { x }, y { y } {
    }
    
    inline float vec2::Dot(const vec2& v) const {
        return x * v.x + y * v.y;
    }
    
    inline float vec2::Magnitude() const {
        return std::sqrt(x * x + y * y);
    }
    
    inline vec2 vec2::Normalize() const {
        float m = Magnitude();
        return vec2(x / m, y / m);
    }
    
    inline vec2 vec2::operator-() const {
        return vec2(-x, -y);
    }
    
    inline vec2 vec2::operator*(float s) const {
        return vec2(x * s, y * s);
    }
    
    inline vec2 operator*(float s, const vec2& v) {
        return vec2(v.x * s, v.y * s);
    }
    
    inline vec2 vec2::operator/(float s) const {
        return vec2(x / s, y / s);
    }
    
    inline vec2 operator/(float s, const vec2& v) {
        return vec2(v.x / s, v.y / s);
    }
    
    inline vec2 vec2::operator+(const vec2& v) const {
        return vec2(x + v.x, y + v.y);
    }
    
    inline vec2 vec2::operator-(const vec2& v) const {
        return vec2(x - v.x, y - v.y);
    }
    
    inline bool vec2::operator==(const vec2& v) const {
        return x == v.x && y == v.y;
    }
    
    inline bool vec2::operator!=(const vec2& v) const {
        return !(*this == v);
    }
    
    inline vec2& vec2::operator*=(float s) {
        x *= s;
        y *= s;
        return *this;
    }
    
    inline vec2& vec2::operator/=(float s) {
        x /= s;
        y /= s;
        return *this;
    }
    
    inline vec2& vec2::operator+=(const vec2& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    
    inline vec2& vec2::operator-=(const vec2& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    
    inline vec3::vec3()
        : x { 0.0f }, y { 0.0f }, z { 0.0f } {
    }
    
    inline vec3::vec3(const vec2& v, float z)
        : x { v.x }, y { v.y }, z { z } {
    }
    
    inline vec3::vec3(float x, float y, float z)
        : x { x }, y { y }, z { z } {
    }
    
    inline vec3 vec3::Cross(const vec3& v) const {
        return vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
    
    inline float vec3::Dot(const vec3& v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    
    inline float vec3::Magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    
    inline vec3 vec3::Normalize() const {
        float m = Magnitude();
        return vec3(x / m, y / m, z / m);
    }
    
    inline vec3 vec3::operator-() const {
        return vec3(-x, -y, -z);
    }
    
    inline vec3 vec3::operator*(float s) const {
        return vec3(x * s, y * s, z * s);
    }
    
    inline vec3 operator*(float s, const vec3& v) {
        return vec3(v.x * s, v.y * s, v.z * s);
    }
    
    inline vec3 vec3::operator/(float s) const {
        return vec3(x / s, y / s, z / s);
    }
    
    inline vec3 operator/(float s, const vec3& v) {
        return vec3(v.x / s, v.y / s, v.z / s);
    }
    
    inline vec3 vec3::operator+(const vec3& v) const {
        return vec3(x + v.x, y + v.y, z + v.z);
    }
    
    inline vec3 vec3::operator-(const vec3& v) const {
        return vec3(x - v.x, y - v.y, z - v.z);
    }
    
    inline bool vec3::operator==(const vec3& v) const {
        return x == v.x && y == v.y && z == v.z;
    }
    
    inline bool vec3::operator!=(const vec3& v) const {
        return !(*this == v);
    }
    
    inline vec3& vec3::operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    
    inline vec3& vec3::operator/=(float s) {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }
    
    inline vec3& vec3::operator+=(const vec3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    
    inline vec3& vec3::operator-=(const vec3& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
}
