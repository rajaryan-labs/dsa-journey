/*
 * Filename: aggressive_cows_binary_search.cpp
 *
 * -----------------------------------------------------------------------------
 * Problem Statement: Aggressive Cows
 * -----------------------------------------------------------------------------
 * Given an array of distinct stall positions and 'k' aggressive cows, place the
 * cows such that the minimum distance between any two cows is maximized.
 *
 * -----------------------------------------------------------------------------
 * Approach: Binary Search on Answer (Maximize the Minimum)
 * -----------------------------------------------------------------------------
 * 1. Sort the array so we can place cows in sequential order of positions.
 * 2. Search space for the minimum distance:
 *    - st = 1 (minimum possible distance for distinct stalls)
 *    - end = arr[n-1] - arr[0] (maximum possible distance)
 * 3. Use a helper function `isValid` to check if we can place 'k' cows with
 *    at least 'mid' distance between them.
 * 4. If `isValid` is true, save 'mid' and search for a larger distance (st =
 * mid + 1). If false, search for a smaller distance (end = mid - 1).
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  // Helper function to check if placing k cows with at least minAllowedDist is
  // possible
  bool isValid(const vector<int>& arr, int k, int minAllowedDist) {
    int cowsPlaced = 1;    // Always place the first cow...
    int lastPos = arr[0];  // ...at the first stall to maximize remaining space

    for (int i = 1; i < arr.size(); i++) {
      // If the distance to the current stall is sufficient, place the next cow
      if (arr[i] - lastPos >= minAllowedDist) {
        cowsPlaced++;
        lastPos = arr[i];  // Update the position of the last placed cow
      }

      // If all cows are placed successfully, this distance is valid
      if (cowsPlaced >= k) {
        return true;
      }
    }

    // Loop finished but couldn't place all cows
    return false;
  }

 public:
  int aggressiveCows(vector<int>& arr, int k) {
    // Step 1: Sort the array to place cows sequentially
    sort(arr.begin(), arr.end());

    int n = arr.size();

    // Edge case: if we have more cows than stalls (though usually guaranteed k
    // <= n)
    if (k > n) return -1;

    // Step 2: Define binary search space
    int st = 1;
    int end = arr[n - 1] - arr[0];
    int ans = -1;

    // Step 3: Binary Search on the answer
    while (st <= end) {
      int mid = st + (end - st) / 2;

      if (isValid(arr, k, mid)) {
        ans = mid;     // 'mid' is a valid minimum distance, save it
        st = mid + 1;  // Try to find a LARGER minimum distance (Maximize it)
      } else {
        end = mid -
              1;  // 'mid' was too large, we couldn't place the cows. Reduce it.
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;

  // Example 1
  vector<int> arr1 = {1, 2, 4, 8, 9};
  int k1 = 3;
  cout << "Maximum possible minimum distance (Example 1): "
       << sol.aggressiveCows(arr1, k1) << endl;

  // Example 2
  vector<int> arr2 = {10, 1, 2, 7, 5};
  int k2 = 3;
  cout << "Maximum possible minimum distance (Example 2): "
       << sol.aggressiveCows(arr2, k2) << endl;

  return 0;
}