//===============================================
#include "GTexture.h"
#include "GConsole.h"
//===============================================
static GTextureO* m_GTextureO = 0;
//===============================================
static void GTexture_LoadImage(sGTexture* texture);
static void GTexture_CreateTexture(sGTexture* texture);
static void GTexture_BindTexture(sGTexture* texture);
static void GTexture_FreeImage(sGTexture* texture);
static void GTexture_UpdateTexture(sGTexture* texture);
static void GTexture_LoadTexture(sGTexture* texture);
//===============================================
GTextureO* GTexture_New() {
	GTextureO* lObj = (GTextureO*)malloc(sizeof(GTextureO));
	lObj->Delete = GTexture_Delete;
	lObj->LoadImage = GTexture_LoadImage;
	lObj->CreateTexture = GTexture_CreateTexture;
	lObj->BindTexture = GTexture_BindTexture;
	lObj->FreeImage = GTexture_FreeImage;
	lObj->UpdateTexture = GTexture_UpdateTexture;
	lObj->LoadTexture = GTexture_LoadTexture;
	return lObj;
}
//===============================================
void GTexture_Delete() {
	GTextureO* lObj = GTexture();
	if(lObj != 0) {
		free(lObj);
	}
	m_GTextureO = 0;
}
//===============================================
GTextureO* GTexture() {
	if(m_GTextureO == 0) {
		m_GTextureO = GTexture_New();
	}
	return m_GTextureO;
}
//===============================================
static void GTexture_LoadImage(sGTexture* texture) {
	sGTextureImage* lTextureImage = &texture->textureImage;
	char* lImageFile = lTextureImage->imageFile;
	int* lImageWidth = &lTextureImage->imageWidth;
	int* lImageHeight = &lTextureImage->imageHeight;
	int* lImageChannel = &lTextureImage->imageChannel;
	uchar* lImageData = SOIL_load_image(lImageFile, lImageWidth, lImageHeight, lImageChannel, SOIL_LOAD_RGBA);
	if(lImageData == 0) {GConsole()->Print("Error GTexture_LoadImage\n"); exit(0);}
	lTextureImage->imageData = lImageData;
}
//===============================================
static void GTexture_CreateTexture(sGTexture* texture) {
	sGTextureItem* lTextureItem = &texture->textureItem;
	glGenTextures(lTextureItem->nTexture, &lTextureItem->textureId);
}
//===============================================
static void GTexture_BindTexture(sGTexture* texture) {
	sGTextureImage* lTextureImage = &texture->textureImage;
	sGTextureItem* lTextureItem = &texture->textureItem;
	int lImageWidth = lTextureImage->imageWidth;
	int lImageHeight = lTextureImage->imageHeight;
	int lTextureFormat = lTextureItem->textureFormat;
	glBindTexture(GL_TEXTURE_2D, lTextureItem->textureId);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, lTextureFormat, lImageWidth, lImageHeight, 0, lTextureFormat, GL_UNSIGNED_BYTE, lTextureImage->imageData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
}
//===============================================
static void GTexture_FreeImage(sGTexture* texture) {
	sGTextureImage* lTextureImage = &texture->textureImage;
	SOIL_free_image_data(lTextureImage->imageData);
}
//===============================================
static void GTexture_UpdateTexture(sGTexture* texture) {
	sGTextureImage* lTextureImage = &texture->textureImage;
	sGTextureItem* lTextureItem = &texture->textureItem;
	int lImageWidth = lTextureImage->imageWidth;
	int lImageHeight = lTextureImage->imageHeight;
	uchar* lImageData = lTextureImage->imageData;
	int lTextureFormat = lTextureItem->textureFormat;
	glTexSubImage2D (GL_TEXTURE_2D, 0, 0, 0, lImageWidth, lImageHeight, lTextureFormat, GL_UNSIGNED_BYTE, lImageData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
}
//===============================================
static void GTexture_LoadTexture(sGTexture* texture) {
	GTexture()->LoadImage(texture);
	GTexture()->CreateTexture(texture);
	GTexture()->BindTexture(texture);
	GTexture()->FreeImage(texture);
}
//===============================================
