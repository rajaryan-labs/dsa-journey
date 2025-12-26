#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// ITERATOR INCREMENT (++) & DECREMENT (--)
// ==========================================

/*
    1. Pre-Increment (++it) vs Post-Increment (it++)
    -------------------------------------------------
    - Use PRE-INCREMENT (++it) whenever possible.
    - REASON: 
      - 'it++' creates a temporary copy of the iterator to return the old value.
      - '++it' modifies the iterator in place and returns a reference.
      - Avoiding the temporary copy makes '++it' more efficient.

    2. Pre-Decrement (--it) vs Post-Decrement (it--)
    -------------------------------------------------
    - Similarly, use PRE-DECREMENT (--it) whenever possible.
    - REASON:
      - 'it--' creates a temporary copy of the old state.
      - '--it' modifies the iterator in place.
    
    NOTE: While modern compilers optimize this for simple pointers/vectors, 
    it is a best practice for all STL containers (lists, maps, sets).
*/

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    // ------------------------------------------
    // Example 1: Forward Traversal (Using ++)
    // ------------------------------------------
    cout << "Forward Traversal (Preferred: ++it): ";
    for(auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " "; 
    }
    cout << endl;

    // ------------------------------------------
    // Example 2: Backward Traversal (Using --)
    // ------------------------------------------
    // Start from the last element. 
    // v.end() points PAST the last element, so we must decrement first.
    
    cout << "Backward Traversal (Preferred: --it): ";
    
    auto it = v.end();
    while (it != v.begin()) {
        --it; // Move back BEFORE accessing
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
