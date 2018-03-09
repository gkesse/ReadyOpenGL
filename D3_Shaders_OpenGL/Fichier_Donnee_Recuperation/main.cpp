//===============================================
char* fileContent = (char*)malloc(fileLength+1); 
if ( fileContent == NULL ) {
	return -3;
}
fread(fileContent,fileLength,1,pFile);
fileContent[fileSize] = '\0';
free(fileContent);
//===============================================
