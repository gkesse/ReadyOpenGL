//================================================
#ifndef _GOpenGL_
#define _GOpenGL_
//================================================
#include "GInclude.h"
//================================================
class GOpenGL {
private:
	GOpenGL();
	
public:
	~GOpenGL();
	static GOpenGL* Instance();
	void viewPort(const string& windowName);
	void clear(const uint& mask);
	void ortho(const string& windowName);
	void rotate(const double& angle, const double& x, const double& y, const double& z);
	void enable(const int& cap);
	void hint(const int& target, const int& mode);
	void blendFunc(const int& sFactor, const int& dFactor);
	void drawPoint(const sGVertex& vertex, const sGColor& color, const int& pointSize);
	void drawTriangle(sGVertex* Vertex, const sGColor& color);
    void drawTriangle(sGVertex* vertex, sGColor* color);
    void drawTriangle(sGTriangle* triangle);

private:
	static GOpenGL* m_instance;
};
//================================================
#endif
//================================================
