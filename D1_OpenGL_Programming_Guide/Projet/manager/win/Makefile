GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\libmanager.a

GGL3W = C:\Users\gerar\Downloads\OpenGL\gl3w-master\gl3w-master

GINCS = \
	-I"C:\Users\gerar\Downloads\OpenGL\glfw-3.2.1\glfw-3.2.1\include" \
	-I"C:\Users\gerar\Downloads\OpenGL\gl3w-master\gl3w-master\include"
	
GOBJS = \
	$(GBUILD)\GWindow.o \
	$(GBUILD)\GDraw.o \
	$(GBUILD)\GDrawLine.o \
	$(GBUILD)\GDrawQuad.o \
	$(GBUILD)\GDrawTriangle.o \
	$(GBUILD)\GVertex.o \
	$(GBUILD)\GShader.o \
	$(GBUILD)\GFile.o \
	$(GBUILD)\GConfig.o \
	$(GBUILD)\gl3w.o
	
all: $(GOBJS)
	ar rcs $(GTARGET) $(GOBJS)
$(GBUILD)\GWindow.o: $(GSRC)\GWindow.cpp
	g++ -c $(GSRC)\GWindow.cpp -o $(GBUILD)\GWindow.o $(GINCS)
$(GBUILD)\GDraw.o: $(GSRC)\GDraw.cpp
	g++ -c $(GSRC)\GDraw.cpp -o $(GBUILD)\GDraw.o $(GINCS)
$(GBUILD)\GDrawLine.o: $(GSRC)\GDrawLine.cpp
	g++ -c $(GSRC)\GDrawLine.cpp -o $(GBUILD)\GDrawLine.o $(GINCS)
$(GBUILD)\GDrawQuad.o: $(GSRC)\GDrawQuad.cpp
	g++ -c $(GSRC)\GDrawQuad.cpp -o $(GBUILD)\GDrawQuad.o $(GINCS)
$(GBUILD)\GDrawTriangle.o: $(GSRC)\GDrawTriangle.cpp
	g++ -c $(GSRC)\GDrawTriangle.cpp -o $(GBUILD)\GDrawTriangle.o $(GINCS)
$(GBUILD)\GVertex.o: $(GSRC)\GVertex.cpp
	g++ -c $(GSRC)\GVertex.cpp -o $(GBUILD)\GVertex.o $(GINCS)
$(GBUILD)\GShader.o: $(GSRC)\GShader.cpp
	g++ -c $(GSRC)\GShader.cpp -o $(GBUILD)\GShader.o $(GINCS)
$(GBUILD)\GFile.o: $(GSRC)\GFile.cpp
	g++ -c $(GSRC)\GFile.cpp -o $(GBUILD)\GFile.o $(GINCS)
$(GBUILD)\GConfig.o: $(GSRC)\GConfig.cpp
	g++ -c $(GSRC)\GConfig.cpp -o $(GBUILD)\GConfig.o $(GINCS)
$(GBUILD)\gl3w.o: $(GGL3W)\src\gl3w.c
	gcc -c $(GGL3W)\src\gl3w.c -o $(GBUILD)\gl3w.o $(GINCS)
clean:
	del /q $(GBIN)\* $(GBUILD)\*
