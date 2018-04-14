include(C:\Users\gerar\Downloads\OpenGL\freeglut-3.0.0\freeglut-3.0.0\GFreeGLUT.pri)
include(..\..\zManager\GManager.pri)

LIBS += \
    -lfreeglut.dll

SOURCES += \
    $$PWD/main.cpp
