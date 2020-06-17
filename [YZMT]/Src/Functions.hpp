/*[YZMT]::[YZMT]::Functions.hpp*/
/*github.com/onemanteamsoftware*/
#pragma once

#define _USE_MATH_DEFINES

#include <cmath>

namespace YZMT {
    float ToDegrees(float Radians) {
        return static_cast<float>(Radians * (180.0f / M_PI));
    }
    
    float ToRadians(float Degrees) {
        return static_cast<float>(Degrees * (M_PI / 180.0f));
    }
}