//===============================================
#include "GProcessOpenGLTriangle.h"
#include "GGLFW.h"
#include "GOpenGL.h"
#include "GConsole.h"
//===============================================
static GProcessO* m_GProcessOpenGLTriangleO = 0;
//===============================================
static void GProcessOpenGLTriangle_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenGLTriangle_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenGLTriangleO* lChild = (GProcessOpenGLTriangleO*)malloc(sizeof(GProcessOpenGLTriangleO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenGLTriangle_Delete;
	lParent->Run = GProcessOpenGLTriangle_Run;
	return lParent;
}
//===============================================
void GProcessOpenGLTriangle_Delete() {
	GProcess_Delete(m_GProcessOpenGLTriangleO);
	m_GProcessOpenGLTriangleO = 0;
}
//===============================================
GProcessO* GProcessOpenGLTriangle() {
	if(m_GProcessOpenGLTriangleO == 0) {
		m_GProcessOpenGLTriangleO = GProcessOpenGLTriangle_New();
	}
	return m_GProcessOpenGLTriangleO;
}
//===============================================
static void GProcessOpenGLTriangle_Run(int argc, char** argv) {
    GGLFW()->Init();
    GGLFW()->CreateWindow("WINDOW", 400, 400, "OpenGL | ReadyDev");
    GGLFW()->MakeContext("WINDOW");
    while(1) {
        int lRes = GGLFW()->WindowClose("WINDOW");
        if(lRes == 1) break;
        GOpenGL()->Viewport("WINDOW");
        GOpenGL()->Clear(GL_COLOR_BUFFER_BIT);
		GOpenGL()->Projection();
		GOpenGL()->Ortho("WINDOW");
		GOpenGL()->ModelView();
		sGGrid lGrid = {
				5.0, 1.0, 1.0/10,
				1, {0.2, 0.2, 0.2, 1.0},
				2, {0.2, 0.2, 0.9, 1.0}
		};
        sGTriangle lTriangle = {
            {{-6, -6, 0.0},{6, -6, 0.0},{0.0, 6, 0.0}},
            {0.5, 0.0, 0.0, 1.0},
			lGrid.gridDiv, 1.0, 1.0, 0.0
        };
		GOpenGL()->DrawGrid(lGrid);
        GOpenGL()->DrawTriangle(lTriangle);
        GGLFW()->SwapBuffers("WINDOW");
        GGLFW()->PollEvents();
    }
    GGLFW()->DestroyWindow("WINDOW");
    GGLFW()->Terminate();
}
//===============================================
