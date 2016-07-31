EXE := executable

CF := -std=c++11 -Wall -g

ROOT_CFLAGS := $(shell root-config --cflags)
ROOT_LIBS   := $(shell root-config --libs)

C_executable := $(ROOT_CFLAGS)
L_executable := $(ROOT_LIBS) -lTreePlayer

.PHONY: all clean

all: $(EXE:%=bin/%)

bin/executable: src/timed_counter.hh

bin/%: src/%.cc | bin
	$(CXX) $(CF) $(C_$*) $(filter %.cc,$^) -o $@ $(L_$*)

bin:
	mkdir $@

clean:
	@rm -rfv bin
