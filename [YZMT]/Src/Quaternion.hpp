/*[YZMT]::[YZMT]::Quaternion.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

namespace YZMT {
    struct Quaternion final {
        float x, y, z, w;
        
        Quaternion();
        Quaternion(float x, float y, float z, float w = 1.0f);
        
        static Quaternion Identity();
    };
}
