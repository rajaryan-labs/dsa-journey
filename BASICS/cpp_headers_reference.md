# C++ Headers — Complete Reference Guide

> A categorized reference of all frequently used C++ headers with descriptions, key functions/classes, use cases, and important notes.

---

## Table of Contents

1. [The "Everything" Header](#1-the-everything-header)
2. [Input / Output Headers](#2-input--output-headers)
3. [Container Headers (STL)](#3-container-headers-stl)
4. [Algorithm & Utility Headers](#4-algorithm--utility-headers)
5. [String & Character Headers](#5-string--character-headers)
6. [Math & Numeric Headers](#6-math--numeric-headers)
7. [Iterator & Functional Headers](#7-iterator--functional-headers)
8. [Memory Management Headers](#8-memory-management-headers)
9. [Multithreading & Concurrency Headers](#9-multithreading--concurrency-headers)
10. [Time & Chrono Headers](#10-time--chrono-headers)
11. [File & Stream Headers](#11-file--stream-headers)
12. [Error Handling Headers](#12-error-handling-headers)
13. [Type Traits & Metaprogramming Headers](#13-type-traits--metaprogramming-headers)
14. [C Compatibility Headers](#14-c-compatibility-headers)
15. [Quick Reference Table](#15-quick-reference-table)

---

## 1. The "Everything" Header

### `#include <bits/stdc++.h>`
- **What it is:** A GCC-specific non-standard header that includes virtually every standard library header.
- **Key Includes:** `<iostream>`, `<vector>`, `<algorithm>`, `<string>`, `<map>`, `<set>`, `<queue>`, `<stack>`, `<cmath>`, `<climits>`, and hundreds more.
- **Use Cases:**
  - Competitive programming (saves time on includes).
  - Quick prototyping and practice.
- **Example:**
  ```cpp
  #include <bits/stdc++.h>
  using namespace std;

  int main() {
      vector<int> v = {3, 1, 4, 1, 5};
      sort(v.begin(), v.end());
      cout << *max_element(v.begin(), v.end());
      return 0;
  }
  ```
- **⚠️ Important Notes:**
  - **Non-standard** — only works on GCC (g++). Not available on MSVC or Clang by default.
  - **Increases compile time** significantly (includes everything).
  - **Never use in production code** or interviews that expect standard code.
  - Prefer individual headers in real projects.

---

## 2. Input / Output Headers

### `#include <iostream>`
- **What it provides:** Standard I/O stream objects.
- **Key Components:** `cin`, `cout`, `cerr`, `clog`, `endl`, `<<`, `>>`.
- **Use Cases:** Console input/output — the most fundamental C++ header.
- **Example:**
  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      int n;
      cout << "Enter a number: ";
      cin >> n;
      cout << "You entered: " << n << endl;
      cerr << "This goes to stderr" << endl;
      return 0;
  }
  ```
- **Tips:**
  - Use `'\n'` instead of `endl` for faster output (avoids buffer flush).
  - For competitive programming, add:
    ```cpp
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ```

---

### `#include <iomanip>`
- **What it provides:** I/O stream manipulators for formatting.
- **Key Components:** `setw()`, `setprecision()`, `fixed`, `setfill()`, `left`, `right`, `hex`, `oct`, `dec`, `boolalpha`.
- **Use Cases:** Formatted output — tables, fixed decimals, padding, alignment.
- **Example:**
  ```cpp
  #include <iostream>
  #include <iomanip>
  using namespace std;

  int main() {
      double pi = 3.14159265358979;

      cout << fixed << setprecision(2) << pi << endl;       // 3.14
      cout << setw(10) << setfill('*') << 42 << endl;       // ********42
      cout << left << setw(10) << "Name" << "Score" << endl; // Name      Score
      cout << hex << 255 << endl;                            // ff
      cout << boolalpha << true << endl;                     // true
      return 0;
  }
  ```
- **Tips:**
  - `fixed << setprecision(n)` is essential for printing exact decimal places.
  - `setw()` only affects the **next** output — not persistent.

---

### `#include <sstream>`
- **What it provides:** String-based stream classes for parsing and building strings.
- **Key Components:** `istringstream`, `ostringstream`, `stringstream`.
- **Use Cases:** Parsing strings into tokens, converting types to/from strings, building formatted strings.
- **Example:**
  ```cpp
  #include <sstream>
  #include <iostream>
  #include <string>
  using namespace std;

  int main() {
      // Parsing a string into tokens
      string line = "10 20 30";
      istringstream iss(line);
      int a, b, c;
      iss >> a >> b >> c;  // a=10, b=20, c=30

      // Building a string
      ostringstream oss;
      oss << "Sum = " << (a + b + c);
      string result = oss.str();  // "Sum = 60"

      // String to int conversion
      stringstream ss("42");
      int val;
      ss >> val;  // val = 42

      return 0;
  }
  ```
- **Tips:**
  - Great for splitting space-separated input.
  - Prefer `to_string()` and `stoi()` for simple conversions (C++11).

---

## 3. Container Headers (STL)

### `#include <vector>`
- **What it provides:** Dynamic array container.
- **Key Components:** `vector<T>`, `push_back()`, `pop_back()`, `size()`, `empty()`, `begin()`, `end()`, `resize()`, `reserve()`, `at()`, `front()`, `back()`, `clear()`, `erase()`, `insert()`.
- **Use Cases:** Most-used container — dynamic arrays, adjacency lists, 2D matrices, stacks.
- **Example:**
  ```cpp
  #include <vector>
  using namespace std;

  vector<int> v = {1, 2, 3, 4, 5};
  v.push_back(6);                    // [1,2,3,4,5,6]
  v.pop_back();                      // [1,2,3,4,5]
  v.insert(v.begin() + 2, 99);      // [1,2,99,3,4,5]
  v.erase(v.begin());               // [2,99,3,4,5]

  // 2D vector (matrix)
  vector<vector<int>> grid(n, vector<int>(m, 0));

  // Iterate
  for (auto& x : v) cout << x << " ";
  ```
- **Complexity:**
  - `push_back()` — amortized O(1)
  - `insert()`/`erase()` at middle — O(n)
  - Random access `v[i]` — O(1)
- **Tips:**
  - Use `reserve()` if you know the size in advance to avoid reallocations.
  - `emplace_back()` is more efficient than `push_back()` for complex objects.

---

### `#include <array>` *(C++11)*
- **What it provides:** Fixed-size array wrapper with STL interface.
- **Key Components:** `array<T, N>`, `size()`, `at()`, `fill()`, `front()`, `back()`.
- **Use Cases:** When array size is known at compile time; safer alternative to C-style arrays.
- **Example:**
  ```cpp
  #include <array>
  using namespace std;

  array<int, 5> arr = {1, 2, 3, 4, 5};
  arr.fill(0);           // all zeros
  cout << arr.size();    // 5
  cout << arr.at(2);     // bounds-checked access
  ```
- **Advantages over C arrays:** Knows its size, supports `.begin()`/`.end()`, no decay to pointer.

---

### `#include <string>`
- **What it provides:** Dynamic string class.
- **Key Components:** `string`, `length()`/`size()`, `substr()`, `find()`, `append()`, `replace()`, `c_str()`, `push_back()`, `pop_back()`, `erase()`, `insert()`, `stoi()`, `stol()`, `stof()`, `to_string()`, `+` operator.
- **Use Cases:** Text manipulation, parsing, string algorithms.
- **Example:**
  ```cpp
  #include <string>
  using namespace std;

  string s = "Hello, World!";
  string sub = s.substr(0, 5);            // "Hello"
  size_t pos = s.find("World");           // 7
  s.replace(7, 5, "C++");                // "Hello, C++!"
  string num = to_string(42);             // "42"
  int val = stoi("123");                  // 123

  // Iterate characters
  for (char c : s) cout << c;

  // Reverse a string
  reverse(s.begin(), s.end());
  ```
- **Tips:**
  - `string::npos` is the "not found" return value of `find()`.
  - Use `s.empty()` instead of `s.size() == 0`.
  - Concatenation in loops is O(n²) — use `ostringstream` or `reserve()`.

---

### `#include <map>`
- **What it provides:** Ordered key-value associative container (Red-Black Tree).
- **Key Components:** `map<K,V>`, `insert()`, `erase()`, `find()`, `count()`, `[]`, `at()`, `begin()`, `end()`, `lower_bound()`, `upper_bound()`, `size()`.
- **Use Cases:** Frequency counting, dictionaries, ordered mappings, coordinate compression.
- **Example:**
  ```cpp
  #include <map>
  using namespace std;

  map<string, int> freq;
  freq["apple"] = 3;
  freq["banana"]++;
  freq.insert({"cherry", 5});

  // Iterate (sorted by key)
  for (auto& [key, val] : freq) {
      cout << key << ": " << val << endl;
  }

  // Check existence
  if (freq.count("apple")) cout << "Found!";
  if (auto it = freq.find("banana"); it != freq.end()) {
      cout << it->second;
  }
  ```
- **Complexity:** All operations O(log n).
- **Tips:**
  - `[]` operator **inserts** a default value if the key doesn't exist — use `find()` or `count()` to check.
  - Use `unordered_map` for O(1) average lookups when order doesn't matter.

---

### `#include <unordered_map>`
- **What it provides:** Hash-based key-value container (Hash Table).
- **Key Components:** Same interface as `map` but unordered. Also: `bucket_count()`, `load_factor()`, `reserve()`.
- **Use Cases:** Fast lookups, frequency counting, caching, two-sum style problems.
- **Example:**
  ```cpp
  #include <unordered_map>
  using namespace std;

  unordered_map<int, int> mp;
  mp[1] = 100;
  mp[2] = 200;

  // Two-sum pattern
  for (int i = 0; i < n; i++) {
      int complement = target - nums[i];
      if (mp.count(complement)) return {mp[complement], i};
      mp[nums[i]] = i;
  }
  ```
- **Complexity:** Average O(1) insert/lookup; worst case O(n) on hash collisions.
- **Tips:**
  - Cannot use `pair`, `vector`, or custom types as keys without a custom hash.
  - Slightly more memory than `map`.
  - For competitive programming, beware of hash collision attacks — use `map` if TLE suspected.

---

### `#include <set>`
- **What it provides:** Ordered unique-element container (Red-Black Tree).
- **Key Components:** `set<T>`, `insert()`, `erase()`, `find()`, `count()`, `lower_bound()`, `upper_bound()`, `begin()`, `end()`, `rbegin()`, `rend()`, `size()`.
- **Use Cases:** Unique elements, sorted order, range queries, sliding window problems.
- **Example:**
  ```cpp
  #include <set>
  using namespace std;

  set<int> s = {5, 3, 1, 4, 2};
  s.insert(6);
  s.erase(3);

  // Iterate (sorted)
  for (int x : s) cout << x << " ";  // 1 2 4 5 6

  // Smallest / Largest
  cout << *s.begin();   // 1
  cout << *s.rbegin();  // 6

  // Lower bound (first element >= 4)
  auto it = s.lower_bound(4);  // points to 4
  ```
- **Complexity:** All operations O(log n).
- **Tips:**
  - Use `multiset` if you need duplicates.
  - `set` doesn't support random access (`s[i]` won't work).

---

### `#include <unordered_set>`
- **What it provides:** Hash-based unique-element container.
- **Key Components:** Same as `set` but unordered and hash-based.
- **Use Cases:** Fast membership checks, deduplication.
- **Example:**
  ```cpp
  #include <unordered_set>
  using namespace std;

  unordered_set<int> seen;
  for (int x : arr) {
      if (seen.count(x)) cout << "Duplicate: " << x;
      seen.insert(x);
  }
  ```
- **Complexity:** Average O(1); worst case O(n).

---

### `#include <queue>`
- **What it provides:** FIFO queue and priority queue adapters.
- **Key Components:**
  - `queue<T>`: `push()`, `pop()`, `front()`, `back()`, `empty()`, `size()`.
  - `priority_queue<T>`: `push()`, `pop()`, `top()`, `empty()`, `size()`.
- **Use Cases:** BFS, level-order traversal, scheduling, top-K problems, Dijkstra's algorithm.
- **Example:**
  ```cpp
  #include <queue>
  using namespace std;

  // --- FIFO Queue ---
  queue<int> q;
  q.push(10);
  q.push(20);
  cout << q.front();  // 10
  q.pop();

  // --- Max Heap (default) ---
  priority_queue<int> maxHeap;
  maxHeap.push(30);
  maxHeap.push(10);
  maxHeap.push(20);
  cout << maxHeap.top();  // 30

  // --- Min Heap ---
  priority_queue<int, vector<int>, greater<int>> minHeap;
  minHeap.push(30);
  minHeap.push(10);
  cout << minHeap.top();  // 10

  // --- Custom comparator (for pairs, structs) ---
  auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
      return a.second > b.second;  // min-heap by second element
  };
  priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
  ```
- **Tips:**
  - `priority_queue` is a **max-heap** by default. Use `greater<int>` for min-heap.
  - No `clear()` method — assign empty queue to clear.
  - `priority_queue` doesn't support `find()` or `erase()` — use `set` or `multiset` if needed.

---

### `#include <stack>`
- **What it provides:** LIFO stack adapter.
- **Key Components:** `stack<T>`, `push()`, `pop()`, `top()`, `empty()`, `size()`.
- **Use Cases:** Parenthesis matching, undo operations, DFS, monotonic stack, expression evaluation.
- **Example:**
  ```cpp
  #include <stack>
  using namespace std;

  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  cout << st.top();  // 3
  st.pop();
  cout << st.top();  // 2

  // Reverse a string using stack
  stack<char> charStack;
  for (char c : str) charStack.push(c);
  while (!charStack.empty()) {
      cout << charStack.top();
      charStack.pop();
  }
  ```
- **Tips:**
  - Built on `deque` by default. Can use `vector` as underlying: `stack<int, vector<int>>`.
  - No iterator support — can't traverse without popping.

---

### `#include <deque>`
- **What it provides:** Double-ended queue — efficient insertion/removal at both ends.
- **Key Components:** `deque<T>`, `push_front()`, `push_back()`, `pop_front()`, `pop_back()`, `front()`, `back()`, `[]`, `size()`.
- **Use Cases:** Sliding window maximum, BFS with 0-1 weights, implementing both stack and queue.
- **Example:**
  ```cpp
  #include <deque>
  using namespace std;

  deque<int> dq;
  dq.push_back(1);
  dq.push_front(0);
  dq.push_back(2);
  // dq: [0, 1, 2]

  cout << dq.front();  // 0
  cout << dq.back();   // 2
  cout << dq[1];       // 1 (random access)

  dq.pop_front();      // [1, 2]
  ```
- **Complexity:** O(1) push/pop at both ends; O(1) random access.
- **Tips:**
  - Not contiguous in memory like `vector` — slightly higher cache miss rate.
  - Use for sliding window problems where you need front removal.

---

### `#include <list>`
- **What it provides:** Doubly-linked list container.
- **Key Components:** `list<T>`, `push_front()`, `push_back()`, `pop_front()`, `pop_back()`, `insert()`, `erase()`, `splice()`, `sort()`, `merge()`, `unique()`, `reverse()`.
- **Use Cases:** Frequent insertions/deletions in the middle, LRU cache implementation.
- **Example:**
  ```cpp
  #include <list>
  using namespace std;

  list<int> lst = {1, 2, 3, 4, 5};
  lst.push_front(0);
  lst.push_back(6);

  auto it = lst.begin();
  advance(it, 3);
  lst.insert(it, 99);   // insert before position 3
  lst.erase(it);        // erase element at iterator
  ```
- **Complexity:** O(1) insert/erase at known position; O(n) to find a position.
- **Tips:**
  - No random access (`lst[i]` won't work).
  - Higher memory overhead per element (two pointers for prev/next).
  - Rarely used in competitive programming — `vector` or `deque` usually suffice.

---

### `#include <pair>` → Actually part of `<utility>`
- **What it provides:** `std::pair<T1, T2>` — holds two values of potentially different types.
- **Key Components:** `first`, `second`, `make_pair()`.
- **Use Cases:** Returning two values, storing edges, map entries, coordinate pairs.
- **Example:**
  ```cpp
  #include <utility>  // or included via <bits/stdc++.h>, <map>, <algorithm>
  using namespace std;

  pair<int, int> p = {3, 5};
  cout << p.first << " " << p.second;  // 3 5

  pair<string, int> student = make_pair("Raj", 100);

  // Pairs are comparable (lexicographic)
  pair<int,int> a = {1, 2}, b = {1, 3};
  if (a < b) cout << "a is smaller";  // true
  ```

---

### `#include <tuple>` *(C++11)*
- **What it provides:** Fixed-size collection of heterogeneous values.
- **Key Components:** `tuple<T1,T2,...>`, `get<N>()`, `make_tuple()`, `tie()`, structured bindings (C++17).
- **Use Cases:** Returning multiple values, storing edges with weights, multi-key sorting.
- **Example:**
  ```cpp
  #include <tuple>
  using namespace std;

  tuple<int, string, double> t = make_tuple(1, "hello", 3.14);
  cout << get<0>(t);  // 1
  cout << get<1>(t);  // hello

  // Structured bindings (C++17)
  auto [id, name, score] = t;

  // tie() for unpacking
  int a; string b; double c;
  tie(a, b, c) = t;

  // Tuples are comparable (lexicographic)
  // Great for multi-key sorting in competitive programming
  vector<tuple<int,int,int>> edges;
  edges.push_back({5, 1, 2});  // weight, u, v
  sort(edges.begin(), edges.end());  // sorts by weight first
  ```

---

### `#include <bitset>`
- **What it provides:** Fixed-size sequence of bits with rich operations.
- **Key Components:** `bitset<N>`, `set()`, `reset()`, `flip()`, `test()`, `count()`, `any()`, `none()`, `all()`, `to_string()`, `to_ulong()`, `&`, `|`, `^`, `~`, `<<`, `>>`.
- **Use Cases:** Sieve of Eratosthenes, subset DP, efficient boolean arrays, bitmask operations.
- **Example:**
  ```cpp
  #include <bitset>
  using namespace std;

  bitset<8> b("10110011");
  cout << b.count();      // 5 (number of 1s)
  cout << b.test(0);      // 1 (bit at position 0)
  b.flip();               // complement
  b.set(3);               // set bit 3 to 1
  b.reset(3);             // set bit 3 to 0

  bitset<8> a(42);        // from integer
  cout << a;              // 00101010
  cout << (a & b);        // bitwise AND

  // Sieve of Eratosthenes
  bitset<1000001> sieve;
  sieve.set();  // all 1s
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i * i <= 1000000; i++)
      if (sieve[i])
          for (int j = i*i; j <= 1000000; j += i)
              sieve[j] = 0;
  ```
- **Tips:**
  - Size must be a compile-time constant.
  - Much more memory efficient than `vector<bool>` for large fixed-size boolean arrays.
  - Bitwise operations on `bitset` are optimized to work on 64-bit chunks.

---

## 4. Algorithm & Utility Headers

### `#include <algorithm>`
- **What it provides:** The workhorse header — 100+ algorithms for containers.
- **Key Components:**

| Function | What it does | Complexity |
|----------|-------------|------------|
| `sort(begin, end)` | Sort in ascending order | O(n log n) |
| `sort(begin, end, cmp)` | Sort with custom comparator | O(n log n) |
| `reverse(begin, end)` | Reverse a range | O(n) |
| `min(a, b)` / `max(a, b)` | Return min/max | O(1) |
| `min_element(begin, end)` | Iterator to minimum | O(n) |
| `max_element(begin, end)` | Iterator to maximum | O(n) |
| `find(begin, end, val)` | Linear search | O(n) |
| `binary_search(begin, end, val)` | Check if exists (sorted) | O(log n) |
| `lower_bound(begin, end, val)` | First element ≥ val | O(log n) |
| `upper_bound(begin, end, val)` | First element > val | O(log n) |
| `count(begin, end, val)` | Count occurrences | O(n) |
| `accumulate(begin, end, init)` | Sum (in `<numeric>`) | O(n) |
| `next_permutation(begin, end)` | Next lexicographic permutation | O(n) |
| `prev_permutation(begin, end)` | Previous permutation | O(n) |
| `unique(begin, end)` | Remove consecutive duplicates | O(n) |
| `fill(begin, end, val)` | Fill range with value | O(n) |
| `swap(a, b)` | Swap two values | O(1) |
| `rotate(begin, mid, end)` | Rotate range | O(n) |
| `nth_element(begin, nth, end)` | Partial sort (nth element in place) | O(n) avg |
| `partial_sort(begin, mid, end)` | Sort first K elements | O(n log k) |
| `merge(b1, e1, b2, e2, out)` | Merge two sorted ranges | O(n+m) |
| `set_union / set_intersection` | Set operations on sorted ranges | O(n+m) |
| `is_sorted(begin, end)` | Check if sorted | O(n) |
| `copy(begin, end, dest)` | Copy range | O(n) |
| `transform(begin, end, out, fn)` | Apply function to each element | O(n) |
| `for_each(begin, end, fn)` | Apply function (no output) | O(n) |
| `all_of / any_of / none_of` | Predicate checks | O(n) |

- **Example:**
  ```cpp
  #include <algorithm>
  #include <vector>
  using namespace std;

  vector<int> v = {5, 3, 1, 4, 2};

  sort(v.begin(), v.end());                    // {1, 2, 3, 4, 5}
  sort(v.begin(), v.end(), greater<int>());    // {5, 4, 3, 2, 1}

  // Binary search on sorted array
  if (binary_search(v.begin(), v.end(), 3)) cout << "Found";

  // Lower bound
  auto it = lower_bound(v.begin(), v.end(), 3);
  int idx = it - v.begin();

  // Next permutation
  string s = "abc";
  do { cout << s << endl; } while (next_permutation(s.begin(), s.end()));

  // Custom sort
  sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
  ```
- **Tips:**
  - `lower_bound` and `upper_bound` require the range to be **sorted**.
  - `unique` only removes **consecutive** duplicates — sort first for full deduplication.
  - `nth_element` is faster than full sort when you only need the k-th element.

---

### `#include <numeric>`
- **What it provides:** Numeric operations on ranges.
- **Key Components:** `accumulate()`, `partial_sum()`, `inner_product()`, `adjacent_difference()`, `iota()`, `gcd()` (C++17), `lcm()` (C++17), `reduce()` (C++17).
- **Use Cases:** Prefix sums, range sums, GCD/LCM, filling sequences.
- **Example:**
  ```cpp
  #include <numeric>
  #include <vector>
  using namespace std;

  vector<int> v = {1, 2, 3, 4, 5};

  int sum = accumulate(v.begin(), v.end(), 0);         // 15
  long long bigSum = accumulate(v.begin(), v.end(), 0LL); // avoids overflow

  // Prefix sum
  vector<int> prefix(v.size());
  partial_sum(v.begin(), v.end(), prefix.begin());     // {1, 3, 6, 10, 15}

  // Fill with increasing values
  vector<int> seq(5);
  iota(seq.begin(), seq.end(), 1);                     // {1, 2, 3, 4, 5}

  // GCD and LCM (C++17)
  cout << gcd(12, 8);   // 4
  cout << lcm(12, 8);   // 24
  ```
- **Tips:**
  - `accumulate` with `0` uses `int` — pass `0LL` for `long long` results.
  - `iota` is named after the APL operator — fills with incrementing values.

---

### `#include <utility>`
- **What it provides:** Miscellaneous utilities.
- **Key Components:** `pair<T1,T2>`, `make_pair()`, `swap()`, `move()`, `forward()`, `declval()`.
- **Use Cases:** Pairs, move semantics, perfect forwarding.
- **Example:**
  ```cpp
  #include <utility>
  using namespace std;

  auto p = make_pair(1, "hello");
  swap(a, b);

  // Move semantics
  string s1 = "Hello";
  string s2 = move(s1);  // s1 is now empty, s2 owns "Hello"
  ```

---

### `#include <functional>`
- **What it provides:** Function objects, wrappers, and utilities.
- **Key Components:** `function<>`, `greater<>`, `less<>`, `plus<>`, `minus<>`, `bind()`, `ref()`, `hash<>`.
- **Use Cases:** Custom comparators, callback storage, hash functions.
- **Example:**
  ```cpp
  #include <functional>
  using namespace std;

  // Min-heap using greater
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // Sort descending
  sort(v.begin(), v.end(), greater<int>());

  // Store a callable
  function<int(int, int)> add = [](int a, int b) { return a + b; };
  cout << add(3, 4);  // 7

  // Recursive lambda (needs std::function)
  function<int(int)> factorial = [&](int n) -> int {
      return n <= 1 ? 1 : n * factorial(n - 1);
  };
  ```

---

## 5. String & Character Headers

### `#include <cctype>` (C) / `#include <ctype.h>`
- **What it provides:** Character classification and conversion functions.
- **Key Components:**

| Function | Description |
|----------|-------------|
| `isalpha(c)` | Is alphabetic (a-z, A-Z) |
| `isdigit(c)` | Is digit (0-9) |
| `isalnum(c)` | Is alphanumeric |
| `isupper(c)` | Is uppercase |
| `islower(c)` | Is lowercase |
| `isspace(c)` | Is whitespace |
| `toupper(c)` | Convert to uppercase |
| `tolower(c)` | Convert to lowercase |

- **Example:**
  ```cpp
  #include <cctype>

  char c = 'A';
  if (isalpha(c)) cout << "Letter";
  if (isupper(c)) cout << "Uppercase";
  char lower = tolower(c);  // 'a'

  // Convert string to lowercase
  string s = "Hello World";
  for (char& ch : s) ch = tolower(ch);
  ```

---

### `#include <cstring>` (C) / `#include <string.h>`
- **What it provides:** C-style string and memory manipulation functions.
- **Key Components:** `strlen()`, `strcpy()`, `strcat()`, `strcmp()`, `strstr()`, `memset()`, `memcpy()`, `memmove()`.
- **Use Cases:** C-style strings, `memset` for array initialization, legacy code.
- **Example:**
  ```cpp
  #include <cstring>

  // Most common use: memset for initialization
  int arr[100];
  memset(arr, 0, sizeof(arr));     // fill with 0
  memset(arr, -1, sizeof(arr));    // fill with -1 (works for int)
  memset(arr, 0x3f, sizeof(arr));  // fill with large value (~1e9)

  // C-string operations (prefer std::string)
  char s1[20] = "Hello";
  char s2[20];
  strcpy(s2, s1);
  strcat(s1, " World");
  cout << strlen(s1);  // 11
  ```
- **⚠️ Warning:** `memset` only reliably works with 0, -1, and 0x3f for integers. It sets **bytes**, not values.

---

## 6. Math & Numeric Headers

### `#include <cmath>` (C) / `#include <math.h>`
- **What it provides:** Mathematical functions.
- **Key Components:**

| Function | Description |
|----------|-------------|
| `sqrt(x)` | Square root |
| `pow(base, exp)` | Power |
| `abs(x)` | Absolute value (use `fabs` for floating-point in C) |
| `ceil(x)` | Round up |
| `floor(x)` | Round down |
| `round(x)` | Round to nearest |
| `log(x)` | Natural log (ln) |
| `log2(x)` | Log base 2 |
| `log10(x)` | Log base 10 |
| `sin/cos/tan(x)` | Trigonometric (radians) |
| `asin/acos/atan(x)` | Inverse trig |
| `atan2(y, x)` | Two-argument arctangent |
| `fmod(x, y)` | Floating-point modulo |
| `hypot(x, y)` | √(x² + y²) |

- **Example:**
  ```cpp
  #include <cmath>

  cout << sqrt(144);          // 12
  cout << pow(2, 10);         // 1024
  cout << ceil(3.2);          // 4
  cout << floor(3.8);         // 3
  cout << round(3.5);         // 4
  cout << log2(1024);         // 10
  cout << abs(-5);            // 5
  cout << hypot(3.0, 4.0);   // 5
  ```
- **⚠️ Warning:**
  - `pow()` returns `double` — may have precision issues for integer exponentiation. Use custom `power()` function for modular exponentiation.
  - `sqrt()` on negative numbers returns `NaN`.

---

### `#include <climits>` (C) / `#include <limits.h>`
- **What it provides:** Limits of integral types.
- **Key Constants:**

| Constant | Value | Type |
|----------|-------|------|
| `INT_MAX` | 2,147,483,647 | `int` |
| `INT_MIN` | −2,147,483,648 | `int` |
| `LONG_LONG_MAX` | 9.2 × 10¹⁸ | `long long` |
| `LONG_LONG_MIN` | −9.2 × 10¹⁸ | `long long` |
| `CHAR_MAX` | 127 | `char` |
| `CHAR_MIN` | −128 | `char` |
| `UINT_MAX` | 4,294,967,295 | `unsigned int` |

- **Example:**
  ```cpp
  #include <climits>

  int maxVal = INT_MAX;       // 2147483647
  int minVal = INT_MIN;       // -2147483648
  long long big = LLONG_MAX;  // 9223372036854775807

  // Common use: initialize min/max
  int minSoFar = INT_MAX;
  int maxSoFar = INT_MIN;
  for (int x : arr) {
      minSoFar = min(minSoFar, x);
      maxSoFar = max(maxSoFar, x);
  }
  ```

---

### `#include <cfloat>` (C) / `#include <float.h>`
- **What it provides:** Limits of floating-point types.
- **Key Constants:** `FLT_MAX`, `FLT_MIN`, `FLT_EPSILON`, `DBL_MAX`, `DBL_MIN`, `DBL_EPSILON`.
- **Example:**
  ```cpp
  #include <cfloat>

  cout << DBL_MAX;      // ~1.8e+308
  cout << DBL_EPSILON;  // ~2.2e-16 (smallest difference from 1.0)
  ```

---

### `#include <limits>` (C++ style)
- **What it provides:** Type-safe numeric limits via `numeric_limits<T>`.
- **Use Cases:** Generic programming, template code.
- **Example:**
  ```cpp
  #include <limits>
  using namespace std;

  cout << numeric_limits<int>::max();          // 2147483647
  cout << numeric_limits<int>::min();          // -2147483648
  cout << numeric_limits<double>::infinity();  // inf
  cout << numeric_limits<float>::epsilon();    // ~1.19e-7
  ```

---

### `#include <cstdlib>` (C) / `#include <stdlib.h>`
- **What it provides:** General utilities — random numbers, memory, conversions, process control.
- **Key Components:** `rand()`, `srand()`, `abs()`, `atoi()`, `atof()`, `malloc()`, `free()`, `exit()`, `system()`, `qsort()`.
- **Example:**
  ```cpp
  #include <cstdlib>
  #include <ctime>

  srand(time(0));                    // seed random
  int r = rand() % 100;             // random 0-99

  int val = atoi("42");             // C-style string to int
  exit(0);                          // terminate program
  ```
- **Tips:** Prefer `<random>` (C++11) over `rand()` for better quality randomness.

---

### `#include <random>` *(C++11)*
- **What it provides:** Modern random number generation.
- **Key Components:** `mt19937`, `uniform_int_distribution`, `uniform_real_distribution`, `random_device`.
- **Example:**
  ```cpp
  #include <random>
  using namespace std;

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(1, 100);  // [1, 100]
  int random_val = dist(rng);

  // Quick random number
  int r = rng() % 100;  // less uniform but fast
  ```
- **Tips:** `mt19937` is the standard Mersenne Twister — much better than `rand()`.

---

## 7. Iterator & Functional Headers

### `#include <iterator>`
- **What it provides:** Iterator utilities and adapters.
- **Key Components:** `advance()`, `next()`, `prev()`, `distance()`, `back_inserter()`, `front_inserter()`, `istream_iterator`, `ostream_iterator`.
- **Example:**
  ```cpp
  #include <iterator>
  using namespace std;

  list<int> lst = {1, 2, 3, 4, 5};
  auto it = lst.begin();
  advance(it, 3);       // move iterator forward 3 positions
  cout << *it;          // 4

  auto nxt = next(it);  // iterator to next element
  auto prv = prev(it);  // iterator to previous element

  // Copy vector to output
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

  // Read input into vector
  vector<int> nums(istream_iterator<int>(cin), istream_iterator<int>());
  ```

---

## 8. Memory Management Headers

### `#include <memory>` *(C++11)*
- **What it provides:** Smart pointers for automatic memory management.
- **Key Components:** `unique_ptr`, `shared_ptr`, `weak_ptr`, `make_unique()` (C++14), `make_shared()`.
- **Use Cases:** RAII, preventing memory leaks, ownership semantics.
- **Example:**
  ```cpp
  #include <memory>
  using namespace std;

  // unique_ptr — sole ownership (preferred)
  auto ptr = make_unique<int>(42);
  cout << *ptr;  // 42
  // automatically deleted when out of scope

  // shared_ptr — shared ownership (reference counted)
  auto sp1 = make_shared<vector<int>>(10, 0);
  auto sp2 = sp1;  // both own the vector
  cout << sp1.use_count();  // 2

  // For tree/graph nodes
  struct Node {
      int val;
      unique_ptr<Node> left, right;
      Node(int v) : val(v) {}
  };
  auto root = make_unique<Node>(1);
  root->left = make_unique<Node>(2);
  ```
- **Tips:**
  - Prefer `unique_ptr` over `shared_ptr` — less overhead.
  - Use `make_unique`/`make_shared` instead of raw `new`.
  - `weak_ptr` breaks circular references in `shared_ptr`.

---

## 9. Multithreading & Concurrency Headers

### `#include <thread>` *(C++11)*
- **What it provides:** Thread creation and management.
- **Key Components:** `thread`, `this_thread::sleep_for()`, `this_thread::get_id()`, `join()`, `detach()`.
- **Example:**
  ```cpp
  #include <thread>
  #include <iostream>
  using namespace std;

  void worker(int id) {
      cout << "Thread " << id << " running\n";
  }

  int main() {
      thread t1(worker, 1);
      thread t2(worker, 2);
      t1.join();  // wait for t1 to finish
      t2.join();
      return 0;
  }
  ```

---

### `#include <mutex>` *(C++11)*
- **What it provides:** Mutual exclusion for thread safety.
- **Key Components:** `mutex`, `lock_guard`, `unique_lock`, `recursive_mutex`.
- **Example:**
  ```cpp
  #include <mutex>
  mutex mtx;

  void safeIncrement(int& counter) {
      lock_guard<mutex> lock(mtx);  // auto-unlocks
      counter++;
  }
  ```

---

### `#include <atomic>` *(C++11)*
- **What it provides:** Lock-free atomic operations.
- **Key Components:** `atomic<T>`, `load()`, `store()`, `fetch_add()`, `compare_exchange_strong()`.
- **Example:**
  ```cpp
  #include <atomic>
  atomic<int> counter(0);
  counter.fetch_add(1);  // thread-safe increment
  ```

---

## 10. Time & Chrono Headers

### `#include <chrono>` *(C++11)*
- **What it provides:** Time utilities — durations, clocks, time points.
- **Key Components:** `system_clock`, `steady_clock`, `high_resolution_clock`, `duration`, `time_point`, `milliseconds`, `seconds`, `minutes`.
- **Use Cases:** Benchmarking, timing code, delays.
- **Example:**
  ```cpp
  #include <chrono>
  using namespace std;
  using namespace chrono;

  // Benchmark code execution
  auto start = high_resolution_clock::now();
  // ... code to measure ...
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);
  cout << "Time: " << duration.count() << " ms" << endl;

  // Sleep
  this_thread::sleep_for(seconds(2));
  ```

---

### `#include <ctime>` (C)
- **What it provides:** C-style time and date functions.
- **Key Components:** `time()`, `clock()`, `difftime()`, `ctime()`, `localtime()`, `strftime()`.
- **Use Cases:** Seeding `srand()`, getting wall-clock time, competitive programming timer.
- **Example:**
  ```cpp
  #include <ctime>

  srand(time(0));  // seed random with current time
  time_t now = time(0);
  cout << ctime(&now);  // "Tue Sep 23 22:38:07 2026\n"
  ```

---

## 11. File & Stream Headers

### `#include <fstream>`
- **What it provides:** File input/output streams.
- **Key Components:** `ifstream` (input), `ofstream` (output), `fstream` (both).
- **Use Cases:** Reading/writing files, competitive programming (local testing).
- **Example:**
  ```cpp
  #include <fstream>
  using namespace std;

  // Write to file
  ofstream fout("output.txt");
  fout << "Hello, File!" << endl;
  fout.close();

  // Read from file
  ifstream fin("input.txt");
  string line;
  while (getline(fin, line)) {
      cout << line << endl;
  }
  fin.close();

  // Competitive programming trick (redirect I/O)
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
  ```

---

## 12. Error Handling Headers

### `#include <stdexcept>`
- **What it provides:** Standard exception classes.
- **Key Components:** `runtime_error`, `logic_error`, `out_of_range`, `invalid_argument`, `overflow_error`, `underflow_error`, `domain_error`, `length_error`.
- **Example:**
  ```cpp
  #include <stdexcept>
  using namespace std;

  int divide(int a, int b) {
      if (b == 0) throw runtime_error("Division by zero");
      return a / b;
  }

  try {
      divide(10, 0);
  } catch (const runtime_error& e) {
      cerr << e.what();  // "Division by zero"
  }
  ```

---

### `#include <cassert>` (C) / `#include <assert.h>`
- **What it provides:** Runtime assertion macro.
- **Use Cases:** Debugging, validating invariants during development.
- **Example:**
  ```cpp
  #include <cassert>

  assert(n > 0);                   // aborts if false
  assert(ptr != nullptr);
  assert(left <= right && "Invalid range");  // with message
  ```
- **Tips:** Disabled when compiling with `-DNDEBUG` (release mode).

---

## 13. Type Traits & Metaprogramming Headers

### `#include <type_traits>` *(C++11)*
- **What it provides:** Compile-time type introspection and transformation.
- **Key Components:** `is_integral<T>`, `is_floating_point<T>`, `is_same<T,U>`, `enable_if<>`, `remove_const<T>`, `decay<T>`, `conditional<>`.
- **Use Cases:** Template metaprogramming, SFINAE, `static_assert` checks.
- **Example:**
  ```cpp
  #include <type_traits>
  using namespace std;

  template <typename T>
  void process(T val) {
      static_assert(is_integral_v<T>, "Only integer types allowed");
      // ...
  }

  cout << is_same_v<int, int>;           // true
  cout << is_floating_point_v<double>;   // true
  ```

---

## 14. C Compatibility Headers

These are C headers wrapped for C++. Use the `c` prefix version (e.g., `<cstdio>` instead of `<stdio.h>`).

| C++ Header | C Header | Key Functions |
|------------|----------|---------------|
| `<cstdio>` | `<stdio.h>` | `printf()`, `scanf()`, `sprintf()`, `fprintf()`, `freopen()`, `getchar()`, `putchar()` |
| `<cstdlib>` | `<stdlib.h>` | `rand()`, `srand()`, `abs()`, `atoi()`, `exit()`, `malloc()`, `free()` |
| `<cstring>` | `<string.h>` | `memset()`, `memcpy()`, `strlen()`, `strcmp()`, `strcpy()`, `strstr()` |
| `<cmath>` | `<math.h>` | `sqrt()`, `pow()`, `ceil()`, `floor()`, `log()`, `abs()` |
| `<cctype>` | `<ctype.h>` | `isalpha()`, `isdigit()`, `toupper()`, `tolower()` |
| `<ctime>` | `<time.h>` | `time()`, `clock()`, `srand(time(0))` |
| `<climits>` | `<limits.h>` | `INT_MAX`, `INT_MIN`, `LLONG_MAX` |
| `<cfloat>` | `<float.h>` | `DBL_MAX`, `FLT_EPSILON` |
| `<cassert>` | `<assert.h>` | `assert()` |
| `<cstdint>` | `<stdint.h>` | `int8_t`, `int16_t`, `int32_t`, `int64_t`, `uint32_t` |

### `#include <cstdio>` — Worth Special Mention
- **Why:** `printf()`/`scanf()` are **faster** than `cout`/`cin` in many cases.
- **Example:**
  ```cpp
  #include <cstdio>

  int n;
  scanf("%d", &n);           // fast input
  printf("Value: %d\n", n);  // fast output
  printf("%.2f\n", 3.14159); // formatted decimal

  // Competitive programming: redirect I/O
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ```

---

## 15. Quick Reference Table

### Headers You'll Use Daily (DSA & CP)

| Header | Primary Use | Must-Know Functions |
|--------|------------|---------------------|
| `<iostream>` | Console I/O | `cin`, `cout`, `cerr` |
| `<vector>` | Dynamic arrays | `push_back`, `size`, `[]` |
| `<string>` | Text | `substr`, `find`, `stoi`, `to_string` |
| `<algorithm>` | Sorting, searching | `sort`, `lower_bound`, `binary_search`, `reverse`, `next_permutation` |
| `<map>` | Ordered key-value | `[]`, `find`, `count`, `lower_bound` |
| `<unordered_map>` | Fast key-value | `[]`, `find`, `count` |
| `<set>` | Ordered unique set | `insert`, `erase`, `lower_bound` |
| `<unordered_set>` | Fast unique set | `insert`, `count` |
| `<queue>` | BFS + heaps | `push`, `pop`, `front`, `top` |
| `<stack>` | DFS + matching | `push`, `pop`, `top` |
| `<cmath>` | Math functions | `sqrt`, `pow`, `ceil`, `floor`, `log2` |
| `<climits>` | Type limits | `INT_MAX`, `INT_MIN`, `LLONG_MAX` |
| `<numeric>` | Accumulate, GCD | `accumulate`, `gcd`, `lcm`, `iota` |
| `<bitset>` | Bit operations | `count`, `set`, `reset`, `flip` |
| `<cstring>` | memset | `memset` (for array init) |
| `<functional>` | Comparators | `greater<>`, `function<>` |
| `<iomanip>` | Formatting | `setprecision`, `fixed`, `setw` |
| `<sstream>` | String parsing | `istringstream`, `ostringstream` |
| `<utility>` | Pairs, move | `pair`, `make_pair`, `swap`, `move` |
| `<tuple>` | Multi-value | `tuple`, `get<>`, `tie` |

### Competitive Programming Starter Template
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    // Your solution here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
```

### Production Code Starter (Individual Headers)
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <numeric>
#include <functional>
#include <memory>
#include <cassert>

using namespace std;  // avoid in headers; OK in .cpp files
```

---

*Last updated: September 2026*
*Companion to: `cpp_keywords_reference.md` in this same folder.*
