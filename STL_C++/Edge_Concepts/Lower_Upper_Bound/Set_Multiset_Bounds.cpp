#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// ==========================================
// LOWER_BOUND & UPPER_BOUND IN SET / MULTISET
// ==========================================

/*
    CONCEPTS:
    ---------
    1. lower_bound(val): Returns an iterator to the FIRST element that is NOT LESS than val (>= val).
       - If val exists: returns iterator to val.
       - If val doesn't exist: returns iterator to the next immediate greater element.

    2. upper_bound(val): Returns an iterator to the FIRST element that is GREATER than val (> val).
       - Always returns the next element greater than val, even if val exists.
    
    Why use member functions s.lower_bound() instead of std::lower_bound(s.begin(), s.end())?
    - s.lower_bound() is O(log N) because it uses the internal tree reference.
    - std::lower_bound() on a set is O(N) typically because set iterators are not random access.

    REAL WORLD / PRODUCTION USE CASES:
    ----------------------------------
    1. Range Queries:
       - Finding all events within a time range [Start, End].
       - Example: "Show me all logs between 10:00 AM and 11:00 AM."
       - auto it_start = s.lower_bound(start_time);
       - auto it_end = s.upper_bound(end_time);

    2. Leaderboards / Ranking Systems:
       - Finding players with scores above a certain threshold.
       - "Find the first player with score >= 1000".

    3. IP Address Routing:
       - Storing IP ranges and finding which range a specific IP belongs to.

    4. Closest Value Search:
       - Finding the closest available price, stock value, or server load to a target.
*/

void explainSet() {
    cout << "\n--- std::set (Unique Elements) ---" << endl;
    set<int> s = {10, 20, 30, 40, 50};
    
    // Set: {10, 20, 30, 40, 50}

    int target = 30;
    auto lb = s.lower_bound(target); // First element >= 30 -> 30
    auto ub = s.upper_bound(target); // First element > 30  -> 40

    cout << "Set: {10, 20, 30, 40, 50}" << endl;
    cout << "lower_bound(30): " << (lb != s.end() ? to_string(*lb) : "End") << endl;
    cout << "upper_bound(30): " << (ub != s.end() ? to_string(*ub) : "End") << endl;

    target = 35; // Value not present
    lb = s.lower_bound(target); // First element >= 35 -> 40
    ub = s.upper_bound(target); // First element > 35  -> 40

    cout << "lower_bound(35) [Not in set]: " << (lb != s.end() ? to_string(*lb) : "End") << endl;
    cout << "upper_bound(35) [Not in set]: " << (ub != s.end() ? to_string(*ub) : "End") << endl;
}

void explainMultiSet() {
    cout << "\n--- std::multiset (Duplicate Elements) ---" << endl;
    multiset<int> ms = {10, 20, 20, 20, 30};

    // MultiSet: {10, 20, 20, 20, 30}

    int target = 20;
    auto lb = ms.lower_bound(target); // First '20'
    auto ub = ms.upper_bound(target); // First element > 20 -> 30

    cout << "MultiSet: {10, 20, 20, 20, 30}" << endl;
    cout << "lower_bound(20): " << *lb << " (Points to the FIRST 20)" << endl;
    cout << "upper_bound(20): " << *ub << " (Points to 30, effectively range [lb, ub) covers all 20s)" << endl;

    // Count occurrences using bounds
    cout << "Count of 20s using bounds: " << distance(lb, ub) << endl;
}

int main() {
    explainSet();
    explainMultiSet();
    return 0;
}
