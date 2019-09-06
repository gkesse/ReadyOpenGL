//===============================================
#ifndef _GProcessExecuteScriptSQLite_
#define _GProcessExecuteScriptSQLite_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessExecuteScriptSQLite : public GProcess {
public:
    GProcessExecuteScriptSQLite();
    ~GProcessExecuteScriptSQLite();

public:
    static GProcessExecuteScriptSQLite* Instance();
    void run(int argc, char** argv);

private:
    static GProcessExecuteScriptSQLite* m_instance;
};
//===============================================
#endif
//===============================================
