//===============================================
#ifndef _GGsl_
#define _GGsl_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GGslO GGslO;
typedef struct _GMapO_GGsl_GCHAR_PTR_GVOID_PTR GMapO_GGsl_GCHAR_PTR_GVOID_PTR;
//===============================================
struct _GGslO {
    void (*Delete)();
    double (*Bessel)(double x);
    void (*ComplexShow)(gsl_complex z);
};
//===============================================
GGslO* GGsl_New();
void GGsl_Delete();
GGslO* GGsl();
//===============================================
#endif
//===============================================
