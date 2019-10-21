//===============================================
#ifndef _GGLFW_
#define _GGLFW_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GGLFWO GGLFWO;
typedef struct _GMapO_GGLFW_GCHAR_PTR_GGLFWWINDOW_PTR GMapO_GGLFW_GCHAR_PTR_GGLFWWINDOW_PTR;
//===============================================
typedef void (*GGLFW_KEY_CALLBACK)(GGLFW_WINDOW* window, int key, int scancode, int action, int mods);
typedef void (*GGLFW_FRAME_CALLBACK)(GGLFW_WINDOW* window, int width, int height);
typedef void (*GGLFW_MOUSE_CALLBACK)(GGLFW_WINDOW* window, int button, int action, int mods);
typedef void (*GGLFW_CURSOR_CALLBACK)(GGLFW_WINDOW* window,  double x, double y);
typedef void (*GGLFW_SCROLL_CALLBACK)(GGLFW_WINDOW* window, double x, double y);
//===============================================
struct _GGLFWO {
    void (*Delete)();
    void (*Init)();
    void (*CreateWindow)(char* windowName, int w, int h, char* title);
    void (*KeyCallback)(char* windowName, GGLFW_KEY_CALLBACK callback);
    void (*FrameCallback)(char* windowName, GGLFW_FRAME_CALLBACK callback);
    void (*MouseCallback)(char* windowName, GGLFW_MOUSE_CALLBACK callback);
    void (*CursorCallback)(char* windowName, GGLFW_CURSOR_CALLBACK callback);
    void (*ScrollCallback)(char* windowName, GGLFW_SCROLL_CALLBACK callback);
    void (*MakeContext)(char* windowName);
    void (*SwapInterval)(int interval);
    int (*WindowClose)(char* windowName);
    void (*FrameSize)(char* windowName, int* w, int* h);
    double (*Ratio)(char* windowName);
    void (*SwapBuffers)(char* windowName);
    double (*GetTime)();
    void (*PollEvents)();
    void (*DestroyWindow)(char* windowName);
    void (*Terminate)();
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* m_windowMap;
#endif
};
//===============================================
GGLFWO* GGLFW_New();
void GGLFW_Delete();
GGLFWO* GGLFW();
//===============================================
#endif
//===============================================
