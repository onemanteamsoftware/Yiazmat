/*[YZMT]::[YZMT]::Quaternion.cpp*/
/*github.com/onemanteamsoftware*/
#include "Quaternion.hpp"

namespace YZMT {
    Quaternion::Quaternion()
        : x { 0.0f }, y { 0.0f }, z { 0.0f }, w { 0.0f } {
    }
    
    Quaternion::Quaternion(const vec4& v)
        : x { v.x }, y { v.y }, z { v.z }, w { v.w } {
    }
    
    Quaternion::Quaternion(const vec3& v, float w)
        : x { v.x }, y { v.y }, z { v.z }, w { w } {
    }
    
    Quaternion::Quaternion(float x, float y, float z, float w)
        : x { x }, y { y }, z { z }, w { w } {
    }
    
    Quaternion Quaternion::Identity() {
        return Quaternion { 0.0f, 0.0f, 0.0f, 1.0f };
    }
    
    bool Quaternion::operator==(const Quaternion& q) const {
        return x == q.x && y == q.y && z == q.z && w == q.w;
    }
    
    bool Quaternion::operator!=(const Quaternion& q) const {
        return !(*this == q);
    }
}
