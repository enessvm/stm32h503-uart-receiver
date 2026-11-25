#include "ring_buffer.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

RingBuffer *rb_init(RingBuffer *rb, size_t capacity, uint8_t *buffer)
{
    // capacity should be power of two for easy wrap around
    if (capacity == 0 || ((capacity & (capacity - 1)) != 0))
    {
        return NULL;
    }

    rb->read_idx = 0;
    rb->write_idx = 0;
    rb->count = 0;
    rb->capacity = capacity;
    rb->buffer = buffer;
    return rb;
}

bool rb_write(RingBuffer *rb, uint8_t data)
{
    if (rb->count >= rb->capacity)
    {
        return false;
    }

    rb->buffer[rb->write_idx++] = data;

    // wrap around if index reaches to end
    rb->write_idx = rb->write_idx & (rb->capacity - 1);

    rb->count++;
    return true;
}

bool rb_read(RingBuffer *rb, uint8_t *data)
{
    if (rb->count == 0)
    {
        return false;
    }

    *data = rb->buffer[rb->read_idx++];

    // wrap around if index reaches to end
    rb->read_idx = rb->read_idx & (rb->capacity - 1);

    rb->count--;
    return true;
}

bool rb_peek(const RingBuffer *rb, uint8_t *data)
{
    if (rb->count == 0)
    {
        return false;
    }

    *data = rb->buffer[rb->read_idx];

    return true;
}

size_t rb_count(const RingBuffer *rb)
{
    return rb->count;
}

bool rb_is_full(const RingBuffer *rb)
{
    return rb->count == rb->capacity;
}

bool rb_is_empty(const RingBuffer *rb)
{
    return rb->count == 0;
}

void rb_reset(RingBuffer *rb)
{
    rb->write_idx = 0;
    rb->read_idx = 0;
    rb->count = 0;
}
