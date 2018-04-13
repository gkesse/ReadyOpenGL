GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\libmanager.a

GINCS = \
	-I"C:\Users\gerar\Downloads\SDL\SDL2-devel-2.0.8-mingw\SDL2-2.0.8\i686-w64-mingw32\include" \
	-I"C:\Users\gerar\Downloads\OpenGL\glew-2.1.0-win32\glew-2.1.0\include" \
	-I"C:\Users\gerar\Downloads\OpenGL\glm-0.9.9-a2\glm-0.9.9-a2" \
	
GOBJS = \
	$(GBUILD)\GWindow.o \
	$(GBUILD)\GDraw.o \
	$(GBUILD)\GDrawTriangle.o \
	$(GBUILD)\GDrawTriangleDouble.o \
	$(GBUILD)\GDrawTriangleColor.o \
	$(GBUILD)\GDrawTransformation.o \
	$(GBUILD)\GShader.o \
	$(GBUILD)\GVertex.o \
	$(GBUILD)\GFile.o \
	$(GBUILD)\GConfig.o \
	
all: $(GOBJS)
	ar rcs $(GTARGET) $(GOBJS)
$(GBUILD)\GWindow.o: $(GSRC)\GWindow.cpp
	g++ -c $(GSRC)\GWindow.cpp -o $(GBUILD)\GWindow.o $(GINCS)
$(GBUILD)\GDraw.o: $(GSRC)\GDraw.cpp
	g++ -c $(GSRC)\GDraw.cpp -o $(GBUILD)\GDraw.o $(GINCS)
$(GBUILD)\GDrawTriangle.o: $(GSRC)\GDrawTriangle.cpp
	g++ -c $(GSRC)\GDrawTriangle.cpp -o $(GBUILD)\GDrawTriangle.o $(GINCS)
$(GBUILD)\GDrawTriangleDouble.o: $(GSRC)\GDrawTriangleDouble.cpp
	g++ -c $(GSRC)\GDrawTriangleDouble.cpp -o $(GBUILD)\GDrawTriangleDouble.o $(GINCS)
$(GBUILD)\GDrawTransformation.o: $(GSRC)\GDrawTransformation.cpp
	g++ -c $(GSRC)\GDrawTransformation.cpp -o $(GBUILD)\GDrawTransformation.o $(GINCS)
$(GBUILD)\GDrawTriangleColor.o: $(GSRC)\GDrawTriangleColor.cpp
	g++ -c $(GSRC)\GDrawTriangleColor.cpp -o $(GBUILD)\GDrawTriangleColor.o $(GINCS)
$(GBUILD)\GShader.o: $(GSRC)\GShader.cpp
	g++ -c $(GSRC)\GShader.cpp -o $(GBUILD)\GShader.o $(GINCS)
$(GBUILD)\GVertex.o: $(GSRC)\GVertex.cpp
	g++ -c $(GSRC)\GVertex.cpp -o $(GBUILD)\GVertex.o $(GINCS)
$(GBUILD)\GFile.o: $(GSRC)\GFile.cpp
	g++ -c $(GSRC)\GFile.cpp -o $(GBUILD)\GFile.o $(GINCS)
$(GBUILD)\GConfig.o: $(GSRC)\GConfig.cpp
	g++ -c $(GSRC)\GConfig.cpp -o $(GBUILD)\GConfig.o $(GINCS)
clean:
	del /q $(GBIN)\* $(GBUILD)\*
