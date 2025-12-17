#include <iostream>
#include <vector>

using namespace std;

// 2. MODIFIERS
// This file covers methods that change the content of the vector: 
// push_back, emplace_back, pop_back, insert, erase, and clear.

void printVector(const vector<int>& v) {
    cout << "{ ";
    for (int x : v) cout << x << " ";
    cout << "}\n";
}

int main() {
    vector<int> vec = {1, 2, 3};
    cout << "Initial: "; printVector(vec);

    // 1. PUSH_BACK & EMPLACE_BACK
    // Adds element to the end.
    vec.push_back(4);
    vec.emplace_back(5); // Slightly faster constructing in-place
    cout << "After push/emplace: "; printVector(vec);

    // 2. INSERT
    // O(N) complexity - shifts elements.
    
    // Insert simple element at specific position
    // insert(position_iterator, value)
    vec.insert(vec.begin() + 1, 100); 
    cout << "After insert(begin+1, 100): "; printVector(vec);

    // Insert multiple copies
    // insert(position_iterator, count, value)
    vec.insert(vec.begin() + 2, 2, 50); 
    cout << "After insert(begin+2, 2, 50): "; printVector(vec);

    // 3. POP_BACK
    // Removes the last element. O(1).
    vec.pop_back();
    cout << "After pop_back: "; printVector(vec);

    // 4. ERASE
    // O(N) complexity - shifts elements.

    // Remove single element
    // erase(position_iterator)
    vec.erase(vec.begin() + 1); // Removes element at index 1
    cout << "After erase(begin+1): "; printVector(vec);

    // Remove range of elements
    // erase(start_iterator, end_iterator) -> [start, end)
    vec.erase(vec.begin() + 1, vec.begin() + 3); 
    cout << "After erase(begin+1, begin+3): "; printVector(vec);

    // 5. CLEAR
    // Removes all elements. Size -> 0. Capacity remains.
    vec.clear();
    cout << "After clear: "; printVector(vec);
    cout << "Size after clear: " << vec.size() << endl;

    return 0;
}
