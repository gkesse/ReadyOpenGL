//================================================
#include "GWindowDraw.h"
//================================================
GWindowDraw* GWindowDraw::m_instance = 0;
//================================================
GWindowDraw::GWindowDraw() {

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

}
//================================================
