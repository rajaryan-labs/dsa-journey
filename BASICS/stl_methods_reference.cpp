/*
 * ============================================================
 *  IMPORTANT & FREQUENTLY USED STL METHODS IN C++
 * ============================================================
 *  A quick-reference guide for the most common built-in
 *  methods used in DSA and competitive programming.
 *
 *  Organized by Container / Category:
 *  1.  STRING  Methods
 *  2.  VECTOR  Methods
 *  3.  MAP / UNORDERED_MAP  Methods
 *  4.  SET / UNORDERED_SET  Methods
 *  5.  STACK   Methods
 *  6.  QUEUE   Methods
 *  7.  DEQUE   Methods
 *  8.  PRIORITY_QUEUE  Methods
 *  9.  LIST    Methods
 *  10. ALGORITHM  Methods  (sort, reverse, binary_search, etc.)
 *  11. NUMERIC    Methods  (accumulate, gcd, lcm, iota, etc.)
 *  12. PAIR / TUPLE  Methods
 *  13. UTILITY    Methods  (swap, move, min, max, clamp, abs)
 *
 *  Legend:
 *    TC = Time Complexity | SC = Space Complexity
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

// ============================================================
//  HELPER: Print a vector
// ============================================================
void printVec(const vector<int>& v, const string& label = "") {
    if (!label.empty()) cout << label << ": ";
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}

// ============================================================
//  1. STRING METHODS
// ============================================================
void string_methods() {
    cout << "\n========== 1. STRING METHODS ==========\n";

    string s = "Hello, World!";

    // --- Basic Info ---
    cout << "s.length()            => " << s.length()     << "\n"; // same as size()
    cout << "s.size()              => " << s.size()       << "\n"; // TC: O(1)
    cout << "s.empty()             => " << s.empty()      << "\n"; // TC: O(1), returns bool

    // --- Access ---
    cout << "s[0]                  => " << s[0]           << "\n"; // TC: O(1), no bounds check
    cout << "s.at(1)               => " << s.at(1)        << "\n"; // TC: O(1), throws out_of_range
    cout << "s.front()             => " << s.front()      << "\n"; // TC: O(1), first char
    cout << "s.back()              => " << s.back()       << "\n"; // TC: O(1), last char

    // --- Modification ---
    s.push_back('!');                                               // TC: amortized O(1)
    cout << "After push_back('!') => " << s << "\n";

    s.pop_back();                                                   // TC: O(1)
    cout << "After pop_back()     => " << s << "\n";

    string s2 = s;
    s2.append(" Raj");                                             // TC: O(n)
    cout << "s.append(\" Raj\")     => " << s2 << "\n";

    s2.insert(7, "Beautiful ");                                    // TC: O(n)
    cout << "s.insert(7, ...)     => " << s2 << "\n";

    s2.erase(7, 10);                                               // erase 10 chars from index 7
    cout << "s.erase(7, 10)       => " << s2 << "\n";             // TC: O(n)

    s2.replace(7, 5, "C++");                                       // replace 5 chars at idx 7
    cout << "s.replace(7,5,\"C++\") => " << s2 << "\n";            // TC: O(n)

    // --- Search ---
    size_t pos = s.find("World");                                  // TC: O(n*m)
    cout << "s.find(\"World\")      => " << pos << "\n";            // string::npos if not found

    pos = s.rfind('l');                                            // TC: O(n), last occurrence
    cout << "s.rfind('l')         => " << pos << "\n";

    // --- Substring ---
    string sub = s.substr(7, 5);                                   // TC: O(n)
    cout << "s.substr(7, 5)       => " << sub << "\n";             // starts at 7, length 5

    // --- Conversion ---
    string num_str = to_string(3.14);                              // TC: O(digits)
    cout << "to_string(3.14)      => " << num_str << "\n";

    int    i_val = stoi("42");                                     // string to int
    long   l_val = stol("1234567");                                // string to long
    double d_val = stod("3.14");                                   // string to double
    cout << "stoi(\"42\")           => " << i_val  << "\n";
    cout << "stol(\"1234567\")      => " << l_val  << "\n";
    cout << "stod(\"3.14\")         => " << d_val  << "\n";

    // --- Comparison ---
    string a = "abc", b = "abd";
    cout << "a.compare(b)         => " << a.compare(b) << "\n";   // <0 if a<b, 0 equal, >0 if a>b

    // --- Reverse a string ---
    string rev = "hello";
    reverse(rev.begin(), rev.end());                               // TC: O(n)
    cout << "reversed \"hello\"     => " << rev << "\n";

    // --- Clear ---
    string tmp = "temp";
    tmp.clear();                                                   // TC: O(1) amortized
    cout << "After clear(), empty  => " << boolalpha << tmp.empty() << "\n";
}

// ============================================================
//  2. VECTOR METHODS
// ============================================================
void vector_methods() {
    cout << "\n========== 2. VECTOR METHODS ==========\n";

    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

    // --- Basic Info ---
    cout << "v.size()          => " << v.size()     << "\n"; // TC: O(1)
    cout << "v.capacity()      => " << v.capacity() << "\n"; // allocated storage
    cout << "v.empty()         => " << v.empty()    << "\n"; // TC: O(1)

    // --- Access ---
    cout << "v[0]              => " << v[0]         << "\n"; // TC: O(1), no bounds check
    cout << "v.at(1)           => " << v.at(1)      << "\n"; // TC: O(1), throws out_of_range
    cout << "v.front()         => " << v.front()    << "\n"; // TC: O(1)
    cout << "v.back()          => " << v.back()     << "\n"; // TC: O(1)

    // --- Modification ---
    v.push_back(7);                                         // TC: amortized O(1)
    printVec(v, "After push_back(7)  ");

    v.pop_back();                                           // TC: O(1)
    printVec(v, "After pop_back()    ");

    v.insert(v.begin() + 2, 99);                           // TC: O(n)
    printVec(v, "After insert at [2] ");

    v.erase(v.begin() + 2);                                // TC: O(n)
    printVec(v, "After erase at [2]  ");

    v.erase(v.begin(), v.begin() + 2);                     // erase range [0, 2)
    printVec(v, "After erase [0,2)   ");

    // --- Resize & Reserve ---
    vector<int> v2;
    v2.reserve(100);                                       // pre-allocate, TC: O(n)
    v2.resize(5, 0);                                       // resize to 5, fill with 0
    printVec(v2, "v2 after resize(5,0)");

    // --- Sort & Reverse ---
    vector<int> v3 = {5, 3, 1, 4, 2};
    sort(v3.begin(), v3.end());                            // TC: O(n log n)
    printVec(v3, "After sort()        ");

    sort(v3.begin(), v3.end(), greater<int>());            // TC: O(n log n), descending
    printVec(v3, "After sort desc     ");

    reverse(v3.begin(), v3.end());                         // TC: O(n)
    printVec(v3, "After reverse()     ");

    // --- Unique (remove consecutive duplicates — sort first!) ---
    vector<int> v4 = {1, 1, 2, 2, 3, 3, 3};
    auto it = unique(v4.begin(), v4.end());                // TC: O(n)
    v4.erase(it, v4.end());
    printVec(v4, "After unique+erase  ");

    // --- Fill & Assign ---
    vector<int> v5(5, 0);
    fill(v5.begin(), v5.end(), 7);                         // TC: O(n)
    printVec(v5, "After fill(7)       ");

    v5.assign(3, 9);                                       // TC: O(n), replaces with 3 nines
    printVec(v5, "After assign(3, 9)  ");

    // --- Search ---
    vector<int> v6 = {1, 2, 3, 4, 5};
    auto found = find(v6.begin(), v6.end(), 3);            // TC: O(n)
    cout << "find(3) index     => " << (found - v6.begin()) << "\n";

    bool exists = binary_search(v6.begin(), v6.end(), 4); // TC: O(log n), MUST be sorted
    cout << "binary_search(4)  => " << boolalpha << exists << "\n";

    auto lb = lower_bound(v6.begin(), v6.end(), 3);       // first element >= 3
    auto ub = upper_bound(v6.begin(), v6.end(), 3);       // first element >  3
    cout << "lower_bound(3)    => index " << (lb - v6.begin()) << "\n";
    cout << "upper_bound(3)    => index " << (ub - v6.begin()) << "\n";

    // --- Min / Max element ---
    cout << "*min_element()    => " << *min_element(v6.begin(), v6.end()) << "\n"; // TC: O(n)
    cout << "*max_element()    => " << *max_element(v6.begin(), v6.end()) << "\n"; // TC: O(n)

    // --- Sum ---
    int sum = accumulate(v6.begin(), v6.end(), 0);         // TC: O(n), from <numeric>
    cout << "accumulate sum    => " << sum << "\n";

    // --- 2D vector (matrix) ---
    int n = 3, m = 4;
    vector<vector<int>> grid(n, vector<int>(m, 0));        // n x m matrix of zeros
    grid[1][2] = 42;
    cout << "grid[1][2]        => " << grid[1][2] << "\n";

    // --- Clear ---
    v3.clear();                                            // TC: O(n), size becomes 0
    cout << "After clear(), size => " << v3.size() << "\n";
}

// ============================================================
//  3. MAP / UNORDERED_MAP METHODS
// ============================================================
void map_methods() {
    cout << "\n========== 3. MAP / UNORDERED_MAP METHODS ==========\n";

    // --- map (ordered, Red-Black Tree, O(log n) ops) ---
    map<string, int> freq;

    freq["apple"]  = 3;                                    // insert or update
    freq["banana"] = 1;
    freq["cherry"] = 5;
    freq["apple"]++;                                       // increment

    cout << "freq.size()           => " << freq.size()    << "\n"; // TC: O(1)
    cout << "freq[\"apple\"]         => " << freq["apple"] << "\n"; // TC: O(log n)
    cout << "freq.at(\"banana\")     => " << freq.at("banana") << "\n"; // throws if missing

    // --- Check existence ---
    cout << "freq.count(\"cherry\")  => " << freq.count("cherry") << "\n"; // 0 or 1, TC: O(log n)
    if (freq.find("banana") != freq.end())                 // TC: O(log n)
        cout << "find(\"banana\") found!\n";

    // --- Erase ---
    freq.erase("banana");                                  // TC: O(log n)
    cout << "After erase(\"banana\"), size => " << freq.size() << "\n";

    // --- Iterate (sorted by key) ---
    cout << "Iterating map:\n";
    for (auto& kv : freq)
        cout << "  " << kv.first << ": " << kv.second << "\n"; // use kv.first/kv.second (C++11)

    // --- Lower / Upper bound ---
    map<int, int> mp = {{1, 10}, {3, 30}, {5, 50}, {7, 70}};
    auto lb = mp.lower_bound(3);                           // first key >= 3
    auto ub = mp.upper_bound(3);                           // first key >  3
    cout << "lower_bound(3) key    => " << lb->first << "\n";
    cout << "upper_bound(3) key    => " << ub->first << "\n";

    // --- unordered_map (hash table, O(1) avg ops) ---
    unordered_map<int, int> ump;
    ump[1] = 100;
    ump[2] = 200;
    ump.insert({3, 300});                                  // alternative insert
    cout << "\nunordered_map size    => " << ump.size()  << "\n";
    cout << "ump.count(2)          => " << ump.count(2) << "\n"; // O(1) avg
    ump.erase(2);
    cout << "After erase(2), size  => " << ump.size()  << "\n";
}

// ============================================================
//  4. SET / UNORDERED_SET METHODS
// ============================================================
void set_methods() {
    cout << "\n========== 4. SET / UNORDERED_SET METHODS ==========\n";

    // --- set (ordered, unique, Red-Black Tree, O(log n) ops) ---
    set<int> s = {5, 3, 1, 4, 2};

    s.insert(6);                                          // TC: O(log n)
    s.insert(3);                                          // ignored, already exists
    cout << "s.size()          => " << s.size() << "\n"; // TC: O(1)

    // --- Check existence ---
    cout << "s.count(3)        => " << s.count(3) << "\n"; // 0 or 1, TC: O(log n)
    if (s.find(4) != s.end())                              // TC: O(log n)
        cout << "find(4) found!\n";

    // --- Smallest / Largest ---
    cout << "*s.begin()        => " << *s.begin()  << "\n"; // smallest, TC: O(1)
    cout << "*s.rbegin()       => " << *s.rbegin() << "\n"; // largest, TC: O(1)

    // --- Lower / Upper bound ---
    auto lb = s.lower_bound(3);                            // first element >= 3
    auto ub = s.upper_bound(3);                            // first element >  3
    cout << "lower_bound(3)    => " << *lb << "\n";
    cout << "upper_bound(3)    => " << *ub << "\n";

    // --- Erase ---
    s.erase(3);                                            // TC: O(log n)
    cout << "After erase(3), size => " << s.size() << "\n";

    // --- Iterate (sorted ascending) ---
    cout << "Iterating set: ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    // --- unordered_set (hash-based, O(1) avg, no order) ---
    unordered_set<int> us = {10, 20, 30};
    us.insert(40);
    cout << "\nus.count(20)      => " << us.count(20)  << "\n"; // O(1) avg
    us.erase(20);
    cout << "After erase(20), size => " << us.size() << "\n";
}

// ============================================================
//  5. STACK METHODS
// ============================================================
void stack_methods() {
    cout << "\n========== 5. STACK METHODS (LIFO) ==========\n";

    stack<int> st;

    st.push(10);                                          // TC: O(1)
    st.push(20);
    st.push(30);

    cout << "st.top()          => " << st.top()   << "\n"; // TC: O(1), peek top
    cout << "st.size()         => " << st.size()  << "\n"; // TC: O(1)
    cout << "st.empty()        => " << st.empty() << "\n"; // TC: O(1)

    st.pop();                                             // TC: O(1), removes top (no return!)
    cout << "After pop(), top  => " << st.top() << "\n";

    // --- Common Pattern: Process all elements ---
    cout << "Draining stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

// ============================================================
//  6. QUEUE METHODS
// ============================================================
void queue_methods() {
    cout << "\n========== 6. QUEUE METHODS (FIFO) ==========\n";

    queue<int> q;

    q.push(10);                                           // TC: O(1), enqueue
    q.push(20);
    q.push(30);

    cout << "q.front()         => " << q.front()  << "\n"; // TC: O(1), first element
    cout << "q.back()          => " << q.back()   << "\n"; // TC: O(1), last element
    cout << "q.size()          => " << q.size()   << "\n"; // TC: O(1)
    cout << "q.empty()         => " << q.empty()  << "\n"; // TC: O(1)

    q.pop();                                              // TC: O(1), dequeue front
    cout << "After pop(), front => " << q.front() << "\n";

    // --- Common Pattern: BFS-style drain ---
    cout << "Draining queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

// ============================================================
//  7. DEQUE METHODS
// ============================================================
void deque_methods() {
    cout << "\n========== 7. DEQUE METHODS (Double-Ended Queue) ==========\n";

    deque<int> dq;

    dq.push_back(2);                                      // TC: O(1)
    dq.push_front(1);                                     // TC: O(1)  <-- key feature!
    dq.push_back(3);
    // dq: [1, 2, 3]

    cout << "dq.front()        => " << dq.front()  << "\n"; // TC: O(1)
    cout << "dq.back()         => " << dq.back()   << "\n"; // TC: O(1)
    cout << "dq[1]             => " << dq[1]       << "\n"; // TC: O(1), random access!
    cout << "dq.size()         => " << dq.size()   << "\n"; // TC: O(1)

    dq.pop_front();                                       // TC: O(1)
    cout << "After pop_front(), front => " << dq.front() << "\n";

    dq.pop_back();                                        // TC: O(1)
    cout << "After pop_back(), back  => " << dq.back()  << "\n";
}

// ============================================================
//  8. PRIORITY_QUEUE METHODS
// ============================================================
void priority_queue_methods() {
    cout << "\n========== 8. PRIORITY_QUEUE METHODS ==========\n";

    // --- Max-Heap (default) ---
    priority_queue<int> maxHeap;
    maxHeap.push(30);                                     // TC: O(log n)
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);

    cout << "Max-Heap top()    => " << maxHeap.top()   << "\n"; // TC: O(1), max element
    cout << "maxHeap.size()    => " << maxHeap.size()  << "\n"; // TC: O(1)
    cout << "maxHeap.empty()   => " << maxHeap.empty() << "\n"; // TC: O(1)
    maxHeap.pop();                                        // TC: O(log n), removes top
    cout << "After pop(), top  => " << maxHeap.top() << "\n";

    // --- Min-Heap (using greater<>) ---
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(50);
    cout << "\nMin-Heap top()    => " << minHeap.top() << "\n";

    // --- Custom comparator (e.g., min-heap by first element of pair) ---
    auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
        return a.first > b.first; // min-heap by first
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    pq.push({3, 100});
    pq.push({1, 200});
    pq.push({2, 300});
    cout << "Custom PQ top().first => " << pq.top().first << "\n";
}

// ============================================================
//  9. LIST METHODS
// ============================================================
void list_methods() {
    cout << "\n========== 9. LIST METHODS (Doubly Linked List) ==========\n";

    list<int> lst = {2, 3, 4};

    lst.push_front(1);                                   // TC: O(1)
    lst.push_back(5);                                    // TC: O(1)

    cout << "lst.front()       => " << lst.front() << "\n"; // TC: O(1)
    cout << "lst.back()        => " << lst.back()  << "\n"; // TC: O(1)
    cout << "lst.size()        => " << lst.size()  << "\n"; // TC: O(1)

    lst.pop_front();                                     // TC: O(1)
    lst.pop_back();                                      // TC: O(1)

    // --- Insert at iterator position ---
    auto it = lst.begin();
    advance(it, 1);                                      // move iterator forward by 1
    lst.insert(it, 99);                                  // insert before it, TC: O(1)

    // --- Erase at iterator ---
    lst.erase(it);                                       // TC: O(1) at known position

    // --- Sort, Reverse, Unique (list's own versions) ---
    list<int> lst2 = {5, 3, 1, 4, 2, 3, 3};
    lst2.sort();                                         // TC: O(n log n)
    lst2.unique();                                       // removes consecutive duplicates, TC: O(n)
    lst2.reverse();                                      // TC: O(n)

    cout << "lst2 after sort+unique+reverse: ";
    for (int x : lst2) cout << x << " ";
    cout << "\n";

    lst2.remove(3);                                      // remove ALL occurrences of value, TC: O(n)
    cout << "lst2 after remove(3): ";
    for (int x : lst2) cout << x << " ";
    cout << "\n";
}

// ============================================================
//  10. ALGORITHM METHODS
// ============================================================
void algorithm_methods() {
    cout << "\n========== 10. ALGORITHM METHODS ==========\n";

    vector<int> v = {5, 3, 1, 4, 2, 3};

    // --- sort ---
    sort(v.begin(), v.end());                                              // TC: O(n log n), ascending
    printVec(v, "sort() asc             ");

    sort(v.begin(), v.end(), greater<int>());                              // descending
    printVec(v, "sort() desc            ");

    sort(v.begin(), v.end(), [](int a, int b){ return a < b; });          // lambda comparator
    printVec(v, "sort() lambda asc      ");

    // --- reverse ---
    reverse(v.begin(), v.end());                                           // TC: O(n)
    printVec(v, "reverse()              ");

    // --- min / max ---
    cout << "min(3, 7)              => " << min(3, 7) << "\n";             // TC: O(1)
    cout << "max(3, 7)              => " << max(3, 7) << "\n";             // TC: O(1)
    cout << "min({1,5,3,2})         => " << min({1, 5, 3, 2}) << "\n";    // initializer_list
    cout << "max({1,5,3,2})         => " << max({1, 5, 3, 2}) << "\n";
    cout << "*min_element()         => " << *min_element(v.begin(), v.end()) << "\n"; // TC: O(n)
    cout << "*max_element()         => " << *max_element(v.begin(), v.end()) << "\n"; // TC: O(n)

    // --- count ---
    vector<int> v2 = {1, 2, 2, 3, 2, 4};
    cout << "count(v, 2)            => " << count(v2.begin(), v2.end(), 2) << "\n"; // TC: O(n)

    // --- find ---
    auto it = find(v2.begin(), v2.end(), 3);                               // TC: O(n)
    cout << "find(3) => index       => " << (it - v2.begin()) << "\n";

    // --- binary_search (sorted required!) ---
    sort(v2.begin(), v2.end());
    cout << "binary_search(3)       => " << binary_search(v2.begin(), v2.end(), 3) << "\n"; // TC: O(log n)

    // --- lower_bound / upper_bound (sorted required!) ---
    auto lb = lower_bound(v2.begin(), v2.end(), 2);                        // first >= 2
    auto ub = upper_bound(v2.begin(), v2.end(), 2);                        // first >  2
    cout << "lower_bound(2) index   => " << (lb - v2.begin()) << "\n";
    cout << "upper_bound(2) index   => " << (ub - v2.begin()) << "\n";

    // --- fill ---
    vector<int> v3(5);
    fill(v3.begin(), v3.end(), 0);                                         // TC: O(n)
    printVec(v3, "fill(0)                ");

    // --- swap ---
    int a = 5, b = 10;
    swap(a, b);                                                            // TC: O(1)
    cout << "After swap, a=" << a << " b=" << b << "\n";

    // --- rotate ---
    vector<int> v4 = {1, 2, 3, 4, 5};
    rotate(v4.begin(), v4.begin() + 2, v4.end());                         // TC: O(n)
    printVec(v4, "rotate by 2            ");

    // --- next_permutation / prev_permutation ---
    string s = "abc";
    int perms = 0;
    do { perms++; } while (next_permutation(s.begin(), s.end()));          // TC: O(n) per call
    cout << "next_permutation count => " << perms << " (for \"abc\")\n";

    // --- unique (removes consecutive duplicates) ---
    vector<int> v5 = {1, 1, 2, 3, 3, 4};
    auto uit = unique(v5.begin(), v5.end());                               // TC: O(n)
    v5.erase(uit, v5.end());
    printVec(v5, "unique+erase           ");

    // --- all_of / any_of / none_of ---
    vector<int> v6 = {2, 4, 6, 8};
    cout << "all_of even            => " << all_of(v6.begin(), v6.end(), [](int x){ return x%2==0; }) << "\n";
    cout << "any_of > 5             => " << any_of(v6.begin(), v6.end(), [](int x){ return x > 5; }) << "\n";
    cout << "none_of negative       => " << none_of(v6.begin(), v6.end(), [](int x){ return x < 0; }) << "\n";

    // --- is_sorted ---
    vector<int> v7 = {1, 2, 3, 4};
    cout << "is_sorted              => " << is_sorted(v7.begin(), v7.end()) << "\n"; // TC: O(n)

    // --- partial_sort (sort only first k elements) ---
    vector<int> v8 = {5, 3, 1, 4, 2};
    partial_sort(v8.begin(), v8.begin() + 3, v8.end());                   // TC: O(n log k)
    printVec(v8, "partial_sort(first 3)  ");

    // --- nth_element (k-th smallest in O(n) avg) ---
    vector<int> v9 = {5, 3, 1, 4, 2};
    nth_element(v9.begin(), v9.begin() + 2, v9.end());                    // TC: O(n) avg
    cout << "nth_element(k=2)       => " << v9[2] << " (3rd smallest)\n";

    // --- merge (two sorted ranges) ---
    vector<int> a1 = {1, 3, 5}, b1 = {2, 4, 6};
    vector<int> merged(6);
    merge(a1.begin(), a1.end(), b1.begin(), b1.end(), merged.begin());    // TC: O(n+m)
    printVec(merged, "merge()                ");

    // --- for_each ---
    vector<int> v10 = {1, 2, 3};
    int total = 0;
    for_each(v10.begin(), v10.end(), [&](int x){ total += x; });          // TC: O(n)
    cout << "for_each sum           => " << total << "\n";

    // --- transform ---
    vector<int> v11 = {1, 2, 3, 4};
    vector<int> v11_sq(v11.size());
    transform(v11.begin(), v11.end(), v11_sq.begin(), [](int x){ return x*x; }); // TC: O(n)
    printVec(v11_sq, "transform (squares)    ");

    // --- copy ---
    vector<int> src = {7, 8, 9};
    vector<int> dst(3);
    copy(src.begin(), src.end(), dst.begin());                             // TC: O(n)
    printVec(dst, "copy()                 ");
}

// ============================================================
//  11. NUMERIC METHODS
// ============================================================
void numeric_methods() {
    cout << "\n========== 11. NUMERIC METHODS ==========\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // --- accumulate (sum) ---
    int sum = accumulate(v.begin(), v.end(), 0);                           // TC: O(n)
    cout << "accumulate(sum)   => " << sum << "\n";

    // --- accumulate (product) ---
    long long prod = accumulate(v.begin(), v.end(), 1LL, multiplies<long long>());
    cout << "accumulate(prod)  => " << prod << "\n";

    // --- partial_sum (prefix sums) ---
    vector<int> prefix(v.size());
    partial_sum(v.begin(), v.end(), prefix.begin());                       // TC: O(n)
    printVec(prefix, "partial_sum           ");

    // --- iota (fill with incrementing values) ---
    vector<int> seq(6);
    iota(seq.begin(), seq.end(), 1);                                       // TC: O(n), fills 1,2,3,...
    printVec(seq, "iota(start=1)         ");

    // --- __gcd (built-in, works on all compilers) ---
    cout << "__gcd(12, 8)      => " << __gcd(12, 8)  << "\n";             // TC: O(log min(a,b))
    // C++17 standard: gcd(12, 8) and lcm(12, 8) from <numeric>

    // --- inner_product (dot product) ---
    vector<int> a = {1, 2, 3}, b = {4, 5, 6};
    int dot = inner_product(a.begin(), a.end(), b.begin(), 0);             // TC: O(n)
    cout << "inner_product     => " << dot << "\n"; // 1*4 + 2*5 + 3*6 = 32
}

// ============================================================
//  12. PAIR / TUPLE METHODS
// ============================================================
void pair_tuple_methods() {
    cout << "\n========== 12. PAIR / TUPLE METHODS ==========\n";

    // --- pair ---
    pair<int, string> p1 = {1, "Raj"};
    pair<int, string> p2 = make_pair(2, "Aryan");

    cout << "p1.first          => " << p1.first  << "\n"; // access first element
    cout << "p1.second         => " << p1.second << "\n"; // access second element

    // Pairs are comparable (lexicographic)
    cout << "p1 < p2           => " << (p1 < p2)  << "\n"; // compares first, then second

    // Swap pairs
    swap(p1, p2);
    cout << "After swap, p1.first => " << p1.first << "\n";

    // --- tuple (C++11) ---
    tuple<int, string, double> t = make_tuple(1, "hello", 3.14);

    cout << "get<0>(t)         => " << get<0>(t) << "\n"; // access by index
    cout << "get<1>(t)         => " << get<1>(t) << "\n";
    cout << "get<2>(t)         => " << get<2>(t) << "\n";

    // Structured bindings (C++17) — shown as comment for compatibility
    // auto [id, name, score] = t;  // C++17 only

    // tie() for unpacking into existing variables (C++11)
    int x; string s; double d;
    tie(x, s, d) = t;
    cout << "tie() unpack      => x=" << x << " s=" << s << " d=" << d << "\n";

    // Tuples in vectors (multi-key sorting)
    vector<tuple<int, int, int>> edges = {{5,1,2},{1,3,4},{3,2,1}};
    sort(edges.begin(), edges.end());          // sorts by first, then second, then third
    cout << "Sorted edge[0]    => " << get<0>(edges[0]) << "\n";
}

// ============================================================
//  13. UTILITY METHODS (swap, move, min, max, clamp, abs)
// ============================================================
void utility_methods() {
    cout << "\n========== 13. UTILITY METHODS ==========\n";

    // --- swap ---
    int a = 5, b = 10;
    swap(a, b);                                                            // TC: O(1)
    cout << "swap(a, b)        => a=" << a << " b=" << b << "\n";

    // --- min / max ---
    cout << "min(3, 7)         => " << min(3, 7) << "\n";                  // TC: O(1)
    cout << "max(3, 7)         => " << max(3, 7) << "\n";                  // TC: O(1)

    // --- clamp (C++17) — keeps value in [lo, hi] ---
    // std::clamp(val, lo, hi) — equivalent to max(lo, min(val, hi))
    auto my_clamp = [](int val, int lo, int hi){ return max(lo, min(val, hi)); };
    cout << "clamp(15, 0, 10)  => " << my_clamp(15, 0, 10) << "\n";         // => 10
    cout << "clamp(-5, 0, 10)  => " << my_clamp(-5, 0, 10) << "\n";         // => 0
    cout << "clamp(5, 0, 10)   => " << my_clamp(5, 0, 10)  << "\n";         // => 5

    // --- abs ---
    cout << "abs(-42)          => " << abs(-42)   << "\n";                  // TC: O(1)
    cout << "abs(-3.14)        => " << abs(-3.14) << "\n";                  // float version

    // --- move (transfer ownership, no copy) ---
    string s1 = "Hello";
    string s2 = move(s1);                                                  // s1 is now empty
    cout << "After move: s2    => " << s2 << "\n";
    cout << "After move: s1 is now in moved-from (empty) state\n";

    // --- __builtin functions (GCC specific, very common in CP) ---
    int n = 12;  // binary: 1100
    cout << "__builtin_popcount(12)  => " << __builtin_popcount(n)  << "\n"; // count 1-bits: 2
    cout << "__builtin_clz(12)       => " << __builtin_clz(n)       << "\n"; // count leading zeros
    cout << "__builtin_ctz(12)       => " << __builtin_ctz(n)       << "\n"; // count trailing zeros
    cout << "__builtin_parity(12)    => " << __builtin_parity(n)    << "\n"; // parity of 1-bits
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "====================================================\n";
    cout << "   IMPORTANT & FREQUENTLY USED STL METHODS IN C++  \n";
    cout << "====================================================\n";

    string_methods();
    vector_methods();
    map_methods();
    set_methods();
    stack_methods();
    queue_methods();
    deque_methods();
    priority_queue_methods();
    list_methods();
    algorithm_methods();
    numeric_methods();
    pair_tuple_methods();
    utility_methods();

    cout << "\n====================================================\n";
    cout << "   Done! Refer to cpp_headers_reference.md for more.\n";
    cout << "====================================================\n";

    return 0;
}
