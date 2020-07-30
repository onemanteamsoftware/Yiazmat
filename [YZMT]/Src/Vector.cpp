/*[YZMT]::[YZMT]::Vector.cpp*/
/*github.com/onemanteamsoftware*/
#include "Vector.hpp"

#include <cmath>
#include <string>

namespace YZMT {
    vec2::vec2()
        : x { 0.0f }, y { 0.0f } {
    }
    
    vec2::vec2(float x, float y)
        : x { x }, y { y } {
    }
    
    vec2 vec2::xAxis() {
        return vec2 { 1.0f, 0.0f };
    }
    
    vec2 vec2::yAxis() {
        return vec2 { 0.0f, 1.0f };
    }
    
    float vec2::Dot(const vec2& v) const {
        return x * v.x + y * v.y;
    }
    
    float vec2::Magnitude() const {
        return std::sqrt(x * x + y * y);
    }
    
    float vec2::MagnitudeSquared() const {
        return x * x + y * y;
    }
    
    vec2 vec2::Normalize() const {
        float m { Magnitude() };
        return vec2 { x / m, y / m };
    }
    
    vec2 vec2::operator-() const {
        return vec2 { -x, -y };
    }
    
    vec2 vec2::operator*(float s) const {
        return vec2 { x * s, y * s };
    }
    
    vec2 operator*(float s, const vec2& v) {
        return vec2 { v.x * s, v.y * s };
    }
    
    vec2 vec2::operator/(float s) const {
        return vec2 { x / s, y / s };
    }
    
    vec2 operator/(float s, const vec2& v) {
        return vec2 { v.x / s, v.y / s };
    }
    
    vec2 vec2::operator+(const vec2& v) const {
        return vec2 { x + v.x, y + v.y };
    }
    
    vec2 vec2::operator-(const vec2& v) const {
        return vec2 { x - v.x, y - v.y };
    }
    
    bool vec2::operator==(const vec2& v) const {
        return x == v.x && y == v.y;
    }
    
    bool vec2::operator!=(const vec2& v) const {
        return !(*this == v);
    }
    
    vec2& vec2::operator*=(float s) {
        x *= s;
        y *= s;
        return *this;
    }
    
    vec2& vec2::operator/=(float s) {
        x /= s;
        y /= s;
        return *this;
    }
    
    vec2& vec2::operator+=(const vec2& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    
    vec2& vec2::operator-=(const vec2& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    
    std::ostream& operator<<(std::ostream& Stream, const vec2& v) {
        Stream << '('
        << std::to_string(v.x).substr(0, 8) << ", "
        << std::to_string(v.y).substr(0, 8) << ')';
        return Stream;
    }
    
    vec3::vec3()
        : x { 0.0f }, y { 0.0f }, z { 0.0f } {
    }
    
    vec3::vec3(const vec2& v, float z)
        : x { v.x }, y { v.y }, z { z } {
    }
    
    vec3::vec3(float x, float y, float z)
        : x { x }, y { y }, z { z } {
    }
    
    vec3 vec3::xAxis() {
        return vec3 { 1.0f, 0.0f, 0.0f };
    }
    
    vec3 vec3::yAxis() {
        return vec3 { 0.0f, 1.0f, 0.0f };
    }
    
    vec3 vec3::zAxis() {
        return vec3 { 0.0f, 0.0f, 1.0f };
    }
    
    vec3 vec3::Cross(const vec3& v) const {
        return vec3 { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };
    }
    
    float vec3::Dot(const vec3& v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    
    float vec3::Magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    
    float vec3::MagnitudeSquared() const {
        return x * x + y * y + z * z;
    }
    
    vec3 vec3::Normalize() const {
        float m { Magnitude() };
        return vec3 { x / m, y / m, z / m };
    }
    
    vec3 vec3::operator-() const {
        return vec3 { -x, -y, -z };
    }
    
    vec3 vec3::operator*(float s) const {
        return vec3 { x * s, y * s, z * s };
    }
    
    vec3 operator*(float s, const vec3& v) {
        return vec3 { v.x * s, v.y * s, v.z * s };
    }
    
    vec3 vec3::operator/(float s) const {
        return vec3 { x / s, y / s, z / s };
    }
    
    vec3 operator/(float s, const vec3& v) {
        return vec3 { v.x / s, v.y / s, v.z / s };
    }
    
    vec3 vec3::operator+(const vec3& v) const {
        return vec3 { x + v.x, y + v.y, z + v.z };
    }
    
    vec3 vec3::operator-(const vec3& v) const {
        return vec3 { x - v.x, y - v.y, z - v.z };
    }
    
    bool vec3::operator==(const vec3& v) const {
        return x == v.x && y == v.y && z == v.z;
    }
    
    bool vec3::operator!=(const vec3& v) const {
        return !(*this == v);
    }
    
    vec3& vec3::operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    
    vec3& vec3::operator/=(float s) {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }
    
    vec3& vec3::operator+=(const vec3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    
    vec3& vec3::operator-=(const vec3& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    
    std::ostream& operator<<(std::ostream& Stream, const vec3& v) {
        Stream << '('
        << std::to_string(v.x).substr(0, 8) << ", "
        << std::to_string(v.y).substr(0, 8) << ", "
        << std::to_string(v.z).substr(0, 8) << ')';
        return Stream;
    }
    
    vec4::vec4()
        : x { 0.0f }, y { 0.0f }, z { 0.0f }, w { 0.0f } {
    }
    
    vec4::vec4(const vec3& v, float w)
        : x { v.x }, y { v.y }, z { v.z }, w { w } {
    }
    
    vec4::vec4(float x, float y, float z, float w)
        : x { x }, y { y }, z { z }, w { w } {
    }
    
    vec4 vec4::xAxis() {
        return vec4 { 1.0f, 0.0f, 0.0f, 0.0f };
    }
    
    vec4 vec4::yAxis() {
        return vec4 { 0.0f, 1.0f, 0.0f, 0.0f };
    }
    
    vec4 vec4::zAxis() {
        return vec4 { 0.0f, 0.0f, 1.0f, 0.0f };
    }
    
    float vec4::Dot(const vec4& v) const {
        return x * v.x + y * v.y + z * v.z + w * v.w;
    }
    
    float vec4::Magnitude() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }
    
    float vec4::MagnitudeSquared() const {
        return x * x + y * y + z * z + w * w;
    }
    
    vec4 vec4::Normalize() const {
        float m { Magnitude() };
        return vec4 { x / m, y / m, z / m, w / m };
    }
    
    vec4 vec4::operator-() const {
        return vec4 { -x, -y, -z, -w };
    }
    
    vec4 vec4::operator*(float s) const {
        return vec4 { x * s, y * s, z * s, w * s };
    }
    
    vec4 operator*(float s, const vec4& v) {
        return vec4 { v.x * s, v.y * s, v.z * s, v.w * s };
    }
    
    vec4 vec4::operator/(float s) const {
        return vec4 { x / s, y / s, z / s, w / s };
    }
    
    vec4 operator/(float s, const vec4& v) {
        return vec4 { v.x / s, v.y / s, v.z / s, v.w / s };
    }
    
    vec4 vec4::operator+(const vec4& v) const {
        return vec4 { x + v.x, y + v.y, z + v.z, w + v.w };
    }
    
    vec4 vec4::operator-(const vec4& v) const {
        return vec4 { x - v.x, y - v.y, z - v.z, w - v.w };
    }
    
    bool vec4::operator==(const vec4& v) const {
        return x == v.x && y == v.y && z == v.z && w == v.w;
    }
    
    bool vec4::operator!=(const vec4& v) const {
        return !(*this == v);
    }
    
    vec4& vec4::operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    
    vec4& vec4::operator/=(float s) {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
        return *this;
    }
    
    vec4& vec4::operator+=(const vec4& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }
    
    vec4& vec4::operator-=(const vec4& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }
    
    std::ostream& operator<<(std::ostream& Stream, const vec4& v) {
        Stream << '('
        << std::to_string(v.x).substr(0, 8) << ", "
        << std::to_string(v.y).substr(0, 8) << ", "
        << std::to_string(v.z).substr(0, 8) << ", "
        << std::to_string(v.w).substr(0, 8) << ')';
        return Stream;
    }
}
