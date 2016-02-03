#
# Makefile
# author : Emrul Hasan Zawad
# modified to include compiler check by: Sohan Chowdhury

# compiler to use, clang is default, if clang ne, then gcc
ERR = $(shell which clang >/dev/null; echo $$?)
ifeq "$(ERR)" "0"
    CC = clang
else
    CC = gcc
endif

# flags to pass compiler
CFLAGS = -ggdb3 -O0 -std=c11 -Wall -Werror

# name for executable
EXE = exampleDemo

# space-separated list of header files
HDRS = spv.h

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =

# space-separated list of source files
SRCS = example.c

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies
$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f core *.o
	@echo "object files are removed"

# all clean
allclean:
	rm -f core $(EXE) *.o
	@echo "executable is removed!"
