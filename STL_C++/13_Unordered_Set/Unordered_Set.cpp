/**
 * std::unordered_set in C++ STL
 *
 * An Unordered Set is an associative container that stores UNIQUE elements in
 * NO PARTICULAR ORDER. It is implemented using Hash Tables.
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
#include <vector>

using namespace std;

int main() {
  // ------------------------------------
  // 1. Initialization Methods
  // ------------------------------------
  cout << "Step 1: Initialization Methods" << endl;

  // a) Default Constructor
  unordered_set<int> us;

  // b) Initializer List (Order Undefined)
  unordered_set<int> us2 = {10, 20, 5, 20}; 
  // Result: {20, 10, 5} or similar (Duplicates removed, order random)
  cout << "Initializer List Unordered Set: ";
  for(int x : us2) cout << x << " ";
  cout << endl;

  // c) Range Constructor
  vector<int> vec = {3, 1, 4, 1, 5};
  unordered_set<int> us3(vec.begin(), vec.end()); 
  // Result: {1, 3, 4, 5} (Order random)
  cout << "Range Unordered Set: ";
  for(int x : us3) cout << x << " ";
  cout << endl;

  // d) Copy Constructor
  unordered_set<int> us4(us3);

  // ------------------------------------
  // 2. Insertion
  // ------------------------------------
  cout << "\nStep 2: Insertion" << endl;

  // insert(): O(1) Avg
  us.insert(10);
  us.insert(5);
  us.insert(20);
  us.insert(5);  // Duplicate - Ignored!

  // emplace(): O(1) Avg
  us.emplace(15);

  // Order is NOT guaranteed to be sorted.
  // Possible output: 20 10 5 15 (Random)

  // ------------------------------------
  // 3. Traversal
  // ------------------------------------
  cout << "\nStep 3: Traversal (Random/Hash Order)" << endl;

  for (int val : us) {
    cout << val << " ";
  }
  cout << endl;

  // ------------------------------------
  // 4. Finding Elements
  // ------------------------------------
  cout << "\nStep 4: Finding Elements (O(1) Avg)" << endl;

  // find(val): Returns iterator - O(1) Avg
  if (us.find(10) != us.end()) {
    cout << "Found 10" << endl;
  }

  // count(val): Returns 1 or 0 - O(1) Avg
  if (us.count(20)) {
    cout << "20 exists" << endl;
  }

  // ------------------------------------
  // 5. Removal
  // ------------------------------------
  cout << "\nStep 5: Removal" << endl;

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
   *    - Note: lower_bound/upper_bound are NOT available because elements are
   * not sorted.
   */

  return 0;
}
