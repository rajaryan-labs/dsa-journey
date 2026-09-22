# C++ Keywords — Complete Reference Guide

> A categorized reference of all frequently used C++ keywords with definitions, use cases, code examples, and limitations.

---

## Table of Contents

1. [Data Type Keywords](#1-data-type-keywords)
2. [Type Qualifiers & Modifiers](#2-type-qualifiers--modifiers)
3. [Storage Class Keywords](#3-storage-class-keywords)
4. [Control Flow Keywords](#4-control-flow-keywords)
5. [Loop Keywords](#5-loop-keywords)
6. [Function-Related Keywords](#6-function-related-keywords)
7. [OOP Keywords](#7-oop-keywords)
8. [Access Specifiers](#8-access-specifiers)
9. [Memory Management Keywords](#9-memory-management-keywords)
10. [Exception Handling Keywords](#10-exception-handling-keywords)
11. [Type Casting Keywords](#11-type-casting-keywords)
12. [Template & Generic Keywords](#12-template--generic-keywords)
13. [Namespace Keywords](#13-namespace-keywords)
14. [Miscellaneous / Modern C++ Keywords](#14-miscellaneous--modern-c-keywords)
15. [Preprocessor Directives (Not Keywords, But Essential)](#15-preprocessor-directives)

---

## 1. Data Type Keywords

### `int`
- **Definition:** Stores whole numbers (integers). Typically 4 bytes (32-bit).
- **Use Cases:** Counters, loop indices, array sizes, general integer arithmetic.
- **Example:**
  ```cpp
  int age = 21;
  int sum = a + b;
  ```
- **Limitations:**
  - Range: −2,147,483,648 to 2,147,483,647 (on 32-bit).
  - Overflow is undefined behavior; use `long long` for large values.
  - Cannot store decimals.

---

### `float`
- **Definition:** Single-precision floating-point number. Typically 4 bytes.
- **Use Cases:** When memory is limited and high precision isn't critical (e.g., graphics, sensor data).
- **Example:**
  ```cpp
  float pi = 3.14f;
  float temp = 36.6f;
  ```
- **Limitations:**
  - ~6–7 significant decimal digits of precision.
  - Prone to rounding errors — avoid for financial calculations.
  - Comparing floats with `==` is unreliable; use epsilon-based comparison.

---

### `double`
- **Definition:** Double-precision floating-point number. Typically 8 bytes.
- **Use Cases:** Scientific computations, competitive programming (default for decimals).
- **Example:**
  ```cpp
  double gravity = 9.80665;
  double result = sqrt(2.0);
  ```
- **Limitations:**
  - ~15–16 significant decimal digits — still not exact for all values.
  - Uses more memory than `float`.
  - Same floating-point comparison pitfalls as `float`.

---

### `char`
- **Definition:** Stores a single character. 1 byte. Internally stored as ASCII integer.
- **Use Cases:** Single characters, building strings manually, ASCII manipulation.
- **Example:**
  ```cpp
  char grade = 'A';
  char newline = '\n';
  int ascii = grade;  // 65
  ```
- **Limitations:**
  - Only 1 character; use `std::string` for text.
  - Signed by default on most platforms (−128 to 127); use `unsigned char` for raw byte data.
  - Cannot hold Unicode characters directly (use `wchar_t` or `char32_t`).

---

### `bool`
- **Definition:** Boolean type — stores `true` (1) or `false` (0). 1 byte.
- **Use Cases:** Flags, conditions, toggle states.
- **Example:**
  ```cpp
  bool isEven = (n % 2 == 0);
  bool found = false;
  ```
- **Limitations:**
  - Takes 1 byte even though it only needs 1 bit (no bit-level storage by default).
  - Implicitly converts to/from integers, which can cause subtle bugs.

---

### `void`
- **Definition:** Represents "no type" or "no value."
- **Use Cases:** Functions that return nothing; generic pointers (`void*`).
- **Example:**
  ```cpp
  void greet() {
      cout << "Hello!";
  }
  void* ptr = &someVar;  // generic pointer
  ```
- **Limitations:**
  - Cannot declare a variable of type `void`.
  - `void*` loses type information — must cast before dereferencing.
  - Cannot do pointer arithmetic on `void*` (non-standard).

---

### `long`
- **Definition:** Extended integer type. At least 32 bits (often 32-bit on Windows, 64-bit on Linux).
- **Use Cases:** When `int` might overflow but `long long` is overkill.
- **Example:**
  ```cpp
  long population = 1400000000L;
  ```
- **Limitations:**
  - Size is platform-dependent — not guaranteed to be 64-bit.
  - Use `long long` for guaranteed 64-bit.

---

### `long long`
- **Definition:** Guaranteed at least 64-bit integer.
- **Use Cases:** Large numbers in competitive programming, timestamps, factorial results.
- **Example:**
  ```cpp
  long long bigNum = 1e18;
  long long factorial = 1;
  for (int i = 1; i <= 20; i++) factorial *= i;
  ```
- **Limitations:**
  - Range: −9.2 × 10¹⁸ to 9.2 × 10¹⁸ — can still overflow.
  - Slower than `int` on some architectures.
  - Use `__int128` or big-integer libraries if you need more.

---

### `short`
- **Definition:** Small integer type. At least 16 bits (2 bytes).
- **Use Cases:** Memory-constrained environments, large arrays of small values.
- **Example:**
  ```cpp
  short temperature = -10;
  short port = 8080;
  ```
- **Limitations:**
  - Range: −32,768 to 32,767 — overflows quickly.
  - Rarely used in modern C++; `int` is usually preferred.

---

### `unsigned`
- **Definition:** Modifier that removes the negative range, doubling the positive range.
- **Use Cases:** Array indices, sizes, bit manipulation, when values are always non-negative.
- **Example:**
  ```cpp
  unsigned int count = 0;
  unsigned long long mask = 0xFFFFFFFF;
  ```
- **Limitations:**
  - Subtracting below 0 wraps around (undefined-like behavior in practice).
  - Mixing signed and unsigned in comparisons causes subtle bugs.
  - `size_t` (unsigned) vs `int` (signed) comparison is a classic pitfall.

---

### `string` (from `<string>`)
- **Definition:** Not a keyword but a standard library type (`std::string`). Dynamic character array.
- **Use Cases:** Text processing, input handling, string manipulation.
- **Example:**
  ```cpp
  #include <string>
  string name = "Raj";
  string greeting = "Hello, " + name + "!";
  cout << greeting.length();  // 10
  ```
- **Limitations:**
  - Heap-allocated — slower than `char[]` for tiny strings.
  - Not null-terminated internally (use `.c_str()` for C compatibility).
  - Concatenation in loops can be O(n²) — use `ostringstream` or `reserve()`.

---

### `auto`
- **Definition:** Compiler deduces the type from the initializer (C++11).
- **Use Cases:** Iterators, lambda captures, long template types, range-based loops.
- **Example:**
  ```cpp
  auto x = 42;              // int
  auto pi = 3.14;           // double
  auto it = vec.begin();    // vector<int>::iterator
  for (auto& elem : vec) { ... }
  ```
- **Limitations:**
  - Must be initialized at declaration.
  - Can reduce readability if the type isn't obvious.
  - Cannot use for function parameters (until C++20 with concepts).

---

## 2. Type Qualifiers & Modifiers

### `const`
- **Definition:** Makes a variable immutable after initialization.
- **Use Cases:** Constants, read-only function parameters, safe API design.
- **Example:**
  ```cpp
  const int MAX = 1e5 + 5;
  const string& getName() const { return name; }
  void print(const vector<int>& v);  // won't modify v
  ```
- **Limitations:**
  - Must be initialized at declaration (except `const` class members via constructor init list).
  - `const_cast` can remove const-ness — dangerous and defeats purpose.
  - `const` pointer syntax can be confusing: `const int*` vs `int* const`.

---

### `constexpr`
- **Definition:** Evaluated at compile time (C++11). Stronger guarantee than `const`.
- **Use Cases:** Compile-time constants, array sizes, template arguments, `if constexpr`.
- **Example:**
  ```cpp
  constexpr int SQUARE(int x) { return x * x; }
  constexpr int SIZE = SQUARE(10);  // 100, computed at compile time
  int arr[SIZE];
  ```
- **Limitations:**
  - Function body must be computable at compile time (no I/O, no dynamic allocation in C++11/14).
  - Relaxed in C++17/20 but still restricted.
  - Not all functions can be `constexpr`.

---

### `volatile`
- **Definition:** Tells the compiler the variable may change unexpectedly (e.g., hardware register, signal handler).
- **Use Cases:** Embedded systems, memory-mapped I/O, signal handlers.
- **Example:**
  ```cpp
  volatile int sensorValue;
  volatile bool stopFlag = false;
  ```
- **Limitations:**
  - Does NOT provide thread safety — use `std::atomic` for multithreading.
  - Prevents compiler optimizations on that variable.
  - Rarely needed in typical application code.

---

### `mutable`
- **Definition:** Allows a member variable to be modified even in a `const` member function.
- **Use Cases:** Caching, lazy evaluation, logging in const methods, mutex locking.
- **Example:**
  ```cpp
  class Data {
      mutable int accessCount = 0;
  public:
      int getValue() const {
          accessCount++;  // OK because mutable
          return value;
      }
  };
  ```
- **Limitations:**
  - Can break the logical constness contract if misused.
  - Should be used sparingly and only for internal bookkeeping.

---

### `signed` / `unsigned`
- **Definition:** `signed` allows negative values (default for `int`, `char` may vary). `unsigned` restricts to non-negative.
- **Use Cases:** Bit manipulation (`unsigned`), explicit sign intent.
- **Example:**
  ```cpp
  signed int temp = -5;
  unsigned int mask = 0xFF;
  ```
- **Limitations:**
  - `unsigned` subtraction past 0 wraps around.
  - Mixing signed/unsigned causes implicit conversion bugs.

---

## 3. Storage Class Keywords

### `static`
- **Definition:** Variable/function retains its value across calls (local) or has internal linkage (global/class).
- **Use Cases:** Counters that persist, class-wide shared data, helper functions with file scope.
- **Example:**
  ```cpp
  void counter() {
      static int count = 0;  // initialized only once
      cout << ++count << endl;
  }

  class Node {
      static int nodeCount;    // shared across all instances
  public:
      Node() { nodeCount++; }
      static int getCount() { return nodeCount; }
  };
  ```
- **Limitations:**
  - Static local variables are not thread-safe before C++11 (guaranteed since C++11).
  - Static class members must be defined outside the class (before C++17 inline).
  - Overuse leads to hidden global state and testing difficulties.

---

### `extern`
- **Definition:** Declares a variable/function defined in another translation unit.
- **Use Cases:** Sharing global variables across files, linking with C code (`extern "C"`).
- **Example:**
  ```cpp
  // file1.cpp
  int globalVar = 42;

  // file2.cpp
  extern int globalVar;  // uses the one from file1.cpp
  cout << globalVar;     // 42

  extern "C" void cFunction();  // C linkage
  ```
- **Limitations:**
  - Breaks encapsulation — prefer passing values or using singletons.
  - Can cause linker errors if the definition is missing.
  - Order of initialization across files is undefined (static init order fiasco).

---

### `register` *(deprecated in C++17)*
- **Definition:** Suggests the compiler store a variable in a CPU register for speed.
- **Use Cases:** Historically used for loop counters; modern compilers ignore the hint.
- **Example:**
  ```cpp
  register int i = 0;  // compiler may ignore this
  ```
- **Limitations:**
  - Completely deprecated in C++17 and removed in C++20.
  - Modern compilers optimize register allocation far better than manual hints.
  - Cannot take the address of a `register` variable.

---

### `thread_local` *(C++11)*
- **Definition:** Each thread gets its own independent copy of the variable.
- **Use Cases:** Per-thread caches, thread-local error codes, per-thread random generators.
- **Example:**
  ```cpp
  thread_local int threadId = 0;
  ```
- **Limitations:**
  - Initialization overhead per thread.
  - Cannot be used with `auto` in some compilers.
  - Destructors of `thread_local` objects run when the thread exits, not at program end.

---

## 4. Control Flow Keywords

### `if` / `else`
- **Definition:** Conditional branching.
- **Use Cases:** Decision-making, validation, edge-case handling.
- **Example:**
  ```cpp
  if (score >= 90) grade = 'A';
  else if (score >= 80) grade = 'B';
  else grade = 'C';

  // C++17: if with initializer
  if (auto it = map.find(key); it != map.end()) {
      cout << it->second;
  }
  ```
- **Limitations:**
  - Deep nesting reduces readability — prefer early returns or switch.
  - `if (x = 5)` (assignment) vs `if (x == 5)` (comparison) — classic bug.

---

### `switch` / `case` / `default`
- **Definition:** Multi-way branching based on integral/enum values.
- **Use Cases:** Menu selection, state machines, opcode dispatch.
- **Example:**
  ```cpp
  switch (choice) {
      case 1:  cout << "Add";    break;
      case 2:  cout << "Delete"; break;
      default: cout << "Invalid";
  }
  ```
- **Limitations:**
  - Only works with integral types and enums (no strings, no floats).
  - Forgetting `break` causes fall-through — intentional fall-through should use `[[fallthrough]]`.
  - Cannot declare variables inside `case` without braces `{}`.

---

### `break`
- **Definition:** Exits the nearest enclosing loop or switch.
- **Use Cases:** Early termination of loops, exiting switch cases.
- **Example:**
  ```cpp
  for (int i = 0; i < n; i++) {
      if (arr[i] == target) { found = true; break; }
  }
  ```
- **Limitations:**
  - Only breaks out of **one** level — cannot break out of nested loops directly (use flags or `goto`).

---

### `continue`
- **Definition:** Skips the rest of the current loop iteration and jumps to the next.
- **Use Cases:** Filtering elements, skipping invalid inputs.
- **Example:**
  ```cpp
  for (int i = 0; i < n; i++) {
      if (arr[i] < 0) continue;  // skip negatives
      process(arr[i]);
  }
  ```
- **Limitations:**
  - Overuse makes control flow hard to follow.
  - In `while`/`do-while`, make sure `continue` doesn't skip the loop counter update.

---

### `return`
- **Definition:** Exits a function and optionally returns a value.
- **Use Cases:** Every non-void function; early exits; returning results.
- **Example:**
  ```cpp
  int add(int a, int b) { return a + b; }
  void validate(int x) {
      if (x < 0) return;  // early exit
      process(x);
  }
  ```
- **Limitations:**
  - Returning references/pointers to local variables is **undefined behavior**.
  - Missing return in a non-void function is UB.

---

### `goto`
- **Definition:** Unconditional jump to a labeled statement.
- **Use Cases:** Breaking out of deeply nested loops (rare, but valid). Error cleanup in C-style code.
- **Example:**
  ```cpp
  for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
          if (grid[i][j] == target) goto found;
  found:
      cout << "Found!";
  ```
- **Limitations:**
  - Creates spaghetti code — strongly discouraged in modern C++.
  - Cannot jump over variable initializations.
  - Use structured alternatives (flags, functions, exceptions) instead.

---

## 5. Loop Keywords

### `for`
- **Definition:** Count-controlled loop with init, condition, and increment.
- **Use Cases:** Array traversal, fixed-count iterations, range-based loops.
- **Example:**
  ```cpp
  // Classic
  for (int i = 0; i < n; i++) { ... }

  // Range-based (C++11)
  for (auto& x : vec) { cout << x; }

  // Infinite loop
  for (;;) { ... }
  ```
- **Limitations:**
  - Range-based `for` doesn't give you the index — use classic `for` if you need it.
  - Off-by-one errors are common (`<` vs `<=`).

---

### `while`
- **Definition:** Pre-condition loop — checks condition before each iteration.
- **Use Cases:** When the number of iterations is unknown; event loops; reading input.
- **Example:**
  ```cpp
  while (n > 0) {
      digits.push_back(n % 10);
      n /= 10;
  }
  while (cin >> x) { ... }  // read until EOF
  ```
- **Limitations:**
  - May never execute if condition is initially false.
  - Forgetting to update the loop variable causes infinite loops.

---

### `do...while`
- **Definition:** Post-condition loop — executes at least once, checks condition after.
- **Use Cases:** Menu-driven programs, input validation (retry until valid).
- **Example:**
  ```cpp
  do {
      cout << "Enter positive number: ";
      cin >> n;
  } while (n <= 0);
  ```
- **Limitations:**
  - Always runs at least once — not always desirable.
  - Less commonly used; `while` is preferred when possible.

---

## 6. Function-Related Keywords

### `inline`
- **Definition:** Suggests the compiler replace function calls with the function body.
- **Use Cases:** Small, frequently-called functions; header-only libraries.
- **Example:**
  ```cpp
  inline int max(int a, int b) { return (a > b) ? a : b; }
  ```
- **Limitations:**
  - The compiler may ignore the hint.
  - Large inline functions increase binary size (code bloat).
  - Recursive functions cannot be effectively inlined.

---

### `virtual`
- **Definition:** Enables dynamic (runtime) polymorphism via vtable dispatch.
- **Use Cases:** Base class methods meant to be overridden; interface design.
- **Example:**
  ```cpp
  class Shape {
  public:
      virtual double area() const = 0;  // pure virtual
      virtual ~Shape() {}               // virtual destructor
  };
  class Circle : public Shape {
      double r;
  public:
      double area() const override { return 3.14159 * r * r; }
  };
  ```
- **Limitations:**
  - Adds vtable overhead (~8 bytes per object + indirect call cost).
  - Cannot be `virtual` and `template` simultaneously.
  - Forgetting a virtual destructor in polymorphic base classes causes memory leaks.

---

### `override` *(C++11)*
- **Definition:** Explicitly marks a function as overriding a base class virtual function.
- **Use Cases:** Catching signature mismatches at compile time.
- **Example:**
  ```cpp
  class Derived : public Base {
      void process() override;  // compile error if Base::process() doesn't exist
  };
  ```
- **Limitations:**
  - Only works with virtual functions.
  - Not technically a keyword — it's a context-sensitive identifier.

---

### `final` *(C++11)*
- **Definition:** Prevents a class from being inherited or a virtual function from being overridden.
- **Use Cases:** Sealing class hierarchies, optimization hints.
- **Example:**
  ```cpp
  class Base final { };       // cannot inherit from Base
  // class Derived : Base {}; // ERROR

  virtual void foo() final;   // cannot override in derived classes
  ```
- **Limitations:**
  - Overuse limits extensibility.
  - Like `override`, it's a context-sensitive identifier, not a reserved keyword.

---

### `noexcept` *(C++11)*
- **Definition:** Specifies that a function does not throw exceptions.
- **Use Cases:** Move constructors, swap functions, performance-critical paths.
- **Example:**
  ```cpp
  void swap(int& a, int& b) noexcept {
      int tmp = a; a = b; b = tmp;
  }
  ```
- **Limitations:**
  - If a `noexcept` function throws, `std::terminate()` is called immediately.
  - Must be accurate — don't mark functions `noexcept` if they call throwing functions.

---

### `lambda` (not a keyword, but essential syntax)
- **Definition:** Anonymous inline function objects (C++11).
- **Use Cases:** STL algorithms, callbacks, custom comparators, event handlers.
- **Example:**
  ```cpp
  auto cmp = [](int a, int b) { return a > b; };
  sort(vec.begin(), vec.end(), cmp);

  // Capture by reference
  int sum = 0;
  for_each(vec.begin(), vec.end(), [&sum](int x) { sum += x; });
  ```
- **Limitations:**
  - Capturing `this` can create dangling references if the object dies.
  - Complex lambdas reduce readability — extract to named functions.
  - Cannot be templated before C++20.

---

## 7. OOP Keywords

### `class`
- **Definition:** Defines a user-defined type with members and methods. Default access: `private`.
- **Use Cases:** Encapsulation, abstraction, modeling real-world entities.
- **Example:**
  ```cpp
  class Student {
      string name;
      int roll;
  public:
      Student(string n, int r) : name(n), roll(r) {}
      void display() const { cout << name << " " << roll; }
  };
  ```
- **Limitations:**
  - Overhead compared to `struct` for simple data (style, not performance).
  - No garbage collection — must manage resources manually (RAII helps).

---

### `struct`
- **Definition:** Same as `class` but with default `public` access.
- **Use Cases:** POD types, data containers, graph/tree nodes, competitive programming.
- **Example:**
  ```cpp
  struct Point {
      int x, y;
      bool operator<(const Point& o) const { return x < o.x; }
  };
  struct Edge {
      int u, v, w;
  };
  ```
- **Limitations:**
  - Functionally identical to `class` (only default access differs).
  - Convention: use `struct` for data, `class` for behavior — not enforced.

---

### `enum` / `enum class`
- **Definition:** Named integer constants. `enum class` (C++11) provides scoped, type-safe enums.
- **Use Cases:** State machines, options, readability over magic numbers.
- **Example:**
  ```cpp
  // Old-style
  enum Color { RED, GREEN, BLUE };

  // Scoped (preferred)
  enum class Direction { UP, DOWN, LEFT, RIGHT };
  Direction d = Direction::UP;
  ```
- **Limitations:**
  - Old `enum` pollutes the enclosing namespace and implicitly converts to `int`.
  - `enum class` can't be implicitly used as integers (must `static_cast`).
  - Cannot have methods (use a class with `enum class` member instead).

---

### `this`
- **Definition:** Pointer to the current object instance inside a member function.
- **Use Cases:** Disambiguating member variables, returning `*this` for chaining, passing self.
- **Example:**
  ```cpp
  class Builder {
      int val;
  public:
      Builder& setValue(int val) {
          this->val = val;  // disambiguate
          return *this;     // method chaining
      }
  };
  ```
- **Limitations:**
  - Not available in static member functions.
  - Is a pointer, not a reference — `*this` to get the object.
  - Cannot be reassigned.

---

### `friend`
- **Definition:** Grants a non-member function or another class access to private/protected members.
- **Use Cases:** Operator overloading (`<<`, `>>`), tightly coupled helper classes.
- **Example:**
  ```cpp
  class Box {
      int width;
      friend ostream& operator<<(ostream& os, const Box& b);
      friend class BoxFactory;
  };
  ostream& operator<<(ostream& os, const Box& b) {
      return os << "Width: " << b.width;
  }
  ```
- **Limitations:**
  - Breaks encapsulation — use sparingly.
  - Friendship is not inherited, not transitive, and not reciprocal.

---

### `typedef` / `using`
- **Definition:** Creates type aliases. `using` (C++11) is the modern, more readable alternative.
- **Use Cases:** Shortening long types, template aliases, readability.
- **Example:**
  ```cpp
  typedef vector<pair<int,int>> vpii;           // old style
  using vpii = vector<pair<int,int>>;           // modern (preferred)
  using ll = long long;
  using pii = pair<int,int>;

  // Template alias (only 'using' can do this)
  template<typename T>
  using Vec = vector<T>;
  ```
- **Limitations:**
  - `typedef` cannot create template aliases.
  - Overuse of short aliases (`ll`, `pii`) can reduce readability outside competitive programming.

---

## 8. Access Specifiers

### `public`
- **Definition:** Members accessible from anywhere.
- **Use Cases:** Public interfaces, API methods.

### `private`
- **Definition:** Members accessible only within the class itself.
- **Use Cases:** Internal data, implementation details.

### `protected`
- **Definition:** Members accessible within the class and its derived classes.
- **Use Cases:** Base class members needed by subclasses but not external code.

- **Example:**
  ```cpp
  class Animal {
  public:
      void speak();       // accessible everywhere
  protected:
      int age;            // accessible in derived classes
  private:
      string dnaSequence; // only within Animal
  };
  ```
- **Limitations:**
  - `protected` breaks encapsulation more than `private` — prefer `private` + accessors.
  - Access specifiers don't affect memory layout.

---

## 9. Memory Management Keywords

### `new` / `delete`
- **Definition:** Dynamically allocate/deallocate memory on the heap.
- **Use Cases:** Dynamic data structures (linked lists, trees), objects with runtime-determined lifetimes.
- **Example:**
  ```cpp
  int* ptr = new int(42);
  delete ptr;

  int* arr = new int[100];
  delete[] arr;  // array form

  Node* node = new Node(10);
  delete node;
  ```
- **Limitations:**
  - Every `new` must have a matching `delete` — memory leaks otherwise.
  - `delete` on already-deleted memory is **undefined behavior** (double-free).
  - Prefer smart pointers (`unique_ptr`, `shared_ptr`) over raw `new`/`delete`.

---

### `nullptr` *(C++11)*
- **Definition:** Type-safe null pointer constant. Replaces `NULL` and `0`.
- **Use Cases:** Initializing pointers, checking for null, function overload resolution.
- **Example:**
  ```cpp
  int* ptr = nullptr;
  if (ptr == nullptr) { cout << "Null pointer"; }

  void foo(int);
  void foo(int*);
  foo(nullptr);  // calls foo(int*), not foo(int)
  ```
- **Limitations:**
  - Cannot be used as an integer (unlike `NULL`).
  - Only for pointers — that's a feature, not a bug.

---

### `sizeof`
- **Definition:** Returns the size in bytes of a type or variable at compile time.
- **Use Cases:** Memory allocation, buffer sizing, portability checks.
- **Example:**
  ```cpp
  cout << sizeof(int);         // typically 4
  cout << sizeof(double);      // typically 8
  int arr[10];
  cout << sizeof(arr) / sizeof(arr[0]);  // 10 (element count)
  ```
- **Limitations:**
  - For arrays passed to functions, `sizeof` returns pointer size, not array size.
  - Result depends on the platform and compiler.
  - For `std::vector`, use `.size()` instead.

---

## 10. Exception Handling Keywords

### `try` / `catch` / `throw`
- **Definition:** Structured exception handling mechanism.
- **Use Cases:** Error recovery, input validation, resource cleanup.
- **Example:**
  ```cpp
  try {
      if (denominator == 0) throw runtime_error("Division by zero");
      result = numerator / denominator;
  }
  catch (const runtime_error& e) {
      cerr << "Error: " << e.what();
  }
  catch (...) {
      cerr << "Unknown error";
  }
  ```
- **Limitations:**
  - Performance overhead when exceptions are thrown (zero-cost when not thrown on most compilers).
  - Don't use exceptions for normal control flow.
  - Not available in all embedded environments (can be disabled with `-fno-exceptions`).

---

## 11. Type Casting Keywords

### `static_cast`
- **Definition:** Compile-time cast for related types (most common, safest explicit cast).
- **Use Cases:** Numeric conversions, upcasting, enum to int.
- **Example:**
  ```cpp
  double pi = 3.14;
  int truncated = static_cast<int>(pi);  // 3
  ```
- **Limitations:** No runtime safety checks; won't catch invalid downcasts.

### `dynamic_cast`
- **Definition:** Runtime-checked cast for polymorphic types (uses RTTI).
- **Use Cases:** Safe downcasting in class hierarchies.
- **Example:**
  ```cpp
  Base* bp = getShape();
  if (auto* cp = dynamic_cast<Circle*>(bp)) {
      cout << cp->radius();
  }
  ```
- **Limitations:** Requires at least one virtual function; returns `nullptr` on failure (pointers) or throws `bad_cast` (references); has runtime cost.

### `const_cast`
- **Definition:** Adds or removes `const`/`volatile` qualifiers.
- **Use Cases:** Interfacing with legacy C APIs that don't use `const`.
- **Example:**
  ```cpp
  void legacyPrint(char* s);
  const char* msg = "Hello";
  legacyPrint(const_cast<char*>(msg));
  ```
- **Limitations:** Modifying a truly `const` object through `const_cast` is **undefined behavior**.

### `reinterpret_cast`
- **Definition:** Bit-level reinterpretation of a pointer/reference type.
- **Use Cases:** Low-level memory manipulation, serialization, hardware access.
- **Example:**
  ```cpp
  int val = 42;
  char* bytes = reinterpret_cast<char*>(&val);
  ```
- **Limitations:** Extremely unsafe — no type checking; platform-dependent; avoid unless absolutely necessary.

---

## 12. Template & Generic Keywords

### `template`
- **Definition:** Enables generic programming — writing code that works with any type.
- **Use Cases:** Generic data structures, algorithms, type-safe containers.
- **Example:**
  ```cpp
  template <typename T>
  T maxVal(T a, T b) { return (a > b) ? a : b; }

  template <typename T>
  class Stack {
      vector<T> data;
  public:
      void push(T val) { data.push_back(val); }
      T pop() { T v = data.back(); data.pop_back(); return v; }
  };
  ```
- **Limitations:**
  - Error messages can be cryptic.
  - Code bloat — each instantiation generates separate code.
  - Must usually be defined in header files.

---

### `typename` / `class` (in templates)
- **Definition:** Used interchangeably in template parameter lists. `typename` also disambiguates dependent types.
- **Example:**
  ```cpp
  template <typename T>    // same as template <class T>
  void print(const T& val);

  template <typename T>
  void foo() {
      typename T::iterator it;  // 'typename' needed to clarify it's a type
  }
  ```

---

### `concept` / `requires` *(C++20)*
- **Definition:** Constrain template parameters with named requirements.
- **Use Cases:** Better error messages, self-documenting templates.
- **Example:**
  ```cpp
  template <typename T>
  concept Sortable = requires(T a, T b) { { a < b } -> std::convertible_to<bool>; };

  template <Sortable T>
  void sort(vector<T>& v);
  ```
- **Limitations:** C++20 only — not supported in older compilers.

---

## 13. Namespace Keywords

### `namespace`
- **Definition:** Groups related declarations to prevent name collisions.
- **Use Cases:** Library design, organizing large codebases, avoiding name clashes.
- **Example:**
  ```cpp
  namespace Math {
      const double PI = 3.14159265;
      double circleArea(double r) { return PI * r * r; }
  }
  cout << Math::PI;
  cout << Math::circleArea(5.0);
  ```
- **Limitations:**
  - Deeply nested namespaces reduce readability (C++17 allows `namespace A::B::C {}`).
  - Anonymous namespaces have internal linkage — useful but can be confusing.

---

### `using namespace`
- **Definition:** Brings all names from a namespace into the current scope.
- **Use Cases:** Competitive programming (`using namespace std;`), short scripts.
- **Example:**
  ```cpp
  using namespace std;
  cout << "Hello" << endl;

  // Selective (preferred in production)
  using std::cout;
  using std::endl;
  ```
- **Limitations:**
  - **Never use in header files** — pollutes the global namespace for all includers.
  - Can cause ambiguity if two namespaces have the same symbol.
  - In production code, prefer `std::` prefix or selective `using` declarations.

---

## 14. Miscellaneous / Modern C++ Keywords

### `decltype` *(C++11)*
- **Definition:** Deduces the type of an expression at compile time.
- **Use Cases:** Matching return types, template metaprogramming.
- **Example:**
  ```cpp
  int x = 5;
  decltype(x) y = 10;  // y is int
  decltype(x + 0.5) z; // z is double
  ```

---

### `static_assert` *(C++11)*
- **Definition:** Compile-time assertion — fails compilation if the condition is false.
- **Use Cases:** Validating template parameters, platform assumptions.
- **Example:**
  ```cpp
  static_assert(sizeof(int) == 4, "int must be 4 bytes");
  static_assert(is_integral_v<T>, "T must be an integral type");
  ```

---

### `alignas` / `alignof` *(C++11)*
- **Definition:** Control and query memory alignment of types/objects.
- **Use Cases:** SIMD operations, cache-line alignment, hardware registers.
- **Example:**
  ```cpp
  alignas(16) float data[4];         // 16-byte aligned
  cout << alignof(double);           // typically 8
  ```

---

### `explicit`
- **Definition:** Prevents implicit type conversions and copy-initialization for constructors/operators.
- **Use Cases:** Avoiding accidental conversions, safer APIs.
- **Example:**
  ```cpp
  class Fraction {
  public:
      explicit Fraction(int num) : n(num), d(1) {}
  };
  // Fraction f = 5;  // ERROR — implicit conversion blocked
  Fraction f(5);      // OK — explicit construction
  ```

---

### `operator`
- **Definition:** Overloads operators for user-defined types.
- **Use Cases:** Custom comparators, arithmetic on custom types, stream I/O.
- **Example:**
  ```cpp
  struct Point {
      int x, y;
      bool operator<(const Point& o) const {
          return (x == o.x) ? (y < o.y) : (x < o.x);
      }
      Point operator+(const Point& o) const {
          return {x + o.x, y + o.y};
      }
      friend ostream& operator<<(ostream& os, const Point& p) {
          return os << "(" << p.x << "," << p.y << ")";
      }
  };
  ```

---

## 15. Preprocessor Directives

> These are **not** keywords but are processed before compilation and are essential to know.

| Directive | Purpose | Example |
|-----------|---------|---------|
| `#include` | Include header files | `#include <iostream>`, `#include "myfile.h"` |
| `#define` | Define macros/constants | `#define MOD 1000000007` |
| `#ifdef` / `#ifndef` | Conditional compilation | `#ifndef HEADER_H` (include guards) |
| `#pragma once` | Non-standard but widely supported include guard | `#pragma once` |
| `#pragma` | Compiler-specific instructions | `#pragma GCC optimize("O2")` |
| `#undef` | Remove a macro definition | `#undef MAX` |
| `#if` / `#else` / `#endif` | Conditional blocks | `#if DEBUG ... #endif` |

---

## Quick Reference Table — Common Keyword Cheat Sheet

| Keyword | Category | Size/Info | Typical Range / Notes |
|---------|----------|-----------|----------------------|
| `int` | Data Type | 4 bytes | ±2.1 billion |
| `long long` | Data Type | 8 bytes | ±9.2 × 10¹⁸ |
| `float` | Data Type | 4 bytes | ~7 decimal digits |
| `double` | Data Type | 8 bytes | ~15 decimal digits |
| `char` | Data Type | 1 byte | −128 to 127 or 0–255 |
| `bool` | Data Type | 1 byte | `true` / `false` |
| `const` | Qualifier | — | Immutable after init |
| `static` | Storage | — | Persists across calls |
| `auto` | Type Deduction | — | Compiler-deduced type |
| `nullptr` | Pointer | — | Type-safe null |
| `virtual` | OOP | vtable | Runtime polymorphism |
| `override` | OOP | — | Compile-time safety |
| `new`/`delete` | Memory | Heap | Manual allocation |
| `template` | Generic | — | Code for any type |
| `constexpr` | Compile-time | — | Computed at compile time |
| `noexcept` | Exception | — | Guarantees no throw |

---

*Last updated: September 2026*
*For DSA-specific usage, combine this with your STL reference in the STL_C++ folder.*
