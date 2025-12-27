#include <iostream>
#include <vector>
#include <algorithm> // Required for max_element, min_element

using namespace std;

// ==========================================
// STL ALGORITHMS: MAX & MIN ELEMENT
// ==========================================
/*
    std::max_element(start_iterator, end_iterator)
    - Returns an ITERATOR to the largest element in the range.
    - Time Complexity: O(N)

    std::min_element(start_iterator, end_iterator)
    - Returns an ITERATOR to the smallest element in the range.
    - Time Complexity: O(N)

    * To get the VALUE, dereference the iterator (*it).
    * To get the INDEX, subtract .begin() (it - v.begin()).
*/

int main() {
    cout << "--- Max & Min Element ---" << endl;
    vector<int> v = {10, 50, 20, 90, 30};

    // 1. Finding Max Element
    // Returns iterator pointing to 90
    auto max_it = max_element(v.begin(), v.end());
    
    // 2. Finding Min Element
    // Returns iterator pointing to 10
    auto min_it = min_element(v.begin(), v.end());

    if (max_it != v.end()) {
        cout << "Max Element Value: " << *max_it << endl;
        cout << "Max Element Index: " << (max_it - v.begin()) << endl; // Index 3
    }

    if (min_it != v.end()) {
        cout << "Min Element Value: " << *min_it << endl;
        cout << "Min Element Index: " << (min_it - v.begin()) << endl; // Index 0
    }

    // 3. Partial Range
    // Find min in range [1, 4) -> elements {50, 20, 90}
    auto partial_min = min_element(v.begin() + 1, v.begin() + 4);
    cout << "Min in range [1, 4): " << *partial_min << endl; // Should be 20

    return 0;
}
