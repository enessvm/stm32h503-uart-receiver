#include "ring_buffer.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

RingBuffer *rb_init(RingBuffer *rb)
{
    rb->read_idx = 0;
    rb->write_idx = 0;
    rb->size = 0;
    return rb;
}

void rb_write(RingBuffer *rb, uint8_t item)
{
    rb->rx_buffer[rb->write_idx++] = item;

    if (rb->write_idx >= BUFFER_SIZE)
    {
        rb->write_idx = 0;
    }

    rb->size++;
}

uint8_t rb_read(RingBuffer *rb)
{
    assert(rb->size > 0 && "There is no data to read!");

    uint8_t ret = rb->rx_buffer[rb->read_idx++];

    if (rb->read_idx >= BUFFER_SIZE)
    {
        rb->read_idx = 0;
    }

    rb->size--;
    return ret;
}

uint8_t peek(const RingBuffer *rb)
{
    assert(rb->size > 0 && "There is no data to read!");

    return rb->rx_buffer[rb->read_idx];
}

size_t rb_size(const RingBuffer *rb)
{
    return rb->size;
}

bool rb_is_full(const RingBuffer *rb)
{
    return rb->size == BUFFER_SIZE;
}

bool rb_is_empty(const RingBuffer *rb)
{
    return rb->size == 0;
}

void rb_reset(RingBuffer *rb)
{
    rb->write_idx = 0;
    rb->read_idx = 0;
    rb->size = 0;
}
