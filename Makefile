CFLAGS=-std=c17 -Wall -Wextra -Werror -pedantic -Iinclude

ring_buffer: main.c src/ring_buffer.c include/ring_buffer.h
	$(CC) $(CFLAGS) -o ring_buffer main.c src/ring_buffer.c
