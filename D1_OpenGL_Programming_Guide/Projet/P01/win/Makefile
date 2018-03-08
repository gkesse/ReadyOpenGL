GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GGL3W = C:\Users\gerar\Downloads\OpenGL\gl3w-master\gl3w-master

GLIBS = \
	-L"C:\Users\gerar\Downloads\OpenGL\glfw-3.2.1\glfw-3.2.1\build\src" \
	-lglfw3 -lgdi32

GINCS = \
	-I"C:\Users\gerar\Downloads\OpenGL\glfw-3.2.1\glfw-3.2.1\include" \
	-I"C:\Users\gerar\Downloads\OpenGL\gl3w-master\gl3w-master\include"
	
GOBJS = \
	$(GBUILD)\main.o \
	$(GBUILD)\GWindow.o \
	$(GBUILD)\GDraw.o \
	$(GBUILD)\GShader.o \
	$(GBUILD)\gl3w.o
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o $(GINCS)
$(GBUILD)\GWindow.o: $(GSRC)\GWindow.cpp
	g++ -c $(GSRC)\GWindow.cpp -o $(GBUILD)\GWindow.o $(GINCS)
$(GBUILD)\GDraw.o: $(GSRC)\GDraw.cpp
	g++ -c $(GSRC)\GDraw.cpp -o $(GBUILD)\GDraw.o $(GINCS)
$(GBUILD)\GShader.o: $(GSRC)\GShader.cpp
	g++ -c $(GSRC)\GShader.cpp -o $(GBUILD)\GShader.o $(GINCS)
$(GBUILD)\gl3w.o: $(GGL3W)\src\gl3w.c
	gcc -c $(GGL3W)\src\gl3w.c -o $(GBUILD)\gl3w.o $(GINCS)
clean:
	del /q $(GOBJS) $(GTARGET)
