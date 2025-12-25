/**
 * std::list in C++ STL
 *
 * A 'list' is a sequence container that implements a Doubly Linked List.
 *
 * Key Features:
 * - Non-contiguous memory: Nodes are scattered in memory and linked via pointers.
 * - Efficient insertion/deletion: O(1) at any position (given an iterator).
 * - No random access: You cannot access elements directly by index (e.g., list[2] is invalid).
 *   You must traverse the list to reach a specific element.
 * - Iterators: Bidirectional iterators (can move forward and backward).
 */

#include <iostream>
#include <vector>
#include <list>
#include <iterator> // For std::advance

using namespace std;

// Helper function to print the list with a descriptive message
void printList(const list<int>& l, const string& message) {
    cout << message << ": [ ";
    for (int val : l) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main() {
    // ------------------------------------
    // 1. Initialization
    // ------------------------------------
    cout << "Step 1: Initialization" << endl;
    // Initializing a list with values
    list<int> l = {1, 2, 3, 4, 5}; 
    
    // Other ways to initialize:
    // list<int> l2(5, 100);       // List of size 5 with all values 100
    // list<int> l3(l);            // Copy constructor
    
    printList(l, "Initial list");

    // ------------------------------------
    // 2. Insertion Operations
    // ------------------------------------
    cout << "\nStep 2: Insertion Operations" << endl;
    
    // push_back(): Insert at the end - O(1)
    l.push_back(6);      
    cout << "push_back(6) -> Added 6 to the end." << endl;

    // emplace_back(): Construct at the end - O(1)
    // More efficient than push_back as it constructs the element in-place
    l.emplace_back(7);   
    cout << "emplace_back(7) -> Constructed 7 at the end." << endl;
    
    // push_front(): Insert at the beginning - O(1)
    l.push_front(0);     
    cout << "push_front(0) -> Added 0 to the beginning." << endl;

    // emplace_front(): Construct at the beginning - O(1)
    l.emplace_front(-1); 
    cout << "emplace_front(-1) -> Constructed -1 at the beginning." << endl;
    
    printList(l, "List after insertions");

    // ------------------------------------
    // 3. Deletion Operations
    // ------------------------------------
    cout << "\nStep 3: Deletion Operations" << endl;
    
    // pop_back(): Remove last element - O(1)
    l.pop_back();        // Removes 7
    cout << "pop_back() -> Removed last element." << endl;

    // pop_front(): Remove first element - O(1)
    l.pop_front();       // Removes -1
    cout << "pop_front() -> Removed first element." << endl;
    
    printList(l, "List after pop operations");

    // ------------------------------------
    // 4. Accessing Elements via Iterators (insert & erase)
    // ------------------------------------
    cout << "\nStep 4: Manipulation using Iterators" << endl;
    
    // Since we don't have random access (l[i]), we must use iterators to traverse.
    auto it = l.begin();
    
    // advance(): Moves the iterator forward by N steps - O(N)
    advance(it, 2); // Points to the element at index 2 (technically the 3rd node)
    cout << "Iterator advanced by 2 steps. Currently pointing to value: " << *it << endl;
    
    // insert(): Inserts BEFORE the iterator position - O(1) plus traversal time
    l.insert(it, 100); 
    cout << "insert(it, 100) -> Inserted 100 before the current iterator." << endl;
    printList(l, "List after insertion");
    
    // erase(): Removes the element AT the iterator position - O(1)
    // Note: 'it' still points to the old element location (which is now invalid after erase)
    // erase() returns a valid iterator to the *next* element.
    cout << "erase(it) -> Removing element at iterator (value was " << *it << ")." << endl;
    it = l.erase(it); // Removes the element 'it' pointed to
    
    if (it != l.end()) {
        cout << "Iterator now points to: " << *it << endl;
    }
    printList(l, "List after erasure");

    // ------------------------------------
    // 5. Utility Functions
    // ------------------------------------
    cout << "\nStep 5: Utility Functions" << endl;
    
    cout << "Size: " << l.size() << endl;
    cout << "Front element: " << l.front() << endl;
    cout << "Back element: " << l.back() << endl;
    cout << "Is empty? " << (l.empty() ? "Yes" : "No") << endl;

    // remove(): Removes ALL occurrences of a specific value - O(N)
    l.push_back(100); // Add another 100 for demonstration
    printList(l, "List before removing 100");
    
    cout << "remove(100) -> removing all elements with value 100." << endl;
    l.remove(100); 
    printList(l, "List after remove(100)");

    // reverse(): Reverses the order of elements - O(N)
    l.reverse();
    cout << "reverse() -> List reversed." << endl;
    printList(l, "Reversed List");

    // sort(): Sorts the list - O(N log N)
    // Note: std::sort(l.begin(), l.end()) generally doesn't work for list because it requires random access iterators.
    // List has its own member function sort().
    l.sort(); 
    cout << "sort() -> List sorted." << endl;
    printList(l, "Sorted List");

    return 0;
}