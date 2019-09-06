//===============================================
#include "GProcessSetCurrentDatabaseSQLite.h"
#include "GSQLite.h"
#include "GConfig.h"
//===============================================
GProcessSetCurrentDatabaseSQLite* GProcessSetCurrentDatabaseSQLite::m_instance = 0;
//===============================================
GProcessSetCurrentDatabaseSQLite::GProcessSetCurrentDatabaseSQLite() {

}
//===============================================
GProcessSetCurrentDatabaseSQLite::~GProcessSetCurrentDatabaseSQLite() {

}
//===============================================
GProcessSetCurrentDatabaseSQLite* GProcessSetCurrentDatabaseSQLite::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessSetCurrentDatabaseSQLite;
	}
	return m_instance;
}
//===============================================
void GProcessSetCurrentDatabaseSQLite::run(int argc, char** argv) {
	string lDatabaseID = GConfig::Instance()->getData("DATABASE_ID");
	string lDatabaseName = GConfig::Instance()->getData("DATABASE_NAME");
	string lDatabasePath = "data/sqlite/" + lDatabaseName;
	GConfig::Instance()->setData("CURRENT_DATABASE_SQLITE_ID", lDatabasePath);
	GConfig::Instance()->setData("CURRENT_DATABASE_SQLITE_PATH", lDatabasePath);
	cout << "[ INFO ] sauvegarde de la base de donnees SQLite courante..." << "\n";
	cout << "[ INFO ] CURRENT_DATABASE_SQLITE_ID : " << left << setw(20) << lDatabaseID << "\n";
	cout << "[ INFO ] CURRENT_DATABASE_SQLITE_PATH : " << left << setw(20) << lDatabasePath << "\n";
}
//===============================================
