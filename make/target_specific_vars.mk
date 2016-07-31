EXE := a test/b
OBJ := $(EXE:%=%.o)

.PHONY: $(EXE) $(OBJ)

all: $(EXE)

LIBS_a := -lfoo
LIBS_test/b := -lbar

$(EXE): %: %.o
	@printf "$@:\n\t$^ $(LIBS_$@)\n\n"

$(OBJ): %.o:
	@printf "$@ needs $(LIBS_$*)\n"

# No secondary expansion is necessary

