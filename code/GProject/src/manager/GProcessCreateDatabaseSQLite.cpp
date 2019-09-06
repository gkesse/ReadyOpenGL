//===============================================
#include "GProcessCreateDatabaseSQLite.h"
#include "GSQLite.h"
#include "GConfig.h"
//===============================================
GProcessCreateDatabaseSQLite* GProcessCreateDatabaseSQLite::m_instance = 0;
//===============================================
GProcessCreateDatabaseSQLite::GProcessCreateDatabaseSQLite() {

}
//===============================================
GProcessCreateDatabaseSQLite::~GProcessCreateDatabaseSQLite() {

}
//===============================================
GProcessCreateDatabaseSQLite* GProcessCreateDatabaseSQLite::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessCreateDatabaseSQLite;
	}
	return m_instance;
}
//===============================================
void GProcessCreateDatabaseSQLite::run(int argc, char** argv) {
	string lDatabaseID = GConfig::Instance()->getData("DATABASE_ID");
	string lDatabaseName = GConfig::Instance()->getData("DATABASE_NAME");
	string lDatabasePath = "data/sqlite/" + lDatabaseName;
	GSQLite::Instance()->open(lDatabaseID, lDatabasePath);
	GSQLite::Instance()->close(lDatabaseID);
	cout << "[ INFO ] creation de la base de donnees SQLite : " << lDatabasePath << "\n";
}
//===============================================
