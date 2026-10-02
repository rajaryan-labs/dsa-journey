#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: 31. Next Permutation
    Link: https://leetcode.com/problems/next-permutation/

    Given an array of integers nums, rearrange it into the next
    lexicographically greater permutation. If no such permutation
    exists (array is in descending order), rearrange into the lowest
    possible order (ascending). Must be done IN-PLACE, O(1) extra space.

    Example:
    Input:  nums = [1,2,3]
    Output: [1,3,2]

    Input:  nums = [3,2,1]
    Output: [1,2,3]  (no greater permutation exists, wrap to smallest)
*/

// ---------------------------------------------------------------------------
// Approach 1: Brute Force (Generate All Permutations) -> O(n! * n) time, O(n!)
// space
//
// Beginner intuition: generate every possible permutation of the array,
// sort them all lexicographically, find where the CURRENT permutation
// sits in that sorted list, and return the one right after it.
//
// Extremely inefficient (factorial time/space) and NOT in-place —
// shown only to understand what "next permutation" literally means.
// Never actually run this for n > ~8 or so.
// ---------------------------------------------------------------------------
void nextPermutationBrute(vector<int>& nums) {
  vector<int> original = nums;
  vector<vector<int>> allPerms;

  sort(nums.begin(), nums.end());  // start from smallest permutation
  do {
    allPerms.push_back(nums);
  } while (next_permutation(nums.begin(), nums.end()));
  // NOTE: using STL's next_permutation here only to GENERATE all
  // permutations for comparison purposes — in a real solution we
  // obviously wouldn't call the very function we're implementing.

  // find index of the original permutation in the sorted list
  int idx = -1;
  for (int i = 0; i < (int)allPerms.size(); i++) {
    if (allPerms[i] == original) {
      idx = i;
      break;
    }
  }

  // wrap around to the first (smallest) if original was the last
  if (idx == (int)allPerms.size() - 1) {
    nums = allPerms[0];
  } else {
    nums = allPerms[idx + 1];
  }
}

// ---------------------------------------------------------------------------
// Approach 2: Optimal In-Place Algorithm -> O(n) time, O(1) space
//
// Beginner intuition: think of the array as a number — to get the
// NEXT bigger arrangement, we want the smallest possible increase.
// That means: change digits as far RIGHT as possible, and keep
// everything after that change point as SMALL as possible.
//
// --- Step by step ---
//
//   Step 1: Find the "pivot" — scan from the RIGHT, find the first
//           index `i` where nums[i] < nums[i+1] (i.e., where the
//           decreasing pattern from the right breaks).
//           This `i` is the rightmost position where increasing the
//           digit can still produce a BIGGER number.
//
//           If no such `i` exists (array is fully descending from
//           left to right, e.g. [3,2,1]), it means this IS the
//           largest permutation — wrap around by reversing the whole
//           array to get the smallest permutation.
//
//   Step 2: Find the smallest element to the RIGHT of `i` that is
//           STILL bigger than nums[i] — scan from the right again
//           (since that portion is guaranteed descending, the first
//           element bigger than nums[i] found from the right is the
//           smallest qualifying one). Swap it with nums[i].
//
//   Step 3: Reverse everything after index `i`. Since that portion
//           was descending before the swap, reversing it makes it
//           ascending — which is the SMALLEST possible arrangement
//           for that suffix, keeping the overall result as small as
//           possible while still being bigger than the original.
//
// --- Walkthrough: nums = [1,2,3] ---
//   Step 1: scan from right -> nums[1]=2 < nums[2]=3, so i=1 (pivot found)
//   Step 2: find smallest element > nums[1]=2 to its right -> nums[2]=3
//           swap nums[1] and nums[2] -> [1,3,2]
//   Step 3: reverse everything after index 1 (just one element, no change)
//   Result: [1,3,2]  correct!
//
// --- Walkthrough: nums = [3,2,1] ---
//   Step 1: scan from right -> nums[1]=2 > nums[2]=1 (no break)
//                               nums[0]=3 > nums[1]=2 (no break)
//           no pivot found -> fully descending -> this is the max permutation
//   Step 2/3: skip directly to reversing the WHOLE array
//   Result: [1,2,3]  correct! (wrapped to smallest)
// ---------------------------------------------------------------------------
void nextPermutationOptimal(vector<int>& nums) {
  int n = nums.size();
  int i = n - 2;

  // Step 1: find pivot (rightmost index where ascending break happens)
  while (i >= 0 && nums[i] >= nums[i + 1]) {
    i--;
  }

  if (i >= 0) {
    // Step 2: find smallest element to the right of i that's > nums[i]
    int j = n - 1;
    while (nums[j] <= nums[i]) {
      j--;
    }
    swap(nums[i], nums[j]);
  }
  // if i < 0, array was fully descending — skip straight to reversing all

  // Step 3: reverse everything after index i (or whole array if i < 0)
  reverse(nums.begin() + i + 1, nums.end());
}

// ---------------------------------------------------------------------------
// Driver code (hardcoded test cases, no cin)
// ---------------------------------------------------------------------------
int main() {
  vector<vector<int>> testCases = {
      {1, 2, 3},  // expected [1,3,2]
      {3, 2, 1},  // expected [1,2,3]
      {1, 1, 5},  // expected [1,5,1]
      {1, 3, 2}   // expected [2,1,3]
  };

  auto printVec = [](const string& label, vector<int>& v) {
    cout << label << ": [";
    for (int i = 0; i < (int)v.size(); i++) {
      cout << v[i];
      if (i < (int)v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
  };

  for (auto& nums : testCases) {
    vector<int> n1 = nums, n2 = nums;

    nextPermutationBrute(n1);
    nextPermutationOptimal(n2);

    printVec("Brute Force", n1);
    printVec("Optimal", n2);
    cout << "-----------------------------------" << endl;
  }

  return 0;
}