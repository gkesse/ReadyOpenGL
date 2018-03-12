GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\libmanager.a

GINCS = \
	-I"C:\Users\gerar\Downloads\SDL\SDL2-devel-2.0.8-mingw\SDL2-2.0.8\i686-w64-mingw32\include" \
	-I"C:\Users\gerar\Downloads\OpenGL\glew-2.1.0-win32\glew-2.1.0\include"
	
GOBJS = \
	$(GBUILD)\GWindow.o \
	
all: $(GOBJS)
	ar rcs $(GTARGET) $(GOBJS)
$(GBUILD)\GWindow.o: $(GSRC)\GWindow.cpp
	g++ -c $(GSRC)\GWindow.cpp -o $(GBUILD)\GWindow.o $(GINCS)
clean:
	del /q $(GBIN)\* $(GBUILD)\*
