// Example of allocator-aware type
#include <memory_resource>
#include <iostream>

using namespace std;

struct S
{
    // Make string long enough to bypass short string optimization
    pmr::string value = "value value value value value value value value";

    using alloc_type = pmr::polymorphic_allocator<>;

    S() = default;
    S(const S &) = default;
    S(S &&) = default;

    explicit S(const alloc_type &alloc) : value{"allocator allocator allocator allocator allocator", alloc} {}
    S(const S &other, const alloc_type &alloc) : value{other.value, alloc} {}
    S(S &&other, const alloc_type &alloc) : value{move(other.value), alloc} {}
};

template <typename T>
void print_line(const string &name, T value)
{
    cout << name << ": " << value << endl;
}

template <>
void print_line(const string &name, void *addr)
{
    cout << name << ": " << hex << addr << endl;
}

int main(int argc, char const *argv[])
{
    byte buf[1024];
    pmr::monotonic_buffer_resource resource(buf, sizeof buf);

    print_line("buf addr            ", static_cast<void *>(buf));
    print_line("buf[64] addr        ", static_cast<void *>(buf + 64));

    pmr::vector<S> vec{&resource};
    
    // The pmr::vector is using the allocator to allocate memory 
    // for S() inside the vector.
    vec.push_back(S());
    print_line("vec[0] addr         ", static_cast<void *>(&vec[0]));
    print_line("vec[0].value addr   ", static_cast<void *>(&vec[0].value));
    print_line("vec[0].value        ", vec[0].value);

    vec.push_back(S(&resource));
    print_line("vec[1] addr         ", static_cast<void *>(&vec[1]));
    print_line("vec[1].value addr   ", static_cast<void *>(&vec[1].value));
    print_line("vec[1].value        ", vec[1].value);

    // NOT all std types are allocator aware!

    return 0;
}
