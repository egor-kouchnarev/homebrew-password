# Variables
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS =
SRC = src/main.c
OBJ = $(SRC:.c=.o)
BIN = password

# Rules
all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean install uninstall

install: $(BIN)
	mkdir -p $(DESTDIR)/usr/local/bin
	cp $(BIN) $(DESTDIR)/usr/local/bin/

uninstall:
	rm -f $(DESTDIR)/usr/local/bin/$(BIN)

clean:
	rm -f $(OBJ) $(BIN)