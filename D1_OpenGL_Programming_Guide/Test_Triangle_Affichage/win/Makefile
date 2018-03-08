GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GCOM = C:\Users\gerar\Downloads\OpenGL\OGLPG-9th-Edition\OGLPG-9th-Edition\lib

GLIBS = \
	-L"C:\Users\gerar\Downloads\OpenGL\glfw-3.2.1\glfw-3.2.1\build\src" \
	-lglfw3 -lgdi32 -lopengl32 -lmingw32

GINCS = \
	-I"C:\Users\gerar\Downloads\OpenGL\glfw-3.2.1\glfw-3.2.1\include" \
	-I"C:\Users\gerar\Downloads\OpenGL\OGLPG-9th-Edition\OGLPG-9th-Edition\include"
	
GOBJS = \
	$(GBUILD)\main.o \
	$(GBUILD)\gl3w.o \
	$(GBUILD)\LoadShaders.o
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o $(GINCS)
$(GBUILD)\gl3w.o: $(GCOM)\gl3w.c
	g++ -c $(GCOM)\gl3w.c -o $(GBUILD)\gl3w.o $(GINCS)
$(GBUILD)\LoadShaders.o: $(GCOM)\LoadShaders.cpp
	g++ -c $(GCOM)\LoadShaders.cpp -o $(GBUILD)\LoadShaders.o $(GINCS)
clean:
	del /q $(GOBJS) $(GTARGET)
