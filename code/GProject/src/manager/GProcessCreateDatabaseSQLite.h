//===============================================
#ifndef _GProcessCreateDatabaseSQLite_
#define _GProcessCreateDatabaseSQLite_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessCreateDatabaseSQLite : public GProcess {
public:
    GProcessCreateDatabaseSQLite();
    ~GProcessCreateDatabaseSQLite();

public:
    static GProcessCreateDatabaseSQLite* Instance();
    void run(int argc, char** argv);

private:
    static GProcessCreateDatabaseSQLite* m_instance;
};
//===============================================
#endif
//===============================================
