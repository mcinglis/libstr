
##############################
### VARIABLES
##############################

DEPS_DIR ?= deps

CPPFLAGS += -I$(DEPS_DIR)

CFLAGS ?= -std=c11 -g \
          -Wall -Wextra -pedantic \
          -Wcomments -Wformat=2 -Wlogical-op -Wmissing-include-dirs \
          -Wnested-externs -Wold-style-definition -Wredundant-decls \
          -Wshadow -Wstrict-prototypes -Wunused-macros -Wvla \
          -Wwrite-strings \
          -Wno-unused-parameter

sources := $(wildcard *.c)
objects := $(sources:.c=.o)
mkdeps  := $(sources:.c=.dep.mk)



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


-include $(mkdeps)

