#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "ring_buffer.h"

#define RX_CAPACITY 8u
#define LOG_CAPACITY 2u

static uint8_t rx_storage[RX_CAPACITY];
static uint8_t log_storage[LOG_CAPACITY];

#define N 16

int main()
{
    RingBuffer rx_rb;
    RingBuffer log_rb;

    rb_init(&rx_rb, sizeof(rx_storage), rx_storage);
    rb_init(&log_rb, sizeof(log_storage), log_storage);

    uint8_t nums[N];
    for (size_t i = 0; i < N; ++i)
    {
        nums[i] = i;
    }

    for (size_t i = 0; i < N; ++i)
    {
        bool ok = rb_write(&rx_rb, nums[i]);
        printf("%zu. write %u -> %s, write_idx: %zu, count: %zu\n",
               i + 1, nums[i], ok ? "ok" : "FULL", rx_rb.write_idx, rb_count(&rx_rb));

        if (i % 3 == 0)
        {
            uint8_t byte;
            if (rb_read(&rx_rb, &byte))
            {
                printf("   read  %u, read_idx: %zu\n", byte, rx_rb.read_idx);
            }
            else
            {
                printf("   read  -> EMPTY\n");
            }
        }
    }
    return 0;
}
