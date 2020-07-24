/*[YZMT]::[YZMT]::Functions.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

#define DNJR_PI 3.14159265358979323846

namespace YZMT {
    inline float ToDegrees(float Radians) {
        return static_cast<float>(Radians * (180.0f / DNJR_PI));
    }
    
    inline float ToRadians(float Degrees) {
        return static_cast<float>(Degrees * (DNJR_PI / 180.0f));
    }
}
