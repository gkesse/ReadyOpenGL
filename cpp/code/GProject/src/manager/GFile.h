//================================================
#ifndef _GFile_
#define _GFile_
//================================================
#include "GInclude.h"
//================================================
class GFile {
private:
	GFile();
	
public:
	~GFile();
	static GFile* Instance();
    string readAll(const string &file);

private:
	static GFile* m_instance;
};
//================================================
#endif
//================================================
