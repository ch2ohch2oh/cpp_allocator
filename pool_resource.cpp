#include <vector>
#include <memory_resource>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

void print_addr(const string &name, void *addr)
{
    cout << name << ": " << hex << addr << endl;
}

class printing_resource : public std::pmr::memory_resource
{
public:
    printing_resource(std::pmr::memory_resource *upstream)
        : m_upstream(upstream)
    {
        assert(upstream);
    }

private:
    std::pmr::memory_resource *m_upstream;

    void *do_allocate(std::size_t bytes, std::size_t alignment) override
    {
        cout << "do_allocate(bytes=" << dec << bytes << ", alignment=" << alignment << ")" << endl;
        return m_upstream->allocate(bytes, alignment);
    }

    void do_deallocate(void *p, std::size_t bytes,
                       std::size_t alignment) override
    {
        cout << "do_deallocate(p=" << hex << p << ", bytes=" << dec << bytes << ", alignment=" << alignment << ")" << endl;
        m_upstream->deallocate(p, bytes, alignment);
    }

    bool do_is_equal(
        const std::pmr::memory_resource &other) const noexcept override
    {
        return this == &other;
    }
};

int main(int argc, char const *argv[])
{
    printing_resource p_resource(pmr::new_delete_resource());
    pmr::synchronized_pool_resource resource(&p_resource);

    // From this example, we can tell the min block size is 16 byte.
    for (size_t size = 1; size <= 1024; size *= 2)
    {
        for (int i = 0; i < 2; i++)
        {
            void *p = resource.allocate(size);
            cout << "allocate(" << setw(5) << dec << size << ") => " << hex << p << endl;
        }
    }

    return 0;
}
