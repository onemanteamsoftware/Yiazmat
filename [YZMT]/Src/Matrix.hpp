/*[YZMT]::[YZMT]::Matrix.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

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
    };
    
    struct mat4 final {
        union {
            float Elements[4 * 4];
            vec4 Columns[4];
        };
        
        mat4();
        explicit mat4(float Diagonal);
        mat4(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3);
    };
}
