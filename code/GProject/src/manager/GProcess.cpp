//===============================================
#include "GProcess.h"
#include "GProcessHelp.h"
#include "GProcessTest.h"
#include "GProcessTestTriangle.h"
#include "GProcessCreateShapeTriangle.h"
#include "GProcessCreateShapeCircle.h"
#include "GProcessShowShapeTriangle.h"
#include "GProcessCreateDatabaseSQLite.h"
#include "GProcessExecuteScriptSQLite.h"
#include "GProcessSetCurrentDatabaseSQLite.h"
#include "GProcessStartWindowOpenGL.h"
#include "GConfig.h"
//===============================================
GProcess::GProcess() {

}
//===============================================
GProcess::~GProcess() {

}
//===============================================
GProcess* GProcess::Instance() {
    string lKey = GConfig::Instance()->getData("PROCESS");
    if(lKey == "HELP") return GProcessHelp::Instance();
    if(lKey == "TEST") return GProcessTest::Instance();
    if(lKey == "TEST_TRIANGLE") return GProcessTestTriangle::Instance();
    if(lKey == "CREATE_SHAPE_TRIANGLE") return GProcessCreateShapeTriangle::Instance();
    if(lKey == "CREATE_SHAPE_CIRCLE") return GProcessCreateShapeCircle::Instance();
    if(lKey == "SHOW_SHAPE_TRIANGLE") return GProcessShowShapeTriangle::Instance();
    if(lKey == "CREATE_DATABASE_SQLITE") return GProcessCreateDatabaseSQLite::Instance();
    if(lKey == "EXECUTE_SCRIPT_SQLITE") return GProcessExecuteScriptSQLite::Instance();
    if(lKey == "SET_CURRENT_DATABASE_SQLITE") return GProcessSetCurrentDatabaseSQLite::Instance();
    if(lKey == "START_WINDOW_OPENGL") return GProcessStartWindowOpenGL::Instance();
    return GProcessHelp::Instance();
}
//===============================================
