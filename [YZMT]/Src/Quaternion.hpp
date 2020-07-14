/*[YZMT]::[YZMT]::Quaternion.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

#include "Matrix.hpp"

namespace YZMT {
    struct Quaternion final {
        float x, y, z, w;
        
        Quaternion();
        Quaternion(const vec4& v);
        Quaternion(const vec3& v, float w = 1.0f);
        Quaternion(float x, float y, float z, float w = 1.0f);
        
        static Quaternion Identity();
        
        Quaternion Conjugate() const;
        float Dot(const Quaternion& q) const;
        mat3 Get3x3Matrix() const;
        Quaternion Inverse() const;
        float Magnitude() const;
        Quaternion Normalize() const;
        
        Quaternion operator-() const;
        
        Quaternion operator*(float s) const;
        Quaternion operator*(const Quaternion& q) const;
        Quaternion operator/(float s) const;
        Quaternion operator+(const Quaternion& q) const;
        Quaternion operator-(const Quaternion& q) const;
        
        bool operator==(const Quaternion& q) const;
        bool operator!=(const Quaternion& q) const;
        
        Quaternion& operator*=(float s);
        Quaternion& operator*=(const Quaternion& q);
        Quaternion& operator/=(float s);
        Quaternion& operator+=(const Quaternion& q);
        Quaternion& operator-=(const Quaternion& q);
    };
}
