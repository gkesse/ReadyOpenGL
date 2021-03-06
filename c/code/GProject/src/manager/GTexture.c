//===============================================
#include "GTexture.h"
#include "GConsole.h"
//===============================================
static GTextureO* m_GTextureO = 0;
//===============================================
static void GTexture_LoadImage(sGTextureImage* texture);
static void GTexture_CreateTexture(sGTexture* texture);
static void GTexture_BindTexture(sGTexture* texture);
static void GTexture_FreeImage(sGTextureImage* texture);
static void GTexture_LoadTexture(sGTexture* texture);
static void GTexture_DeleteTexture(sGTexture* texture);
static void GTexture_UpdateTexture(sGTexture* texture);
static void GTexture_ActiveTexture(sGTextureActive* texture);
//===============================================
GTextureO* GTexture_New() {
	GTextureO* lObj = (GTextureO*)malloc(sizeof(GTextureO));
	lObj->Delete = GTexture_Delete;
	lObj->LoadImage = GTexture_LoadImage;
	lObj->CreateTexture = GTexture_CreateTexture;
	lObj->BindTexture = GTexture_BindTexture;
	lObj->FreeImage = GTexture_FreeImage;
	lObj->LoadTexture = GTexture_LoadTexture;
	lObj->DeleteTexture = GTexture_DeleteTexture;
	lObj->UpdateTexture = GTexture_UpdateTexture;
	lObj->ActiveTexture = GTexture_ActiveTexture;
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
static void GTexture_LoadImage(sGTextureImage* texture) {
	char* lImageFile = texture->imageFile;
	int* lImageWidth = &texture->imageWidth;
	int* lImageHeight = &texture->imageHeight;
	int* lImageChannel = &texture->imageChannel;
	uchar* lImageData = SOIL_load_image(lImageFile, lImageWidth, lImageHeight, lImageChannel, SOIL_LOAD_RGBA);
	if(lImageData == 0) {GConsole()->Print("Error GTexture_LoadImage\n"); exit(0);}
	texture->imageData = lImageData;
}
//===============================================
static void GTexture_CreateTexture(sGTexture* texture) {
	glGenTextures(texture->nTexture, &texture->textureId);
}
//===============================================
static void GTexture_BindTexture(sGTexture* texture) {
	sGTextureImage* lTextureImage = &texture->textureImage;
	int lImageWidth = lTextureImage->imageWidth;
	int lImageHeight = lTextureImage->imageHeight;
	int lTextureFormat = texture->textureFormat;
	glBindTexture(GL_TEXTURE_2D, texture->textureId);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, lTextureFormat, lImageWidth, lImageHeight, 0, lTextureFormat, GL_UNSIGNED_BYTE, lTextureImage->imageData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
}
//===============================================
static void GTexture_FreeImage(sGTextureImage* texture) {
	SOIL_free_image_data(texture->imageData);
}
//===============================================
static void GTexture_LoadTexture(sGTexture* texture) {
	GTexture()->LoadImage(&texture->textureImage);
	GTexture()->CreateTexture(texture);
	GTexture()->BindTexture(texture);
	GTexture()->FreeImage(&texture->textureImage);
}
//===============================================
static void GTexture_DeleteTexture(sGTexture* texture) {
	glDeleteTextures(texture->nTexture, &texture->textureId);
}
//===============================================
static void GTexture_UpdateTexture(sGTexture* texture) {
	sGTextureImage* lTextureImage = &texture->textureImage;
	int lImageWidth = lTextureImage->imageWidth;
	int lImageHeight = lTextureImage->imageHeight;
	uchar* lImageData = lTextureImage->imageData;
	int lTextureFormat = texture->textureFormat;
	glTexSubImage2D (GL_TEXTURE_2D, 0, 0, 0, lImageWidth, lImageHeight, lTextureFormat, GL_UNSIGNED_BYTE, lImageData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
}
//===============================================
static void GTexture_ActiveTexture(sGTextureActive* texture) {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, *texture->textureId);
	glUniform1i(*texture->textureId, 0);
}
//===============================================
