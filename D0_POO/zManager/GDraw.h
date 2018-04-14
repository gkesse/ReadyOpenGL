//===============================================
#ifndef _GDraw_
#define _GDraw_
//================================================
#include <iostream>
#include <string>
//===============================================
#include <GL/glew.h>
//===============================================
#define VERTICES_BUFFER_MAX (256)
//===============================================
using namespace std;
//===============================================
class GDraw {
public:
    GDraw();
    ~GDraw();

public:
    static GDraw* Instance();
    void setVertices();
    void draw();

private:
    static GDraw* m_instance;
    float m_verticesMap[VERTICES_BUFFER_MAX];
};
//===============================================
#endif
//===============================================
