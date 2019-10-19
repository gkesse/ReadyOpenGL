//===============================================
#include "GProcess.h"
#include "GProcessHelp.h"
#include "GProcessOpenGLTest.h"
#include "GProcessOpenGLPoint.h"
#include "GProcessOpenGLLine.h"
#include "GProcessOpenGLTriangle.h"
#include "GProcessOpenGLGrid.h"
#include "GProcessOpenGLSinus.h"
#include "GProcessOpenGLGaussian.h"
#include "GProcessOpenGLGaussian2D.h"
#include "GProcessOpenGLHeatMap.h"
#include "GProcessOpenGLEcgData.h"
#include "GString2.h"
#include "GConfig.h"
//===============================================
GProcessO* GProcess_New() {
    GProcessO* lObj = (GProcessO*)malloc(sizeof(GProcessO));
    lObj->m_child = 0;
    return lObj;
}
//===============================================
void GProcess_Delete(GProcessO* obj) {
    if(obj != 0) {
        if(obj->m_child != 0) {
            free(obj->m_child);
        }
        free(obj);
    }
}
//===============================================
GProcessO* GProcess() {
    char* lKey = GConfig()->GetData("PROCESS");
    if(GString2()->IsEqual(lKey, "HELP")) return GProcessHelp();
    if(GString2()->IsEqual(lKey, "OPENGL_TEST")) return GProcessOpenGLTest();
    if(GString2()->IsEqual(lKey, "OPENGL_POINT")) return GProcessOpenGLPoint();
    if(GString2()->IsEqual(lKey, "OPENGL_LINE")) return GProcessOpenGLLine();
    if(GString2()->IsEqual(lKey, "OPENGL_TRIANGLE")) return GProcessOpenGLTriangle();
    if(GString2()->IsEqual(lKey, "OPENGL_GRID")) return GProcessOpenGLGrid();
    if(GString2()->IsEqual(lKey, "OPENGL_SINUS")) return GProcessOpenGLSinus();
    if(GString2()->IsEqual(lKey, "OPENGL_GAUSSIAN")) return GProcessOpenGLGaussian();
    if(GString2()->IsEqual(lKey, "OPENGL_GAUSSIAN_2D")) return GProcessOpenGLGaussian2D();
    if(GString2()->IsEqual(lKey, "OPENGL_HEATMAP")) return GProcessOpenGLHeatMap();
    if(GString2()->IsEqual(lKey, "OPENGL_ECG")) return GProcessOpenGLEcgData();
    return GProcessHelp();
}
//===============================================
