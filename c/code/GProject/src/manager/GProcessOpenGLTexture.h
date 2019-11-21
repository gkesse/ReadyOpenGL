//===============================================
#ifndef _GProcessOpenGLTexture_
#define _GProcessOpenGLTexture_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenGLTextureO GProcessOpenGLTextureO;
//===============================================
struct _GProcessOpenGLTextureO {
    GProcessO* m_parent;
    sGWindow m_window;
    sGCamera m_camera;
    sGCameraView m_cameraView;
};
//===============================================
GProcessO* GProcessOpenGLTexture_New();
void GProcessOpenGLTexture_Delete();
GProcessO* GProcessOpenGLTexture();
//===============================================
#endif
//===============================================
