ifeq ($(OS), Windows_NT)
	EXT := .exe
	PREFIX =
	RM	= del
	WHICH := where
	PLATFORM := Windows
	LFLAGS = -framework OpenGL -framework GLUT
else
	EXT :=
	PREFIX := ./
	RM 	= rm -f
	WHICH := which
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		PLATFORM := Linux
		LFLAGS = -lglut -lGL -lGLEW -lGLU
	endif
	ifeq ($(UNAME_S), Darwin)
		PLATFORM := Mac
		LFLAGS = -framework OpenGL -framework GLUT
	endif
endif
