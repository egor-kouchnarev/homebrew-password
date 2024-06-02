CC = gcc
CFLAGS = -Wall -Wextra -O2

password: src/main.c
    $(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
    rm -f passphrase