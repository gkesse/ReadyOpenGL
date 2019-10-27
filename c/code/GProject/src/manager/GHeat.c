//===============================================
#include "GHeat.h"
//===============================================
static GHeatO* m_GHeatO = 0;
//===============================================
static sGColor GHeat_HeatColor(sGHeat* heat);
static sGColor GHeat_JetColor(sGHeat* heat);
//===============================================
GHeatO* GHeat_New() {
	GHeatO* lObj = (GHeatO*)malloc(sizeof(GHeatO));
	lObj->Delete = GHeat_Delete;
	lObj->HeatColor = GHeat_HeatColor;
	lObj->JetColor = GHeat_JetColor;
	return lObj;
}
//===============================================
void GHeat_Delete() {
	GHeatO* lObj = GHeat();
	if(lObj != 0) {
		free(lObj);
	}
	m_GHeatO = 0;
}
//===============================================
GHeatO* GHeat() {
	if(m_GHeatO == 0) {
		m_GHeatO = GHeat_New();
	}
	return m_GHeatO;
}
//===============================================
static sGColor GHeat_HeatColor(sGHeat* heat) {
	double lAvg = (heat->iMin + heat->iMax)/2.0;
	double lBlue = 1.0 - heat->iVal/lAvg;
	double lRed = heat->iVal/lAvg - 1.0;
	if(lBlue < 0) {lBlue = 0.0;}
	if(lRed < 0) {lRed = 0.0;}
	double lGreen = 1.0 - lBlue - lRed;
	heat->iColor.r = lRed;
	heat->iColor.g = lGreen;
	heat->iColor.b = lBlue;
	heat->iColor.a = heat->iAlpha;
	return heat->iColor;
}
//===============================================
static sGColor GHeat_JetColor(sGHeat* heat) {
	if(heat->iVal < heat->iMin) heat->iVal = heat->iMin;
	if(heat->iVal > heat->iMax) heat->iVal = heat->iMax;

	double lDiff = heat->iMax - heat->iMin;
	heat->iColor.r = heat->iColor.g = heat->iColor.b = 1.0;
	heat->iColor.a = heat->iAlpha;

	if(heat->iVal < (heat->iMin + 0.25*lDiff)) {
		heat->iColor.r = 0.0;
		heat->iColor.g = 4.0*(heat->iVal - heat->iMin)/lDiff;
	}
	else if(heat->iVal < (heat->iMin + 0.4*lDiff)) {
		heat->iColor.r = 0.0;
		heat->iColor.b = 1.0 + 4.0*(heat->iMin + 0.25*lDiff - heat->iVal) / lDiff;
	}
	else if (heat->iVal < (heat->iMin + 0.75*lDiff)) {
		heat->iColor.r = 4.0 * (heat->iVal - heat->iMin - 0.5*lDiff)/lDiff;
		heat->iColor.b = 0.0;
	}
	else {
		heat->iColor.g = 1.0 + 4.0*(heat->iMin + 0.75*lDiff - heat->iVal)/lDiff;
		heat->iColor.b = 0.0;
	}

	return heat->iColor;
}
//===============================================
