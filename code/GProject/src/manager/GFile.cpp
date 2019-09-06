//================================================
#include "GFile.h"
//================================================
GFile* GFile::m_instance = 0;
//================================================
GFile::GFile() {

}
//================================================
GFile::~GFile() {
	
}
//================================================
GFile* GFile::Instance() {
	if(m_instance == 0) {
		m_instance = new GFile;
	}
	return m_instance;
}
//================================================
string GFile::readAll(const string &file) {
	ifstream lStream(file);
	string lBuffer((istreambuf_iterator<char>(lStream)), istreambuf_iterator<char>());
	return lBuffer;
}
//================================================
