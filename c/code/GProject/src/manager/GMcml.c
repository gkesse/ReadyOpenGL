//===============================================
#include "GMcml.h"
#include "GFile2.h"
#include "GHeat.h"
//===============================================
static GMcmlO* m_GMcmlO = 0;
//===============================================
static void GMcml_Load(char* filename, sGMCML* mcml);
static void GMcml_JetColor(sGMCML* heat);
//===============================================
GMcmlO* GMcml_New() {
	GMcmlO* lObj = (GMcmlO*)malloc(sizeof(GMcmlO));
	lObj->Delete = GMcml_Delete;
	lObj->Load = GMcml_Load;
	lObj->JetColor = GMcml_JetColor;
	return lObj;
}
//===============================================
void GMcml_Delete() {
	GMcmlO* lObj = GMcml();
	if(lObj != 0) {
		free(lObj);
	}
	m_GMcmlO = 0;
}
//===============================================
GMcmlO* GMcml() {
	if(m_GMcmlO == 0) {
		m_GMcmlO = GMcml_New();
	}
	return m_GMcmlO;
}
//===============================================
static void GMcml_Load(char* filename, sGMCML* mcml) {
	int lOneOnly = TRUE;
	double lMin = 0.0;
	double lMax = 0.0;

	GFile2()->Exist(filename);
	GFile2()->Open("MCML", filename, "r");

	for(int x = 0; x < mcml->xNmax; x++) {
		for(int z = 0; z < mcml->zNmax; z++) {
			for(int y = 0; y < mcml->yNmax; y++) {
				int k = z;
				k += y*GMCML_BUFFER_Z;
				k += x*GMCML_BUFFER_Y*GMCML_BUFFER_Z;

				double lData;
				GFile2()->fScanf("MCML", "%lf", &lData);
				lData = log(lData + 1);
				mcml->data[k] = lData;

				if(lOneOnly == TRUE) {
					lOneOnly = FALSE;
					lMin = lData;
					lMax = lData;
				}

				if(lMin > lData) lMin = lData;
				if(lMax < lData) lMax = lData;

				mcml->vertex[k].x = (double)(x - mcml->xNmax/2.0)/mcml->xNmax;
				mcml->vertex[k].y = (double)(y - mcml->yNmax/2.0)/mcml->yNmax;
				mcml->vertex[k].z = (double)(z - mcml->zNmax/2.0)/mcml->zNmax * 2.0;
			}
		}
	}

	mcml->dMin = lMin;
	mcml->dMax = lMax;

	GFile2()->Close("MCML");
}
//===============================================
static void GMcml_JetColor(sGMCML* mcml) {
	for(int z = 0; z < mcml->zNmax; z++) {
		for(int x = 0; x < mcml->xNmax; x++) {
			for(int y = 0; y < mcml->yNmax; y++) {
				int k = z;
				k += y*GMCML_BUFFER_Z;
				k += x*GMCML_BUFFER_Y*GMCML_BUFFER_Z;

				sGHeat lHeat = {
						mcml->data[k],
						mcml->dMin,
						mcml->dMax,
						{0}
				};
				GHeat()->JetColor(&lHeat);
				mcml->color[k] = lHeat.iColor;
			}
		}
	}
}
//===============================================
