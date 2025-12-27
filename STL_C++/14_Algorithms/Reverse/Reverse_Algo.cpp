#include <iostream>
#include <vector>
#include <algorithm> // Required for std::reverse
#include <string>

using namespace std;

// ==========================================
// STL ALGORITHMS: REVERSE
// ==========================================
/*
    std::reverse(start_iterator, end_iterator)
    
    - Reverses the order of elements in the range [start, end).
    - Time Complexity: O(N)
    - Works on: Vector, String, Array, Deque (Requires Bidirectional Iterators).
*/

int main() {
    // 1. Reversing a Vector
    cout << "--- 1. Reversing Vector ---" << endl;
    vector<int> v = {1, 2, 3, 4, 5};
    
    cout << "Original: ";
    for(int x : v) cout << x << " "; 
    cout << endl;

    reverse(v.begin(), v.end());

    cout << "Reversed: ";
    for(int x : v) cout << x << " "; 
    cout << endl; // Output: 5 4 3 2 1

    // 2. Reversing a String
    cout << "\n--- 2. Reversing String ---" << endl;
    string s = "Hello";
    
    reverse(s.begin(), s.end());
    
    cout << "Reversed String: " << s << endl; // Output: olleH

    // 3. Reversing an Array
    cout << "\n--- 3. Reversing Array ---" << endl;
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr)/sizeof(arr[0]);

    reverse(arr, arr + n);

    cout << "Reversed Array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    // 4. Reverse in a Particular Range
    cout << "\n--- 4. Reverse in a Particular Range ---" << endl;
    vector<int> v2 = {10, 20, 30, 40, 50, 60};
    // Reverse only index 1 to 4 (elements 20, 30, 40)
    // Range is [start, end) -> [v2.begin()+1, v2.begin()+4)
    reverse(v2.begin() + 1, v2.begin() + 4); 
    
    cout << "Partial Reverse (idx 1-3): ";
    for(int x : v2) cout << x << " "; 
    cout << endl; // Expected: 10 40 30 20 50 60

    return 0;
}
