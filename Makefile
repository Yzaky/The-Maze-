CC 			= gcc
LD 			= gcc

JEU	= texte
#JEU = graphique
#OS	= WIN32
OS	= LINUX


	SRCS = Ball.c Field.c Game.c sdlGame.c main.c
	FINAL_TARGET = TheMaze_gfx
	DEFINE = -D$(OS) -DJEU_SDL


ifeq ($(JEU)$(OS),texteWIN32)
	LIBS = "C:\Program Files (x86)\PDCurses-SO\win32\pdcurses.a"
endif
ifeq ($(JEU)$(OS),texteLINUX)
	LIBS = -lncurses
endif
ifeq ($(JEU)$(OS),graphiqueWIN32)
	LIBS = -L"G:\alex\A_CLASSER\LIF7-DeveloppementApp\SDL-1.2.14\lib" -lmingw32 -lSDLmain -lSDL.dll
endif
ifeq ($(JEU)$(OS),graphiqueLINUX)
	LIBS = -lSDL
endif



LDFLAGS  			= -lSDL -lSDL_mixer
CFLAGS 			= $(DEFINE)  -Wall -pedantic -ansi -ggdb  
INCLUDE_DIR 		= -I/usr/include/SDL 

OBJ_DIR 		= obj
SRC_DIR 		= src
BIN_DIR 		= bin



default: $(BIN_DIR)/$(FINAL_TARGET)


$(BIN_DIR)/$(FINAL_TARGET): $(SRCS:%.c=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIB_DIR) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(FINAL_TARGET)
