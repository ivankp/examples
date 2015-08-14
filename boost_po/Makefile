EXE := test

.PHONY: all clean

all: $(EXE)

$(EXE): %: %.cc
	g++ -std=c++11 -Wall -O2 $^ -o $@ -lboost_program_options

clean:
	rm -fv $(EXE)

