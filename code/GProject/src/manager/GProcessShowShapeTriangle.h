//===============================================
#ifndef _GProcessShowShapeTriangle_
#define _GProcessShowShapeTriangle_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessShowShapeTriangle : public GProcess {
public:
    GProcessShowShapeTriangle();
    ~GProcessShowShapeTriangle();

public:
    static GProcessShowShapeTriangle* Instance();
    void run(int argc, char** argv);
    static int getTriangleData(void* params, int rows, char** values, char** fields);

private:
    static GProcessShowShapeTriangle* m_instance;
};
//===============================================
#endif
//===============================================
