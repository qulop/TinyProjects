extern "C" {
#include "Atomic.h"
}
#include <atomic>


// Implementation for int64_t
class AtomicI64
{
    using ValueType = int64_t;
public:
    Atomic(ValueType val = 0) :
        m_storage(val)
    {}


    ValueType Load() const
    { return __atomicLoad(m_storage);
        
     }

    ValueType Exchange(ValueType val)
    { return __atomicExhange(m_storage, val); }

    void Store(ValueType val)
    { __atomicStore(m_storage, val); }
    
private:
    AtomicStorage m_storage = nullptr;
};