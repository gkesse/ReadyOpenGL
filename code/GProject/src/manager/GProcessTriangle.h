//===============================================
#ifndef _GProcessTriangle_
#define _GProcessTriangle_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessTriangle : public GProcess {
public:
    GProcessTriangle();
    ~GProcessTriangle();

public:
    static GProcessTriangle* Instance();
    void run(int argc, char** argv);

private:
    static GProcessTriangle* m_instance;
};
//===============================================
#endif
//===============================================
