include(C:\Users\gerar\Downloads\OpenGL\freeglut-3.0.0\freeglut-3.0.0\GFreeGLUT.pri)
include(C:\Users\gerar\Downloads\OpenGL\bullet3-master\bullet3-master\GBullet.pri)

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/GWindow.cpp \
    $$PWD/GCamera.cpp \
    $$PWD/GDraw.cpp \
    $$PWD/GLight.cpp

HEADERS += \
    $$PWD/GWindow.h \
    $$PWD/GCamera.h \
    $$PWD/GDraw.h \
    $$PWD/GLight.h
