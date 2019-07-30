//===============================================
#include "GProcess.h"
#include "GProcessTriangle.h"
#include "GConfig.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess() {

}
//===============================================
GProcess::~GProcess() {

}
//===============================================
GProcess* GProcess::Instance() {
    string lKey = GConfig::Instance()->getData("PROCESS");
    if(lKey == "TRIANGLE") return GProcessTriangle::Instance();
    return GProcessTriangle::Instance();
}
//===============================================
