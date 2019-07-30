GSRC = ../code/GProject/src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GProject.exe

GINCS = \
    -I$(GSRC)/manager \
    -IC:\Users\Admin\Downloads\glfw-3.2.1.bin.WIN64\glfw-3.2.1.bin.WIN64\include \

GLIBS = \
    -LC:\Users\Admin\Downloads\glfw-3.2.1.bin.WIN64\glfw-3.2.1.bin.WIN64\lib-mingw-w64 \
    -lglfw3 -lopengl32 -lgdi32 \
    
GOBJS = \
    $(patsubst $(GSRC)/%.cpp, $(GBUILD)/%.o, $(wildcard $(GSRC)/*.cpp)) \
    $(patsubst $(GSRC)/manager/%.cpp, $(GBUILD)/%.o, $(wildcard $(GSRC)/manager/*.cpp))

all: $(GOBJS)
	@if not exist "$(GBIN)" @mkdir $(GBIN)
	g++ -o $(GTARGET) $(GOBJS) $(GLIBS) 
$(GBUILD)/%.o: $(GSRC)/%.cpp
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	g++ -Wall -c $< -o $@ $(GINCS)
$(GBUILD)/%.o: $(GSRC)/manager/%.cpp
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	g++ -Wall -c $< -o $@ $(GINCS)
clean:
	del /q $(GBUILD)\*.o $(GBIN)\*.exe
