/*[YZMT]::[YZMT]::Quaternion.cpp*/
/*github.com/onemanteamsoftware*/
#include "Quaternion.hpp"

namespace YZMT {
    Quaternion::Quaternion()
        : x { 0.0f }, y { 0.0f }, z { 0.0f }, w { 0.0f } {
    }
    
    Quaternion::Quaternion(float x, float y, float z, float w)
        : x { x }, y { y }, z { z }, w { w } {
    }
    
    Quaternion Quaternion::Identity() {
        return Quaternion { 0.0f, 0.0f, 0.0f, 1.0f };
    }
}
