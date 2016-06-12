EXE := $(patsubst %.cc,%,$(wildcard *.cc))

all: $(EXE)

$(EXE): %: %.cc
	@echo CC "$@"
	@g++ -Wall $^ -o $@

clean:
	@rm -fv $(EXE)
