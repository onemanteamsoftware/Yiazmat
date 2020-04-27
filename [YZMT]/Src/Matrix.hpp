/*[YZMT]::[YZMT]::Matrix.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

#include "Vector.hpp"

namespace YZMT {
    struct mat3 {
        union {
            float Elements[3 * 3];
            vec3 Columns[3];
        };
        
        mat3() : Elements { 0.0f } {}
    };
    
    struct mat4 {
        union {
            float Elements[4 * 4];
            vec4 Columns[4];
        };
        
        mat4() : Elements { 0.0f } {}
    };
}
