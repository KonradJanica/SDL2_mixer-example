#Copyright Notice:
#The files within this zip file are copyrighted by Lazy Foo' Productions (2004-2014)
#and may not be redistributed without written permission.

#OBJS specifies which files to compile as part of the project
OBJS = foo.c

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -L/usr/local/lib 
LINKER_FLAGS1 = -lcygwin
LINKER_FLAGS2 = -lSDL2main
LINKER_FLAGS3 = -lSDL2
LINKER_FLAGS4 = -lSDL2_mixer
LINKER_FLAGS5 = -mwindows

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = foo

#This is the target that compiles our executable
all : $(OBJS)

	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(LINKER_FLAGS1) $(LINKER_FLAGS2) $(LINKER_FLAGS3) $(LINKER_FLAGS4) $(LINKER_FLAGS5) -o $(OBJ_NAME)
