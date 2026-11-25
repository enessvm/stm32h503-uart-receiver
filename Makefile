CFLAGS=-std=c17 -Wall -Wextra -Werror -pedantic

ring_buffer: main.c ring_buffer.c ring_buffer.h
	$(CC) $(CFLAGS) -o ring_buffer main.c ring_buffer.c