#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // for std::pair

using namespace std;

// ==========================================
// 4. DSA PATTERNS: SORTING VECTOR OF PAIRS
// ==========================================
/*
    In Data Structures & Algorithms (DSA), specifically Greedy problems
    or Graph theory (Weighted edges), we often need to sort a list of Pairs.

    Common Use Cases:
    1. Interval Scheduling (Sort by Finish Time).
    2. Fractional Knapsack (Sort by Value/Weight ratio).
    3. Merging Intervals (Sort by Start Time).
*/

// Comparator: Sort by Second Element (Ascending)
bool sortBySecond(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

// Comparator: Complex Logic
// logic: Sort by Second Element DESCENDING. 
//        If Second elements are EQUAL, then sort by First Element ASCENDING.
bool complexLogic(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second; // Primary condition (Desc)
    }
    return a.first < b.first;       // Secondary condition (Asc)
}

int main() {
    // Example Data: {Val, Weight} or {Start, End}
    vector<pair<int, int>> v = { {1, 20}, {3, 10}, {2, 10}, {5, 50} };

    // ------------------------------------
    // Scenario 1: Default Sort
    // ------------------------------------
    // Output: {1,20} {2,10} {3,10} {5,50} (Sorted by First element)
    sort(v.begin(), v.end());
    
    cout << "Default Sort (First Asc): ";
    for(auto p : v) cout << "{" << p.first << "," << p.second << "} ";
    cout << endl;

    // ------------------------------------
    // Scenario 2: Sort by Second Element (Greedy Pattern)
    // ------------------------------------
    // Output: {3,10} {2,10} {1,20} {5,50}
    sort(v.begin(), v.end(), sortBySecond);

    cout << "Sort by Second (Asc):     ";
    for(auto p : v) cout << "{" << p.first << "," << p.second << "} ";
    cout << endl;

    // ------------------------------------
    // Scenario 3: Complex Logic (Second Desc, First Asc)
    // ------------------------------------
    // Output: {5,50} {1,20} {2,10} {3,10}
    // Note for {2,10} and {3,10}: Second is equal (10). First is 2 vs 3. 2 < 3. 
    sort(v.begin(), v.end(), complexLogic);

    cout << "Complex Sort:             ";
    for(auto p : v) cout << "{" << p.first << "," << p.second << "} ";
    cout << endl;

    return 0;
}
