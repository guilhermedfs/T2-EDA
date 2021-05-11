TARGET   = ABP

CC       = gcc
CFLAGS   = -std=c99 -Wall -I.

LINKER   = gcc
LFLAGS   = -Wall -I. -lm

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       := rm -f
MKDIR_P  := $(shell mkdir -p $(OBJDIR))

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(MKDIR_P)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"
	@$(rm) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"


.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

.PHONY: run
run:
		cd bin && ./ABP