//================================================
#include "GDraw.h"
#include "GDrawQuad.h"
#include "GDrawTriangle.h"
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
	if(m_draw == "GL_TRIANGLES") return GDrawTriangle::Instance();
	if(m_draw == "GL_QUADS") return GDrawQuad::Instance();
	return 0;
}
//================================================
void GDraw::draw() {
	drawBackground();
	drawShape();
}
//================================================
void GDraw::drawBackground() {
	float m_bgColor[] = {0.0f, 0.0f, 0.0f, 1.0f};
	glClearBufferfv(GL_COLOR, 0, m_bgColor);
}
//================================================
