//===============================================
#ifndef _GGLew_
#define _GGLew_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GGLewO GGLewO;
//===============================================
struct _GGLewO {
    void (*Delete)();
    void (*Experimental)(int flag);
    void (*Init)();
};
//===============================================
GGLewO* GGLew_New();
void GGLew_Delete();
GGLewO* GGLew();
//===============================================
#endif
//===============================================
