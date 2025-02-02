CC = gcc
CFLAGS = -lmenu -lncurses -lSDL2 -lSDL2_mixer -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c\
		  $(SRCDIR)windows/*.c\
		  $(SRCDIR)entities/*.c\
		  $(SRCDIR)/entities/items/*.c\
		  $(SRCDIR)utils/*.c


all: rogue

rogue: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./rogue

clean:
	rm rogue