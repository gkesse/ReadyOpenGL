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
};
//===============================================
GProcessO* GProcessOpenGLTexture_New();
void GProcessOpenGLTexture_Delete();
GProcessO* GProcessOpenGLTexture();
//===============================================
#endif
//===============================================
