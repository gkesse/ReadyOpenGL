//===============================================
#ifndef _GFunction_
#define _GFunction_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GFunctionO GFunctionO;
//===============================================
struct _GFunctionO {
    void (*Delete)();
    void (*Compute)(sGFunction* func);
    void (*Compute2D)(sGFunction2D* func);
    double (*Sinus)(double x, void* params);
    double (*Gaussian)(double x, void* params);
    double (*Gaussian2D)(double x, double y, void* params);
    double (*Min)(sGVertex* data, int nMax, int pos);
    double (*Max)(sGVertex* data, int nMax, int pos);
    void (*Free)(sGVertex* data);
};
//===============================================
GFunctionO* GFunction_New();
void GFunction_Delete();
GFunctionO* GFunction();
//===============================================
#endif
//===============================================
