/**
 * std::stack in C++ STL
 *
 * A Stack is a container adapter that operates on LIFO (Last In, First Out) principle.
 * Think of it like a stack of plates: the last plate placed on top is the first one removed.
 *
 * Key Features:
 * - Elements are added (pushed) and removed (popped) only from one end (the top).
 * - No Iterators: You cannot traverse a stack (no begin()/end()).
 * - Complexity: All operations (push, pop, top, empty, size) are O(1).
 */

#include <iostream>
#include <stack>

using namespace std;

// Helper function to visualize stack content (by copy, so original is preserved)
void printStack(stack<int> s, const string& name) {
    cout << name << ": [Top] ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "[Bottom]" << endl;
}

int main() {
    // ------------------------------------
    // 1. Initialization & Pushing
    // ------------------------------------
    cout << "Step 1: Initialization & Pushing" << endl;
    
    // Declaration: stack<Type> stackName;
    stack<int> s;

    // push(): Insterts element at the top - O(1)
    s.push(1);
    s.push(2);
    s.push(3);
    
    // emplace(): Constructs element in-place at the top - O(1)
    // More efficient for objects as it avoids temporary copies.
    s.emplace(4);
    
    // Visualization:
    //    | 4 |  <-- Top
    //    | 3 |
    //    | 2 |
    //    | 1 |
    //    -----
    printStack(s, "Stack after pushes");


    // ------------------------------------
    // 2. Accessing Elements
    // ------------------------------------
    cout << "\nStep 2: Accessing Top Element" << endl;
    
    // top(): Returns reference to the top element - O(1)
    // Does NOT remove the element.
    if (!s.empty()) {
        cout << "Top element: " << s.top() << endl; // Expected: 4
    }


    // ------------------------------------
    // 3. Removal Operations
    // ------------------------------------
    cout << "\nStep 3: Popping Elements" << endl;
    
    // pop(): Removes the top element - O(1)
    // Does NOT return the value, just removes it.
    s.pop(); // Removes 4
    cout << "pop() called. New Top: " << s.top() << endl; // Expected: 3
    
    s.pop(); // Removes 3
    cout << "pop() called. New Top: " << s.top() << endl; // Expected: 2


    // ------------------------------------
    // 4. Size and Empty Check
    // ------------------------------------
    cout << "\nStep 4: Utility Functions" << endl;
    
    cout << "Size: " << s.size() << endl; // Expected: 2 (elements 1, 2)
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;


    // ------------------------------------
    // 5. Swapping
    // ------------------------------------
    cout << "\nStep 5: Swapping Stacks" << endl;
    
    stack<int> s1;
    s1.push(100);
    s1.push(200);
    
    stack<int> s2;
    s2.push(5); 
    
    cout << "Before Swap:" << endl; 
    cout << "s1 top: " << s1.top() << ", s2 top: " << s2.top() << endl;
    
    s1.swap(s2);
    
    cout << "After Swap:" << endl;
    cout << "s1 top: " << s1.top() << ", s2 top: " << s2.top() << endl;

    return 0;
}