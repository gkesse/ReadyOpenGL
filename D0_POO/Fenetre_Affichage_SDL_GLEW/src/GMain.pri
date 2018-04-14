include(C:\Users\gerar\Downloads\OpenGL\freeglut-3.0.0\freeglut-3.0.0\GFreeGLUT.pri)
include(C:\Users\gerar\Downloads\OpenGL\glew-2.1.0-win32\glew-2.1.0\GGLEW.pri)
include(C:\Users\gerar\Downloads\SDL\SDL2-devel-2.0.8-mingw\SDL2-2.0.8\i686-w64-mingw32\GSDL.pri)
include(..\..\zManager\GManager.pri)

LIBS += \
      -lopengl32 -lglew32 -lfreeglut.dll -lSDL2main -lSDL2

SOURCES += \
    $$PWD/main.cpp
