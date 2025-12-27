#include <iostream>
#include <vector>
#include <algorithm> // Required for binary_search, sort

using namespace std;

// ==========================================
// STL ALGORITHMS: BINARY SEARCH
// ==========================================
/*
    std::binary_search(start_iterator, end_iterator, target)
    
    - Checks if 'target' exists in the SORTED range.
    - Returns: boolean (true if found, false otherwise).
    - Time Complexity: O(log N).
    - PRE-REQUISITE: The range MUST be SORTED. If not, behavior is undefined.

    * Note: It only tells you IF it exists. It does NOT return the position.
      (Use lower_bound/upper_bound to get position/iterator).
*/

int main() {
    cout << "--- Binary Search ---" << endl;
    vector<int> v = {1, 4, 5, 8, 9}; // Sorted

    int target = 8;
    
    // Check if 8 exists
    bool exists = binary_search(v.begin(), v.end(), target);

    if (exists) {
        cout << target << " is present." << endl;
    } else {
        cout << target << " is NOT present." << endl;
    }

    // Try a non-existent element
    int target2 = 3;
    if (binary_search(v.begin(), v.end(), target2)) {
        cout << target2 << " is present." << endl;
    } else {
        cout << target2 << " is NOT present." << endl;
    }

    // Unsorted Example (Why it fails/requires sort)
    vector<int> v2 = {8, 1, 5, 9, 4};
    // binary_search(v2.begin(), v2.end(), 8) -> UNDEFINED BEHAVIOR (Might return false)
    
    sort(v2.begin(), v2.end()); // Must sort first!
    if (binary_search(v2.begin(), v2.end(), 8)) {
        cout << "8 found in v2 after sorting." << endl;
    }

    return 0;
}
