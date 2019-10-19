//================================================
#ifndef _GInclude_
#define _GInclude_
//================================================
/* C++ Standard */
#include <iostream>
#include <string>
#include <fstream> 
#include <cmath>
#include <iomanip>
#include <map>
#include <vector>
//================================================
#if defined(__WIN32)
#define G_PLATEFORM_OS "WINDOWS"
//================================================
/* OpenGL */
#include <GLFW/glfw3.h>
//================================================
/* SQLite */
#include <sqlite3.h>
//================================================
#else
#define G_PLATEFORM_OS "UNIX"
//================================================
//================================================
#endif
//===============================================
/* Typedef */
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long int ulint;
//===============================================
using namespace std;
//================================================
#include "GStruct.h"
//================================================
#endif
//================================================
