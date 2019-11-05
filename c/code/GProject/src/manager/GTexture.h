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
    void (*LoadImage)(sGTexture* texture);
    void (*CreateTexture)(sGTexture* texture);
    void (*BindTexture)(sGTexture* texture);
    void (*FreeImage)(sGTexture* texture);
    void (*UpdateTexture)(sGTexture* texture);};
//===============================================
GTextureO* GTexture_New();
void GTexture_Delete();
GTextureO* GTexture();
//===============================================
#endif
//===============================================
