/**
 * std::set in C++ STL
 *
 * A Set is an associative container that stores UNIQUE elements in SORTED order.
 *
 * Key Features:
 * - Unique Keys: No duplicates allowed. If you insert a duplicate, it is ignored.
 * - Ordered: Elements are always sorted (default: ascending).
 * - Underlying Structure: Binary Search Tree (Red-Black Tree).
 * - Complexity: Insert, Delete, Search are O(log N).
 * - Modification: You cannot modify elements in place (they are const). You must erase and re-insert.
 */

#include <iostream>
#include <set>

using namespace std;

int main() {
    // ------------------------------------
    // 1. Initialization & Insertion
    // ------------------------------------
    cout << "Step 1: Initialization & Insertion" << endl;
    
    set<int> st;

    // insert(): O(log N)
    st.insert(10);
    st.insert(5);
    st.insert(20);
    st.insert(5); // Duplicate - Ignored!
    
    // emplace(): Constructs in-place
    st.emplace(15);
    
    // Order: 5, 10, 15, 20 (Sorted)


    // ------------------------------------
    // 2. Traversal
    // ------------------------------------
    cout << "\nStep 2: Traversal (Sorted Order)" << endl;
    
    for (int val : st) {
        cout << val << " ";
    }
    cout << endl; // Output: 5 10 15 20


    // ------------------------------------
    // 3. Finding Elements
    // ------------------------------------
    cout << "\nStep 3: Finding Elements" << endl;
    
    // find(val): Returns iterator to element if found, else end() - O(log N)
    if (st.find(10) != st.end()) {
        cout << "Found 10" << endl;
    }
    
    // count(val): Returns 1 if exists, 0 otherwise - O(log N)
    if (st.count(20)) {
        cout << "20 exists" << endl;
    }


    // ------------------------------------
    // 4. Removal
    // ------------------------------------
    cout << "\nStep 4: Removal" << endl;
    
    // erase(val): O(log N)
    st.erase(10); // Removes 10
    
    // erase(iterator): O(1) amortized
    auto it = st.find(5);
    if (it != st.end()) {
        st.erase(it); // Removes 5
    }
    
    cout << "After removal: ";
    for (int val : st) cout << val << " ";
    cout << endl; // Output: 15 20


    // ------------------------------------
    // 5. Bounds (Lower & Upper)
    // ------------------------------------
    cout << "\nStep 5: Lower & Upper Bounds" << endl;
    
    // Re-populating for demonstration
    st.insert(30);
    st.insert(40);
    st.insert(50);
    // Content: 15, 20, 30, 40, 50
    
    // lower_bound(k): Iterator to first element >= k
    auto lb = st.lower_bound(30); // Points to 30
    cout << "lower_bound(30): " << *lb << endl;
    
    // upper_bound(k): Iterator to first element > k
    auto ub = st.upper_bound(30); // Points to 40
    cout << "upper_bound(30): " << *ub << endl;
    
    /*
     * Comparison Summary:
     * 1. set: Unique, Sorted, O(log N)
     * 2. multiset: Duplicates, Sorted, O(log N)
     * 3. unordered_set: Unique, Unsorted, O(1) Avg
     */

    return 0;
}
