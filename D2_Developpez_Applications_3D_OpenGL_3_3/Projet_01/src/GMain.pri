include(C:\Users\gerar\Downloads\OpenGL\glew-2.1.0-win32\glew-2.1.0\GGLEW.pri)
include(C:\Users\gerar\Downloads\SDL\SDL2-devel-2.0.8-mingw\SDL2-2.0.8\i686-w64-mingw32\GSDL.pri)

LIBS += \
       -lglew32 -lopengl32 -lmingw32 -lSDL2main -lSDL2


SOURCES += \
    $$PWD/main.cpp \
    $$PWD/GWindow.cpp \
    $$PWD/GDraw.cpp \
    $$PWD/GFile.cpp \
    $$PWD/GShader.cpp

HEADERS += \
    $$PWD/GWindow.h \
    $$PWD/GDraw.h \
    $$PWD/GFile.h \
    $$PWD/GShader.h

