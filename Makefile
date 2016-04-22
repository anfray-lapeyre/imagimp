SYS = $(shell gcc -dumpmachine)
ifneq (,$(findstring mingw,$(SYS)))
	OS=windows
else
	OS=unix
endif

ifeq ($(OS),windows)
	CC = gcc
	CFLAGS = -Wall -std=c11
	LDFLAGS  =  -lm  

	APP_BIN = imagimp

	SRC_PATH = src
	OBJ_PATH = obj
	INC_PATH = -I include
	BIN_PATH = .
	LIB_PATH = lib
	MKDIR_P = mkdir

	SRC_FILES = $(wildcard */*.c)
	OBJ_FILES = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, $(SRC_FILES))

	ALL_CMDA = if not exist "$(BIN_PATH)" $(MKDIR_P) $(BIN_PATH)
	ALL_CMDB = if not exist "$(@D)" $(MKDIR_P) "$(@D)"	
	CLEAN_CMD = del /s obj\* $(BIN_PATH)\$(APP_BIN).exe 
	RUN_CMD = $(APP_BIN)
else
	CC = gcc
	CFLAGS = -Wall -std=c11
	LDFLAGS =-I/Library/Frameworks/SDL.frameworks/Headers SDLmain.m -framework SDL -framework Cocoa

	APP_BIN = imagimp

	SRC_PATH = src
	OBJ_PATH = obj
	INC_PATH = -I include
	BIN_PATH = bin
	LIB_PATH = lib

	SRC_FILES = $(shell find $(SRC_PATH) -type f -name '*.c')
	OBJ_FILES = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, $(SRC_FILES))
	
	ALL_CMDA =@mkdir -p $(BIN_PATH)
	ALL_CMDB =@mkdir -p "$(@D)"
	CLEAN_CMD = rm $(OBJ_FILES) $(BIN_PATH)/$(APP_BIN)
	RUN_CMD = ./$(APP_BIN)

endif

.PHONY: all clean run

all: $(APP_BIN)

$(APP_BIN): $(OBJ_FILES)
	$(ALL_CMDA)
	$(CC) -o $(BIN_PATH)/$(APP_BIN) $(OBJ_FILES) $(LDFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(ALL_CMDB)
	$(CC) -c $< -o $@ $(CFLAGS) $(INC_PATH)$(LDFLAGS)

clean:
	$(CLEAN_CMD)
	
run : 
	$(RUN_CMD)