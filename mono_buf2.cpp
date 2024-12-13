#include <vector>
#include <memory_resource>
#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
void print_vector(const string &name, T vec)
{
    cout << name << ": ";
    for(const auto &x: vec) {
        cout << x << " ";
    }
    cout << endl;
}


int main(int argc, char const *argv[])
{
    // Will allocate 16 byte each time.
    pmr::monotonic_buffer_resource resource(16);

    pmr::vector<int> data1{{1,2,3,4}, &resource};
    pmr::vector<int> data2{{5,6,7,8}, &resource};
    
    cout << "data1[0] addr: " << hex << static_cast<void*>(&data1[0]) << endl;
    cout << "data2[0] addr: " << hex << static_cast<void*>(&data2[0]) << endl;
    
    cout << "data1 capacity: " << data1.capacity() << endl;
    cout << "data2 capacity: " << data2.capacity() << endl;
    
    print_vector("data1", data1);
    print_vector("data2", data2);

    return 0;
}
