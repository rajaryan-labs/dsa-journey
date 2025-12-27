#include <iostream>
// No specific header needed for __builtin functions in GCC/Clang
// For MSVC (Visual Studio), consider using <bit> or std::bitset for standard C++20

using namespace std;

// ==========================================
// ALGORITHMS: COUNT SET BITS
// ==========================================
/*
    __builtin_popcount(n)
    
    - counts the number of set bits (1s) in the binary representation of n.
    - This is a GCC/Clang built-in function (very fast, often O(1) hardware instruction).
    
    Variants:
    1. __builtin_popcount(int)       : for int
    2. __builtin_popcountl(long)     : for long
    3. __builtin_popcountll(long long): for long long
*/

int main() {
    cout << "--- Count Set Bits ---" << endl;

    int n = 7; // Binary: 111
    int bits = __builtin_popcount(n);
    cout << "Set bits in " << n << " (111): " << bits << endl; // Output: 3

    int m = 6; // Binary: 110
    cout << "Set bits in " << m << " (110): " << __builtin_popcount(m) << endl; // Output: 2

    long long ln = 1234567890123LL;
    cout << "Set bits in long long: " << __builtin_popcountll(ln) << endl;

    return 0;
}
