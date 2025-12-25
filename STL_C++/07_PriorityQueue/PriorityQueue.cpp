/**
 * std::priority_queue in C++ STL
 *
 * A Priority Queue is a container adapter that provides constant time lookup of the largest (by default) element.
 *
 * Key Operations:
 * - push/emplace: Insert element. O(log N)
 * - pop: Remove the "top" element. O(log N)
 * - top: Access the "top" element. O(1)
 *
 * Internal Structure:
 * - By default, it acts as a MAX HEAP (Largest element is at the top).
 * - Underlying container is usually a std::vector.
 */

#include <iostream>
#include <queue>
#include <vector>
#include <functional> // For std::greater

using namespace std;

// Helper to print and empty a copy of the priority_queue
template<typename T>
void printPQ(T pq, const string& name) {
    cout << name << ": [Top] ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    // ------------------------------------
    // 1. Max Heap (Default Behavior)
    // ------------------------------------
    cout << "Step 1: Max Heap (Default)" << endl;
    
    // Declaration: priority_queue<Type>
    // Internally rearranges elements so the largest is always at the top.
    // NOTE: It behaves like a STACK so far as you only access/remove the 'top' element.
    // However, unlike a normal stack (LIFO), the 'top' is decided by priority (Value),
    // not by insertion order.
    priority_queue<int> maxPQ;

    // push/emplace: O(log N)
    maxPQ.push(5);
    maxPQ.push(2);
    maxPQ.push(10);
    maxPQ.emplace(8); 
    
    // Visualization of pushes:
    // 5
    // 5, 2 -> 5 is top
    // 5, 2, 10 -> 10 is top
    // 10, 8, 5, 2 (approximate structure)
    
    cout << "Top element (Max): " << maxPQ.top() << endl; // Expected: 10
    
    printPQ(maxPQ, "Max Queue content"); // Prints: 10 8 5 2


    // ------------------------------------
    // 2. Removal (Max Heap)
    // ------------------------------------
    cout << "\nStep 2: Removal from Max Heap" << endl;
    
    // pop(): Removes the top (largest) element - O(log N)
    maxPQ.pop(); // Removes 10
    cout << "After pop(), new Top: " << maxPQ.top() << endl; // Expected: 8
    
    
    // ------------------------------------
    // 3. Min Heap (Custom Comparator)
    // ------------------------------------
    cout << "\nStep 3: Min Heap" << endl;
    
    // To make a Min Heap (Smallest at top), we need to specify the container and comparator.
    // Syntax: priority_queue<Type, Container, Comparator>
    // std::vector<int> is the underlying container.
    // std::greater<int> is a built-in function object that reverses the order.
    priority_queue<int, vector<int>, greater<int>> minPQ;
    
    minPQ.push(5);
    minPQ.push(2);
    minPQ.push(10);
    minPQ.push(8);
    
    cout << "Top element (Min): " << minPQ.top() << endl; // Expected: 2 (Smallest)
    
    printPQ(minPQ, "Min Queue content"); // Prints: 2 5 8 10


    // ------------------------------------
    // 4. Utility Functions
    // ------------------------------------
    cout << "\nStep 4: Utility Functions" << endl;
    
    cout << "Size of Min Heap: " << minPQ.size() << endl;
    cout << "Is Min Heap empty? " << (minPQ.empty() ? "Yes" : "No") << endl;

    return 0;
}