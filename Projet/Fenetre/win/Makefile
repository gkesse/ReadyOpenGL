GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GLIBS = \
	-L"C:\Users\gerar\Downloads\SDL\SDL2-devel-2.0.8-mingw\SDL2-2.0.8\i686-w64-mingw32\lib" \
	-L"C:\Users\gerar\Downloads\OpenGL\glew-2.1.0-win32\glew-2.1.0\lib\Release\Win32" \
	-lopengl32 -lmingw32 -lSDL2main -lSDL2 -lglew32

GINCS = \
	-I"C:\Users\gerar\Downloads\SDL\SDL2-devel-2.0.8-mingw\SDL2-2.0.8\i686-w64-mingw32\include" \
	-I"C:\Users\gerar\Downloads\OpenGL\glew-2.1.0-win32\glew-2.1.0\include"

GOBJS = \
	$(GBUILD)\main.o \
	$(GBUILD)\GWindow.o
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o $(GINCS)
$(GBUILD)\GWindow.o: $(GSRC)\GWindow.cpp
	g++ -c $(GSRC)\GWindow.cpp -o $(GBUILD)\GWindow.o $(GINCS)
clean:
	del /q $(GOBJS) $(GTARGET)
