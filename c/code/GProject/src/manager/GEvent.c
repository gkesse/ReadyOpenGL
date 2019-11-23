//===============================================
#include "GEvent.h"
#include "GGLFW.h"
#include "GConsole.h"
//===============================================
static GEventO* m_GEventO = 0;
//===============================================
static void GEvent_InitEvent(char* windowName);
static sGEvent* GEvent_GetEvent();
static void GEvent_CleanEvent();
//===============================================
static void GEvent_KeyCallBack(GGLFW_WINDOW* window, int key, int scancode, int action, int mods);
static void GEvent_FrameCallBack(GGLFW_WINDOW* window, int width, int height);
static void GEvent_MouseCallBack(GGLFW_WINDOW* window, int button, int action, int mods);
static void GEvent_CursorCallBack(GGLFW_WINDOW* window,  double x, double y);
static void GEvent_ScrollCallBack(GGLFW_WINDOW* window, double x, double y);
//===============================================
GEventO* GEvent_New() {
	GEventO* lObj = (GEventO*)malloc(sizeof(GEventO));
	lObj->Delete = GEvent_Delete;

	lObj->m_event.key.onFlag = FALSE;
	lObj->m_event.frame.onFlag = TRUE;
	lObj->m_event.mouse.onFlag = FALSE;
	lObj->m_event.cursor.onFlag = FALSE;
	lObj->m_event.scroll.onFlag = FALSE;

	lObj->InitEvent = GEvent_InitEvent;
	lObj->GetEvent = GEvent_GetEvent;
	lObj->CleanEvent = GEvent_CleanEvent;
	lObj->KeyCallBack = GEvent_KeyCallBack;
	lObj->FrameCallBack = GEvent_FrameCallBack;
	lObj->MouseCallBack = GEvent_MouseCallBack;
	lObj->CursorCallBack = GEvent_CursorCallBack;
	lObj->ScrollCallBack = GEvent_ScrollCallBack;
	return lObj;
}
//===============================================
void GEvent_Delete() {
	GEventO* lObj = GEvent();
	if(lObj != 0) {
		free(lObj);
	}
	m_GEventO = 0;
}
//===============================================
GEventO* GEvent() {
	if(m_GEventO == 0) {
		m_GEventO = GEvent_New();
	}
	return m_GEventO;
}
//===============================================
static void GEvent_InitEvent(char* windowName) {
	GGLFW()->KeyCallback(windowName, GEvent()->KeyCallBack);
	GGLFW()->FrameCallback(windowName, GEvent()->FrameCallBack);
	GGLFW()->MouseCallback(windowName, GEvent()->MouseCallBack);
	GGLFW()->CursorCallback(windowName, GEvent()->CursorCallBack);
	GGLFW()->ScrollCallback(windowName, GEvent()->ScrollCallBack);
}
//===============================================
static sGEvent* GEvent_GetEvent() {
	return &m_GEventO->m_event;
}
//===============================================
static void GEvent_CleanEvent() {
	sGEvent* lEvent = &m_GEventO->m_event;
	lEvent->key.onFlag = FALSE;
	lEvent->frame.onFlag = FALSE;
	lEvent->mouse.onFlag = FALSE;
	lEvent->cursor.onFlag = FALSE;
	lEvent->scroll.onFlag = FALSE;
}
//===============================================
static void GEvent_KeyCallBack(GGLFW_WINDOW* window, int key, int scancode, int action, int mods) {
	sGEvent* lEvent = &m_GEventO->m_event;
	lEvent->key.key = key;
	lEvent->key.scancode = scancode;
	lEvent->key.action = action;
	lEvent->key.mods = mods;
	lEvent->key.onFlag = TRUE;
}
//===============================================
static void GEvent_FrameCallBack(GGLFW_WINDOW* window, int width, int height) {
	sGEvent* lEvent = &m_GEventO->m_event;
	lEvent->frame.width = width;
	lEvent->frame.height = height;
	lEvent->frame.onFlag = TRUE;
}
//===============================================
static void GEvent_MouseCallBack(GGLFW_WINDOW* window, int button, int action, int mods) {
	sGEvent* lEvent = &m_GEventO->m_event;
	lEvent->mouse.button = button;
	lEvent->mouse.action = action;
	lEvent->mouse.mods = mods;
	lEvent->mouse.onFlag = TRUE;
}
//===============================================
static void GEvent_CursorCallBack(GGLFW_WINDOW* window,  double x, double y) {
	sGEvent* lEvent = &m_GEventO->m_event;
	lEvent->cursor.x = (int)x;
	lEvent->cursor.y = (int)y;
	lEvent->cursor.onFlag = TRUE;
}
//===============================================
static void GEvent_ScrollCallBack(GGLFW_WINDOW* window, double x, double y) {
	sGEvent* lEvent = &m_GEventO->m_event;
	lEvent->scroll.x = x;
	lEvent->scroll.y = y;
	lEvent->scroll.onFlag = TRUE;
}
//===============================================

