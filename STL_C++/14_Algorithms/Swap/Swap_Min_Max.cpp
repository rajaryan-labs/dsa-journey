#include <iostream>
#include <vector>
#include <algorithm> // Required for swap, min, max
#include <utility>   // Required for swap in modern C++ (usually <algorithm> covers it)

using namespace std;

// ==========================================
// STL ALGORITHMS: SWAP, MIN, MAX
// ==========================================

int main() {
    // ------------------------------------
    // 1. Swap
    // ------------------------------------
    cout << "--- 1. Swap ---" << endl;
    int a = 10, b = 20;
    cout << "Before Swap: a=" << a << ", b=" << b << endl;

    swap(a, b); // Swaps values effectively
    cout << "After Swap:  a=" << a << ", b=" << b << endl;

    // ------------------------------------
    // 2. Min & Max (Two Elements)
    // ------------------------------------
    cout << "\n--- 2. Min & Max ---" << endl;
    cout << "min(10, 20): " << min(10, 20) << endl;
    cout << "max(10, 20): " << max(10, 20) << endl;

    // ------------------------------------
    // 3. Min/Max Element in Container
    // ------------------------------------
    cout << "\n--- 3. Min/Max in Vector ---" << endl;
    vector<int> v = {5, 1, 9, 3, 7};

    // min_element returns an ITERATOR to the smallest element
    auto min_it = min_element(v.begin(), v.end()); 
    // max_element returns an ITERATOR to the largest element
    auto max_it = max_element(v.begin(), v.end());

    cout << "Vector: {5, 1, 9, 3, 7}" << endl;
    cout << "Minimum Element: " << *min_it << endl;
    cout << "Maximum Element: " << *max_it << endl;

    return 0;
}
