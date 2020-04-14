/*[YZMT]::[YZMT]::Vector.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

namespace YZMT {
    struct vec2 {
        union {
            struct { float x; float y; };
            float v[2];
        };
        
        vec2() : x { 0.0f }, y { 0.0f } {}
        explicit vec2(float x, float y = 0.0f) : x { x }, y { y } {}
        
        vec2& operator*=(float s) { x *= s; y *= s; return *this; }
        vec2& operator/=(float s) { x /= s; y /= s; return *this; }
    };
    
    struct vec3 {
        union {
            struct { float x; float y; float z; };
            struct { vec2 xy; float z; };
            float v[3];
        };
        
        vec3() : x { 0.0f }, y { 0.0f }, z { 0.0f } {}
        vec3(const vec2& v, float z = 0.0f) : x { v.x }, y { v.y }, z { z } {}
        vec3(float x, float y, float z = 0.0f) : x { x }, y { y }, z { z } {}
        
        vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
        vec3& operator/=(float s) { x /= s; y /= s; z /= s; return *this; }
    };
    
    struct vec4 {
        union {
            struct { float x; float y; float z; float w; };
            struct { vec3 xyz; float w; };
            float v[4];
        };
        
        vec4() : x { 0.0f }, y { 0.0f }, z { 0.0f }, w { 0.0f } {}
        vec4(const vec3& v, float w = 0.0f) : x { v.x }, y { v.y }, z { v.z }, w { w } {}
        vec4(float x, float y, float z, float w = 0.0f) : x { x }, y { y }, z { z }, w { w } {}
        
        vec4& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
        vec4& operator/=(float s) { x /= s; y /= s; z /= s; w /= s; return *this; }
    };
}
