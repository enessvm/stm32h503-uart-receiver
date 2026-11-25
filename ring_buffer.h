#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define BUFFER_SIZE 256 // in byte

typedef struct RingBuffer
{
    size_t write_idx;
    size_t read_idx;
    size_t size;
    uint8_t rx_buffer[BUFFER_SIZE];
} RingBuffer;

RingBuffer *rb_init(RingBuffer *rb);
void rb_write(RingBuffer *rb, uint8_t item);
uint8_t rb_read(RingBuffer *rb);
uint8_t peek(const RingBuffer *rb);
size_t rb_size(const RingBuffer *rb);
bool rb_is_full(const RingBuffer *rb);
bool rb_is_empty(const RingBuffer *rb);
void rb_reset(RingBuffer *rb);

#endif // RING_BUFFER_H_