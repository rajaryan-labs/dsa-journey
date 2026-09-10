/*
 * ============================================================
 *  BINARY NUMBER SYSTEM BASICS
 * ============================================================
 *  1. LSB (Least Significant Bit)
 *     - The rightmost bit in a binary number.
 *     - Tells us if the number is Even (0) or Odd (1).
 * 
 *  2. MSB (Most Significant Bit)
 *     - The leftmost bit in a binary number.
 *     - In 'signed' data types, the MSB acts as the SIGN BIT:
 *       0 = Positive Number
 *       1 = Negative Number
 * 
 *  3. 1's Complement
 *     - Simply invert all the bits (flip 0 to 1, and 1 to 0).
 *     - The Bitwise NOT operator (~) in C++ does exactly this.
 * 
 *  4. 2's Complement
 *     - Formula: 1's Complement + 1
 *     - WHY is it important? Modern computers use 2's complement 
 *       to store negative numbers! 
 *     - To find the binary representation of -X, you calculate 
 *       the 2's complement of X.
 *       i.e., -X = (~X) + 1
 * ============================================================
 */

#include <iostream>
#include <bitset>
using namespace std;

int main() {
    cout << "===== Binary Fundamentals =====\n\n";

    // 1. MSB and LSB
    int num = 5; // Binary: 00000101
    cout << "1. MSB & LSB for number " << num << " (Binary: " << bitset<8>(num) << ")\n";
    cout << "   LSB is 1 (So the number is Odd)\n";
    cout << "   MSB is 0 (So the number is Positive)\n\n";

    // 2. 1's Complement
    // Invert all bits using bitwise NOT (~)
    int onesComp = ~num; 
    // Note: Since 'int' is 32 bits, all the leading 0s turn into 1s!
    cout << "2. 1's Complement of 5:\n";
    cout << "   Original (32-bit): " << bitset<32>(num) << "\n";
    cout << "   ~5       (32-bit): " << bitset<32>(onesComp) << "\n\n";

    // 3. 2's Complement (How negative numbers are stored)
    // To get -5, we do 1's complement of 5, then add 1.
    int twosComp = (~num) + 1;
    cout << "3. 2's Complement of 5:\n";
    cout << "   (~5) + 1         : " << twosComp << "\n";
    cout << "   Wait, is that -5?: " << (twosComp == -5 ? "YES!" : "NO") << "\n";
    cout << "   Binary of -5     : " << bitset<32>(-5) << "\n";
    cout << "   Notice the MSB (leftmost bit) of -5 is 1 (Negative!)\n";

    return 0;
}
