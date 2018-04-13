//================================================
#include "GDraw.h"
#include "GDrawTriangle.h"
#include "GDrawTriangleDouble.h"
#include "GDrawTriangleColor.h"
#include "GDrawTransformation.h"
#include "GConfig.h"
//================================================
GDraw* GDraw::m_instance = 0;
//================================================
GDraw::GDraw() {

}
//================================================
GDraw::~GDraw() {
	
}
//================================================
GDraw* GDraw::Instance() {
	string m_draw = GConfig::Instance()->getData("draw");
	if(m_draw == "TRIANGLE") return GDrawTriangle::Instance();
	if(m_draw == "TRIANGLE_DOUBLE") return GDrawTriangleDouble::Instance();
	if(m_draw == "TRIANGLE_COLOR") return GDrawTriangleColor::Instance();
	if(m_draw == "TRANSFORMATION") return GDrawTransformation::Instance();
	return 0;
}
//================================================
void GDraw::draw() {
	drawShape();
}
//================================================
void GDraw::setWindowSize(const int& w, const int& h) {
	m_w = w;
	m_h = h;
}
//================================================
