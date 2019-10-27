//===============================================
#ifndef _GMcml_
#define _GMcml_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GMcmlO GMcmlO;
//===============================================
struct _GMcmlO {
    void (*Delete)();
    void (*Load)(char* filename, sGMCML* mcml);
    void (*JetColor)(sGMCML* mcml);
};
//===============================================
GMcmlO* GMcml_New();
void GMcml_Delete();
GMcmlO* GMcml();
//===============================================
#endif
//===============================================
