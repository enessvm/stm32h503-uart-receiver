#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "ring_buffer.h"
#define N 10

int main()
{
    RingBuffer rb;

    if (rb_init(&rb) == NULL)
    {
        return 1;
    }

    uint16_t nums[N];

    for (size_t i = 0; i < N; ++i)
    {
        nums[i] = i;
    }

    for (size_t i = 0; i < N; ++i)
    {
        rb_write(&rb, nums[i]);
    }

    for (size_t i = 0; i < N; ++i)
    {
        printf("Reading: %d\n", rb_read(&rb));
    }

    return 0;
}
