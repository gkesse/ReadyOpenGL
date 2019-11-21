//===============================================
#ifndef _GGlm_
#define _GGlm_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GGlmO GGlmO;
typedef struct _GMapO_GGlm_GCHAR_PTR_GVOID_PTR GMapO_GGlm_GCHAR_PTR_GVOID_PTR;
//===============================================
struct _GGlmO {
    void (*Delete)();
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
