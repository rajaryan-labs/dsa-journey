/**
 * std::multiset in C++ STL
 *
 * A MultiSet is an associative container like std::set, but it allows DUPLICATE
 * elements. Elements are sorted.
 *
 * Key Features:
 * - Duplicate Keys: Allowed!
 * - Ordered: Always sorted (default: ascending).
 * - Underlying Structure: Binary Search Tree (Red-Black Tree).
 * - Complexity: Insert, Delete, Search are O(log N).
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  // ------------------------------------
  // 1. Initialization Methods
  // ------------------------------------
  cout << "Step 1: Initialization Methods" << endl;

  // a) Default Constructor
  multiset<int> ms;

  // b) Initializer List (Sorted, Duplicates Kept)
  multiset<int> ms2 = {10, 20, 10, 5, 20}; 
  // Result: {5, 10, 10, 20, 20}
  cout << "Initializer List MultiSet: ";
  for(int x : ms2) cout << x << " ";
  cout << endl;

  // c) Range Constructor
  vector<int> vec = {3, 1, 4, 1, 5};
  multiset<int> ms3(vec.begin(), vec.end()); 
  // Result: {1, 1, 3, 4, 5} (Duplicates preserved)
  cout << "Range MultiSet: ";
  for(int x : ms3) cout << x << " ";
  cout << endl;

  // d) Copy Constructor
  multiset<int> ms4(ms3);

  // ------------------------------------
  // 2. Insertion
  // ------------------------------------
  cout << "\nStep 2: Insertion" << endl;

  // insert(): O(log N)
  ms.insert(10);
  ms.insert(20);
  ms.insert(10);  // Duplicate allowed
  ms.insert(10);  // Another duplicate
  ms.emplace(5);

  // Order: 5, 10, 10, 10, 20 (Sorted)

  // ------------------------------------
  // 3. Traversal
  // ------------------------------------
  cout << "\nStep 3: Traversal (Sorted duplicates)" << endl;

  for (int val : ms) {
    cout << val << " ";
  }
  cout << endl;  // Output: 5 10 10 10 20

  // ------------------------------------
  // 4. Counting & Finding
  // ------------------------------------
  cout << "\nStep 4: Counting & Finding" << endl;

  // count(val): Returns number of occurrences - O(log N)
  cout << "Count of 10: " << ms.count(10) << endl;  // Expected: 3

  // find(val): Returns iterator to the FIRST occurrence - O(log N)
  auto it = ms.find(10);
  if (it != ms.end()) {
    cout << "Found first occurrence of 10" << endl;
  }

  // ------------------------------------
  // 5. Removal
  // ------------------------------------
  cout << "\nStep 5: Removal" << endl;

  // erase(val): Removes ALL instances of that value!
  // ms.erase(10); // Would remove all three 10s

  // erase(iterator): Removes ONLY the element pointed to
  if (it != ms.end()) {
    ms.erase(it);  // Removes just one '10'
    cout << "Removed one instance of 10." << endl;
  }

  cout << "Count of 10 after single removal: " << ms.count(10)
       << endl;  // Expected: 2

  // ------------------------------------
  // 6. Bounds & Equal Range
  // ------------------------------------
  cout << "\nStep 6: Equal Range" << endl;

  // equal_range(val): Returns pair {first, last} iterators containing all
  // instances of val

  // insert more values for better visiualisation
  ms.insert(10);
  ms.insert(10);

  auto range = ms.equal_range(10);

  cout << "Iterating all 10s: ";
  for (auto i = range.first; i != range.second; ++i) {
    cout << *i << " ";
  }
  cout << endl;

  // ------------------------------------
  // 6. Comparison: Set vs MultiSet vs UnorderedSet
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
   */

  return 0;
}
