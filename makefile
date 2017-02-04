sources = *.c general/*.c
target = ns4
cc := gcc-6

# The include folders.
includes = include
# The include flags.
includeflags = $(foreach include, $(includes),-I $(include))

# Recipe for building the emulator binary.
all:
	$(cc) $(includeflags) $(sources) -o $(target)
