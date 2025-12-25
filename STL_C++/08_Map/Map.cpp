/**
 * std::map in C++ STL
 *
 * A Map is an associative container that stores elements in Key-Value pairs.
 * Keys are unique and elements are stored in sorted order of keys.
 *
 * Key Features:
 * - Ordered: Elements are always sorted by key (default: ascending).
 * - Unique Keys: No duplicate keys allowed (use multimap for duplicates).
 * - Complexity: Insert, Delete, Search are O(log N) (implemented as Red-Black Tree).
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
    
    // Declaration: map<KeyType, ValueType> mapName;
    map<string, int> m;

    // operator[]: Inserts if key doesn't exist, updates if it does. O(log N)
    m["tv"] = 100;
    m["macbook"] = 50;
    m["airbuds"] = 100; // Duplicate values allowed, but keys must be unique

    // insert(): Inserts a pair. Does nothing if key already exists.
    m.insert({"apple vision pro", 25});
    
    // emplace(): Constructs in-place.
    m.emplace("meta glasses", 30);
    
    // Note: Keys are sorted lexicographically (alphabetical order for strings).
    // Order: airbuds, apple vision pro, macbook, meta glasses, tv


    // ------------------------------------
    // 2. Traversal (Sorted Order)
    // ------------------------------------
    cout << "\nStep 2: Traversal (Sorted Order)" << endl;
    
    for (const auto& p : m) {
        cout << p.first << " -> " << p.second << endl;
    }


    // ------------------------------------
    // 3. Finding Elements
    // ------------------------------------
    cout << "\nStep 3: Finding Elements" << endl;
    
    // find(key): Returns iterator to element if found, else returns end() - O(log N)
    string target = "iphone";
    auto it = m.find(target);
    
    if (it != m.end()) {
        cout << "Found " << target << ": " << it->second << endl;
    } else {
        cout << target << " not found." << endl;
    }
    
    // count(key): Returns 1 if key exists, 0 otherwise (since keys are unique) - O(log N)
    if (m.count("tv")) {
        cout << "Key 'tv' exists." << endl;
    }


    // ------------------------------------
    // 4. Removal
    // ------------------------------------
    cout << "\nStep 4: Removal" << endl;
    
    // erase(key): Removes element by key - O(log N)
    m.erase("tv");
    cout << "After erasing 'tv':" << endl;
    for (const auto& p : m) cout << "[" << p.first << "] "; 
    cout << endl;
    
    // erase(iterator): Remove specific element
    auto it2 = m.find("macbook");
    if (it2 != m.end()) m.erase(it2);
    cout << "After erasing 'macbook':" << endl;
    for (const auto& p : m) cout << "[" << p.first << "] ";
    cout << endl;


    // ------------------------------------
    // 5. Bounds (Lower & Upper) - Important!
    // ------------------------------------
    cout << "\nStep 5: Lower & Upper Bounds" << endl;
    
    // lower_bound(k): Iterator to first element >= k
    // upper_bound(k): Iterator to first element > k
    
    // Adding checking elements
    m["batman"] = 1;
    m["superman"] = 2;
    
    // Current keys: airbuds, apple vision pro, batman, meta glasses, superman
    
    string query = "b";
    auto lb = m.lower_bound(query); // First element >= "b" -> "batman"
    
    if(lb != m.end()) {
        cout << "lower_bound(\"b\"): " << lb->first << endl; 
    }
    
    auto ub = m.upper_bound("batman"); // First element > "batman" -> "meta glasses"
    if(ub != m.end()) {
        cout << "upper_bound(\"batman\"): " << ub->first << endl;
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