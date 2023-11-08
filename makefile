CXX = clang++
CXXFLAGS = -std=c++17
CC = clang
CCFLAGS = -std=c17

all: minop

minop: minop.c
	$(CC) $(CCFLAGS) -o minop minop.c

clean:
	rm -rf minop minop_debug
