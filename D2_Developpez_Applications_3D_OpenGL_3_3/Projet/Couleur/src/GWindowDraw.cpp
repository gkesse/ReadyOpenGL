//================================================
#include "GWindowDraw.h"
#include "GConfig.h"
#include "GDraw.h"
//================================================
GWindowDraw* GWindowDraw::m_instance = 0;
//================================================
GWindowDraw::GWindowDraw() {
	GConfig::Instance()->setData("draw", "TRIANGLE_COLOR");
}
//================================================
GWindowDraw::~GWindowDraw() {
	
}
//================================================
GWindowDraw* GWindowDraw::Instance() {
	if(m_instance == 0) {
		m_instance = new GWindowDraw;
	}
	return m_instance;
}
//================================================
void GWindowDraw::draw() {
	GDraw::Instance()->draw();
}
//================================================
