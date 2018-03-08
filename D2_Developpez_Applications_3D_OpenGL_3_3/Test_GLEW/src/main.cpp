//================================================
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
//================================================
using namespace std;
//================================================
int main(int argc, char** argv) {
	cout << "GLEW Welcome\n";
	// On initialise GLEW
	GLenum m_ok = glewInit();
	
	if (m_ok == GLEW_OK) {
		cout << "SUCCESS: GLEW_OK\n";
	}
	else {
		cout << "ERROR: GLEW_OK\n";
	}

	if (GLEW_ARB_vertex_program) {
		cout << "SUCCESS: GLEW_ARB_vertex_program\n";
	}
	else {
		cout << "ERROR: GLEW_ARB_vertex_program\n";
	}
	
	return 0;
}
//================================================
