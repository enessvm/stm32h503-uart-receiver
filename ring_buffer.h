#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct RingBuffer
{
    size_t write_idx;
    size_t read_idx;
    size_t count;
    size_t capacity;
    uint8_t *buffer;
} RingBuffer;

RingBuffer *rb_init(RingBuffer *rb, size_t capacity, uint8_t *buffer);
bool rb_write(RingBuffer *rb, uint8_t data);
bool rb_read(RingBuffer *rb, uint8_t *data);
bool rb_peek(const RingBuffer *rb, uint8_t *data);
size_t rb_count(const RingBuffer *rb);
bool rb_is_full(const RingBuffer *rb);
bool rb_is_empty(const RingBuffer *rb);
void rb_reset(RingBuffer *rb);

#endif // RING_BUFFER_H
