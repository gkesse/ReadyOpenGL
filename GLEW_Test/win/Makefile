GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GLIBS = \
	-L"C:\Users\sabine\Downloads\Gerard\glew-2.1.0-win32\glew-2.1.0\lib\Release\Win32" \
	-lglew32

GINCS = \
	-I"C:\Users\sabine\Downloads\Gerard\glew-2.1.0-win32\glew-2.1.0\include"
	
GOBJS = \
	$(GBUILD)\main.o
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o $(GINCS)
clean:
	del /q $(GOBJS) $(GTARGET)
