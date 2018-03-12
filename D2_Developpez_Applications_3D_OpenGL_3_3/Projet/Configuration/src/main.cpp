//================================================
#include "GConfig.h"
//================================================
int main(int argc, char** argv) {
	cout << "### Start GProject\n";
	string m_data;
	GConfig::Instance()->setData("draw", "GL_TRIANGLES");
	m_data = GConfig::Instance()->getData("draw");
	cout << "draw: " << m_data << "\n";
	GConfig::Instance()->setData("draw", "GL_QUADS");
	m_data = GConfig::Instance()->getData("draw");
	cout << "draw: " << m_data << "\n";
	cout << "### End GProject\n";
	return 0;
}
//================================================
