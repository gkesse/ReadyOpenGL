//===============================================
#ifndef _GProcessTestTriangle_
#define _GProcessTestTriangle_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessTestTriangle : public GProcess {
public:
    GProcessTestTriangle();
    ~GProcessTestTriangle();

public:
    static GProcessTestTriangle* Instance();
    void run(int argc, char** argv);

private:
    static GProcessTestTriangle* m_instance;
};
//===============================================
#endif
//===============================================
