GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GLIBS = \
	-L"C:\Users\gerar\Downloads\SDL\SDL2-devel-2.0.8-mingw\SDL2-2.0.8\i686-w64-mingw32\lib" \
	-lmingw32 -lSDL2main -lSDL2

GINCS = \
	-I"C:\Users\gerar\Downloads\SDL\SDL2-devel-2.0.8-mingw\SDL2-2.0.8\i686-w64-mingw32\include"
	
GOBJS = \
	$(GBUILD)\main.o
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o $(GINCS)
clean:
	del /q $(GOBJS) $(GTARGET)
