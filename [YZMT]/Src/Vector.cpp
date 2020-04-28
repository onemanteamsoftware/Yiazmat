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
}
