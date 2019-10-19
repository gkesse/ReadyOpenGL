//===============================================
#include "GFunction.h"
#include "GConsole.h"
//===============================================
static GFunctionO* m_GFunctionO = 0;
//===============================================
static void GFunction_Compute(sGFunction* func);
static void GFunction_Compute2D(sGFunction2D* func);
//===============================================
static double GFunction_Sinus(double x, void* params);
static double GFunction_Gaussian(double x, void* params);
static double GFunction_Gaussian2D(double x, double y, void* params);
//===============================================
static double GFunction_Min(sGVertex* data, int nMax, int pos);
static double GFunction_Max(sGVertex* data, int nMax, int pos);
static void GFunction_Free(sGVertex* data);
//===============================================
GFunctionO* GFunction_New() {
	GFunctionO* lObj = (GFunctionO*)malloc(sizeof(GFunctionO));
	lObj->Delete = GFunction_Delete;
	lObj->Compute = GFunction_Compute;
	lObj->Compute2D = GFunction_Compute2D;
	lObj->Sinus = GFunction_Sinus;
	lObj->Gaussian = GFunction_Gaussian;
	lObj->Gaussian2D = GFunction_Gaussian2D;
	lObj->Min = GFunction_Min;
	lObj->Max = GFunction_Max;
	lObj->Free = GFunction_Free;
	return lObj;
}
//===============================================
void GFunction_Delete() {
	GFunctionO* lObj = GFunction();
	if(lObj != 0) {
		free(lObj);
	}
	m_GFunctionO = 0;
}
//===============================================
GFunctionO* GFunction() {
	if(m_GFunctionO == 0) {
		m_GFunctionO = GFunction_New();
	}
	return m_GFunctionO;
}
//===============================================
static void GFunction_Compute(sGFunction* func) {
	double lXmin = func->xMin;
	double lXmax = func->xMax;
	int lNmax = func->nMax;
	double lDx = (lXmax - lXmin)/(lNmax - 1);
	func->data = (sGVertex*)malloc(sizeof(sGVertex)*(lNmax + 1));
	double lXi = lXmin;

	for(int i = 0; i < lNmax; i++) {
		func->data[i].x = lXi;
		func->data[i].y = func->func(lXi, func->params);
		lXi += lDx;
	}
}
//===============================================
static void GFunction_Compute2D(sGFunction2D* func) {
	double lXmin = func->xMin;
	double lXmax = func->xMax;
	double lYmin = func->yMin;
	double lYmax = func->yMax;
	int lxNmax = func->xNmax;
	int lyNmax = func->yNmax;
	int lNmax = lxNmax*lyNmax;
	double lDx = (lXmax - lXmin)/(lxNmax - 1);
	double lDy = (lYmax - lYmin)/(lyNmax - 1);
	func->data = (sGVertex*)malloc(sizeof(sGVertex)*lNmax);
	double lXi = lXmin;
	int k = 0;
	for(int i = 0; i < lxNmax; i++) {
		double lYi = lYmin;
		for(int j = 0; j < lyNmax; j++) {
			double lZi = func->func(lXi, lYi, func->params);
			func->data[k].x = lXi;
			func->data[k].y = lYi;
			func->data[k].z = lZi;
			lYi += lDy;
			k++;
		}
		lXi += lDx;
	}
}
//===============================================
static double GFunction_Sinus(double x, void* params) {
	sGSinus* lParams = (sGSinus*)params;
	double lYmax = lParams->yMax;
	double lFreq = lParams->freq;
	double lPhi0 = lParams->phi0;
	double lOmega = 2*M_PI*lFreq;
	double lPhi = lOmega*x - lPhi0;
	double lY = lYmax*sin(lPhi);
	return lY;
}
//===============================================
static double GFunction_Gaussian(double x, void* params) {
	sGGaussian* lParams = (sGGaussian*)params;
	double lSigma = lParams->sigma;
	double lMu = lParams->mu;
	double lYmax = 1.0/(lSigma*sqrt(2*M_PI));
	double lA = pow((x - lMu), 2)/(2*pow(lSigma, 2));
	double lY = lYmax*exp(-lA);
	return lY;
}
//===============================================
static double GFunction_Gaussian2D(double x, double y, void* params) {
	sGGaussian2D* lParams = (sGGaussian2D*)params;
	double lSigmaX = lParams->sigmaX;
	double lSigmaY = lParams->sigmaY;
	double lX0 = lParams->x0;
	double lY0 = lParams->y0;
	double lZmax = 1.0/(lSigmaX*lSigmaY*sqrt(2*M_PI));
	double lAx = pow((x - lX0), 2)/(2*pow(lSigmaX, 2));
	double lAy = pow((y - lY0), 2)/(2*pow(lSigmaY, 2));
	double lA = lAx + lAy;
	double lZ = lZmax*exp(-lA);
	return lZ;
}
//===============================================
static double GFunction_Min(sGVertex* data, int nMax, int pos) {
	double lData = 0.0;
	if(pos == 0) {lData = data[0].x;}
	else if(pos == 1) {lData = data[0].y;}
	else if(pos == 2) {lData = data[0].z;}

	for(int i = 0; i < nMax; i++) {
		if(pos == 0) {if(lData > data[i].x) {lData = data[i].x;}}
		else if(pos == 1) {if(lData > data[i].y) {lData = data[i].y;}}
		else if(pos == 2) {if(lData > data[i].z) {lData = data[i].z;}}
	}
	return lData;
}
//===============================================
static double GFunction_Max(sGVertex* data, int nMax, int pos) {
	double lData = 0.0;
	if(pos == 0) {lData = data[0].x;}
	else if(pos == 1) {lData = data[0].y;}
	else if(pos == 2) {lData = data[0].z;}

	for(int i = 0; i < nMax; i++) {
		if(pos == 0) {if(lData < data[i].x) {lData = data[i].x;}}
		else if(pos == 1) {if(lData < data[i].y) {lData = data[i].y;}}
		else if(pos == 2) {if(lData < data[i].z) {lData = data[i].z;}}
	}
	return lData;
}
//===============================================
static void GFunction_Free(sGVertex* data) {
	free(data);
}
//===============================================
