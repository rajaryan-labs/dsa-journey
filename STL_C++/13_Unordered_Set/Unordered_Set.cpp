/**
 * std::unordered_set in C++ STL
 *
 * An Unordered Set is an associative container that stores UNIQUE elements in NO PARTICULAR ORDER.
 * It is implemented using Hash Tables.
 *
 * Key Features:
 * - Unique Keys: No duplicates allowed.
 * - Unsorted: Order is random/undefined (depends on hash function).
 * - Underlying Structure: Hash Table.
 * - Complexity: Insert, Delete, Search are O(1) on average.
 *   (Can degrade to O(N) in worst case collisions, though rare).
 */

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // ------------------------------------
    // 1. Initialization & Insertion
    // ------------------------------------
    cout << "Step 1: Initialization & Insertion" << endl;
    
    unordered_set<int> us;

    // insert(): O(1) Avg
    us.insert(10);
    us.insert(5);
    us.insert(20);
    us.insert(5); // Duplicate - Ignored!
    
    // emplace(): O(1) Avg
    us.emplace(15);
    
    // Order is NOT guaranteed to be sorted.
    // Possible output: 20 10 5 15 (Random)


    // ------------------------------------
    // 2. Traversal
    // ------------------------------------
    cout << "\nStep 2: Traversal (Random/Hash Order)" << endl;
    
    for (int val : us) {
        cout << val << " ";
    }
    cout << endl;


    // ------------------------------------
    // 3. Finding Elements
    // ------------------------------------
    cout << "\nStep 3: Finding Elements (O(1) Avg)" << endl;
    
    // find(val): Returns iterator - O(1) Avg
    if (us.find(10) != us.end()) {
        cout << "Found 10" << endl;
    }
    
    // count(val): Returns 1 or 0 - O(1) Avg
    if (us.count(20)) {
        cout << "20 exists" << endl;
    }


    // ------------------------------------
    // 4. Removal
    // ------------------------------------
    cout << "\nStep 4: Removal" << endl;
    
    // erase(val): O(1) Avg
    us.erase(10);
    cout << "After removing 10, count: " << us.count(10) << endl;


    // ------------------------------------
    // 5. Comparison: Set vs MultiSet vs UnorderedSet
    // ------------------------------------
    /*
     * 1. std::set
     *    - Ordered: YES
     *    - Unique: YES
     *    - Implementation: BST (Red-Black Tree)
     *    - Complexity: O(log N)
     *
     * 2. std::multiset
     *    - Ordered: YES
     *    - Unique: NO (Duplicates allowed)
     *    - Implementation: BST
     *    - Complexity: O(log N)
     *
     * 3. std::unordered_set
     *    - Ordered: NO (Hash)
     *    - Unique: YES
     *    - Implementation: Hash Table
     *    - Complexity: O(1) Avg
     *    - Note: lower_bound/upper_bound are NOT available because elements are not sorted.
     */

    return 0;
}
