/**
 * std::queue in C++ STL
 *
 * A Queue is a container adapter that operates on FIFO (First In, First Out) principle.
 * Think of it like a line of people: the first person to join the line is the first one served.
 *
 * Key Features:
 * - Elements are inserted at the back (push) and removed from the front (pop).
 * - Elements are accessed from both ends: front() and back().
 * - No Iterators: You cannot traverse a queue (no begin()/end()).
 * - Complexity: All operations (push, pop, front, back, size, empty) are O(1).
 */

#include <iostream>
#include <queue>

using namespace std;

// Helper function to visualize queue content
// Note: Passing by value to create a copy, so we don't empty the original queue
void printQueue(queue<int> q, const string& name) {
    cout << name << ": [Front] ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "[Back]" << endl;
}

int main() {
    // ------------------------------------
    // 1. Initialization & Pushing
    // ------------------------------------
    cout << "Step 1: Initialization & Pushing" << endl;
    
    // Declaration: queue<Type> queueName;
    queue<int> q;

    // push(): Inserts element at the end (back) - O(1)
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.push(3); // {1, 2, 3}
    
    // emplace(): Constructs element in-place at the end - O(1)
    // Avoids temporary object creation.
    q.emplace(4); // {1, 2, 3, 4}
    
    // Visualization:
    // Front -> | 1 | 2 | 3 | 4 | <- Back
    printQueue(q, "Queue after pushes");


    // ------------------------------------
    // 2. Accessing Elements
    // ------------------------------------
    cout << "\nStep 2: Accessing Elements" << endl;
    
    if (!q.empty()) {
        // front(): Access the first element (the one to be removed next) - O(1)
        cout << "Front element: " << q.front() << endl; // Expected: 1
        
        // back(): Access the last element (the one most recently added) - O(1)
        cout << "Back element: " << q.back() << endl;   // Expected: 4
    }


    // ------------------------------------
    // 3. Removal Operations
    // ------------------------------------
    cout << "\nStep 3: Popping Elements" << endl;
    
    // pop(): Removes the element from the front - O(1)
    // Does NOT return the value.
    q.pop(); // Removes 1
    cout << "pop() called. New Front: " << q.front() << endl; // Expected: 2
    
    q.pop(); // Removes 2
    cout << "pop() called. New Front: " << q.front() << endl; // Expected: 3


    // ------------------------------------
    // 4. Size and Empty Check
    // ------------------------------------
    cout << "\nStep 4: Utility Functions" << endl;
    
    cout << "Size: " << q.size() << endl; // Expected: 2 (elements 3, 4)
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;


    // ------------------------------------
    // 5. Swapping
    // ------------------------------------
    cout << "\nStep 5: Swapping Queues" << endl;
    
    queue<int> q1;
    q1.push(100);
    q1.push(200);
    
    queue<int> q2;
    q2.push(5); 
    
    cout << "Before Swap -> q1 front: " << q1.front() << ", q2 front: " << q2.front() << endl;
    
    q1.swap(q2);
    
    cout << "After Swap  -> q1 front: " << q1.front() << ", q2 front: " << q2.front() << endl;

    return 0;
}
