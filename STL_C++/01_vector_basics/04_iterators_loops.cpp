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
    // Optimization Note: We use ++it (pre-increment) instead of it++ (post-increment)
    // because post-increment creates a temporary copy of the iterator to return the old value,
    // which can be slower for complex iterator types. Pre-increment just increments and returns valid reference.
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
    // Explicitly defining the reverse iterator type
    vector<int>::reverse_iterator rit;
    for(rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // ==========================================
    // UNDERSTANDING THE 'auto' KEYWORD
    // ==========================================
    // The 'auto' keyword (introduced in C++11) tells the compiler to automatically 
    // deduce the datatypes of a variable based on its initialization.
    // It is extremely useful for complex types like iterators.

    // Implementation 1: Auto with Standard Iterator Loop
    // Instead of typing 'vector<int>::iterator', we use 'auto'
    cout << "Auto with Standard Loop: ";
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Implementation 2: Auto with Range-based For Loop
    // This is the most modern and concise way to iterate.
    // 'val' takes the value of each element in 'vec' sequentially.
    cout << "Auto with Range-based Loop: ";
    for(auto val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // 4. Constant Iterators
    // Used when you want to iterate but ensure elements are not modified.
    // cbegin(), cend()
    cout << "Const Iterator: ";
    // auto helps here too! deduced as vector<int>::const_iterator
    for(auto cit = vec.cbegin(); cit != vec.cend(); ++cit) {
        cout << *cit << " ";
        // *cit = 100; // ERROR: Cannot modify read-only location
    }
    cout << endl;

    return 0;
}
