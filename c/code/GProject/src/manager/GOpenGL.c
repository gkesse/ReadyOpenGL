//===============================================
#include "GOpenGL.h"
#include "GGLFW.h"
#include "GEvent.h"
#include "GFunction.h"
#include "GHeat.h"
#include "GConsole.h"
//===============================================
#define GDIRECTION_0 (sGDirection){{0.0, 0.0, -2.0}, {-70.0, 0.0, 210.0}, {1.0, 1.0, 1.0}};
//===============================================
static GOpenGLO* m_GOpenGLO = 0;
//===============================================
static void GOpenGL_Enable(int cap);
static void GOpenGL_Hint(int target, int mode);
static void GOpenGL_BlendFunc(int sfactor, int dfactor);
static void GOpenGL_Viewport(char* windowName);
static void GOpenGL_Clear(int mask);
static void GOpenGL_ClearColor(double r, double g, double b, double a);
static void GOpenGL_Projection();
static void GOpenGL_Ortho(char* windowName);
static void GOpenGL_Frustum(char* windowName, sGCamera camera);
static void GOpenGL_ModelView();
static void GOpenGL_Rotate(double angle, double x, double y, double z);
static void GOpenGL_Translate(double x, double y, double z);
static void GOpenGL_DrawPoint(sGPoint obj);
static void GOpenGL_DrawPoints(sGData obj);
static void GOpenGL_DrawDataTab(sGDataTab obj);
static void GOpenGL_DrawHeatMap(sGData2D obj);
static void GOpenGL_DrawHeatMapPoints(sGData2D obj);
static void GOpenGL_DrawMcml(sGMCML mcml);
static void GOpenGL_DrawMcmlSlice(sGMCML obj);
static void GOpenGL_DrawLine(sGLine obj);
static void GOpenGL_DrawLines(sGData obj);
static void GOpenGL_DrawTriangle(sGTriangle obj);
static void GOpenGL_DrawGrid(sGGrid obj);
static void GOpenGL_DrawOrigin();
static void GOpenGL_DrawFunction(sGFunction* obj);
static void GOpenGL_DrawFunction2D(sGFunction2D* obj);
static void GOpenGL_DrawFunctionHeatMap(sGFunction2D* obj);
static sGDirection* GOpenGL_GetDirection();
static void GOpenGL_SetDirection(sGDirection direction);
static void GOpenGL_InitDirection();
static void GOpenGL_CleanEvent();
static void GOpenGL_MainLoop(sGWindow* sWindow);
//===============================================
static sGVertex GOpenGL_VertexDiv(sGVertexDiv vertex);
//===============================================
GOpenGLO* GOpenGL_New() {
    GOpenGLO* lObj = (GOpenGLO*)malloc(sizeof(GOpenGLO));

    lObj->m_direction0 = GDIRECTION_0;
    lObj->m_direction = lObj->m_direction0;

    lObj->Delete = GOpenGL_Delete;
    lObj->Enable = GOpenGL_Enable;
    lObj->Hint = GOpenGL_Hint;
    lObj->BlendFunc = GOpenGL_BlendFunc;
    lObj->Viewport = GOpenGL_Viewport;
    lObj->Clear = GOpenGL_Clear;
    lObj->ClearColor = GOpenGL_ClearColor;
    lObj->Projection = GOpenGL_Projection;
    lObj->Ortho = GOpenGL_Ortho;
    lObj->Frustum = GOpenGL_Frustum;
    lObj->ModelView = GOpenGL_ModelView;
    lObj->Rotate = GOpenGL_Rotate;
    lObj->Translate = GOpenGL_Translate;
    lObj->DrawPoint = GOpenGL_DrawPoint;
    lObj->DrawPoints = GOpenGL_DrawPoints;
    lObj->DrawDataTab = GOpenGL_DrawDataTab;
    lObj->DrawHeatMap = GOpenGL_DrawHeatMap;
    lObj->DrawHeatMapPoints = GOpenGL_DrawHeatMapPoints;
    lObj->DrawMcml = GOpenGL_DrawMcml;
    lObj->DrawMcmlSlice = GOpenGL_DrawMcmlSlice;
    lObj->DrawLine = GOpenGL_DrawLine;
    lObj->DrawLines = GOpenGL_DrawLines;
    lObj->DrawTriangle = GOpenGL_DrawTriangle;
    lObj->DrawGrid = GOpenGL_DrawGrid;
    lObj->DrawOrigin = GOpenGL_DrawOrigin;
    lObj->DrawFunction = GOpenGL_DrawFunction;
    lObj->DrawFunction2D = GOpenGL_DrawFunction2D;
    lObj->DrawFunctionHeatMap = GOpenGL_DrawFunctionHeatMap;
    lObj->GetDirection = GOpenGL_GetDirection;
    lObj->SetDirection = GOpenGL_SetDirection;
    lObj->InitDirection = GOpenGL_InitDirection;
    lObj->CleanEvent = GOpenGL_CleanEvent;
    lObj->MainLoop = GOpenGL_MainLoop;
    return lObj;
}
//===============================================
void GOpenGL_Delete() {
    GOpenGLO* lObj = GOpenGL();
    if(lObj != 0) {
        free(lObj);
    }
    m_GOpenGLO = 0;
}
//===============================================
GOpenGLO* GOpenGL() {
    if(m_GOpenGLO == 0) {
        m_GOpenGLO = GOpenGL_New();
    }
    return m_GOpenGLO;
}
//===============================================
static void GOpenGL_Enable(int cap) {
#if defined(__WIN32)
    glEnable(cap);
#endif
}
//===============================================
static void GOpenGL_Hint(int target, int mode) {
#if defined(__WIN32)
    glHint(target, mode);
#endif
}
//===============================================
static void GOpenGL_BlendFunc(int sfactor, int dfactor) {
#if defined(__WIN32)
    glBlendFunc(sfactor, dfactor);
#endif
}
//===============================================
static void GOpenGL_Viewport(char* windowName) {
#if defined(__WIN32)
    int lWidth;
    int lHeight;
    GGLFW()->FrameSize(windowName, &lWidth, &lHeight);
    glViewport(0, 0, lWidth, lHeight);
#endif
}
//===============================================
static void GOpenGL_Clear(int mask) {
#if defined(__WIN32)
    glClear(mask);
#endif
}
//===============================================
static void GOpenGL_ClearColor(double r, double g, double b, double a) {
    glClearColor(r, g, b, a);
}
//===============================================
static void GOpenGL_Projection() {
#if defined(__WIN32)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#endif
}
//===============================================
static void GOpenGL_Ortho(char* windowName) {
#if defined(__WIN32)
    int lWidth;
    int lHeight;
    GGLFW()->FrameSize(windowName, &lWidth, &lHeight);
    double lRatio = (double)lWidth/lHeight;
    glOrtho(-lRatio, lRatio, -1.0, 1.0, 1.0, -1.0);
#endif
}
//===============================================
static void GOpenGL_Frustum(char* windowName, sGCamera camera) {
#if defined(__WIN32)
    int lWidth;
    int lHeight;
    GGLFW()->FrameSize(windowName, &lWidth, &lHeight);
    double lRatio = (double)lWidth/lHeight;

    double lFovY = camera.fovY;
    double lNear = camera.zNear;
    double lFar = camera.zFar;

    double lTangent = tan((lFovY/2.0)*(M_PI/180.0));
    double lHeightF = lTangent*lNear;
    double lWidthF = lHeightF*lRatio;

    glFrustum(-lWidthF, lWidthF, -lHeightF, lHeightF, lNear, lFar);
#endif
}
//===============================================
static void GOpenGL_ModelView() {
#if defined(__WIN32)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
#endif
}
//===============================================
static void GOpenGL_Rotate(double angle, double x, double y, double z) {
#if defined(__WIN32)
    glRotated(angle, x, y, z);
#endif
}
//===============================================
static void GOpenGL_Translate(double x, double y, double z) {
#if defined(__WIN32)
    glTranslated(x, y, z);
#endif
}
//===============================================
static void GOpenGL_DrawPoint(sGPoint obj) {
#if defined(__WIN32)
    double lSize = obj.size;
    glPointSize(lSize);
    glBegin(GL_POINTS);
    sGVertexDiv lVertexDiv = {obj.vertex , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
    sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
    sGColor lColor = obj.color;
    glColor4d(lColor.r, lColor.g, lColor.b, lColor.a);
    glVertex3d(lVertex.x, lVertex.y, lVertex.z);
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawPoints(sGData obj) {
#if defined(__WIN32)
    sGColor lColor = obj.pointColor;
    int lNmax = obj.nMax;
    double lPointSize = obj.pointSize;

    glPointSize(lPointSize);

    glBegin(GL_POINTS);
    glColor4d(lColor.r, lColor.g, lColor.b, lColor.a);
    for(int i = 0; i < lNmax; i++) {
        sGVertexDiv lVertexDiv = {obj.data[i] , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
        sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
        glVertex3d(lVertex.x, lVertex.y, lVertex.z);
    }
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawDataTab(sGDataTab obj) {
#if defined(__WIN32)
    double lxMin = obj.xMin;
    double lxMax = obj.xMax;
    int lNmax = obj.nMax;
    double lDx = (lxMax - lxMin) / (lNmax - 1);
    sGColor lColor = obj.lineColor;
    double lLineWidth = obj.lineWidth;

    glLineWidth(lLineWidth);

    glBegin(GL_LINE_STRIP);
    glColor4d(lColor.r, lColor.g, lColor.b, lColor.a);
    double lX = lxMin;
    for(int i = 0; i < lNmax; i++) {
        double lY = obj.data[i] + obj.yOffset;
        sGVertex lData = {lX, lY, 0.0};
        sGVertexDiv lVertexDiv = {lData, obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
        sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
        glVertex3d(lVertex.x, lVertex.y, lVertex.z);
        lX += lDx;
    }
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawHeatMap(sGData2D obj) {
#if defined(__WIN32)
    int lxNmax = obj.xNmax;
    int lyNmax = obj.yNmax;
    int lNmax = lxNmax*lyNmax;
    double lZmin = GFunction()->Min(obj.data, lNmax, 2);
    double lZmax = GFunction()->Max(obj.data, lNmax, 2);

    double lPointSize = obj.pointSize;

    glPointSize(lPointSize);

    glBegin(GL_POINTS);
    for(int i = 0; i < lNmax; i++) {
        sGHeat lHeat = {
                obj.data[i].z, lZmin, lZmax, {0}
        };
        GHeat()->HeatColor(&lHeat);

        sGVertexDiv lVertexDiv = {obj.data[i] , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
        sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
        glColor4d(lHeat.iColor.r, lHeat.iColor.g, lHeat.iColor.b, obj.alpha);
        glVertex3d(lVertex.x, lVertex.y, 0.0);
    }
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawHeatMapPoints(sGData2D obj) {
#if defined(__WIN32)
    int lxNmax = obj.xNmax;
    int lyNmax = obj.yNmax;
    int lNmax = lxNmax*lyNmax;
    double lZmin = GFunction()->Min(obj.data, lNmax, 2);
    double lZmax = GFunction()->Max(obj.data, lNmax, 2);

    double lPointSize = obj.pointSize;

    glPointSize(lPointSize);

    glBegin(GL_POINTS);
    for(int i = 0; i < lNmax; i++) {
        sGHeat lHeat = {
                obj.data[i].z, lZmin, lZmax, {0}
        };
        GHeat()->HeatColor(&lHeat);

        sGVertexDiv lVertexDiv = {obj.data[i] , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
        sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
        glColor4d(lHeat.iColor.r, lHeat.iColor.g, lHeat.iColor.b, obj.alpha);
        glVertex3d(lVertex.x, lVertex.y, lVertex.z);
    }
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawMcml(sGMCML obj) {
#if defined(__WIN32)
    glPointSize(obj.pointSize);

    glBegin(GL_POINTS);
    for(int z = 0; z < obj.zNmax; z++) {
        for(int x = 0; x < obj.xNmax; x++) {
            for(int y = 0; y < obj.yNmax; y++) {
                int k = z;
                k += y*GMCML_BUFFER_Z;
                k += x*GMCML_BUFFER_Y*GMCML_BUFFER_Z;

                sGVertexDiv lVertexDiv = {obj.vertex[k] , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
                sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
                glColor4d(obj.color[k].r, obj.color[k].g, obj.color[k].b, obj.alpha);
                glVertex3d(lVertex.x, lVertex.y, lVertex.z);
            }
        }
    }
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawMcmlSlice(sGMCML obj) {
#if defined(__WIN32)
    glPointSize(obj.sliceSize);

    glBegin(GL_POINTS);
    // xy
    for(int x = 0; x < obj.xNmax; x++) {
        for(int y = 0; y < obj.yNmax; y++) {
            int z = obj.sliceZ;
            int k = z;
            k += y*GMCML_BUFFER_Z;
            k += x*GMCML_BUFFER_Y*GMCML_BUFFER_Z;

            sGVertexDiv lVertexDiv = {obj.vertex[k] , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
            sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
            glColor4d(obj.color[k].r, obj.color[k].g, obj.color[k].b, obj.sliceAlpha);
            glVertex3d(lVertex.x, lVertex.y, lVertex.z);
        }
    }
    // xz
    for(int z = 0; z < obj.zNmax; z++) {
        for(int y = 0; y < obj.yNmax; y++) {
            int x = obj.sliceX;
            int k = z;
            k += y*GMCML_BUFFER_Z;
            k += x*GMCML_BUFFER_Y*GMCML_BUFFER_Z;

            sGVertexDiv lVertexDiv = {obj.vertex[k] , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
            sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
            glColor4d(obj.color[k].r, obj.color[k].g, obj.color[k].b, obj.sliceAlpha);
            glVertex3d(lVertex.x, lVertex.y, lVertex.z);
        }
    }
    // yz
    for(int z = 0; z < obj.zNmax; z++) {
        for(int x = 0; x < obj.xNmax; x++) {
            int y = obj.sliceY;
            int k = z;
            k += y*GMCML_BUFFER_Z;
            k += x*GMCML_BUFFER_Y*GMCML_BUFFER_Z;

            sGVertexDiv lVertexDiv = {obj.vertex[k] , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
            sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
            glColor4d(obj.color[k].r, obj.color[k].g, obj.color[k].b, obj.sliceAlpha);
            glVertex3d(lVertex.x, lVertex.y, lVertex.z);
        }
    }
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawLine(sGLine obj) {
#if defined(__WIN32)
    double lWidth = obj.width;
    sGColor lColor = obj.color;

    glLineWidth(lWidth);

    glBegin(GL_LINES);
    glColor4d(lColor.r, lColor.g, lColor.b, lColor.a);
    for(int i = 0; i < 2; i++) {
        sGVertexDiv lVertexDiv = {obj.vertex[i], obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
        sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
        glVertex3d(lVertex.x, lVertex.y, lVertex.z);
    }
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawLines(sGData obj) {
#if defined(__WIN32)
    double lLineWidth = obj.lineWidth;
    sGColor lColor = obj.lineColor;
    int lNmax = obj.nMax;

    glLineWidth(lLineWidth);

    glBegin(GL_LINE_STRIP);
    glColor4d(lColor.r, lColor.g, lColor.b, lColor.a);
    for(int i = 0; i < lNmax; i++) {
        sGVertexDiv lVertexDiv = {obj.data[i] , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
        sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
        glVertex3d(lVertex.x, lVertex.y, lVertex.z);
    }
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawTriangle(sGTriangle obj) {
#if defined(__WIN32)
    sGColor lColor = obj.color;
    glBegin(GL_TRIANGLES);
    glColor4d(lColor.r, lColor.g, lColor.b, lColor.a);
    for(int i = 0; i < 3; i++) {
        sGVertexDiv lVertexDiv = {obj.vertex[i] , obj.gridDiv, obj.xDiv, obj.yDiv, obj.zDiv};
        sGVertex lVertex = GOpenGL_VertexDiv(lVertexDiv);
        glVertex3d(lVertex.x, lVertex.y, lVertex.z);
    }
    glEnd();
#endif
}
//===============================================
static void GOpenGL_DrawGrid(sGGrid obj) {
#if defined(__WIN32)
    double lWidth = obj.width;
    double lHeight = obj.hight;
    double lGridDiv = obj.gridDiv;
    double lGridLine = obj.gridLine;
    sGColor lGridColor = obj.gridColor;
    double lAxisLine = obj.axisLine;
    sGColor lAxisColor = obj.axisColor;

    for(double y = -lHeight; y <= lHeight; y += lGridDiv) {
        sGLine lLine = {
                {{-lWidth, y, 0.0}, {lWidth, y, 0.0}},
                lGridColor, lGridLine,
                1.0, 1.0, 1.0, 1.0
        };
        GOpenGL_DrawLine(lLine);
    }
    for(double x = -lWidth; x <= lWidth; x += lGridDiv) {
        sGLine lLine = {
                {{x, -lHeight, 0.0}, {x, lHeight, 0.0}},
                lGridColor,    lGridLine,
                1.0, 1.0, 1.0, 1.0
        };
        GOpenGL_DrawLine(lLine);
    }

    sGLine lAxisX = {
            {{-lWidth, 0.0, 0.0}, {lWidth, 0.0, 0.0}},
            lAxisColor, lAxisLine,
            1.0, 1.0, 1.0, 1.0
    };
    GOpenGL_DrawLine(lAxisX);

    sGLine lAxisY = {
            {{0.0, -lHeight, 0.0}, {0.0, lHeight, 0.0}},
            lAxisColor,    lAxisLine,
            1.0, 1.0, 1.0, 1.0
    };
    GOpenGL_DrawLine(lAxisY);
#endif
}
//===============================================
static void GOpenGL_DrawOrigin() {
#if defined(__WIN32)
    double lLineWidth = 5.0;
    double lAxisWidth = 5.0;
    double lTransparency = 0.5;

    sGLine lAxisX = {
            {{0.0, 0.0, 0.0}, {lAxisWidth, 0.0, 0.0}},
            {1.0, 0.0, 0.0, lTransparency}, lLineWidth,
            1.0, 1.0, 1.0, 1.0
    };
    GOpenGL_DrawLine(lAxisX);

    sGLine lAxisY = {
            {{0.0, 0.0, 0.0}, {0.0, lAxisWidth, 0.0}},
            {0.0, 1.0, 0.0, lTransparency}, lLineWidth,
            1.0, 1.0, 1.0, 1.0
    };
    GOpenGL_DrawLine(lAxisY);

    sGLine lAxisZ = {
            {{0.0, 0.0, 0.0}, {0.0, 0.0, lAxisWidth}},
            {0.0, 0.0, 1.0, lTransparency}, lLineWidth,
            1.0, 1.0, 1.0, 1.0
    };
    GOpenGL_DrawLine(lAxisZ);

#endif
}
//===============================================
static void GOpenGL_DrawFunction(sGFunction* obj) {
#if defined(__WIN32)
    GFunction()->Compute(obj);
    sGData lData = {
            obj->data,
            obj->pointColor,
            obj->lineColor,
            obj->nMax,
            obj->pointSize,
            obj->lineWidth,
            obj->gridDiv,
            obj->xDiv,
            obj->yDiv,
            obj->zDiv
    };
    GOpenGL_DrawLines(lData);
    GOpenGL_DrawPoints(lData);
    GFunction()->Free(obj->data);
#endif
}
//===============================================
static void GOpenGL_DrawFunction2D(sGFunction2D* obj) {
#if defined(__WIN32)
    GFunction()->Compute2D(obj);
    sGData2D lData = {
            obj->data,
            obj->pointSize,
            obj->xNmax,
            obj->yNmax,
            obj->gridDiv,
            obj->xDiv,
            obj->yDiv,
            obj->zDiv
    };
    GOpenGL_DrawHeatMap(lData);
    GFunction()->Free(obj->data);
#endif
}
//===============================================
static void GOpenGL_DrawFunctionHeatMap(sGFunction2D* obj) {
#if defined(__WIN32)
    GFunction()->Compute2D(obj);
    sGData2D lData = {
            obj->data,
            obj->pointSize,
            obj->alpha,
            obj->xNmax,
            obj->yNmax,
            obj->gridDiv,
            obj->xDiv,
            obj->yDiv,
            obj->zDiv
    };
    GOpenGL_DrawHeatMapPoints(lData);
    GFunction()->Free(obj->data);
#endif
}
//===============================================
static sGDirection* GOpenGL_GetDirection() {
#if defined(__WIN32)
    return &m_GOpenGLO->m_direction;
#endif
}
//===============================================
static void GOpenGL_SetDirection(sGDirection direction) {
#if defined(__WIN32)
    m_GOpenGLO->m_direction0 = direction;
    m_GOpenGLO->m_direction = m_GOpenGLO->m_direction0;
#endif
}
//===============================================
static void GOpenGL_InitDirection() {
#if defined(__WIN32)
    sGDirection* lDirection = GOpenGL_GetDirection();
    sGEvent* lEvent = GEvent()->GetEvent();

    GOpenGL()->Translate(lDirection->tra.x, lDirection->tra.y, lDirection->tra.z);
    GOpenGL()->Rotate(lDirection->rot.x, 1.0, 0.0, 0.0);
    GOpenGL()->Rotate(lDirection->rot.y, 0.0, 1.0, 0.0);
    GOpenGL()->Rotate(lDirection->rot.z, 0.0, 0.0, 1.0);

    if(lEvent->key.onFlag == TRUE) {
        //GConsole()->Print("[ KEY ] : %d\n", lEvent->key.key);

        if(lEvent->key.action == GLFW_PRESS) {
            switch(lEvent->key.key ) {
            // Rotation suivant -x
            case GLFW_KEY_UP:
                lDirection->rot.x -= 10.0;
                if(lDirection->rot.x <= -360.0) lDirection->rot.x = 0.0;
                break;
                // Rotation suivant +x
            case GLFW_KEY_DOWN:
                lDirection->rot.x += 10.0;
                if(lDirection->rot.x >= 360.0) lDirection->rot.x = 0.0;
                break;
                // Rotation suivant -y
            case GLFW_KEY_LEFT:
                lDirection->rot.y -= 10.0;
                if(lDirection->rot.y <= -360.0) lDirection->rot.y = 0.0;
                break;
                // Rotation suivant +y
            case GLFW_KEY_RIGHT:
                lDirection->rot.y += 10.0;
                if(lDirection->rot.y >= 360.0) lDirection->rot.y = 0.0;
                break;
                // Rotation suivant -z
            case GLFW_KEY_RIGHT_ALT:
                lDirection->rot.z -= 10.0;
                if(lDirection->rot.z <= -360.0) lDirection->rot.z = 0.0;
                break;
                // Rotation suivant +z
            case GLFW_KEY_RIGHT_CONTROL:
                lDirection->rot.z += 10.0;
                if(lDirection->rot.z >= 360.0) lDirection->rot.z = 0.0;
                break;
                // Translation suivant -x
            case GLFW_KEY_A:
                lDirection->tra.x -= 0.02;
                if(lDirection->tra.x <= -10.0) lDirection->tra.x = -10.0;
                break;
                // Translation suivant +x
            case GLFW_KEY_S:
                lDirection->tra.x += 0.02;
                if(lDirection->tra.x >= 10.0) lDirection->tra.x = 10.0;
                break;
                // Translation suivant -y
            case GLFW_KEY_Z:
                lDirection->tra.y -= 0.02;
                if(lDirection->tra.y <= -10.0) lDirection->tra.y = -10.0;
                break;
                // Translation suivant +y
            case GLFW_KEY_W:
                lDirection->tra.y += 0.02;
                if(lDirection->tra.y >= 10.0) lDirection->tra.y = 10.0;
                break;
                // Translation suivant -z
            case GLFW_KEY_X:
                lDirection->tra.z -= 0.02;
                if(lDirection->tra.z <= -100.0) lDirection->tra.z = -100.0;
                break;
                // Translation suivant +z
            case GLFW_KEY_Q:
                lDirection->tra.z += 0.02;
                if(lDirection->tra.z >= 100.0) lDirection->tra.z = 100.0;
                break;
                // Variation suivant -divX
            case GLFW_KEY_D:
                lDirection->div.x -= 0.25;
                if(lDirection->div.x <= -25.0) lDirection->div.x = -25.0;
                break;
                // Variation suivant +divX
            case GLFW_KEY_F:
                lDirection->div.x += 0.25;
                if(lDirection->div.x >= 25.0) lDirection->div.x = 25.0;
                break;
                // Variation suivant -divY
            case GLFW_KEY_C:
                lDirection->div.y -= 0.25;
                if(lDirection->div.y <= -25.0) lDirection->div.y = -25.0;
                break;
                // Variation suivant +divY
            case GLFW_KEY_R:
                lDirection->div.y += 0.25;
                if(lDirection->div.y >= 25.0) lDirection->div.y = 25.0;
                break;
                // Variation suivant -divZ
            case GLFW_KEY_E:
                lDirection->div.z -= 0.25;
                if(lDirection->div.z <= -25.0) lDirection->div.z = -25.0;
                break;
                // Variation suivant +divZ
            case GLFW_KEY_V:
                lDirection->div.z += 0.25;
                if(lDirection->div.z >= 25.0) lDirection->div.z = 25.0;
                break;
                // Initialisation de la direction
            case GLFW_KEY_MENU:
                *lDirection = m_GOpenGLO->m_direction0;
                break;
            }
        }
    }
#endif
}
//===============================================
static void GOpenGL_CleanEvent() {
#if defined(__WIN32)
    sGEvent* lEvent = GEvent()->GetEvent();

    lEvent->key.onFlag = FALSE;
    lEvent->frame.onFlag = FALSE;
    lEvent->mouse.onFlag = FALSE;
    lEvent->cursor.onFlag = FALSE;
    lEvent->scroll.onFlag = FALSE;
#endif
}
//===============================================
static void GOpenGL_MainLoop(sGWindow* sWindow) {
#if defined(__WIN32)
    char* lWindowName = sWindow->name;
    int lWidth = sWindow->width;
    int lHeight = sWindow->height;
    char* lTitle = sWindow->title;

    GGLFW()->Init();
    GGLFW()->CreateWindow(lWindowName, lWidth, lHeight, lTitle);

    GGLFW()->KeyCallback(lWindowName, GEvent()->KeyCallBack);
    GGLFW()->FrameCallback(lWindowName, GEvent()->FrameCallBack);
    GGLFW()->MouseCallback(lWindowName, GEvent()->MouseCallBack);
    GGLFW()->CursorCallback(lWindowName, GEvent()->CursorCallBack);
    GGLFW()->ScrollCallback(lWindowName, GEvent()->ScrollCallBack);

    GGLFW()->MakeContext(lWindowName);
    GGLFW()->SwapInterval(1);

    GOpenGL()->Enable(GL_BLEND);
    GOpenGL()->Enable(GL_LINE_SMOOTH);
    GOpenGL()->Enable(GL_POINT_SMOOTH);
    GOpenGL()->Enable(GL_ALPHA_TEST);

    GOpenGL()->Hint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    GOpenGL()->Hint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    GOpenGL()->BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while(1) {
        int lRes = GGLFW()->WindowClose(lWindowName);
        if(lRes == 1) break;

        sWindow->update(sWindow);
        GOpenGL()->CleanEvent();

        GGLFW()->SwapBuffers(lWindowName);
        GGLFW()->PollEvents();
    }

    GGLFW()->DestroyWindow(lWindowName);
    GGLFW()->Terminate();
#endif
}
//===============================================
static sGVertex GOpenGL_VertexDiv(sGVertexDiv vertex) {
#if defined(__WIN32)
    sGVertex lVertex = {
            vertex.vertex.x * vertex.divGrid * vertex.xDiv,
            vertex.vertex.y * vertex.divGrid * vertex.yDiv,
            vertex.vertex.z * vertex.divGrid * vertex.zDiv
    };
    return lVertex;
#endif
}
//===============================================
