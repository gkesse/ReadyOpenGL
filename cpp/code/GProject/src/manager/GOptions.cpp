//================================================
#include "GOptions.h"
#include "GConfig.h"
#include "GString.h"
//================================================
GOptions* GOptions::m_instance = 0;
//================================================
GOptions::GOptions() {

}
//================================================
GOptions::~GOptions() {
	
}
//================================================
GOptions* GOptions::Instance() {
	if(m_instance == 0) {
		m_instance = new GOptions;
	}
	return m_instance;
}
//================================================
void GOptions::args(int argc, char** argv) {
	bool lShowHelp = true;

	if(argc > 1) {
		lShowHelp = false;
		string lProcess = GString::Instance()->toUpper(argv[1]);
		GConfig::Instance()->setData("PROCESS", lProcess);
		if(lProcess == "CREATE_DATABASE_SQLITE") {
			lShowHelp = true;
			if(argc > 2) {
				lShowHelp = false;
				string lDatabaseID = GString::Instance()->toUpper(argv[2]);
				string lDatabaseName = GString::Instance()->toLower(argv[2]);
				GConfig::Instance()->setData("DATABASE_ID", lDatabaseID);
				GConfig::Instance()->setData("DATABASE_NAME", lDatabaseName);
			}
		}
	}

	if(lShowHelp == true) {
		GConfig::Instance()->setData("PROCESS", "HELP");
	}
}
//================================================
