//===============================================
long getFileSize(FILE* pFile) {
	long length = 0;
	fseek(pFile,0,SEEK_END);
	length = ftell(pFile);
	fseek(pFile,0,SEEK_SET);
	return length;
}
//===============================================
