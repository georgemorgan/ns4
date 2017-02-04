sources = $(shell find . -name '*.c')
target = ns4
cc := gcc-6

# The include folders.
includes = include
# Compute objects, append extra flags, and add includes.
objects = $(addsuffix .o, $(basename $(sources)))
flags += $(foreach include, $(includes),-I $(include))

# Recipe for building the emulator binary.
all: $(objects)
	$(cc) $(objects) -o $(target)

%.o : %.c
	$(cc) $(flags) -c $< -o $@

clean:
	rm -rf $(target) $(objects)
