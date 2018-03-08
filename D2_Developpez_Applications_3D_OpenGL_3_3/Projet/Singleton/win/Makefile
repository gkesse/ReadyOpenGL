GSRC = ..\src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)\GProject.exe

GOBJS = \
	$(GBUILD)\main.o \
	$(GBUILD)\GWindow.o
	
all: $(GOBJS)
	g++ -o $(GTARGET) $(GOBJS)
$(GBUILD)\main.o: $(GSRC)\main.cpp
	g++ -c $(GSRC)\main.cpp -o $(GBUILD)\main.o
$(GBUILD)\GWindow.o: $(GSRC)\GWindow.cpp
	g++ -c $(GSRC)\GWindow.cpp -o $(GBUILD)\GWindow.o
clean:
	del /q $(GOBJS) $(GTARGET)
