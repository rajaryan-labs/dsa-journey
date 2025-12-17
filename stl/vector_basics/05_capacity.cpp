#include <iostream>
#include <vector>

using namespace std;

// 5. CAPACITY
// This file covers methods related to the size and storage capacity of vectors.

int main() {
    vector<int> vec;

    // 1. empty()
    // Returns true (1) if vector is empty, false (0) otherwise.
    cout << "Is empty initially? " << (vec.empty() ? "Yes" : "No") << endl;

    // 2. size()
    // Returns the number of elements currently in the vector.
    cout << "Initial size: " << vec.size() << endl;

    // 3. capacity()
    // Returns the number of elements the vector can hold before allocating more memory.
    // Capacity usually grows geometrically (e.g., doubles) to ensure amortized O(1) push_back.
    cout << "Initial capacity: " << vec.capacity() << endl;

    cout << "\nPushing 5 elements...\n";
    for(int i=0; i<5; ++i) {
        vec.push_back(i);
        cout << "Added " << i << " -> Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;
    }

    // 4. reserve(n)
    // Requests that the vector capacity be at least enough to contain n elements.
    // Useful to avoid multiple reallocations if you know the size beforehand.
    cout << "\nReserving capacity of 20...\n";
    vec.reserve(20);
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

    // 5. shrink_to_fit() (C++11)
    // Requests the container to reduce its capacity to fit its size.
    cout << "\nShrinking to fit...\n";
    vec.shrink_to_fit();
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

    // 6. max_size()
    // Returns the maximum number of elements the vector can verify hold (system dependent).
    cout << "\nMax Size: " << vec.max_size() << endl;

    return 0;
}
