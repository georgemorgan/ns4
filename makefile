sources = *.c general/*.c
target = ns4
cc := gcc-6

# The include folders.
include = include
# The include flags.
includes = $(foreach inc,$(include),-I $(inc))

# Recipe for building the emulator binary.
all:
	$(cc) $(includes) $(sources) -o $(target)
