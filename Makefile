CXXFLAGS="-std=c++14"

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out: %.cpp Makefile
	g++ $< -o $@ -std=c++14
