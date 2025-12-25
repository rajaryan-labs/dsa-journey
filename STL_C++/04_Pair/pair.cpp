/**
 * std::pair in C++ STL
 *
 * A 'pair' is a container that stores two values, which can be of different types.
 * It is defined in the <utility> header.
 *
 * Key Concepts:
 * - Stores two elements: 'first' and 'second'.
 * - Useful for returning two values from a function.
 * - Used effectively in containers like map, hash_map, or vector of pairs.
 * - Supports comparison operators (Lexicographical comparison).
 */

#include <iostream>
#include <utility>  // Required for std::pair
#include <vector>
#include <algorithm> // For std::sort
#include <string>

using namespace std;

// Function that returns a pair (Demonstrating return of multiple values)
pair<int, int> getMinMax(int a, int b) {
    if (a < b) return {a, b}; // braced-init-list (C++11)
    return make_pair(b, a);   // using make_pair traditional way
}

int main() {
    // ------------------------------------
    // 1. Basic Initialization & Access
    // ------------------------------------
    cout << "Step 1: Basic Initialization & Access" << endl;
    
    // Declaration: pair<Type1, Type2> pairName;
    pair<int, string> p1;
    
    // Assignment
    p1.first = 1;
    p1.second = "Apple"; // "Apple" is implicitly converted to std::string
    
    cout << "p1: {" << p1.first << ", " << p1.second << "}" << endl;

    // Direct Initialization
    pair<int, string> p2(2, "Banana");
    cout << "p2: {" << p2.first << ", " << p2.second << "}" << endl;

    // using std::make_pair (Automatically deduces types)
    // ------------------------------------
    // Relationship between 'auto' and 'make_pair':
    // 1. make_pair(3, "Cherry") creates a pair<int, const char*> by deducing types from values.
    // 2. 'auto' then captures that type for the variable 'p3'.
    //
    // synergy: Together they avoid verbose type definitions.
    // Instead of: pair<int, const char*> p3 = pair<int, const char*>(3, "Cherry");
    // We write:   auto p3 = make_pair(3, "Cherry");
    // ------------------------------------
    auto p3 = make_pair(3, "Cherry");
    cout << "p3 (via make_pair): {" << p3.first << ", " << p3.second << "}" << endl;


    // ------------------------------------
    // 2. Nested Pairs
    // ------------------------------------
    cout << "\nStep 2: Nested Pairs (Storing 3 or more values)" << endl;
    // Storing 3 integers: {x, y, z} -> {x, {y, z}}
    pair<int, pair<int, int>> p4 = {10, {20, 30}};
    
    cout << "p4: {" 
         << p4.first << ", {" 
         << p4.second.first << ", " 
         << p4.second.second << "}}" << endl;


    // ------------------------------------
    // 3. Array of Pairs
    // ------------------------------------
    cout << "\nStep 3: Array of Pairs" << endl;
    
    pair<int, int> arr[] = { {1, 2}, {3, 4}, {5, 6} };
    
    cout << "Array element at index 1: {" 
         << arr[1].first << ", " << arr[1].second << "}" << endl;


    // ------------------------------------
    // 4. Vector of Pairs & Sorting
    // ------------------------------------
    cout << "\nStep 4: Vector of Pairs & Sorting" << endl;
    
    // A vector where each element is a pair
    vector<pair<string, int>> students;
    
    // push_back(): Needs a constructed pair object
    students.push_back({"Alice", 85});
    students.push_back(make_pair("Bob", 92));
    
    // emplace_back(): Constructs the pair IN-PLACE at the end of the vector.
    // This avoids creating a temporary pair object and moving/copying it.
    // You pass the constructor arguments for the pair directly.
    students.emplace_back("Charlie", 78);
    
    cout << "Before Sorting:" << endl;
    
    // Using 'auto' in loops avoids writing long types like pair<string, int>
    for(const auto& s : students) {
        cout << "Name: " << s.first << ", Score: " << s.second << endl;
    }

    // Sorting: By default, pairs are compared element-wise.
    // It compares 'first' elements appropriately. If 'first' are equal, it compares 'second'.
    // Here it behaves like a Lexicographical Sort on strings (Names).
    sort(students.begin(), students.end());
    
    cout << "\nAfter Sorting (by Name - default behavior):" << endl;
    for(const auto& s : students) {
        cout << "Name: " << s.first << ", Score: " << s.second << endl;
    }


    // ------------------------------------
    // 5. Comparison Operators
    // ------------------------------------
    cout << "\nStep 5: Comparison" << endl;
    pair<int, int> pairA = {10, 20};
    pair<int, int> pairB = {10, 25};
    pair<int, int> pairC = {11, 5};

    // Compares first, then second
    if (pairB > pairA) {
        cout << "pairB {10, 25} is greater than pairA {10, 20} (Second element is larger)" << endl;
    }

    if (pairC > pairB) {
        cout << "pairC {11, 5} is greater than pairB {10, 25} (First element is larger)" << endl;
    }

    // ------------------------------------
    // 6. Swapping
    // ------------------------------------
    cout << "\nStep 6: Swapping" << endl;
    cout << "Before Swap -> pairA: {" << pairA.first << ", " << pairA.second << "}" << endl;
    
    pairA.swap(pairC); // Swaps pairA content with pairC
    
    cout << "After Swap -> pairA: {" << pairA.first << ", " << pairA.second << "}" << endl;
    
    return 0;
}
