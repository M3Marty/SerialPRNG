#pragma once

extern long __serial_seed;

// Max value of serial_rand 
#define SERIAL_RAND_MAX 32767

// Set up randomizer
#define serial_srand(x) __serial_seed = x
// Current seed, copy it to recover flow from this point
#define serial_seed __serial_seed
#define __serial_next(x) (x = x * 1103515245 + 12345)
// Random number in range of 0 to SERIAL_RAND_MAX
#define serial_rand ((unsigned int) (__serial_next(__serial_seed) / 65536) % (SERIAL_RAND_MAX + 1))
// Random number in range of [0 to 1]
#define serial_random (serial_rand / SERIAL_RAND_MAX)
