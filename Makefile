SYS = $(shell gcc -dumpmachine)
ifneq (,$(findstring mingw,$(SYS)))
	OS=windows
else
	OS=other
endif


CC = gcc
CFLAGS = -Wall -std=c11

BIN_PATH = bin
APP_BIN = imagimp

SRC_PATH = src
OBJ_PATH = obj
INC_PATH = -I include
	
LIB_PATH = lib

ifeq ($(OS),windows)


	LDFLAGS  =  -lm  
	
	SRC_FILES = $(wildcard */*.c)
	OBJ_FILES = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, $(SRC_FILES))

	ALL_CMDA = if not exist "$(BIN_PATH)" mkdir $(BIN_PATH)
	ALL_CMDB = if not exist "$(@D)" mkdir "$(@D)"	
	CLEAN_CMD = del /s obj\* $(BIN_PATH)\$(APP_BIN).exe 
	RUN_CMD = $(BIN_PATH)\$(APP_BIN)
else

	
	SRC_FILES = $(shell find $(SRC_PATH) -type f -name '*.c')
	OBJ_FILES = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, $(SRC_FILES))
	
	UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
		LDFLAGS = -lm

		
    else
		LDFLAGS =-lm -framework Cocoa

	endif
	
	
	ALL_CMDA =@mkdir -p $(BIN_PATH)
	ALL_CMDB =@mkdir -p "$(@D)"
	CLEAN_CMD = rm $(OBJ_FILES) $(BIN_PATH)/$(APP_BIN)
	RUN_CMD = ./$(BIN_PATH)/$(APP_BIN)
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