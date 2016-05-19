SYS = $(shell gcc -dumpmachine)
ifneq (,$(findstring mingw,$(SYS)))
OS=windows
else
OS=unix
endif

.PHONY: all clean mrproper re dirs

CC = gcc
CFLAGS = -Wall -Iinclude -g -O2 -std=c11
LDLIBS = -fPIC -Llib -lglimagimp -lm
EXE = bin/imagimp$

ifeq ($(OS),windows)
	MKDIRP=mkdir
	DLL_PREFIX=
	DLL_EXTENSION=.dll
	LIBGL=-lopengl32 -lglu32 -lfreeglut
	CLEANCMD = if exist obj ( rmdir /Q /S obj lib )
	RUNCMD= $(EXE)
	COPYCMD = xcopy /y /i "$(@D)" "bin"
else
	LDLIBS+=-Wl,-rpath=lib -Wl,-rpath=../lib
	MKDIRP=mkdir -p
	DLL_PREFIX=lib
	DLL_EXTENSION=.so
	
	CLEANCMD = rm -rf obj lib
	RUNCMD= ./$(EXE)
	
	ifeq ($(UNAME_S),Linux)
		LIBGL=-lGL -lGLU -lglut
		COPYCMD = cp "$(@D)" "bin"
		
    else
		LIBGL += -I/Library/Frameworks/SDL.framework/Headers -I/Library/Frameworks/SDL_image.framework/Headers -I/opt/local/include
		LIBGL += `sdl-config --libs` `sdl-config --cflags`
		LIBGL += -framework Cocoa -framework OpenGL -lGLU -lGL -lglut

	endif
endif

LIBGLIMAGIMP = lib/$(DLL_PREFIX)glimagimp$(DLL_EXTENSION)


all: $(LIBGLIMAGIMP) $(EXE)

dirs: bin lib obj/glimagimp obj/imagimp
obj:
	$(MKDIRP) "$@"
obj/glimagimp: | obj
	$(MKDIRP) "$@"
obj/imagimp: | obj
	$(MKDIRP) "$@"
lib:
	$(MKDIRP) "$@"
bin:
	$(MKDIRP) "$@"


obj/imagimp/%.o : src/imagimp/%.c | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(EXE): $(addsuffix .o, \
			$(addprefix obj/imagimp/, \
				$(notdir \
					$(basename \
						$(wildcard src/imagimp/*.c)))))
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS) $(LIBGL)

obj/glimagimp/%.o: src/glimagimp/%.c | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBGLIMAGIMP): obj/glimagimp/interface.o \
			     obj/glimagimp/outils.o
	$(CC) $(CFLAGS) -shared $^ -o $@ $(LIBGL) -lm
	$(COPYCMD) 
clean:
	$(CLEANCMD)
run:
	$(RUNCMD)
mrproper: clean all
re: mrproper