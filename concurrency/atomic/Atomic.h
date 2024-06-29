#include <stdint.h>

typedef volatile int64_t* AtomicStorage;


// struct MemoryOrder 
// {
//     int RELAXED = 0;
//     int SEQ_CST = 1;
//     int RELEASE = 2;
//     int ACQUIRE = 3;
// };

void __atomicStore(AtomicStorage storage, int64_t val);

int64_t __atomicLoad(AtomicStorage storage);

int64_t __atomicExhange(AtomicStorage storage, int64_t val);