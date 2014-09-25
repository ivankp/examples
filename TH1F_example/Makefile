EXE := example

all: $(EXE)

$(EXE): %: %.cxx
	g++ -Wall -O3 $(shell root-config --cflags) $< -o $@ $(shell root-config --glibs)

clean:
	rm -f $(EXE)

