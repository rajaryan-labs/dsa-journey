/**
 * Deque (Double-Ended Queue) in C++ STL
 *
 * A deque allows insertion and deletion at both ends (front and back)
 * efficiently. Unlike vectors, deques are not guaranteed to store elements
 * contiguously in memory, but they still support random access iterators.
 *
 * Key Features:
 * - Direct access to elements via operator[] or at().
 * - Efficient insertion/removal at the beginning and end: O(1).
 * - Dynamic size handling.
 */

#include <deque>
#include <iostream>

using namespace std;

int main() {
  // Declare a deque of integers
  deque<int> dq;

  cout << "Step 1: Inserting elements..." << endl;

  // push_front(): Insert element at the beginning - O(1)
  // Adds 5 to the front
  dq.push_front(5);

  // push_back(): Insert element at the end - O(1)
  // Adds 10 to the back
  dq.push_back(10);

  // Adds 15 to the back
  dq.push_back(15);

  // Adds 2 to the front
  dq.push_front(2);

  // emplace_front(): Construct and insert element at the beginning - O(1)
  // Constructs 100 in-place at the front (more efficient than push for objects)
  dq.emplace_front(100);

  // emplace_back(): Construct and insert element at the end - O(1)
  // Constructs 200 in-place at the back
  dq.emplace_back(200);

  // Current state visualization: [100, 2, 5, 10, 15, 200]
  cout << "Elements added: 100, 2, 5, 10, 15, 200" << endl;

  // Accessing elements
  cout << "\nStep 2: Accessing elements" << endl;
  cout << "Front element (dq.front()): " << dq.front()
       << endl;                                               // Expected: 100
  cout << "Back element (dq.back()): " << dq.back() << endl;  // Expected: 200

  // Random access
  // at() performs bounds checking, whereas operator[] does not.
  cout << "Element at index 1 (dq.at(1)): " << dq.at(1) << endl;  // Expected: 2

  // Removing elements
  cout << "\nStep 3: Removing elements" << endl;

  // pop_front(): Remove element from the beginning - O(1)
  cout << "Popping front..." << endl;
  dq.pop_front();                                               // Removes 100
  cout << "New Front after pop_front: " << dq.front() << endl;  // Expected: 2

  // pop_back(): Remove element from the end - O(1)
  cout << "Popping back..." << endl;
  dq.pop_back();                                             // Removes 200
  cout << "New Back after pop_back: " << dq.back() << endl;  // Expected: 15

  // Size and Empty check
  cout << "\nStep 4: Checking size and empty status" << endl;
  cout << "Size: " << dq.size() << endl;
  cout << "Is empty? " << (dq.empty() ? "Yes" : "No") << endl;

  // Traversal
  cout << "\nStep 5: Iterating through the deque" << endl;
  cout << "Final Deque elements: ";
  // Using range-based for loop for cleaner syntax
  for (int x : dq) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
