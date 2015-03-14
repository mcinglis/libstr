
##############################
### VARIABLES
##############################

DEPS_DIR ?= ./deps

CPPFLAGS += -I$(DEPS_DIR)

cflags_std := -std=c11
cflags_warnings := -Wall -Wextra -pedantic \
                   -Wcomments -Wformat=2 -Wlogical-op -Wmissing-include-dirs \
                   -Wnested-externs -Wold-style-definition -Wredundant-decls \
                   -Wshadow -Wstrict-prototypes -Wunused-macros -Wvla \
                   -Wwrite-strings

CFLAGS ?= $(cflags_std) -g $(cflags_warnings)

TPLRENDER ?= $(DEPS_DIR)/tplrender/tplrender

sources := $(wildcard *.c)
objects := $(sources:.c=.o)
mkdeps  := $(sources:.c=.dep.mk)

maybe_size_def := $(DEPS_DIR)/libmaybe/def/maybe-size.h



##############################
### BUILDING
##############################

.PHONY: all
all: objects

.PHONY: fast
fast: CPPFLAGS += -DNDEBUG
fast: CFLAGS = $(cflags_std) -O3 $(cflags_warnings)
fast: all

.PHONY: objects
objects: $(objects)

.PHONY: clean
clean:
	rm -rf $(objects) $(mkdeps) $(maybe_size_def)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MF "$(@:.o=.dep.mk)" -c $< -o $@

str.o strm.o: $(maybe_size_def)

$(maybe_size_def): $(DEPS_DIR)/libmaybe/def.h.jinja
	$(TPLRENDER) $< "size_t" -o $@


-include $(mkdeps)

