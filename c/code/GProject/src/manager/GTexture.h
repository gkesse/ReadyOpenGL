//===============================================
#ifndef _GTexture_
#define _GTexture_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GTextureO GTextureO;
//===============================================
struct _GTextureO {
    void (*Delete)();
    void (*LoadImage)(sGTextureImage* texture);
    void (*CreateTexture)(sGTexture* texture);
    void (*BindTexture)(sGTexture* texture);
    void (*FreeImage)(sGTextureImage* texture);
    void (*LoadTexture)(sGTexture* texture);
    void (*DeleteTexture)(sGTexture* texture);
    void (*UpdateTexture)(sGTexture* texture);
    void (*ActiveTexture)(sGTextureActive* texture);
};
//===============================================
GTextureO* GTexture_New();
void GTexture_Delete();
GTextureO* GTexture();
//===============================================
#endif
//===============================================
