/*[YZMT]::[YZMT]::Vector.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

namespace YZMT {
    struct vec2 {
        union {
            struct { float x; float y; };
            float v[2];
        };
    };
    
    struct vec3 {
        union {
            struct { float x; float y; float z; };
            struct { vec2 xy; float z; };
            float v[3];
        };
    };
    
    struct vec4 {
        union {
            struct { float x; float y; float z; float w; };
            struct { vec3 xyz; float w; };
            float v[4];
        };
    };
}
