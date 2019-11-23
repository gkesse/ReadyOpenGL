//===============================================
#ifndef _GGlm_
#define _GGlm_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GGlmO GGlmO;
//===============================================
struct _GGlmO {
    void (*Delete)();
    void (*RadVec3)(vec3 deg, vec3 rad);
    void (*ShowVec3)(vec3 v1);
    void (*ShowMat4)(mat4 m1);
    void (*RotateMatrix)(mat4 m1, double angle, vec3 axis);
};
//===============================================
GGlmO* GGlm_New();
void GGlm_Delete();
GGlmO* GGlm();
//===============================================
#endif
//===============================================
