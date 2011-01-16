// HashFunctions.hpp : This file contains the interfaces for several hash functions that we
//                     can swap in and out. I figure we can test several and see what we like
//                     best.

#pragma once

// SuperFastHash
#include "stdint_superdyne.h"
uint32_t SuperFastHash (const char * data, int len);

// MurmurHash2A
// This is a variation of MurmurHash2 that I found at http://sites.google.com/site/murmurhash/
// It claims to be faster than SuperFast becasue it has a different way of processing data.
unsigned int MurmurHash2A ( const void * key, int len, unsigned int seed );

// Note: There is also a version of MurmurHash2A in the cpp file that is designed to work
//       "incrementally". We can pull that in here if we need.

