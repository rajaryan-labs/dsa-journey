#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <string>

using namespace std;

// ==========================================
// 1. BASICS OF SORTING IN STL
// ==========================================
/*
    std::sort Function:
    -------------------
    - LIBRARY: <algorithm>
    - SYNTAX: sort(start_iterator, end_iterator);
    - TIME COMPLEXITY: O(N log N) on average and worst case.
    - ALGORITHM: Introsort (Hybrid of QuickSort, HeapSort, and InsertionSort).
      1. Starts with QuickSort.
      2. Switches to HeapSort if recursion depth gets too deep (to avoid stack overflow).
      3. Switches to InsertionSort for small number of elements (efficient for small N).
    
    - PRE-REQUISITE: The container must support Random Access Iterators.
      (Works on: Array, Vector, Deque, String)
      (Does NOT work on: List, Forward_List, Set, Map - they use their own logic).
*/

void sortArray() {
    cout << "\n--- Sorting Array ---" << endl;
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    // Syntax: sort(start_pointer, end_pointer)
    // arr points to the first element.
    // arr + n points to the address JUST AFTER the last element.
    sort(arr, arr + n); 

    cout << "Sorted:   ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

void sortVector() {
    cout << "\n--- Sorting Vector ---" << endl;
    vector<int> v = {10, 50, 30, 20, 40};

    // Syntax: sort(v.begin(), v.end())
    // .begin() -> Iterator to start
    // .end()   -> Iterator to past-the-end
    sort(v.begin(), v.end());

    cout << "Sorted Vector: ";
    for(int x : v) cout << x << " ";
    cout << endl;
}

void sortString() {
    cout << "\n--- Sorting String ---" << endl;
    string s = "edcba";

    // Strings are essentially vectors of characters.
    // Sorting arranges characters based on their ASCII values.
    sort(s.begin(), s.end());

    cout << "Sorted String: " << s << endl; // Output: abcde
}

int main() {
    sortArray();
    sortVector();
    sortString();
    return 0;
}
