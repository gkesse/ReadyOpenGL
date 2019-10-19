//===============================================
#ifndef _GProcessCreateShapeCircle_
#define _GProcessCreateShapeCircle_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessCreateShapeCircle : public GProcess {
public:
    GProcessCreateShapeCircle();
    ~GProcessCreateShapeCircle();

public:
    static GProcessCreateShapeCircle* Instance();
    void run(int argc, char** argv);

private:
    static GProcessCreateShapeCircle* m_instance;
};
//===============================================
#endif
//===============================================
