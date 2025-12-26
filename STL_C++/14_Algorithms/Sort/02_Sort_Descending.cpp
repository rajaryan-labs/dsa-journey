#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <functional> // for greater<int>

using namespace std;

// ==========================================
// 2. SORTING IN DESCENDING ORDER
// ==========================================
/*
    By default, std::sort rearranges elements in Ascending Order (Increasing).
    To change this, we provide a third argument: a COMPARATOR.

    A Comparator can be:
    1. A predefined function object (Functor) like std::greater<T>().
    2. A custom boolean function.
    3. A lambda function (modern C++).
*/

// Custom Comparator Function
// Returns TRUE if element 'a' should appear BEFORE element 'b'.
// For Descending: We want larger elements first. So return a > b.
bool descendingComp(int a, int b) {
    return a > b; 
}

int main() {
    vector<int> v = {1, 3, 5, 2, 4};

    // ------------------------------------
    // Method 1: Using std::greater<Type>()
    // ------------------------------------
    // 'greater<int>()' is a built-in functor in <functional> header.
    sort(v.begin(), v.end(), greater<int>());

    cout << "Descending (std::greater): ";
    for(int x : v) cout << x << " "; 
    cout << endl;

    // ------------------------------------
    // Method 2: Using Custom Comparator
    // ------------------------------------
    vector<int> v2 = {10, 30, 50, 20, 40};
    sort(v2.begin(), v2.end(), descendingComp);

    cout << "Descending (Custom Func):  ";
    for(int x : v2) cout << x << " "; 
    cout << endl;

    return 0;
}
