//===============================================
#include "GProcessStartWindowOpenGL.h"
#include "GSQLite.h"
#include "GConfig.h"
//===============================================
GProcessStartWindowOpenGL* GProcessStartWindowOpenGL::m_instance = 0;
//===============================================
GProcessStartWindowOpenGL::GProcessStartWindowOpenGL() {

}
//===============================================
GProcessStartWindowOpenGL::~GProcessStartWindowOpenGL() {

}
//===============================================
GProcessStartWindowOpenGL* GProcessStartWindowOpenGL::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessStartWindowOpenGL;
	}
	return m_instance;
}
//===============================================
void GProcessStartWindowOpenGL::run(int argc, char** argv) {
	string lDatabaseID = GConfig::Instance()->getData("DATABASE_ID");
	string lDatabaseName = GConfig::Instance()->getData("DATABASE_NAME");
	string lDatabasePath = "data/sqlite/" + lDatabaseName;
	GSQLite::Instance()->open(lDatabaseID, lDatabasePath);
	GSQLite::Instance()->close(lDatabaseID);
	cout << "[ INFO ] creation de la base de donnees SQLite : " << lDatabasePath << "\n";
}
//===============================================
