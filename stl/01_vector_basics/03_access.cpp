#include <iostream>
#include <vector>

using namespace std;

// 3. ELEMENT ACCESS
// This file demonstrates how to access elements in a vector.

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // 1. Operator []
    // Access element at index i. 
    // WARNING: No bounds checking. Undefined behavior if index is out of range.
    cout << "vec[2]: " << vec[2] << endl; // 30

    // 2. at() function
    // Access element at index i.
    // SAFE: Throws 'out_of_range' exception if index is invalid.
    cout << "vec.at(2): " << vec.at(2) << endl; // 30

    try {
        cout << vec.at(10); // Will throw exception
    } catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    // 3. front()
    // Returns reference to the first element.
    cout << "Front: " << vec.front() << endl; // 10

    // 4. back()
    // Returns reference to the last element.
    cout << "Back: " << vec.back() << endl; // 50

    // Note: Calling front() or back() on an empty vector is undefined behavior.

    return 0;
}
