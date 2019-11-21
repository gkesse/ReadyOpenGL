//===============================================
#include "GProcessGslTest.h"
#include "GGsl.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessGslTestO = 0;
//===============================================
static void GProcessGslTest_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessGslTest_New() {
	GProcessO* lParent = GProcess_New();
	GProcessGslTestO* lChild = (GProcessGslTestO*)malloc(sizeof(GProcessGslTestO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessGslTest_Delete;
	lParent->Run = GProcessGslTest_Run;
	return lParent;
}
//===============================================
void GProcessGslTest_Delete() {
	GProcess_Delete(m_GProcessGslTestO);
	m_GProcessGslTestO = 0;
}
//===============================================
GProcessO* GProcessGslTest() {
	if(m_GProcessGslTestO == 0) {
		m_GProcessGslTestO = GProcessGslTest_New();
	}
	return m_GProcessGslTestO;
}
//===============================================
static void GProcessGslTest_Run(int argc, char** argv) {
	double J0 = GGsl()->Bessel(5);
	GConsole()->Print("J0: %.2e\n", J0);
}
//===============================================
