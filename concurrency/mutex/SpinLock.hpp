#include <atomic>



class SpinLock
{
    using AtomType = std::atomic<size_t>;
public:
    SpinLock() = default;

    void Lock()
    {
        auto myTicket = m_nextTicket.fetch_add(1);
        while (myTicket != m_currentTicket.load());
    }

    void Unlock()
    {
        m_currentTicket.fetch_add(1);
    }


private:
    AtomType m_currentTicket = 0;
    AtomType m_nextTicket = 0;
};