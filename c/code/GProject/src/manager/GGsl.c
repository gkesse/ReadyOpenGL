//===============================================
#include "GGsl.h"
#include "GConsole.h"
//===============================================
static GGslO* m_GGslO = 0;
//===============================================
static double GGsl_Bessel(double x);
static void GGsl_ComplexShow(gsl_complex z);
//===============================================
GGslO* GGsl_New() {
	GGslO* lObj = (GGslO*)malloc(sizeof(GGslO));
	lObj->Delete = GGsl_Delete;
	lObj->Bessel = GGsl_Bessel;
	lObj->ComplexShow = GGsl_ComplexShow;
	return lObj;
}
//===============================================
void GGsl_Delete() {
	GGslO* lObj = GGsl();
	if(lObj != 0) {
		free(lObj);
	}
	m_GGslO = 0;
}
//===============================================
GGslO* GGsl() {
	if(m_GGslO == 0) {
		m_GGslO = GGsl_New();
	}
	return m_GGslO;
}
//===============================================
static double GGsl_Bessel(double x) {
	double lData = gsl_sf_bessel_J0(x);
	return lData;
}
//===============================================
static void GGsl_ComplexShow(gsl_complex z) {
	GConsole()->Print("[ %10.2f ] + i[ %10.2f ]\n\n", z.dat[0], z.dat[1]);
}
//===============================================
