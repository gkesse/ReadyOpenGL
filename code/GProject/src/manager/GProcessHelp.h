//===============================================
#ifndef _GProcessHelp_
#define _GProcessHelp_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessHelp : public GProcess {
public:
    GProcessHelp();
    ~GProcessHelp();

public:
    static GProcessHelp* Instance();
    void run(int argc, char** argv);

private:
    static GProcessHelp* m_instance;
};
//===============================================
#endif
//===============================================
