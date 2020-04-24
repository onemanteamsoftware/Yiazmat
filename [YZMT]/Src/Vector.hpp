/*[YZMT]::[YZMT]::Vector.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

#include <cmath>

namespace YZMT {
    struct vec2 {
        union {
            struct { float x; float y; };
            float v[2];
        };
        
        vec2() : x { 0.0f }, y { 0.0f } {}
        explicit vec2(float x, float y = 0.0f) : x { x }, y { y } {}
        
        float Dot(const vec2& v) const { return x * v.x + y * v.y; }
        float Magnitude() const { return std::sqrt(x * x + y * y); }
        vec2 Normalize() const { float m = Magnitude(); return vec2(x / m, y / m); }
        
        vec2 operator-() const { return vec2(-x, -y); }
        
        vec2 operator+(const vec2& v) const { return vec2(x + v.x, y + v.y); }
        vec2 operator-(const vec2& v) const { return vec2(x - v.x, y - v.y); }
        
        vec2& operator*=(float s) { x *= s; y *= s; return *this; }
        vec2& operator/=(float s) { x /= s; y /= s; return *this; }
        
        vec2& operator+=(const vec2& v) { x += v.x; y += v.y; return *this; }
        vec2& operator-=(const vec2& v) { x -= v.x; y -= v.y; return *this; }
    };
    
    inline vec2 operator*(float s, const vec2& v) { return vec2(v.x * s, v.y * s); }
    inline vec2 operator*(const vec2& v, float s) { return vec2(v.x * s, v.y * s); }
    inline vec2 operator/(float s, const vec2& v) { return vec2(v.x / s, v.y / s); }
    inline vec2 operator/(const vec2& v, float s) { return vec2(v.x / s, v.y / s); }
    
    struct vec3 {
        union {
            struct { float x; float y; float z; };
            struct { vec2 xy; float z; };
            float v[3];
        };
        
        vec3() : x { 0.0f }, y { 0.0f }, z { 0.0f } {}
        vec3(const vec2& v, float z = 0.0f) : x { v.x }, y { v.y }, z { z } {}
        vec3(float x, float y, float z = 0.0f) : x { x }, y { y }, z { z } {}
        
        vec3 Cross(const vec3& v) const { return vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
        float Dot(const vec3& v) const { return x * v.x + y * v.y + z * v.z; }
        float Magnitude() const { return std::sqrt(x * x + y * y + z * z); }
        vec3 Normalize() const { float m = Magnitude(); return vec3(x / m, y / m, z / m); }
        
        vec3 operator-() const { return vec3(-x, -y, -z); }
        
        vec3 operator+(const vec3& v) const { return vec3(x + v.x, y + v.y, z + v.z); }
        vec3 operator-(const vec3& v) const { return vec3(x - v.x, y - v.y, z - v.z); }
        
        vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
        vec3& operator/=(float s) { x /= s; y /= s; z /= s; return *this; }
        
        vec3& operator+=(const vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
        vec3& operator-=(const vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
    };
    
    inline vec3 operator*(float s, const vec3& v) { return vec3(v.x * s, v.y * s, v.z * s); }
    inline vec3 operator*(const vec3& v, float s) { return vec3(v.x * s, v.y * s, v.z * s); }
    inline vec3 operator/(float s, const vec3& v) { return vec3(v.x / s, v.y / s, v.z / s); }
    inline vec3 operator/(const vec3& v, float s) { return vec3(v.x / s, v.y / s, v.z / s); }
    
    struct vec4 {
        union {
            struct { float x; float y; float z; float w; };
            struct { vec3 xyz; float w; };
            float v[4];
        };
        
        vec4() : x { 0.0f }, y { 0.0f }, z { 0.0f }, w { 0.0f } {}
        vec4(const vec3& v, float w = 0.0f) : x { v.x }, y { v.y }, z { v.z }, w { w } {}
        vec4(float x, float y, float z, float w = 0.0f) : x { x }, y { y }, z { z }, w { w } {}
        
        float Dot(const vec4& v) const { return x * v.x + y * v.y + z * v.z + w * v.w; }
        float Magnitude() const { return std::sqrt(x * x + y * y + z * z + w * w); }
        vec4 Normalize() const { float m = Magnitude(); return vec4(x / m, y / m, z / m, w / m); }
        
        vec4 operator-() const { return vec4(-x, -y, -z, -w); }
        
        vec4 operator+(const vec4& v) const { return vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
        vec4 operator-(const vec4& v) const { return vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
        
        vec4& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
        vec4& operator/=(float s) { x /= s; y /= s; z /= s; w /= s; return *this; }
        
        vec4& operator+=(const vec4& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
        vec4& operator-=(const vec4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }
    };
    
    inline vec4 operator*(float s, const vec4& v) { return vec4(v.x * s, v.y * s, v.z * s, v.w * s); }
    inline vec4 operator*(const vec4& v, float s) { return vec4(v.x * s, v.y * s, v.z * s, v.w * s); }
    inline vec4 operator/(float s, const vec4& v) { return vec4(v.x / s, v.y / s, v.z / s, v.w / s); }
    inline vec4 operator/(const vec4& v, float s) { return vec4(v.x / s, v.y / s, v.z / s, v.w / s); }
}
