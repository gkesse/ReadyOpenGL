GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GMGR=..\..\manager

GINCS = \
	-I"..\..\manager"
	
GOBJS = \
	$(GBUILD)\main.o \
	$(GBUILD)\GConfig.o
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o $(GINCS)
$(GBUILD)\GConfig.o: $(GMGR)\GConfig.cpp
	g++ -c $(GMGR)\GConfig.cpp -o $(GBUILD)\GConfig.o $(GINCS)
clean:
	del /q $(GBIN)\* $(GBUILD)\*
