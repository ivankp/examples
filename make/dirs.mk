SRCDIR := test
BLDDIR := build

.PHONY: all

SRCS := $(shell find $(SRCDIR) -type f -name "*.in")
OBJS := $(patsubst $(SRCDIR)/%.in,$(BLDDIR)/%.o,$(SRCS))
BLDDIRS := $(shell find $(SRCDIR) -type d | sed "s|^$(SRCDIR)|$(BLDDIR)|")

all: $(OBJS)

.SECONDEXPANSION:

$(OBJS): $$(dir $$@)
	@echo "$@ : $^"
	@touch $@

$(BLDDIRS): | $$(dir $$@)
	@echo "$@ : $^"
	@mkdir $@

