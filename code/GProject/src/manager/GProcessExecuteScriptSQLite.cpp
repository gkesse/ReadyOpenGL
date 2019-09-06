//===============================================
#include "GProcessExecuteScriptSQLite.h"
#include "GSQLite.h"
#include "GFile.h"
#include "GConfig.h"
//===============================================
GProcessExecuteScriptSQLite* GProcessExecuteScriptSQLite::m_instance = 0;
//===============================================
GProcessExecuteScriptSQLite::GProcessExecuteScriptSQLite() {

}
//===============================================
GProcessExecuteScriptSQLite::~GProcessExecuteScriptSQLite() {

}
//===============================================
GProcessExecuteScriptSQLite* GProcessExecuteScriptSQLite::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessExecuteScriptSQLite;
	}
	return m_instance;
}
//===============================================
void GProcessExecuteScriptSQLite::run(int argc, char** argv) {
	string lDatabaseID = GConfig::Instance()->getData("CURRENT_DATABASE_SQLITE_ID");
	string lDatabasePath = GConfig::Instance()->getData("CURRENT_DATABASE_SQLITE_PATH");
	string lScriptPath = GConfig::Instance()->getData("CURRENT_SCRIPT_SQLITE_PATH");

	string lSqlQuery = GFile::Instance()->readAll(lScriptPath);

	GSQLite::Instance()->open(lDatabaseID, lDatabasePath);
	GSQLite::Instance()->exec(lDatabaseID, 0, 0, lSqlQuery);
	GSQLite::Instance()->showTableList(lDatabaseID);
	GSQLite::Instance()->showTableData(lDatabaseID, "triangle");
	GSQLite::Instance()->close(lDatabaseID);
}
//===============================================
