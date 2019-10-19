//===============================================
#ifndef _GOpenGL_
#define _GOpenGL_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GOpenGLO GOpenGLO;
//===============================================
struct _GOpenGLO {
    void (*Delete)();
    void (*Enable)(int cap);
    void (*Hint)(int target, int mode);
    void (*BlendFunc)(int sfactor, int dfactor);
    void (*Viewport)(char* windowName);
    void (*Clear)(int mask);
    void (*Projection)(char* windowName);
    void (*Rotate)(double angle, double x, double y, double z);
    void (*DrawPoint)(sGPoint obj);
    void (*DrawPoints)(sGData obj);
    void (*DrawDataTab)(sGDataTab obj);
    void (*DrawHeatMap)(sGData2D obj);
    void (*DrawLine)(sGLine obj);
    void (*DrawLines)(sGData obj);
    void (*DrawTriangle)(sGTriangle obj);
    void (*DrawGrid)(sGGrid obj);
    void (*DrawFunction)(sGFunction* obj);
    void (*DrawFunction2D)(sGFunction2D* obj);
    void (*DrawFunctionHeatMap)(sGFunction2D* obj);
    void (*MainLoop)(sGWindow sWindow);
};
//===============================================
GOpenGLO* GOpenGL_New();
void GOpenGL_Delete();
GOpenGLO* GOpenGL();
//===============================================
#endif
//===============================================
