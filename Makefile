
##############################
### VARIABLES
##############################

DEPS_DIR ?= deps

LIBMAYBE := $(DEPS_DIR)/libmaybe

CPPFLAGS += -I$(DEPS_DIR)

CFLAGS ?= -std=c11 -g \
          -Wall -Wextra -pedantic \
          -Wcomments -Wformat=2 -Wlogical-op -Wmissing-include-dirs \
          -Wnested-externs -Wold-style-definition -Wredundant-decls \
          -Wshadow -Wstrict-prototypes -Wunused-macros -Wvla \
          -Wwrite-strings \
          -Wno-unused-parameter

TPLRENDER ?= $(DEPS_DIR)/tplrender/tplrender

sources := $(wildcard *.c)
objects := $(sources:.c=.o)
mkdeps  := $(sources:.c=.dep.mk)

maybe_size_def := $(LIBMAYBE)/def/maybe-size.h



##############################
### BUILDING
##############################

.PHONY: all
all: $(objects)

.PHONY: clean
clean:
	rm -rf $(objects) $(mkdeps) $(maybe_size_def)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MF "$(@:.o=.dep.mk)" -c $< -o $@

str.o strm.o: $(maybe_size_def)

$(maybe_size_def): $(LIBMAYBE)/def.h.jinja
	$(TPLRENDER) $< "size_t" -o $@


-include $(mkdeps)

