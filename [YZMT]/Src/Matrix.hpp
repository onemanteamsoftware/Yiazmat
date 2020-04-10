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
    };
    
    struct mat4 {
        union {
            float Elements[4 * 4];
            vec4 Columns[4];
        };
    };
}
