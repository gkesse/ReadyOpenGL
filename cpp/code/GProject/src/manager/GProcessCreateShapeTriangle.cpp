//===============================================
#include "GProcessCreateShapeTriangle.h"
//===============================================
GProcessCreateShapeTriangle* GProcessCreateShapeTriangle::m_instance = 0;
//===============================================
GProcessCreateShapeTriangle::GProcessCreateShapeTriangle() {

}
//===============================================
GProcessCreateShapeTriangle::~GProcessCreateShapeTriangle() {

}
//===============================================
GProcessCreateShapeTriangle* GProcessCreateShapeTriangle::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessCreateShapeTriangle;
	}
	return m_instance;
}
//===============================================
void GProcessCreateShapeTriangle::run(int argc, char** argv) {


	cout << "[ INFO ] creation d'un triangle" << "\n";
}
//===============================================
