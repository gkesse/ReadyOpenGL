//================================================
#include "GVertex.h"
//================================================
GVertex* GVertex::m_instance = 0;
//================================================
GVertex::GVertex() {

}
//================================================
GVertex::~GVertex() {
	
}
//================================================
GVertex* GVertex::Instance() {
	if(m_instance == 0) {
		m_instance = new GVertex;
	}
	return m_instance;
}
//================================================
void GVertex::loadVertexGrid(GLfloat vertex[][2], const int& row) {
	int N = row/2;
	for(int i = 0; i < N; i += 2) {
		float dx = -1.0 + (i*2.0)/N;
		vertex[i][0] = dx;
		vertex[i][1] = -1.0;
		vertex[i + 1][0] = dx;
		vertex[i + 1][1] = 1.0;
	}
	
	for(int i = 0; i < N; i += 2) {
		float dy = -1.0 + (i*2.0)/N;
		vertex[N + i][0] = -1.0;
		vertex[N + i][1] = dy;
		vertex[N + i + 1][0] = 1.0;
		vertex[N + i + 1][1] = dy;
	}	
}
//================================================
