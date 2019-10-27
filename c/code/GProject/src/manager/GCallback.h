//===============================================
#ifndef _GCallback_
#define _GCallback_
//===============================================
typedef struct _sGWindow sGWindow;
//===============================================
typedef double (*GFUNCTION)(double x, void* params);
typedef double (*GFUNCTION_2D)(double x, double y, void* params);
typedef void (*GOPENGL_UPDATE_CALLBACK)(sGWindow* sWindow);
//===============================================
#endif
//===============================================
