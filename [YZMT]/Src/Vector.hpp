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
    };
    
    struct vec3 {
        union {
            struct { float x; float y; float z; };
            struct { vec2 xy; float z; };
            float v[3];
        };
        
        vec3() : x { 0.0f }, y { 0.0f }, z { 0.0f } {}
    };
    
    struct vec4 {
        union {
            struct { float x; float y; float z; float w; };
            struct { vec3 xyz; float w; };
            float v[4];
        };
        
        vec4() : x { 0.0f }, y { 0.0f }, z { 0.0f }, w { 0.0f } {}
    };
}
