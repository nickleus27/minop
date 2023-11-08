CXX = clang++
CXXFLAGS = -std=c++17
CC = clang
CCFLAGS = -std=c17

all: minop minopfast

minop: minop.c
	$(CC) $(CCFLAGS) -o minop minop.c

minopfast: minopfast.c
	$(CC) $(CCFLAGS) -o minopfast minopfast.c

clean:
	rm -rf minop minop_debug minopfast minopfast_debug
