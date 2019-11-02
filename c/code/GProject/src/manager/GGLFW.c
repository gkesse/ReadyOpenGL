//===============================================
#include "GGLFW.h"
#include "GConsole.h"
//===============================================
#if defined(__WIN32)
typedef char* GCHAR_PTR;
typedef GLFWwindow* GGLFWWINDOW_PTR;
//===============================================
GDECLARE_MAP(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)
GDEFINE_MAP(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)
#endif
//===============================================
static GGLFWO* m_GGLFWO = 0;
//===============================================
static void GGLFW_Init();
static void GGLFW_WindowHint(int hint, int value);
static void GGLFW_CreateWindow(char* windowName, int w, int h, char* title);
static void GGLFW_KeyCallback(char* windowName, GGLFW_KEY_CALLBACK callback);
static void GGLFW_FrameCallback(char* windowName, GGLFW_FRAME_CALLBACK callback);
static void GGLFW_MouseCallback(char* windowName, GGLFW_MOUSE_CALLBACK callback);
static void GGLFW_CursorCallback(char* windowName, GGLFW_CURSOR_CALLBACK callback);
static void GGLFW_ScrollCallback(char* windowName, GGLFW_SCROLL_CALLBACK callback);
static void GGLFW_MakeContext(char* windowName);
static void GGLFW_SwapInterval(int interval);
static int GGLFW_WindowClose(char* windowName);
static void GGLFW_FrameSize(char* windowName, int* w, int* h);
static double GGLFW_Ratio(char* windowName);
static void GGLFW_SwapBuffers(char* windowName);
static double GGLFW_GetTime();
static void GGLFW_PollEvents();
static void GGLFW_DestroyWindow(char* windowName);
static void GGLFW_Terminate();
//===============================================
#if defined(__WIN32)
static int GGLFW_MapEqual(char* key1, char* key2) ;
#endif
//===============================================
GGLFWO* GGLFW_New() {
	GGLFWO* lObj = (GGLFWO*)malloc(sizeof(GGLFWO));
	lObj->Delete = GGLFW_Delete;
	lObj->Init = GGLFW_Init;
	lObj->WindowHint = GGLFW_WindowHint;
	lObj->CreateWindow = GGLFW_CreateWindow;
	lObj->KeyCallback = GGLFW_KeyCallback;
	lObj->FrameCallback = GGLFW_FrameCallback;
	lObj->MouseCallback = GGLFW_MouseCallback;
	lObj->CursorCallback = GGLFW_CursorCallback;
	lObj->ScrollCallback = GGLFW_ScrollCallback;
	lObj->MakeContext = GGLFW_MakeContext;
	lObj->SwapInterval = GGLFW_SwapInterval;
	lObj->WindowClose = GGLFW_WindowClose;
	lObj->FrameSize = GGLFW_FrameSize;
	lObj->Ratio = GGLFW_Ratio;
	lObj->SwapBuffers = GGLFW_SwapBuffers;
	lObj->GetTime = GGLFW_GetTime;
	lObj->PollEvents = GGLFW_PollEvents;
	lObj->DestroyWindow = GGLFW_DestroyWindow;
	lObj->Terminate = GGLFW_Terminate;
#if defined(__WIN32)
    lObj->m_windowMap = GMap_New_GGLFW_GCHAR_PTR_GGLFWWINDOW_PTR();
#endif
	return lObj;
}
//===============================================
void GGLFW_Delete() {
	GGLFWO* lObj = GGLFW();
	if(lObj != 0) {
		free(lObj);
	}
	m_GGLFWO = 0;
}
//===============================================
GGLFWO* GGLFW() {
	if(m_GGLFWO == 0) {
		m_GGLFWO = GGLFW_New();
	}
	return m_GGLFWO;
}
//===============================================
static void GGLFW_Init() {
#if defined(__WIN32)
    int lRes = glfwInit();
    if(lRes == 0) {GConsole()->Print("Error GGLFW_Init\n"); exit(0);}
#endif
}
//===============================================
static void GGLFW_WindowHint(int hint, int value) {
#if defined(__WIN32)
	glfwWindowHint(hint, value);
#endif
}
//===============================================
static void GGLFW_CreateWindow(char* windowName, int w, int h, char* title) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = glfwCreateWindow(w, h, title, NULL, NULL);
    if(lWindow == 0) {GConsole()->Print("Error GGLFW_CreateWindow\n"); exit(0);}
	lWindowMap->SetData(lWindowMap, windowName, lWindow, GGLFW_MapEqual);
#endif
}
//===============================================
static void GGLFW_KeyCallback(char* windowName, GGLFW_KEY_CALLBACK callback) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    glfwSetKeyCallback(lWindow, callback);
#endif
}
//===============================================
static void GGLFW_FrameCallback(char* windowName, GGLFW_FRAME_CALLBACK callback) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    glfwSetFramebufferSizeCallback(lWindow, callback);
#endif
}
//===============================================
static void GGLFW_MouseCallback(char* windowName, GGLFW_MOUSE_CALLBACK callback) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    glfwSetMouseButtonCallback(lWindow, callback);
#endif
}
//===============================================
static void GGLFW_CursorCallback(char* windowName, GGLFW_CURSOR_CALLBACK callback) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    glfwSetCursorPosCallback(lWindow, callback);
#endif
}
//===============================================
static void GGLFW_ScrollCallback(char* windowName, GGLFW_SCROLL_CALLBACK callback) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    glfwSetScrollCallback(lWindow, callback);
#endif
}
//===============================================
static void GGLFW_MakeContext(char* windowName) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    glfwMakeContextCurrent(lWindow);
#endif
}
//===============================================
static void GGLFW_SwapInterval(int interval) {
#if defined(__WIN32)
    glfwSwapInterval(interval);
#endif
}
//===============================================
static int GGLFW_WindowClose(char* windowName) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    int lRes = glfwWindowShouldClose(lWindow);
    return lRes;
#endif
}
//===============================================
static void GGLFW_FrameSize(char* windowName, int* w, int* h) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    glfwGetFramebufferSize(lWindow, w, h);
#endif
}
//===============================================
static double GGLFW_Ratio(char* windowName) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    int lWidth;
    int lHeight;
    glfwGetFramebufferSize(lWindow, &lWidth, &lHeight);
    double lRatio = (double)lWidth/lHeight;
    return lRatio;
#endif
}
//===============================================
static double GGLFW_GetTime() {
#if defined(__WIN32)
	double lTime = glfwGetTime();
    return lTime;
#endif
}
//===============================================
static void GGLFW_SwapBuffers(char* windowName) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    glfwSwapBuffers(lWindow);
#endif
}
//===============================================
static void GGLFW_PollEvents() {
#if defined(__WIN32)
    glfwPollEvents();
#endif
}
//===============================================
static void GGLFW_DestroyWindow(char* windowName) {
#if defined(__WIN32)
	GMapO(GGLFW, GCHAR_PTR, GGLFWWINDOW_PTR)* lWindowMap = m_GGLFWO->m_windowMap;
    GLFWwindow* lWindow = lWindowMap->GetData(lWindowMap, windowName, GGLFW_MapEqual);
    glfwDestroyWindow(lWindow);
#endif
}
//===============================================
static void GGLFW_Terminate() {
#if defined(__WIN32)
	glfwTerminate();
#endif
}
//===============================================
#if defined(__WIN32)
static int GGLFW_MapEqual(char* key1, char* key2) {
	int lStrcmp = strcmp(key1, key2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
#endif
//===============================================
