//===============================================
#include "GEvent.h"
#include "GConsole.h"
//===============================================
static GEventO* m_GEventO = 0;
//===============================================
static void GEvent_KeyCallBack(GGLFW_WINDOW* window, int key, int scancode, int action, int mods);
static void GEvent_FrameCallBack(GGLFW_WINDOW* window, int width, int height);
static void GEvent_MouseCallBack(GGLFW_WINDOW* window, int button, int action, int mods);
static void GEvent_CursorCallBack(GGLFW_WINDOW* window,  double x, double y);
static void GEvent_ScrollCallBack(GGLFW_WINDOW* window, double x, double y);
static sGEvent* GEvent_GetEvent();
//===============================================
GEventO* GEvent_New() {
	GEventO* lObj = (GEventO*)malloc(sizeof(GEventO));
	lObj->Delete = GEvent_Delete;

	lObj->m_event.key.onFlag = FALSE;
	lObj->m_event.frame.onFlag = TRUE;
	lObj->m_event.mouse.onFlag = FALSE;
	lObj->m_event.cursor.onFlag = FALSE;
	lObj->m_event.scroll.onFlag = FALSE;

	lObj->KeyCallBack = GEvent_KeyCallBack;
	lObj->FrameCallBack = GEvent_FrameCallBack;
	lObj->MouseCallBack = GEvent_MouseCallBack;
	lObj->CursorCallBack = GEvent_CursorCallBack;
	lObj->ScrollCallBack = GEvent_ScrollCallBack;
	lObj->GetEvent = GEvent_GetEvent;
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
static sGEvent* GEvent_GetEvent() {
	return &m_GEventO->m_event;
}
//===============================================
