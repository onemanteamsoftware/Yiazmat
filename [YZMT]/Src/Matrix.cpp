/*[YZMT]::[YZMT]::Matrix.cpp*/
/*github.com/onemanteamsoftware*/
#include "Matrix.hpp"

namespace YZMT {
    mat3::mat3()
        : Elements { 0.0f } {
    }
    
    mat3::mat3(float Diagonal)
        : Elements { 0.0f } {
        Elements[0 + 0 * 3] = Diagonal;
        Elements[1 + 1 * 3] = Diagonal;
        Elements[2 + 2 * 3] = Diagonal;
    }
    
    mat3::mat3(const vec3& v0, const vec3& v1, const vec3& v2)
        : Columns { v0, v1, v2 } {
    }
    
    mat3 mat3::Identity() {
        return mat3 { 1.0f };
    }
    
    mat3 mat3::Scale(const vec2& v) {
        mat3 Result {};
        Result.Elements[0 + 0 * 3] = v.x;
        Result.Elements[1 + 1 * 3] = v.y;
        Result.Elements[2 + 2 * 3] = 1.0f;
        return Result;
    }
    
    mat3 mat3::Scale(float x, float y) {
        mat3 Result {};
        Result.Elements[0 + 0 * 3] = x;
        Result.Elements[1 + 1 * 3] = y;
        Result.Elements[2 + 2 * 3] = 1.0f;
        return Result;
    }
    
    mat3 mat3::Translate(const vec2& v) {
        mat3 Result { 1.0f };
        Result.Elements[0 + 2 * 3] = v.x;
        Result.Elements[1 + 2 * 3] = v.y;
        return Result;
    }
    
    mat3 mat3::Translate(float x, float y) {
        mat3 Result { 1.0f };
        Result.Elements[0 + 2 * 3] = x;
        Result.Elements[1 + 2 * 3] = y;
        return Result;
    }
    
    mat3 mat3::operator*(float s) const {
        return mat3 { Columns[0] * s, Columns[1] * s, Columns[2] * s };
    }
    
    mat3& mat3::operator*=(float s) {
        Columns[0] *= s;
        Columns[1] *= s;
        Columns[2] *= s;
        return *this;
    }
    
    mat4::mat4()
        : Elements { 0.0f } {
    }
    
    mat4::mat4(float Diagonal)
        : Elements { 0.0f } {
        Elements[0 + 0 * 4] = Diagonal;
        Elements[1 + 1 * 4] = Diagonal;
        Elements[2 + 2 * 4] = Diagonal;
        Elements[3 + 3 * 4] = Diagonal;
    }
    
    mat4::mat4(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3)
        : Columns { v0, v1, v2, v3 } {
    }
    
    mat4 mat4::Identity() {
        return mat4 { 1.0f };
    }
    
    mat4 mat4::Scale(const vec3& v) {
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = v.x;
        Result.Elements[1 + 1 * 4] = v.y;
        Result.Elements[2 + 2 * 4] = v.z;
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    mat4 mat4::Scale(float x, float y, float z) {
        mat4 Result {};
        Result.Elements[0 + 0 * 4] = x;
        Result.Elements[1 + 1 * 4] = y;
        Result.Elements[2 + 2 * 4] = z;
        Result.Elements[3 + 3 * 4] = 1.0f;
        return Result;
    }
    
    mat4 mat4::Translate(const vec3& v) {
        mat4 Result { 1.0f };
        Result.Elements[0 + 3 * 4] = v.x;
        Result.Elements[1 + 3 * 4] = v.y;
        Result.Elements[2 + 3 * 4] = v.z;
        return Result;
    }
    
    mat4 mat4::Translate(float x, float y, float z) {
        mat4 Result { 1.0f };
        Result.Elements[0 + 3 * 4] = x;
        Result.Elements[1 + 3 * 4] = y;
        Result.Elements[2 + 3 * 4] = z;
        return Result;
    }
    
    mat3 mat4::GetSubMatrix() const {
        return mat3 {
            vec3 { Columns[0].x, Columns[0].y, Columns[0].z },
            vec3 { Columns[1].x, Columns[1].y, Columns[1].z },
            vec3 { Columns[2].x, Columns[2].y, Columns[2].z }
        };
    }
}
