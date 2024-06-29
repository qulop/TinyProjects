#include "Atomic.h"


void __atomicStore(AtomicStorage storage, int64_t val)
{
    __asm__ __volatile__(
        ""
        : 
    );
}

int64_t __atomicLoad(AtomicStorage storage)
{

}

int64_t __atomicExhange(AtomicStorage storage, int64_t val)
{

}