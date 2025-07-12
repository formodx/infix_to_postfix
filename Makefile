CC := gcc
CFLAGS := -pedantic
INCDIR := include
SRCDIR := src
OBJDIR := obj
TARGET := i2p


sources := $(wildcard $(SRCDIR)/*.c)
objects := $(sources:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


.PHONY: clean rebuild


$(TARGET): $(objects)
	$(CC) $(CFLAGS) -o $@ $^


$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -c $(CFLAGS) -I $(INCDIR) -o $@ $<


$(OBJDIR):
	mkdir $(OBJDIR)


clean:
	rm -rf $(OBJDIR) $(TARGET)


rebuild: clean $(TARGET)