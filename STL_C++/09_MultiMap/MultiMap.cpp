/**
 * std::multimap in C++ STL
 *
 * A MultiMap is an associative container like std::map, but it allows MULTIPLE values for the same key.
 * Elements are still sorted by key.
 *
 * Key Features:
 * - Duplicate Keys: Allowed! (e.g., storing multiple students with the same name).
 * - Sorted: Always stored in sorted order of keys.
 * - No operator[]: Since multiple values exist for a key, `m["key"]` is ambiguous and NOT supported.
 * - Complexity: Insert, Delete, Search are O(log N).
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // ------------------------------------
    // 1. Initialization & Insertion
    // ------------------------------------
    cout << "Step 1: Initialization & Insertion" << endl;
    
    // Declaration
    multimap<string, int> mm;

    // insert(): We must use insert() or emplace(). operator[] is NOT available.
    mm.insert({"Harry", 100});
    mm.insert({"Ron", 90});
    mm.insert({"Harry", 80}); // Duplicate key "Harry" allowed!
    mm.insert({"Hermione", 110});
    
    // emplace()
    mm.emplace("Ron", 50); // Another "Ron"
    
    // Order in map (Sorted by Key):
    // Harry -> 100
    // Harry -> 80
    // Hermione -> 110
    // Ron -> 90
    // Ron -> 50


    // ------------------------------------
    // 2. Traversal
    // ------------------------------------
    cout << "\nStep 2: Traversal (Sorted)" << endl;
    
    for (const auto& p : mm) {
        cout << p.first << " -> " << p.second << endl;
    }


    // ------------------------------------
    // 3. Counting & Finding
    // ------------------------------------
    cout << "\nStep 3: Counting & Finding" << endl;
    
    // count(key): Returns number of elements with that key - O(log N)
    cout << "Count of 'Harry': " << mm.count("Harry") << endl; // Expected: 2
    
    // find(key): Returns iterator to the FIRST occurrence of the key
    auto it = mm.find("Harry");
    if(it != mm.end()) {
        cout << "First occurrence of 'Harry': " << it->second << endl;
    }


    // ------------------------------------
    // 4. Iterating over specific key (equal_range)
    // ------------------------------------
    cout << "\nStep 4: Iterating all values for 'Harry'" << endl;
    
    // equal_range(key): Returns a pair of iterators {first_iterator, last_iterator}
    // representing the range of all elements with that key.
    auto range = mm.equal_range("Harry");
    
    // Iterate from range.first (start) up to range.second (end)
    for (auto it = range.first; it != range.second; ++it) {
        cout << "Harry: " << it->second << endl;
    }


    // ------------------------------------
    // 5. Removal
    // ------------------------------------
    cout << "\nStep 5: Removal" << endl;
    
    // erase(key): Removes ALL instances of that key!
    cout << "Erasing 'Ron' (All instances)..." << endl;
    mm.erase("Ron");
    
    cout << "New Count of 'Ron': " << mm.count("Ron") << endl; // Expected: 0
    
    // erase(iterator): Remove specific instance
    // Let's remove just one "Harry"
    auto harryIt = mm.find("Harry"); // Finds first Harry
    if(harryIt != mm.end()) {
        mm.erase(harryIt); // Removes only that specific entry
        cout << "Removed one 'Harry'. Remaining count: " << mm.count("Harry") << endl;
    }

    // ------------------------------------
    // 6. Comparison: Map vs MultiMap vs UnorderedMap
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
