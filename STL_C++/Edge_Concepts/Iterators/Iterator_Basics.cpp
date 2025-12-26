#include <iostream>
#include <vector>
#include <utility> // for pair

using namespace std;

int main() {
    // ==========================================
    // ITERATORS IN C++ STL
    // ==========================================
    // Iterators are objects (like pointers) that point to an element inside a container.
    // They are used to traverse through the elements of a container (vector, list, map, etc.).

    // ------------------------------------------
    // 1. Basic Usage with Vector
    // ------------------------------------------
    vector<int> v = {10, 20, 30, 40, 50};

    // Syntax: ContainerType::iterator iteratorName;
    // v.begin() returns an iterator pointing to the FIRST element.
    vector<int>::iterator it = v.begin();

    cout << "First element (*it): " << *it << endl; // Dereference to get value (10)

    it++; // Move iterator to the next element
    cout << "Second element after it++: " << *it << endl; // (20)

    // v.end() returns an iterator pointing to the position AFTER the last element.
    // It does NOT point to the last element itself.
    
    cout << "Traversing vector using iterator: ";
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // ------------------------------------------
    // 2. Iterators with Pairs
    // ------------------------------------------
    vector<pair<int, int>> v_p = {{1, 2}, {3, 4}, {5, 6}};
    vector<pair<int, int>>::iterator it_p = v_p.begin();

    // Accessing members of the pair using iterator
    // Method 1: (*it).member
    cout << "Pair 1 (using *): " << (*it_p).first << " " << (*it_p).second << endl;

    // Method 2: it->member (Arrow operator is easier and more common)
    cout << "Pair 1 (using ->): " << it_p->first << " " << it_p->second << endl;

    // ------------------------------------------
    // 3. The 'auto' Keyword
    // ------------------------------------------
    // Writing 'vector<int>::iterator' is long and tedious.
    // The 'auto' keyword automatically determines the type based on initialization.
    
    cout << "Traversing using auto: ";
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // ------------------------------------------
    // 4. Range-based For Loop (Syntactic Sugar for Iterators)
    // ------------------------------------------
    // Under the hood, this also uses iterators.
    cout << "Range-based for loop: ";
    for(int value : v) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
