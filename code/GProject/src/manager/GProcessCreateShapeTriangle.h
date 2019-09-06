//===============================================
#ifndef _GProcessCreateShapeTriangle_
#define _GProcessCreateShapeTriangle_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessCreateShapeTriangle : public GProcess {
public:
    GProcessCreateShapeTriangle();
    ~GProcessCreateShapeTriangle();

public:
    static GProcessCreateShapeTriangle* Instance();
    void run(int argc, char** argv);

private:
    static GProcessCreateShapeTriangle* m_instance;
};
//===============================================
#endif
//===============================================
