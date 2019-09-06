//===============================================
#include "GProcessHelp.h"
//===============================================
GProcessHelp* GProcessHelp::m_instance = 0;
//===============================================
GProcessHelp::GProcessHelp() {

}
//===============================================
GProcessHelp::~GProcessHelp() {

}
//===============================================
GProcessHelp* GProcessHelp::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessHelp;
	}
	return m_instance;
}
//===============================================
void GProcessHelp::run(int argc, char **argv) {
	cout << "ReadyOpenGL est une application de traitements de formes 3D...\n";
	cout << "\n";
	cout << "Utilisation:\n";
	cout << "\tReadyOpenGL [ Process ] [ Options ] [ Arguments ]\n";
	cout << "\n";
	cout << "Process:\n";
	cout << left << setw(10) << "\tHelp:"  << "\tAfficher les informations d'aide" << "\n";
	cout << left << setw(10) << "\tCreate:" << "\tCree une forme 3D" << "\n";
	cout << "\n";
	cout << "Create:\n";
	cout << left << setw(10) << "\tTriangle:" << "\tCree un triangle dans l'espace" << "\n";
	cout << "\n";
}
//===============================================
