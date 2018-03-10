GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GLIBS = \
	-L"C:\Users\gerar\Downloads\OpenGL\glfw-3.2.1\glfw-3.2.1\build\src" \
	-L"..\..\manager\win\bin" \
	 -lmanager -lglfw3 -lgdi32

GINCS = \
	-I"C:\Users\gerar\Downloads\OpenGL\glfw-3.2.1\glfw-3.2.1\include" \
	-I"C:\Users\gerar\Downloads\OpenGL\gl3w-master\gl3w-master\include" \
	-I"..\..\manager\src"
	
GOBJS = \
	$(GBUILD)\main.o \
	$(GBUILD)\GWindowDraw.o \
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o $(GINCS)
$(GBUILD)\GWindowDraw.o: $(GSRC)\GWindowDraw.cpp
	g++ -c $(GSRC)\GWindowDraw.cpp -o $(GBUILD)\GWindowDraw.o $(GINCS)
clean:
	del /q $(GBIN)\* $(GBUILD)\*
