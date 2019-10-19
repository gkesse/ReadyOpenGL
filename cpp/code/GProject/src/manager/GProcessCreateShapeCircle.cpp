//===============================================
#include "GProcessCreateShapeCircle.h"
//===============================================
GProcessCreateShapeCircle* GProcessCreateShapeCircle::m_instance = 0;
//===============================================
GProcessCreateShapeCircle::GProcessCreateShapeCircle() {

}
//===============================================
GProcessCreateShapeCircle::~GProcessCreateShapeCircle() {

}
//===============================================
GProcessCreateShapeCircle* GProcessCreateShapeCircle::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessCreateShapeCircle;
	}
	return m_instance;
}
//===============================================
void GProcessCreateShapeCircle::run(int argc, char** argv) {
	cout << "GProcessCreateShapeCircle" << "\n";
}
//===============================================
