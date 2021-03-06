/*[YZMT]::[YZMT]::Matrix.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

#include <iostream>

#include "Vector.hpp"

namespace YZMT {
    struct mat3 final {
        union {
            float Elements[3 * 3];
            vec3 Columns[3];
        };
        
        mat3();
        explicit mat3(float Diagonal);
        mat3(const vec3& v0, const vec3& v1, const vec3& v2);
        
        static mat3 Identity();
        static mat3 Rotate(float Angle, const vec3& v);
        static mat3 RotateX(float Angle);
        static mat3 RotateY(float Angle);
        static mat3 RotateZ(float Angle);
        static mat3 Scale(const vec2& v);
        static mat3 Scale(float x, float y);
        static mat3 Translate(const vec2& v);
        static mat3 Translate(float x, float y);
        
        float Determinant() const;
        mat3 Inverse() const;
        mat3 Transpose() const;
        
        mat3 operator*(float s) const;
        vec3 operator*(const vec3& v) const;
        mat3 operator*(const mat3& m) const;
        mat3 operator/(float s) const;
        mat3 operator+(const mat3& m) const;
        mat3 operator-(const mat3& m) const;
        
        bool operator==(const mat3& m) const;
        bool operator!=(const mat3& m) const;
        
        mat3& operator*=(float s);
        mat3& operator*=(const mat3& m);
        mat3& operator/=(float s);
        mat3& operator+=(const mat3& m);
        mat3& operator-=(const mat3& m);
    };
    
    std::ostream& operator<<(std::ostream& Stream, const mat3& m);
    
    struct mat4 final {
        union {
            float Elements[4 * 4];
            vec4 Columns[4];
        };
        
        mat4();
        explicit mat4(float Diagonal);
        mat4(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3);
        
        static mat4 Identity();
        static mat4 Rotate(float Angle, const vec3& v);
        static mat4 RotateX(float Angle);
        static mat4 RotateY(float Angle);
        static mat4 RotateZ(float Angle);
        static mat4 Scale(const vec3& v);
        static mat4 Scale(float x, float y, float z);
        static mat4 Translate(const vec3& v);
        static mat4 Translate(float x, float y, float z);
        
        static mat4 Orthographic(float Left, float Right, float Bottom, float Top, float Near, float Far);
        static mat4 Perspective(float FOV, float Aspect, float Near, float Far);
        
        float Determinant() const;
        mat3 GetSubMatrix() const;
        mat4 Inverse() const;
        mat4 Transpose() const;
        
        mat4 operator*(float s) const;
        vec4 operator*(const vec4& v) const;
        mat4 operator*(const mat4& m) const;
        mat4 operator/(float s) const;
        mat4 operator+(const mat4& m) const;
        mat4 operator-(const mat4& m) const;
        
        bool operator==(const mat4& m) const;
        bool operator!=(const mat4& m) const;
        
        mat4& operator*=(float s);
        mat4& operator*=(const mat4& m);
        mat4& operator/=(float s);
        mat4& operator+=(const mat4& m);
        mat4& operator-=(const mat4& m);
    };
    
    std::ostream& operator<<(std::ostream& Stream, const mat4& m);
}

#include "Matrix.inl"
