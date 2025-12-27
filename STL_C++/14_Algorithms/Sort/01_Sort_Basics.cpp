#include <algorithm>  // Required for std::sort
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. BASICS OF SORTING IN STL
// ==========================================
/*
    std::sort Function:
    -------------------
    - LIBRARY: <algorithm>
    - SYNTAX: sort(start_iterator, end_iterator);
    - Sorting is performed in the range [start_iterator, end_iterator)
       — (start included, end excluded).
    - TIME COMPLEXITY: O(N log N) on average and worst case.
    - ALGORITHM: Introsort (Hybrid of QuickSort, HeapSort, and InsertionSort).
      1. Starts with QuickSort.
      2. Switches to HeapSort if recursion depth gets too deep (to avoid stack
   overflow).
      3. Switches to InsertionSort for small number of elements (efficient for
   small N).

    - PRE-REQUISITE: The container must support Random Access Iterators.
      (Works on: Array, Vector, Deque, String)
      (Does NOT work on: List, Forward_List, Set, Map - they use their own
   logic).
*/

void sortArray() {
  cout << "\n--- Sorting Array ---" << endl;
  int arr[] = {5, 2, 9, 1, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;

  // Syntax: sort(start_pointer, end_pointer)
  // arr points to the first element.
  // arr + n points to the address JUST AFTER the last element.
  sort(arr, arr + n);

  cout << "Sorted:   ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}

void sortVector() {
  cout << "\n--- Sorting Vector ---" << endl;
  vector<int> v = {10, 50, 30, 20, 40};

  // Syntax: sort(v.begin(), v.end())
  // .begin() -> Iterator to start
  // .end()   -> Iterator next to the-end
  sort(v.begin(), v.end());

  cout << "Sorted Vector: ";
  for (int x : v) cout << x << " ";
  cout << endl;
}

void sortString() {
  cout << "\n--- Sorting String ---" << endl;
  string s = "edcba";

  // Strings are essentially vectors of characters.
  // Sorting arranges characters based on their ASCII values.
  sort(s.begin(), s.end());

  cout << "Sorted String: " << s << endl;  // Output: abcde
}

void sortPartialRange() {
    cout << "\n--- Sorting Particular Range ---" << endl;
    vector<int> v = {10, 50, 2, 8, 40, 20};

    // Syntax: sort(start_iterator, end_iterator)
    // To sort only index 2 to 4 (elements 2, 8, 40)
    // Range: [v.begin()+2, v.begin()+5) -> recall end is EXCLUSIVE
    
    cout << "Original: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    sort(v.begin() + 2, v.begin() + 5); 

    // {10, 50, 2, 8, 40, 20} -> {10, 50, 2, 8, 40} is the range... wait.
    // indices: 0   1   2  3   4   5
    // values: 10  50   2  8  40  20
    // range [2, 5) covers indices 2, 3, 4. Elements: {2, 8, 40}.
    // If they were {40, 8, 2}, they would become {2, 8, 40}.
    // Let's use a clearer example: {10, 50, 40, 8, 2, 20}
    // Sort indices 2 to 4: {40, 8, 2} -> {2, 8, 40}
    
    cout << "Sorted partial range (idx 2-4): ";
    for(int x : v) cout << x << " ";
    cout << endl;
}

int main() {
  sortArray();
  sortVector();
  sortString();
  sortPartialRange();
  return 0;
}
