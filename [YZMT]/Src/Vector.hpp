/*[YZMT]::[YZMT]::Vector.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

namespace YZMT {
    struct vec2 final {
        float x, y;
        
        vec2();
        explicit vec2(float x, float y = 0.0f);
        
        static vec2 xAxis();
        static vec2 yAxis();
        
        float Dot(const vec2& v) const;
        float Magnitude() const;
        vec2 Normalize() const;
        
        vec2 operator-() const;
        
        vec2 operator*(float s) const;
        vec2 operator/(float s) const;
        vec2 operator+(const vec2& v) const;
        vec2 operator-(const vec2& v) const;
        
        bool operator==(const vec2& v) const;
        bool operator!=(const vec2& v) const;
        
        vec2& operator*=(float s);
        vec2& operator/=(float s);
        vec2& operator+=(const vec2& v);
        vec2& operator-=(const vec2& v);
    };
    
    struct vec3 final {
        float x, y, z;
        
        vec3();
        vec3(const vec2& v, float z = 0.0f);
        vec3(float x, float y, float z = 0.0f);
        
        static vec3 xAxis();
        static vec3 yAxis();
        static vec3 zAxis();
        
        vec3 Cross(const vec3& v) const;
        float Dot(const vec3& v) const;
        float Magnitude() const;
        vec3 Normalize() const;
        
        vec3 operator-() const;
        
        vec3 operator*(float s) const;
        vec3 operator/(float s) const;
        vec3 operator+(const vec3& v) const;
        vec3 operator-(const vec3& v) const;
        
        bool operator==(const vec3& v) const;
        bool operator!=(const vec3& v) const;
        
        vec3& operator*=(float s);
        vec3& operator/=(float s);
        vec3& operator+=(const vec3& v);
        vec3& operator-=(const vec3& v);
    };
    
    struct vec4 final {
        float x, y, z, w;
        
        vec4();
        vec4(const vec3& v, float w = 0.0f);
        vec4(float x, float y, float z, float w = 0.0f);
        
        static vec4 xAxis();
        static vec4 yAxis();
        static vec4 zAxis();
        
        float Dot(const vec4& v) const;
        float Magnitude() const;
        vec4 Normalize() const;
        
        vec4 operator-() const;
        
        vec4 operator*(float s) const;
        vec4 operator/(float s) const;
        vec4 operator+(const vec4& v) const;
        vec4 operator-(const vec4& v) const;
        
        bool operator==(const vec4& v) const;
        bool operator!=(const vec4& v) const;
        
        vec4& operator*=(float s);
        vec4& operator/=(float s);
        vec4& operator+=(const vec4& v);
        vec4& operator-=(const vec4& v);
    };
}
