//================================================
#ifndef _GDrawTransformation_
#define _GDrawTransformation_
//================================================
#include "GDraw.h"
//================================================
class GDrawTransformation : public GDraw {
public:
	GDrawTransformation();
	~GDrawTransformation();
	
public:
	static GDrawTransformation* Instance();
	void initDraw();
	void drawShape();
	
private:
	static GDrawTransformation* m_instance;
	float m_vertices[3][3];
	GLuint m_program;
	glm::mat4 m_projection;
	glm::mat4 m_modelview;
};
//================================================
#endif
//================================================
