//===============================================
#include "GProcessShowShapeTriangle.h"
#include "GSQLite.h"
#include "GString.h"
#include "GOpenGL.h"
#include "GConfig.h"
//===============================================
GProcessShowShapeTriangle* GProcessShowShapeTriangle::m_instance = 0;
//===============================================
GProcessShowShapeTriangle::GProcessShowShapeTriangle() {

}
//===============================================
GProcessShowShapeTriangle::~GProcessShowShapeTriangle() {

}
//===============================================
GProcessShowShapeTriangle* GProcessShowShapeTriangle::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessShowShapeTriangle;
	}
	return m_instance;
}
//===============================================
void GProcessShowShapeTriangle::run(int argc, char** argv) {
	string lDatabaseID = GConfig::Instance()->getData("CURRENT_DATABASE_SQLITE_ID");
	string lDatabasePath = GConfig::Instance()->getData("CURRENT_DATABASE_SQLITE_PATH");
	sGTriangle lTriangle;

	string lSqlQuery = ""
			"SELECT * FROM triangle "
			"WHERE id = 1";

	GSQLite::Instance()->open(lDatabaseID, lDatabasePath);
	GSQLite::Instance()->exec(lDatabaseID, getTriangleData, &lTriangle, lSqlQuery);
	GSQLite::Instance()->close(lDatabaseID);
	GOpenGL::Instance()->drawTriangle(&lTriangle);
}
//================================================
int GProcessShowShapeTriangle::getTriangleData(void* params, int colCount, char** colValues, char** colNames) {
	sGTriangle* lTriangle = (sGTriangle*)params;
	lTriangle->m_id = atoi(colValues[0]);
	lTriangle->m_vertex[0] = {atof(colValues[1]), atof(colValues[2]), atof(colValues[3])};
	lTriangle->m_vertex[1] = {atof(colValues[4]), atof(colValues[5]), atof(colValues[6])};
	lTriangle->m_vertex[2] = {atof(colValues[7]), atof(colValues[8]), atof(colValues[9])};
	lTriangle->m_color[0] = {atof(colValues[10]), atof(colValues[11]), atof(colValues[12])};
	lTriangle->m_color[1] = {atof(colValues[13]), atof(colValues[14]), atof(colValues[15])};
	lTriangle->m_color[2] = {atof(colValues[16]), atof(colValues[17]), atof(colValues[18])};
	return 0;
}
//===============================================
