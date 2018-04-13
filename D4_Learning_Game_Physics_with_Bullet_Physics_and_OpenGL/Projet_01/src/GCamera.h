//===============================================
#ifndef _GCamera_
#define _GCamera_
//===============================================
#include <GL/freeglut.h>
#include <iostream>
//===============================================
using namespace std;
//===============================================
class GCamera {
public:
    GCamera();
    ~GCamera();

public:
    static GCamera* Instance();
    void setWindowSize(int w, int h);
    void update();

private:
    static GCamera* m_instance;
    int m_w;
    int m_h;
};
//===============================================
#endif
//===============================================
