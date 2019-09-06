//================================================
#ifndef _GOptions_
#define _GOptions_
//================================================
#include "GInclude.h"
//================================================
class GOptions {
private:
	GOptions();
	
public:
	~GOptions();
	static GOptions* Instance();
    void args(int argc, char** argv);

private:
	static GOptions* m_instance;
};
//================================================
#endif
//================================================
