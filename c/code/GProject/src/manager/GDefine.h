//===============================================
#ifndef _GDefine_
#define _GDefine_
//===============================================
#define GPOINTER_NULL (void*)0
//===============================================
#define GMCML_BUFFER_X 50
#define GMCML_BUFFER_Y 50
#define GMCML_BUFFER_Z 200
#define GMCML_BUFFER_MAX \
	(GMCML_BUFFER_X*GMCML_BUFFER_Y*GMCML_BUFFER_Z)
//===============================================
#if defined(__WIN32)
#define GGLFW_WINDOW GLFWwindow
#else
#define GGLFW_WINDOW void
#endif
//===============================================
#define GSHADER_BUFFER_CODE 1024
//===============================================
#endif
//===============================================
