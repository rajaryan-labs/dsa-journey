/**
 * std::unordered_map in C++ STL
 *
 * An Unordered Map is an associative container that stores elements in Key-Value pairs.
 * Unlike std::map, elements are NOT sorted. They are organized using HASH TABLES.
 *
 * Key Features:
 * - Unsorted: Order of elements is undefined (random-looking).
 * - Unique Keys: No duplicate keys allowed.
 * - Complexity: Insert, Delete, Search are O(1) on average (O(N) in rare worst case).
 * - Faster than std::map for lookups/insertions when order doesn't matter.
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // ------------------------------------
    // 1. Initialization & Insertion
    // ------------------------------------
    cout << "Step 1: Initialization & Insertion" << endl;
    
    // Declaration
    unordered_map<string, int> um;

    // Insertion: Same usage as std::map
    um.insert({"TV", 100});
    um.insert({"Laptop", 50});
    um.emplace("Headphones", 25);
    
    // operator[]: O(1) average
    um["Mouse"] = 10;
    um["Keyboard"] = 20;

    // Note: The order of storage depends on the Hash Function.
    // It will likely NOT be alphabetical.


    // ------------------------------------
    // 2. Traversal
    // ------------------------------------
    cout << "\nStep 2: Traversal (Unsorted)" << endl;
    
    // Output order is not guaranteed to be alphabetical!
    for (const auto& p : um) {
        cout << p.first << " -> " << p.second << endl;
    }


    // ------------------------------------
    // 3. Finding Elements
    // ------------------------------------
    cout << "\nStep 3: Finding Elements (O(1) Avg)" << endl;
    
    string target = "TV";
    
    // find(key): Returns iterator - O(1)
    if (um.find(target) != um.end()) {
        cout << "Found " << target << endl;
    } else {
        cout << target << " not found." << endl;
    }
    
    // count(key): Returns 1 or 0 - O(1)
    if (um.count("Laptop")) {
        cout << "Laptop exists in the map." << endl;
    }


    // ------------------------------------
    // 4. Removal
    // ------------------------------------
    cout << "\nStep 4: Removal" << endl;
    
    // erase(key): O(1) average
    um.erase("Mouse");
    cout << "After erasing 'Mouse':" << endl;
    for (const auto& p : um) cout << "[" << p.first << "] ";
    cout << endl;

    // ------------------------------------
    // 5. Comparison: Map vs MultiMap vs UnorderedMap
    // ------------------------------------
    /*
     * 1. std::map
     *    - Ordered: YES (Sorted by Key)
     *    - Unique Keys: YES
     *    - Implementation: Self-Balancing BST (Red-Black Tree)
     *    - Complexity: O(log N)
     *
     * 2. std::multimap
     *    - Ordered: YES
     *    - Unique Keys: NO (Duplicates allowed)
     *    - Implementation: Self-Balancing BST
     *    - Complexity: O(log N)
     *
     * 3. std::unordered_map
     *    - Ordered: NO (Random/Hash order)
     *    - Unique Keys: YES
     *    - Implementation: Hash Table
     *    - Complexity: O(1) Average
     */

    return 0;
}
