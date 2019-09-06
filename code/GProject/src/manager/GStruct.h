//================================================
#ifndef _GStruct_
#define _GStruct_
//================================================
typedef struct _sGVertex sGVertex;
typedef struct _sGColor sGColor;
typedef struct _sGTraingle sGTriangle;
//================================================
struct _sGVertex {
	double x, y, z;
};
//================================================
struct _sGColor {
	double r, g, b, a;
};
//================================================
struct _sGTraingle {
	int m_id;
	sGVertex m_vertex[3];
	sGColor m_color[3];
};
//================================================
#endif
//================================================
