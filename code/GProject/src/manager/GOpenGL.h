//================================================
#ifndef _GOpenGL_
#define _GOpenGL_
//================================================
#include "GInclude.h"
//================================================
typedef struct _sGVertex sGVertex;
typedef struct _sGColor sGColor;
//================================================
struct _sGVertex {
	double x;
	double y;
	double z;
};
//================================================
struct _sGColor {
	double r;
	double g;
	double b;
	double a;
};
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
	void drawTriangle(sGVertex* Vertex, sGColor color);

private:
	static GOpenGL* m_instance;
    map<string, string> m_dataMap;
};
//================================================
#endif
//================================================
