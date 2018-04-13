//===============================================
#ifndef _GLight_
#define _GLight_
//===============================================
#include <GL/freeglut.h>
//===============================================
class GLight {
public:
    GLight();
    ~GLight();

public:
    static GLight* Instance();
    void initLight();

private:
    static GLight* m_instance;
    int m_w;
    int m_h;
};
//===============================================
#endif
//===============================================
