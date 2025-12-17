#include <iostream>
#include <vector>

using namespace std;

// 4. ITERATORS & LOOPS
// This file demonstrates different ways to iterate through a vector.

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // 1. Forward Loop (Using Iterators)
    // begin(): iterator to first element
    // end(): iterator to "past-the-last" element
    cout << "Forward Iterator: ";
    vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 2. Backward Loop (Using Reverse Iterators)
    // rbegin(): iterator to last element
    // rend(): iterator to "before-the-first" element
    cout << "Backward Iterator: ";
    // Using auto for brevity (type is vector<int>::reverse_iterator)
    for(auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // 3. Range-based For Loop (C++11 Modern)
    // The cleanest and preferred way for simple traversal.
    cout << "Range-based Loop: ";
    for(int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // 4. Constant Iterators
    // Used when you want to iterate but ensure elements are not modified.
    // cbegin(), cend()
    cout << "Const Iterator: ";
    for(auto cit = vec.cbegin(); cit != vec.cend(); ++cit) {
        cout << *cit << " ";
        // *cit = 100; // ERROR: Cannot modify read-only location
    }
    cout << endl;

    return 0;
}
