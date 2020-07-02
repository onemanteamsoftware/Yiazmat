/*[YZMT]::[YZMT]::Quaternion.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

#include "Vector.hpp"

namespace YZMT {
    struct Quaternion final {
        float x, y, z, w;
        
        Quaternion();
        Quaternion(const vec4& v);
        Quaternion(const vec3& v, float w = 1.0f);
        Quaternion(float x, float y, float z, float w = 1.0f);
        
        static Quaternion Identity();
    };
}
