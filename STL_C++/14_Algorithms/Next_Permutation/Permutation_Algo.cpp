#include <iostream>
#include <vector>
#include <algorithm> // Required for next_permutation
#include <string>

using namespace std;

// ==========================================
// STL ALGORITHMS: NEXT PERMUTATION
// ==========================================
/*
    std::next_permutation(start, end)
    
    - Rearranges elements into the next lexicographically greater permutation.
    - Returns true if such a permutation exists.
    - Returns false if the container is already at the highest possible permutation (sorted descending),
      and resets it to the lowest possible permutation (sorted ascending).
    
    - Time Complexity: O(N) per call.
    - Note: To generate ALL permutations, start with a SORTED container.
*/

int main() {
    // 1. Basic Example
    cout << "--- 1. Basic Next Permutation ---" << endl;
    string s = "abc";

    // "abc" -> "acb" -> "bac" -> "bca" -> "cab" -> "cba" -> back to "abc"

    bool hasNext = next_permutation(s.begin(), s.end());
    if(hasNext) {
        cout << "Next permutation of 'abc' is: " << s << endl;
    }

    // 2. Generating All Permutations
    cout << "\n--- 2. Generating All Permutations ---" << endl;
    vector<int> v = {1, 3, 2}; // Start with unsorted

    // IMPORTANT: Sort first to get ALL permutations from the beginning
    sort(v.begin(), v.end()); // v becomes {1, 2, 3}

    cout << "All permutations of {1, 2, 3}:" << endl;
    do {
        for(int x : v) cout << x << " ";
        cout << endl;
    } while(next_permutation(v.begin(), v.end()));

    // 3. Previous Permutation
    // There is also prev_permutation() which goes backwards.
    cout << "\n--- 3. Previous Permutation ---" << endl;
    vector<int> v2 = {3, 2, 1}; // Largest permutation
    if (prev_permutation(v2.begin(), v2.end())) {
        cout << "Previous of {3, 2, 1} is: ";
        for(int x : v2) cout << x << " ";
        cout << endl;
    }

    return 0;
}
