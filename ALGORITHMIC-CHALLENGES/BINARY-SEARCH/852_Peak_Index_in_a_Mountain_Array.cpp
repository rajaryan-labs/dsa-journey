#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: 852. Peak Index in a Mountain Array
    Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/

    An array arr is a "mountain" if:
      - arr.length >= 3
      - There exists some index i (0 < i < arr.length - 1) such that:
          arr[0] < arr[1] < ... < arr[i-1] < arr[i]  (strictly increasing)
          arr[i] > arr[i+1] > ... > arr[arr.length-1] (strictly decreasing)

    Given such a mountain array, return the peak index i.

    Example:
    Input:  arr = [0,1,0]
    Output: 1

    Input:  arr = [0,2,1,0]
    Output: 1

    Input:  arr = [0,10,5,2]
    Output: 1
*/

// ---------------------------------------------------------------------------
// Approach 1: Brute Force (Linear Scan) -> O(n) time, O(1) space
//
// Beginner intuition: walk through the array and find the index where
// the sequence stops increasing — that's the peak. Correct, but doesn't
// use the fact that the array has a special "mountain" shape which
// allows a much faster search.
// ---------------------------------------------------------------------------
int peakIndexInMountainArrayBrute(vector<int>& arr) {
  int n = arr.size();

  for (int i = 1; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return i;
    }
  }

  return -1;  // unreachable given valid mountain array input
}

// ---------------------------------------------------------------------------
// Approach 2: Binary Search, lo/hi Convergence Style -> O(log n) time, O(1)
// space
//
// Beginner intuition: at any index `mid`, compare it to its NEXT
// neighbor (mid+1):
//   - if arr[mid] < arr[mid+1]  -> we're still on the UPHILL side,
//     the peak must be somewhere to the RIGHT of mid (or mid+1 itself)
//     so move lo = mid + 1
//   - if arr[mid] > arr[mid+1]  -> we're on the DOWNHILL side (or
//     already AT the peak), so the peak is at mid or to its LEFT,
//     move hi = mid (don't exclude mid, it could BE the answer)
//
// Search range starts at lo=1, hi=n-2, since the mountain definition
// GUARANTEES the peak is strictly between the first and last index
// (0 < i < n-1) — index 0 and n-1 can never be the answer.
//
// Loop ends when lo == hi, and that final position IS the peak index.
// ---------------------------------------------------------------------------
int peakIndexInMountainArrayOptimal(vector<int>& arr) {
  int n = arr.size();
  int lo = 1, hi = n - 2;

  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;

    if (arr[mid] < arr[mid + 1]) {
      lo = mid + 1;  // still climbing, peak is to the right
    } else {
      hi = mid;  // descending (or at peak), peak is here or to the left
    }
  }

  return lo;  // lo == hi at this point, pointing to the peak
}

// ---------------------------------------------------------------------------
// Approach 3: Binary Search with Explicit Peak Check -> O(log n) time, O(1)
// space
//
// Beginner intuition: instead of narrowing lo/hi until they meet,
// directly check at each `mid` whether IT is the peak:
//
//   arr[mid] is the peak if:  arr[mid] > arr[mid-1]  AND  arr[mid] > arr[mid+1]
//
// If mid IS the peak, return it immediately — no need to keep searching.
// Otherwise, decide which half to search next:
//   - if arr[mid] < arr[mid+1] -> still climbing, peak is to the RIGHT
//     move lo = mid + 1
//   - else (arr[mid] < arr[mid-1]) -> descending, peak is to the LEFT
//     move hi = mid - 1
//
// This separates "is this the answer?" from "which way do I search next?",
// which can be easier to reason about than the lo==hi convergence style.
// ---------------------------------------------------------------------------
int peakIndexInMountainArrayExplicitCheck(vector<int>& arr) {
  int n = arr.size();
  int lo = 1, hi = n - 2;

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;

    // Step 1: check if mid itself is the peak
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
      return mid;  // found the peak, return immediately
    }

    // Step 2: decide which half to search next
    if (arr[mid] < arr[mid + 1]) {
      lo = mid + 1;  // still climbing, peak is to the right
    } else {
      hi = mid - 1;  // descending, peak is to the left
    }
  }

  return -1;  // unreachable given valid mountain array input
}

// ---------------------------------------------------------------------------
// Driver code (hardcoded test cases, no cin)
// ---------------------------------------------------------------------------
int main() {
  vector<vector<int>> testCases = {
      {0, 1, 0},     // expected 1
      {0, 2, 1, 0},  // expected 1
      {0, 10, 5, 2}  // expected 1
  };

  for (auto& arr : testCases) {
    vector<int> a1 = arr, a2 = arr, a3 = arr;

    cout << "Brute Force     -> Peak Index: "
         << peakIndexInMountainArrayBrute(a1) << endl;
    cout << "Optimal (lo=hi) -> Peak Index: "
         << peakIndexInMountainArrayOptimal(a2) << endl;
    cout << "Explicit Check  -> Peak Index: "
         << peakIndexInMountainArrayExplicitCheck(a3) << endl;
    cout << "-----------------------------------" << endl;
  }

  return 0;
}