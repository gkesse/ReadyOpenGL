GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GGL3W = C:\Users\gerar\Downloads\OpenGL\gl3w-master\gl3w-master
GMGR=..\..\manager

GLIBS = \
	-L"C:\Users\gerar\Downloads\OpenGL\glfw-3.2.1\glfw-3.2.1\build\src" \
	-lglfw3 -lgdi32

GINCS = \
	-I"C:\Users\gerar\Downloads\OpenGL\glfw-3.2.1\glfw-3.2.1\include" \
	-I"C:\Users\gerar\Downloads\OpenGL\gl3w-master\gl3w-master\include" \
	-I"..\..\manager"
	
GOBJS = \
	$(GBUILD)\main.o \
	$(GBUILD)\GWindow.o \
	$(GBUILD)\GDraw.o \
	$(GBUILD)\GShader.o \
	$(GBUILD)\GFile.o \
	$(GBUILD)\gl3w.o
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o $(GINCS)
$(GBUILD)\GWindow.o: $(GMGR)\GWindow.cpp
	g++ -c $(GMGR)\GWindow.cpp -o $(GBUILD)\GWindow.o $(GINCS)
$(GBUILD)\GDraw.o: $(GMGR)\GDraw.cpp
	g++ -c $(GMGR)\GDraw.cpp -o $(GBUILD)\GDraw.o $(GINCS)
$(GBUILD)\GShader.o: $(GMGR)\GShader.cpp
	g++ -c $(GMGR)\GShader.cpp -o $(GBUILD)\GShader.o $(GINCS)
$(GBUILD)\GFile.o: $(GMGR)\GFile.cpp
	g++ -c $(GMGR)\GFile.cpp -o $(GBUILD)\GFile.o $(GINCS)
$(GBUILD)\gl3w.o: $(GGL3W)\src\gl3w.c
	gcc -c $(GGL3W)\src\gl3w.c -o $(GBUILD)\gl3w.o $(GINCS)
clean:
	del /q $(GOBJS) $(GTARGET)
