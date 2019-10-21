//===============================================
#ifndef _GStruct_
#define _GStruct_
//===============================================
typedef struct _sGWindow sGWindow;
typedef struct _sGVertex sGVertex;
typedef struct _sGColor sGColor;
typedef struct _sGPoint sGPoint;
typedef struct _sGLine sGLine;
typedef struct _sGTriangle sGTriangle;
typedef struct _sGGrid sGGrid;
typedef struct _sGFunction sGFunction;
typedef struct _sGFunctionData sGFunctionData;
typedef struct _sGFunction2D sGFunction2D;
typedef struct _sGSinus sGSinus;
typedef struct _sGGaussian sGGaussian;
typedef struct _sGGaussian2D sGGaussian2D;
typedef struct _sGData sGData;
typedef struct _sGDataTab sGDataTab;
typedef struct _sGData2D sGData2D;
typedef struct _sGVertexDiv sGVertexDiv;
typedef struct _sGKey sGKey;
typedef struct _sGFrame sGFrame;
typedef struct _sGMouse sGMouse;
typedef struct _sGCursor sGCursor;
typedef struct _sGScroll sGScroll;
typedef struct _sGEvent sGEvent;
typedef struct _sGTranslate sGTranslate;
typedef struct _sGRotate sGRotate;
typedef struct _sGDiv sGDiv;
typedef struct _sGDirection sGDirection;
typedef struct _sGCamera sGCamera;
//===============================================
struct _sGWindow {
	char* name;
    char* title;
    int width;
    int height;
    GOPENGL_UPDATE_CALLBACK update;
};
//===============================================
struct _sGVertex {
    double x, y, z;
};
//===============================================
struct _sGColor {
    double r, g, b, a;
};
//===============================================
struct _sGPoint {
    sGVertex vertex;
    sGColor color;
    double size;
    double gridDiv;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGLine {
    sGVertex vertex[2];
    sGColor color;
    double width;
    double gridDiv;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGTriangle {
    sGVertex vertex[3];
    sGColor color;
    double gridDiv;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGGrid {
    double width;
    double hight;
    double gridDiv;
    double gridLine;
    sGColor gridColor;
    double axisLine;
    sGColor axisColor;
};
//===============================================
struct _sGFunction {
    double xMin;
    double xMax;
    int nMax;
    sGColor pointColor;
    sGColor lineColor;
    double pointSize;
    double lineWidth;
    GFUNCTION func;
    void* params;
    sGVertex* data;
    double gridDiv;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGFunctionData {
    double xMin;
    double xMax;
    int nMax;
    sGColor pointColor;
    sGColor lineColor;
    double pointSize;
    double lineWidth;
    GFUNCTION func;
    void* params;
    sGVertex* data;
    double* tab;
    double gridDiv;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGFunction2D {
    double xMin;
    double xMax;
    double yMin;
    double yMax;
    int xNmax;
    int yNmax;
    sGColor pointColor;
    sGColor lineColor;
    double pointSize;
    double lineWidth;
    GFUNCTION_2D func;
    void* params;
    sGVertex* data;
    double gridDiv;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGSinus {
    double yMax;
    double freq;
    double phi0;
};
//===============================================
struct _sGGaussian {
    double sigma;
    double mu;
};
//===============================================
struct _sGGaussian2D {
    double sigmaX;
    double sigmaY;
    double x0;
    double y0;
};
//===============================================
struct _sGData {
    sGVertex* data;
    sGColor pointColor;
    sGColor lineColor;
    int nMax;
    double pointSize;
    double lineWidth;
    double gridDiv;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGDataTab {
    double* data;
    int nMax;
    double xMin;
    double xMax;
    double yOffset;
    sGColor pointColor;
    sGColor lineColor;
    double pointSize;
    double lineWidth;
    double gridDiv;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGData2D {
    sGVertex* data;
    double pointSize;
    int xNmax;
    int yNmax;
    double gridDiv;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGVertexDiv {
    sGVertex vertex;
    double divGrid;
    double xDiv;
    double yDiv;
    double zDiv;
};
//===============================================
struct _sGKey {
	int key;
	int scancode;
	int action;
	int mods;
	int onFlag;
};
//===============================================
struct _sGFrame {
	int width;
	int height;
	int onFlag;
};
//===============================================
struct _sGMouse {
	int button;
	int action;
	int mods;
	int onFlag;
};
//===============================================
struct _sGCursor {
	int x;
	int y;
	int onFlag;
};
//===============================================
struct _sGScroll {
	double x;
	double y;
	int onFlag;
};
//===============================================
struct _sGEvent {
	sGKey key;
	sGFrame frame;
	sGMouse mouse;
	sGCursor cursor;
	sGScroll scroll;
};
//===============================================
struct _sGTranslate {
	double x;
	double y;
	double z;
};
//===============================================
struct _sGRotate {
	double x;
	double y;
	double z;
};
//===============================================
struct _sGDiv {
	double x;
	double y;
	double z;
};
//===============================================
struct _sGDirection {
	sGTranslate tra;
	sGRotate rot;
	sGDiv div;
};
//===============================================
struct _sGCamera {
	double fovY;
	double zNear;
	double zFar;
};
//===============================================
#endif
//===============================================
