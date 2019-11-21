GREADYLIB = C:\Users\Admin\Downloads\Programs\ReadyLib\dev
GSRC = ../code/GProject/src
GBIN = bin
GBUILD = build
GTARGET = $(GBIN)/GProject.exe

GINCS = \
    -I$(GSRC)\manager \
    -I$(GREADYLIB)\glfw\c\3.3\include \
    -I$(GREADYLIB)\glew\c\2.1.0\include \
    -I$(GREADYLIB)\soil\c\1.16\include \
    -I$(GREADYLIB)\glm\c\0.6.0\include \
    -I$(GREADYLIB)\gsl\c\2.2.1\include \

GLIBS = \
    -L$(GREADYLIB)\glfw\c\3.3\mingw64\lib \
    -L$(GREADYLIB)\glew\c\2.1.0\mingw64\lib \
    -L$(GREADYLIB)\soil\c\1.16\mingw64\lib \
    -L$(GREADYLIB)\glm\c\0.6.0\mingw64\lib \
    -L$(GREADYLIB)\gsl\c\2.2.1\mingw64\lib \
    -lgsl -lglm -lglfw3 -lglew32 -lSOIL -lglu32 -lopengl32 -lgdi32 \
    
GOBJS = \
    $(patsubst $(GSRC)/%.c, $(GBUILD)/%.o, $(wildcard $(GSRC)/*.c)) \
    $(patsubst $(GSRC)/manager/%.c, $(GBUILD)/%.o, $(wildcard $(GSRC)/manager/*.c))
    	
all: $(GOBJS)
	@if not exist "$(GBIN)" @mkdir $(GBIN)
	gcc -o $(GTARGET) $(GOBJS) $(GLIBS) 
$(GBUILD)/%.o: $(GSRC)/%.c
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	gcc -Wall -std=c11 -c $< -o $@ $(GINCS)
$(GBUILD)/%.o: $(GSRC)/manager/%.c
	@if not exist "$(GBUILD)" @mkdir $(GBUILD)
	gcc -Wall -std=c11 -c $< -o $@ $(GINCS)
clean:
	del /q $(GBUILD)\*.o $(GBIN)\*.exe
