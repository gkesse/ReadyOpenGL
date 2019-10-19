//===============================================
#ifndef _GProcessStartWindowOpenGL_
#define _GProcessStartWindowOpenGL_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessStartWindowOpenGL : public GProcess {
public:
    GProcessStartWindowOpenGL();
    ~GProcessStartWindowOpenGL();

public:
    static GProcessStartWindowOpenGL* Instance();
    void run(int argc, char** argv);

private:
    static GProcessStartWindowOpenGL* m_instance;
};
//===============================================
#endif
//===============================================
