/*[YZMT]::[YZMT]::Matrix.inl*/
/*github.com/onemanteamsoftware*/
#include <cmath>
#include <string>

#include "Functions.hpp"

namespace YZMT {
    inline mat3::mat3()
        : Elements { 0.0f } {
    }
    
    inline mat3::mat3(float Diagonal)
        : Elements { 0.0f } {
        Elements[0 + 0 * 3] = Diagonal;
        Elements[1 + 1 * 3] = Diagonal;
        Elements[2 + 2 * 3] = Diagonal;
    }
    
    inline mat3::mat3(const vec3& v0, const vec3& v1, const vec3& v2)
        : Columns { v0, v1, v2 } {
    }
    
    inline mat3 mat3::Identity() {
        return mat3 { 1.0f };
    }
    
    inline mat3 mat3::Rotate(float Angle, const vec3& v) {
        float Radians { ToRadians(Angle) };
        float c { std::cos(Radians) };
        float s { std::sin(Radians) };
        float omc { 1.0f - c };
        mat3 Result {};
        Result.Elements[0 + 0 * 3] = (v.x * v.x * omc) + c;
        Result.Elements[1 + 0 * 3] = (v.x * v.y * omc) + (s * v.z);
        Result.Elements[2 + 0 * 3] = (v.x * v.z * omc) - (s * v.y);
        Result.Elements[0 + 1 * 3] = (v.y * v.x * omc) - (s * v.z);
        Result.Elements[1 + 1 * 3] = (v.y * v.y * omc) + c;
        Result.Elements[2 + 1 * 3] = (v.y * v.z * omc) + (s * v.x);
        Result.Elements[0 + 2 * 3] = (v.z * v.x * omc) + (s * v.y);
        Result.Elements[1 + 2 * 3] = (v.z * v.y * omc) - (s * v.x);
        Result.Elements[2 + 2 * 3] = (v.z * v.z * omc) + c;
        return Result;
    }
    
    inline mat3 mat3::RotateX(float Angle) {
        float Radians { ToRadians(Angle) };
        float c { std::cos(Radians) };
        float s { std::sin(Radians) };
        mat3 Result {};
        Result.Elements[0 + 0 * 3] = 1.0f;
        Result.Elements[1 + 1 * 3] = c;
        Result.Elements[2 + 1 * 3] = -s;
        Result.Elements[1 + 2 * 3] = s;
        Result.Elements[2 + 2 * 3] = c;
        return Result;
    }
    
    inline mat3 mat3::RotateY(float Angle) {
        float Radians { ToRadians(Angle) };
        float c { std::cos(Radians) };
        float s { std::sin(Radians) };
        mat3 Result {};
        Result.Elements[0 + 0 * 3] = c;
        Result.Elements[2 + 0 * 3] = s;
        Result.Elements[1 + 1 * 3] = 1.0f;
        Result.Elements[0 + 2 * 3] = -s;
        Result.Elements[2 + 2 * 3] = c;
        return Result;
    }
    
    inline mat3 mat3::RotateZ(float Angle) {
        float Radians { ToRadians(Angle) };
        float c { std::cos(Radians) };
        float s { std::sin(Radians) };
        mat3 Result {};
        Result.Elements[0 + 0 * 3] = c;
        Result.Elements[1 + 0 * 3] = s;
        Result.Elements[0 + 1 * 3] = -s;
        Result.Elements[1 + 1 * 3] = c;
        Result.Elements[2 + 2 * 3] = 1.0f;
        return Result;
    }
    
    inline mat3 mat3::Scale(const vec2& v) {
        mat3 Result {};
        Result.Elements[0 + 0 * 3] = v.x;
        Result.Elements[1 + 1 * 3] = v.y;
        Result.Elements[2 + 2 * 3] = 1.0f;
        return Result;
    }
    
    inline mat3 mat3::Scale(float x, float y) {
        mat3 Result {};
        Result.Elements[0 + 0 * 3] = x;
        Result.Elements[1 + 1 * 3] = y;
        Result.Elements[2 + 2 * 3] = 1.0f;
        return Result;
    }
    
    inline mat3 mat3::Translate(const vec2& v) {
        mat3 Result { 1.0f };
        Result.Elements[0 + 2 * 3] = v.x;
        Result.Elements[1 + 2 * 3] = v.y;
        return Result;
    }
    
    inline mat3 mat3::Translate(float x, float y) {
        mat3 Result { 1.0f };
        Result.Elements[0 + 2 * 3] = x;
        Result.Elements[1 + 2 * 3] = y;
        return Result;
    }
    
    inline float mat3::Determinant() const {
        return {
            Elements[0] * (Elements[4] * Elements[8] - Elements[7] * Elements[5]) -
            Elements[3] * (Elements[1] * Elements[8] - Elements[7] * Elements[2]) +
            Elements[6] * (Elements[1] * Elements[5] - Elements[4] * Elements[2])
        };
    }
    
    inline mat3 mat3::Inverse() const {
        vec3 r0 { Columns[1].Cross(Columns[2]) };
        vec3 r1 { Columns[2].Cross(Columns[0]) };
        vec3 r2 { Columns[0].Cross(Columns[1]) };
        float InvDet { 1.0f / r2.Dot(Columns[2]) };
        vec3 c0 { r0.x, r1.x, r2.x };
        vec3 c1 { r0.y, r1.y, r2.y };
        vec3 c2 { r0.z, r1.z, r2.z };
        return mat3 { c0 * InvDet, c1 * InvDet, c2 * InvDet };
    }
    
    inline mat3 mat3::Transpose() const {
        return mat3 {
            vec3 { Elements[0], Elements[3], Elements[6] },
            vec3 { Elements[1], Elements[4], Elements[7] },
            vec3 { Elements[2], Elements[5], Elements[8] }
        };
    }
    
    inline mat3 mat3::operator*(float s) const {
        return mat3 { Columns[0] * s, Columns[1] * s, Columns[2] * s };
    }
    
    inline mat3 operator*(float s, const mat3& m) {
        return mat3 { m.Columns[0] * s, m.Columns[1] * s, m.Columns[2] * s };
    }
    
    inline vec3 mat3::operator*(const vec3& v) const {
        return vec3 {
            Elements[0] * v.x + Elements[3] * v.y + Elements[6] * v.z,
            Elements[1] * v.x + Elements[4] * v.y + Elements[7] * v.z,
            Elements[2] * v.x + Elements[5] * v.y + Elements[8] * v.z
        };
    }
    
    inline mat3 mat3::operator*(const mat3& m) const {
        return mat3 {
            vec3 {
                Elements[0] * m.Elements[0] + Elements[3] * m.Elements[1] + Elements[6] * m.Elements[2],
                Elements[1] * m.Elements[0] + Elements[4] * m.Elements[1] + Elements[7] * m.Elements[2],
                Elements[2] * m.Elements[0] + Elements[5] * m.Elements[1] + Elements[8] * m.Elements[2]
            },
            vec3 {
                Elements[0] * m.Elements[3] + Elements[3] * m.Elements[4] + Elements[6] * m.Elements[5],
                Elements[1] * m.Elements[3] + Elements[4] * m.Elements[4] + Elements[7] * m.Elements[5],
                Elements[2] * m.Elements[3] + Elements[5] * m.Elements[4] + Elements[8] * m.Elements[5]
            },
            vec3 {
                Elements[0] * m.Elements[6] + Elements[3] * m.Elements[7] + Elements[6] * m.Elements[8],
                Elements[1] * m.Elements[6] + Elements[4] * m.Elements[7] + Elements[7] * m.Elements[8],
                Elements[2] * m.Elements[6] + Elements[5] * m.Elements[7] + Elements[8] * m.Elements[8]
            }
        };
    }
    
    inline mat3 mat3::operator/(float s) const {
        return mat3 { Columns[0] / s, Columns[1] / s, Columns[2] / s };
    }
    
    inline mat3 mat3::operator+(const mat3& m) const {
        return mat3 { Columns[0] + m.Columns[0], Columns[1] + m.Columns[1], Columns[2] + m.Columns[2] };
    }
    
    inline mat3 mat3::operator-(const mat3& m) const {
        return mat3 { Columns[0] - m.Columns[0], Columns[1] - m.Columns[1], Columns[2] - m.Columns[2] };
    }
    
    inline bool mat3::operator==(const mat3& m) const {
        return Columns[0] == m.Columns[0] && Columns[1] == m.Columns[1] && Columns[2] == m.Columns[2];
    }
    
    inline bool mat3::operator!=(const mat3& m) const {
        return !(*this == m);
    }
    
    inline mat3& mat3::operator*=(float s) {
        Columns[0] *= s;
        Columns[1] *= s;
        Columns[2] *= s;
        return *this;
    }
    
    inline mat3& mat3::operator*=(const mat3& m) {
        *this = *this * m;
        return *this;
    }
    
    inline mat3& mat3::operator/=(float s) {
        Columns[0] /= s;
        Columns[1] /= s;
        Columns[2] /= s;
        return *this;
    }
    
    inline mat3& mat3::operator+=(const mat3& m) {
        Columns[0] += m.Columns[0];
        Columns[1] += m.Columns[1];
        Columns[2] += m.Columns[2];
        return *this;
    }
    
    inline mat3& mat3::operator-=(const mat3& m) {
        Columns[0] -= m.Columns[0];
        Columns[1] -= m.Columns[1];
        Columns[2] -= m.Columns[2];
        return *this;
    }
    
    inline std::ostream& operator<<(std::ostream& Stream, const mat3& m) {
        Stream << '['
        << std::to_string(m.Elements[0]).substr(0, 8) << ", "
        << std::to_string(m.Elements[3]).substr(0, 8) << ", "
        << std::to_string(m.Elements[6]).substr(0, 8) << "]\n["
        << std::to_string(m.Elements[1]).substr(0, 8) << ", "
        << std::to_string(m.Elements[4]).substr(0, 8) << ", "
        << std::to_string(m.Elements[7]).substr(0, 8) << "]\n["
        << std::to_string(m.Elements[2]).substr(0, 8) << ", "
        << std::to_string(m.Elements[5]).substr(0, 8) << ", "
        << std::to_string(m.Elements[8]).substr(0, 8) << ']';
        return Stream;
    }
    
    inline mat4::mat4()
        : Elements { 0.0f } {
    }
    
    inline mat4::mat4(float Diagonal)
        : Elements { 0.0f } {
        Elements[0 + 0 * 4] = Diagonal;
        Elements[1 + 1 * 4] = Diagonal;
        Elements[2 + 2 * 4] = Diagonal;
        Elements[3 + 3 * 4] = Diagonal;
    }
    
    inline mat4::mat4(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3)
        : Columns { v0, v1, v2, v3 } {
    }
    
    inline mat4 mat4::Identity() {
        return mat4 { 1.0f };
    }
    
    inline mat4 mat4::Rotate(float Angle, const vec3& v) {
        float Radians { ToRadians(Angle) };
        float c { std::cos(Radians) };
        float s { std::sin(Radians) };
        float omc { 1.0f - c };
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = (v.x * v.x * omc) + c;
        Result.Elements[1 + 0 * 4] = (v.x * v.y * omc) + (s * v.z);
        Result.Elements[2 + 0 * 4] = (v.x * v.z * omc) - (s * v.y);
        Result.Elements[0 + 1 * 4] = (v.y * v.x * omc) - (s * v.z);
        Result.Elements[1 + 1 * 4] = (v.y * v.y * omc) + c;
        Result.Elements[2 + 1 * 4] = (v.y * v.z * omc) + (s * v.x);
        Result.Elements[0 + 2 * 4] = (v.z * v.x * omc) + (s * v.y);
        Result.Elements[1 + 2 * 4] = (v.z * v.y * omc) - (s * v.x);
        Result.Elements[2 + 2 * 4] = (v.z * v.z * omc) + c;
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    inline mat4 mat4::RotateX(float Angle) {
        float Radians { ToRadians(Angle) };
        float c { std::cos(Radians) };
        float s { std::sin(Radians) };
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = 1.0f;
        Result.Elements[1 + 1 * 4] = c;
        Result.Elements[2 + 1 * 4] = -s;
        Result.Elements[1 + 2 * 4] = s;
        Result.Elements[2 + 2 * 4] = c;
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    inline mat4 mat4::RotateY(float Angle) {
        float Radians { ToRadians(Angle) };
        float c { std::cos(Radians) };
        float s { std::sin(Radians) };
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = c;
        Result.Elements[2 + 0 * 4] = s;
        Result.Elements[1 + 1 * 4] = 1.0f;
        Result.Elements[0 + 2 * 4] = -s;
        Result.Elements[2 + 2 * 4] = c;
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    inline mat4 mat4::RotateZ(float Angle) {
        float Radians { ToRadians(Angle) };
        float c { std::cos(Radians) };
        float s { std::sin(Radians) };
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = c;
        Result.Elements[1 + 0 * 4] = s;
        Result.Elements[0 + 1 * 4] = -s;
        Result.Elements[1 + 1 * 4] = c;
        Result.Elements[2 + 2 * 4] = 1.0f;
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    inline mat4 mat4::Scale(const vec3& v) {
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = v.x;
        Result.Elements[1 + 1 * 4] = v.y;
        Result.Elements[2 + 2 * 4] = v.z;
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    inline mat4 mat4::Scale(float x, float y, float z) {
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = x;
        Result.Elements[1 + 1 * 4] = y;
        Result.Elements[2 + 2 * 4] = z;
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    inline mat4 mat4::Translate(const vec3& v) {
        mat4 Result { 1.0f };
        Result.Elements[0 + 3 * 4] = v.x;
        Result.Elements[1 + 3 * 4] = v.y;
        Result.Elements[2 + 3 * 4] = v.z;
        return Result;
    }
    
    inline mat4 mat4::Translate(float x, float y, float z) {
        mat4 Result { 1.0f };
        Result.Elements[0 + 3 * 4] = x;
        Result.Elements[1 + 3 * 4] = y;
        Result.Elements[2 + 3 * 4] = z;
        return Result;
    }
    
    inline mat4 mat4::Orthographic(float Left, float Right, float Bottom, float Top, float Near, float Far) {
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = 2.0f / (Right - Left);
        Result.Elements[1 + 1 * 4] = 2.0f / (Top - Bottom);
        Result.Elements[2 + 2 * 4] = 2.0f / (Near - Far);
        Result.Elements[0 + 3 * 4] = (Left + Right) / (Left - Right);
        Result.Elements[1 + 3 * 4] = (Bottom + Top) / (Bottom - Top);
        Result.Elements[2 + 3 * 4] = (Far + Near) / (Far - Near);
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    inline mat4 mat4::Perspective(float FOV, float Aspect, float Near, float Far) {
        float q { 1.0f / std::tan(ToRadians(FOV * 0.5f)) };
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = q / Aspect;
        Result.Elements[1 + 1 * 4] = q;
        Result.Elements[2 + 2 * 4] = (Near + Far) / (Near - Far);
        Result.Elements[3 + 2 * 4] = -1.0f;
        Result.Elements[2 + 3 * 4] = (2.0f * Near * Far) / (Near - Far);
        return Result;
    }
    
    inline float mat4::Determinant() const {
        vec3 v0 { Elements[ 1], Elements[ 2], Elements[ 3] };
        vec3 v1 { Elements[ 5], Elements[ 6], Elements[ 7] };
        vec3 v2 { Elements[ 9], Elements[10], Elements[11] };
        vec3 v3 { Elements[13], Elements[14], Elements[15] };
        mat3 m0 { v1, v2, v3 };
        mat3 m1 { v0, v2, v3 };
        mat3 m2 { v0, v1, v3 };
        mat3 m3 { v0, v1, v2 };
        float a { Elements[ 0] * m0.Determinant() };
        float b { Elements[ 4] * m1.Determinant() };
        float c { Elements[ 8] * m2.Determinant() };
        float d { Elements[12] * m3.Determinant() };
        return { a - b + c - d };
    }
    
    inline mat3 mat4::GetSubMatrix() const {
        return mat3 {
            vec3 { Columns[0].x, Columns[0].y, Columns[0].z },
            vec3 { Columns[1].x, Columns[1].y, Columns[1].z },
            vec3 { Columns[2].x, Columns[2].y, Columns[2].z }
        };
    }
    
    inline mat4 mat4::Inverse() const {
        const vec3& a { reinterpret_cast<const vec3&>(Columns[0]) };
        const vec3& b { reinterpret_cast<const vec3&>(Columns[1]) };
        const vec3& c { reinterpret_cast<const vec3&>(Columns[2]) };
        const vec3& d { reinterpret_cast<const vec3&>(Columns[3]) };
        const float& x { Elements[ 3] };
        const float& y { Elements[ 7] };
        const float& z { Elements[11] };
        const float& w { Elements[15] };
        vec3 s { a.Cross(b) };
        vec3 t { c.Cross(d) };
        vec3 u { a * y - b * x };
        vec3 v { c * w - d * z };
        float InvDet { 1.0f / (s.Dot(v) + t.Dot(u)) };
        s *= InvDet;
        t *= InvDet;
        u *= InvDet;
        v *= InvDet;
        vec3 r0 { b.Cross(v) + t * y };
        vec3 r1 { v.Cross(a) - t * x };
        vec3 r2 { d.Cross(u) + s * w };
        vec3 r3 { u.Cross(c) - s * z };
        return mat4 {
            vec4 { r0.x, r1.x, r2.x, r3.x },
            vec4 { r0.y, r1.y, r2.y, r3.y },
            vec4 { r0.z, r1.z, r2.z, r3.z },
            vec4 { -b.Dot(t), a.Dot(t), -d.Dot(s), c.Dot(s) }
        };
    }
    
    inline mat4 mat4::Transpose() const {
        return mat4 {
            vec4 { Elements[0], Elements[4], Elements[ 8], Elements[12] },
            vec4 { Elements[1], Elements[5], Elements[ 9], Elements[13] },
            vec4 { Elements[2], Elements[6], Elements[10], Elements[14] },
            vec4 { Elements[3], Elements[7], Elements[11], Elements[15] }
        };
    }
    
    inline mat4 mat4::operator*(float s) const {
        return mat4 { Columns[0] * s, Columns[1] * s, Columns[2] * s, Columns[3] * s };
    }
    
    inline mat4 operator*(float s, const mat4& m) {
        return mat4 { m.Columns[0] * s, m.Columns[1] * s, m.Columns[2] * s, m.Columns[3] * s };
    }
    
    inline vec4 mat4::operator*(const vec4& v) const {
        return vec4 {
            Elements[0] * v.x + Elements[4] * v.y + Elements[ 8] * v.z + Elements[12] * v.w,
            Elements[1] * v.x + Elements[5] * v.y + Elements[ 9] * v.z + Elements[13] * v.w,
            Elements[2] * v.x + Elements[6] * v.y + Elements[10] * v.z + Elements[14] * v.w,
            Elements[3] * v.x + Elements[7] * v.y + Elements[11] * v.z + Elements[15] * v.w
        };
    }
    
    inline mat4 mat4::operator*(const mat4& m) const {
        return mat4 {
            vec4 {
                Elements[0] * m.Elements[ 0] + Elements[4] * m.Elements[ 1] + Elements[ 8] * m.Elements[ 2] + Elements[12] * m.Elements[ 3],
                Elements[1] * m.Elements[ 0] + Elements[5] * m.Elements[ 1] + Elements[ 9] * m.Elements[ 2] + Elements[13] * m.Elements[ 3],
                Elements[2] * m.Elements[ 0] + Elements[6] * m.Elements[ 1] + Elements[10] * m.Elements[ 2] + Elements[14] * m.Elements[ 3],
                Elements[3] * m.Elements[ 0] + Elements[7] * m.Elements[ 1] + Elements[11] * m.Elements[ 2] + Elements[15] * m.Elements[ 3]
            },
            vec4 {
                Elements[0] * m.Elements[ 4] + Elements[4] * m.Elements[ 5] + Elements[ 8] * m.Elements[ 6] + Elements[12] * m.Elements[ 7],
                Elements[1] * m.Elements[ 4] + Elements[5] * m.Elements[ 5] + Elements[ 9] * m.Elements[ 6] + Elements[13] * m.Elements[ 7],
                Elements[2] * m.Elements[ 4] + Elements[6] * m.Elements[ 5] + Elements[10] * m.Elements[ 6] + Elements[14] * m.Elements[ 7],
                Elements[3] * m.Elements[ 4] + Elements[7] * m.Elements[ 5] + Elements[11] * m.Elements[ 6] + Elements[15] * m.Elements[ 7]
            },
            vec4 {
                Elements[0] * m.Elements[ 8] + Elements[4] * m.Elements[ 9] + Elements[ 8] * m.Elements[10] + Elements[12] * m.Elements[11],
                Elements[1] * m.Elements[ 8] + Elements[5] * m.Elements[ 9] + Elements[ 9] * m.Elements[10] + Elements[13] * m.Elements[11],
                Elements[2] * m.Elements[ 8] + Elements[6] * m.Elements[ 9] + Elements[10] * m.Elements[10] + Elements[14] * m.Elements[11],
                Elements[3] * m.Elements[ 8] + Elements[7] * m.Elements[ 9] + Elements[11] * m.Elements[10] + Elements[15] * m.Elements[11]
            },
            vec4 {
                Elements[0] * m.Elements[12] + Elements[4] * m.Elements[13] + Elements[ 8] * m.Elements[14] + Elements[12] * m.Elements[15],
                Elements[1] * m.Elements[12] + Elements[5] * m.Elements[13] + Elements[ 9] * m.Elements[14] + Elements[13] * m.Elements[15],
                Elements[2] * m.Elements[12] + Elements[6] * m.Elements[13] + Elements[10] * m.Elements[14] + Elements[14] * m.Elements[15],
                Elements[3] * m.Elements[12] + Elements[7] * m.Elements[13] + Elements[11] * m.Elements[14] + Elements[15] * m.Elements[15]
            }
        };
    }
    
    inline mat4 mat4::operator/(float s) const {
        return mat4 { Columns[0] / s, Columns[1] / s, Columns[2] / s, Columns[3] / s };
    }
    
    inline mat4 mat4::operator+(const mat4& m) const {
        return mat4 { Columns[0] + m.Columns[0], Columns[1] + m.Columns[1], Columns[2] + m.Columns[2], Columns[3] + m.Columns[3] };
    }
    
    inline mat4 mat4::operator-(const mat4& m) const {
        return mat4 { Columns[0] - m.Columns[0], Columns[1] - m.Columns[1], Columns[2] - m.Columns[2], Columns[3] - m.Columns[3] };
    }
    
    inline bool mat4::operator==(const mat4& m) const {
        return Columns[0] == m.Columns[0] && Columns[1] == m.Columns[1] && Columns[2] == m.Columns[2] && Columns[3] == m.Columns[3];
    }
    
    inline bool mat4::operator!=(const mat4& m) const {
        return !(*this == m);
    }
    
    inline mat4& mat4::operator*=(float s) {
        Columns[0] *= s;
        Columns[1] *= s;
        Columns[2] *= s;
        Columns[3] *= s;
        return *this;
    }
    
    inline mat4& mat4::operator*=(const mat4& m) {
        *this = *this * m;
        return *this;
    }
    
    inline mat4& mat4::operator/=(float s) {
        Columns[0] /= s;
        Columns[1] /= s;
        Columns[2] /= s;
        Columns[3] /= s;
        return *this;
    }
    
    inline mat4& mat4::operator+=(const mat4& m) {
        Columns[0] += m.Columns[0];
        Columns[1] += m.Columns[1];
        Columns[2] += m.Columns[2];
        Columns[3] += m.Columns[3];
        return *this;
    }
    
    inline mat4& mat4::operator-=(const mat4& m) {
        Columns[0] -= m.Columns[0];
        Columns[1] -= m.Columns[1];
        Columns[2] -= m.Columns[2];
        Columns[3] -= m.Columns[3];
        return *this;
    }
    
    inline std::ostream& operator<<(std::ostream& Stream, const mat4& m) {
        Stream << '['
        << std::to_string(m.Elements[ 0]).substr(0, 8) << ", "
        << std::to_string(m.Elements[ 4]).substr(0, 8) << ", "
        << std::to_string(m.Elements[ 8]).substr(0, 8) << ", "
        << std::to_string(m.Elements[12]).substr(0, 8) << "]\n["
        << std::to_string(m.Elements[ 1]).substr(0, 8) << ", "
        << std::to_string(m.Elements[ 5]).substr(0, 8) << ", "
        << std::to_string(m.Elements[ 9]).substr(0, 8) << ", "
        << std::to_string(m.Elements[13]).substr(0, 8) << "]\n["
        << std::to_string(m.Elements[ 2]).substr(0, 8) << ", "
        << std::to_string(m.Elements[ 6]).substr(0, 8) << ", "
        << std::to_string(m.Elements[10]).substr(0, 8) << ", "
        << std::to_string(m.Elements[14]).substr(0, 8) << "]\n["
        << std::to_string(m.Elements[ 3]).substr(0, 8) << ", "
        << std::to_string(m.Elements[ 7]).substr(0, 8) << ", "
        << std::to_string(m.Elements[11]).substr(0, 8) << ", "
        << std::to_string(m.Elements[15]).substr(0, 8) << ']';
        return Stream;
    }
}
