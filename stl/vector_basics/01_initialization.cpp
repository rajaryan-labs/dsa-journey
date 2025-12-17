#include <iostream>
#include <vector>

using namespace std;

// 1. INITIALIZATION
// This file demonstrates different ways to initialize a vector in C++.

int main() {
    // 1. Default Initialization
    // Creates an empty vector with size 0.
    vector<int> vec; 
    cout << "Default: Size = " << vec.size() << endl;

    // 2. Fill Initialization with Size
    // Creates a vector of size 5 with default values (0 for int).
    vector<int> vec_zeros(5); // {0, 0, 0, 0, 0}
    cout << "Fill (Size 5): ";
    for(int x : vec_zeros) cout << x << " ";
    cout << endl;

    // 3. Fill Initialization with Validation
    // Creates a vector of size 5 with all elements set to 10.
    vector<int> vec_filled(5, 10); // {10, 10, 10, 10, 10}
    cout << "Fill (5, 10): ";
    for(int x : vec_filled) cout << x << " ";
    cout << endl;

    // 4. Initializer List (C++11)
    // Initializes vector with specific values.
    vector<int> vec_list = {1, 2, 3, 4, 5}; 
    cout << "Initializer List: ";
    for(int x : vec_list) cout << x << " ";
    cout << endl;

    // 5. Copy Initialization
    // Creates a new vector by copying elements from another vector.
    vector<int> vec_copy(vec_list); 
    cout << "Copy: ";
    for(int x : vec_copy) cout << x << " ";
    cout << endl;

    // 6. Range Initialization
    // Initializes from a range of another container.
    // Example: Copy first 3 elements of vec_list.
    vector<int> vec_range(vec_list.begin(), vec_list.begin() + 3); // {1, 2, 3}
    cout << "Range Copy (First 3): ";
    for(int x : vec_range) cout << x << " ";
    cout << endl;

    return 0;
}
