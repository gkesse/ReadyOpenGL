//===============================================
#ifndef _GProcessSetCurrentDatabaseSQLite_
#define _GProcessSetCurrentDatabaseSQLite_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessSetCurrentDatabaseSQLite : public GProcess {
public:
    GProcessSetCurrentDatabaseSQLite();
    ~GProcessSetCurrentDatabaseSQLite();

public:
    static GProcessSetCurrentDatabaseSQLite* Instance();
    void run(int argc, char** argv);

private:
    static GProcessSetCurrentDatabaseSQLite* m_instance;
};
//===============================================
#endif
//===============================================
