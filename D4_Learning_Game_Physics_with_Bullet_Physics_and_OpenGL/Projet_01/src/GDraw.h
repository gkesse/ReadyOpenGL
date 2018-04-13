//===============================================
#ifndef _GDraw_
#define _GDraw_
//===============================================
#include <GL/freeglut.h>
#include <BulletDynamics/Dynamics/btDynamicsWorld.h>
//===============================================
class GDraw {
public:
    GDraw();
    ~GDraw();

public:
    static GDraw* Instance();
    void draw();

private:
    static GDraw* m_instance;
    int m_w;
    int m_h;
};
//===============================================
#endif
//===============================================
