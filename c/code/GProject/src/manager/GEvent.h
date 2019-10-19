//===============================================
#ifndef _GEvent_
#define _GEvent_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GEventO GEventO;
//===============================================
struct _GEventO {
    void (*Delete)();
    void (*KeyCallBack)(GGLFW_WINDOW* window, int key, int scancode, int action, int mods);
    void (*FrameCallBack)(GGLFW_WINDOW* window, int width, int height);
    void (*MouseCallBack)(GGLFW_WINDOW* window, int button, int action, int mods);
    void (*CursorCallBack)(GGLFW_WINDOW* window,  double x, double y);
    void (*ScrollCallBack)(GGLFW_WINDOW* window, double x, double y);
    sGEvent (*GetEvent)();
    sGEvent m_event;
};
//===============================================
GEventO* GEvent_New();
void GEvent_Delete();
GEventO* GEvent();
//===============================================
#endif
//===============================================
