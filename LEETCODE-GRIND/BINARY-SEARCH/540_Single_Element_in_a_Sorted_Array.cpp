#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: 540. Single Element in a Sorted Array
    Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

    You are given a sorted array consisting of only integers where
    every element appears exactly twice, except for one element which
    appears exactly once. Return the single element that appears once.

    Must run in O(log n) time and O(1) space.

    Example:
    Input:  nums = [1,1,2,3,3,4,4,8,8]
    Output: 2

    Input:  nums = [3,3,7,7,10,11,11]
    Output: 10
*/

// ---------------------------------------------------------------------------
// Approach 1: XOR (Linear) -> O(n) time, O(1) space
//
// Beginner intuition: XOR-ing a number with itself gives 0, and XOR-ing
// with 0 leaves a number unchanged. So if every number appears exactly
// twice except one, XOR-ing the WHOLE array cancels out all the pairs,
// leaving only the single element.
//
// Correct and simple, but doesn't use the fact that the array is SORTED,
// so it can't reach O(log n) — shown here just for comparison.
// ---------------------------------------------------------------------------
int singleNonDuplicateXOR(vector<int>& nums) {
    int result = 0;

    for (int num : nums) {
        result ^= num;
    }

    return result;
}

// ---------------------------------------------------------------------------
// Approach 2: Binary Search on Pair Boundary (Optimal) -> O(log n) time, O(1) space
//
// Beginner intuition: BEFORE the single element, every pair starts at
// an EVEN index (0,2,4,...) — nums[even] == nums[even+1].
// AFTER the single element, that pattern SHIFTS — pairs start at ODD
// indices instead, because the lone element throws off the alignment.
//
// So the single element is exactly the point where this pairing
// pattern breaks. Binary search for that break point:
//
//   1. Force `mid` to always be EVEN (if mid is odd, decrement it by 1).
//      This way we always compare the FIRST element of a potential pair.
//   2. If nums[mid] == nums[mid+1]:
//        the pair is intact, meaning the single element is somewhere
//        AFTER this pair -> search right: lo = mid + 2
//   3. Else (nums[mid] != nums[mid+1]):
//        the pairing pattern has already broken by here, meaning the
//        single element is at `mid` OR somewhere BEFORE it -> search
//        left: hi = mid
//
//   Loop ends when lo == hi, which lands exactly on the single element.
//
// Example walkthrough: [1,1,2,3,3,4,4,8,8]
//   indices:             0 1 2 3 4 5 6 7 8
//   lo=0, hi=8, mid=4 (even) -> nums[4]=3, nums[5]=4 -> different!
//                                single element is at/before index 4 -> hi=4
//   lo=0, hi=4, mid=2 (even) -> nums[2]=2, nums[3]=3 -> different!
//                                single element is at/before index 2 -> hi=2
//   lo=0, hi=2, mid=0 (even) -> nums[0]=1, nums[1]=1 -> same!
//                                single element is after this pair -> lo=2
//   lo=2, hi=2 -> loop ends, return nums[2] = 2  correct!
// ---------------------------------------------------------------------------
int singleNonDuplicateOptimal(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (mid % 2 == 1) {
            mid--; // force mid to always be even
        }

        if (nums[mid] == nums[mid + 1]) {
            lo = mid + 2; // pair intact, single element is after this
        } else {
            hi = mid; // pattern broken, single element is here or before
        }
    }

    return nums[lo]; // lo == hi at this point
}

// ---------------------------------------------------------------------------
// Driver code (hardcoded test cases, no cin)
// ---------------------------------------------------------------------------
int main() {
    vector<vector<int>> testCases = {
        {1, 1, 2, 3, 3, 4, 4, 8, 8},  // expected 2
        {3, 3, 7, 7, 10, 11, 11},     // expected 10
        {1}                            // expected 1
    };

    for (auto& nums : testCases) {
        vector<int> n1 = nums, n2 = nums;

        cout << "XOR (linear)     -> Single Element: " << singleNonDuplicateXOR(n1)     << endl;
        cout << "Binary Search    -> Single Element: " << singleNonDuplicateOptimal(n2) << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}