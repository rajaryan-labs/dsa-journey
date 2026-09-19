/*
 * Filename: painters_partition_binary_search.cpp
 *
 * -----------------------------------------------------------------------------
 * Problem Statement: Painter's Partition Problem
 * -----------------------------------------------------------------------------
 * Given an integer array `boards` representing the lengths of different boards
 * and an integer `k` representing the number of painters. Each painter takes
 * 1 unit of time to paint 1 unit of board length. Find the minimum time to
 * paint all boards under the condition that any painter will only paint
 * contiguous sections of boards.
 *
 * -----------------------------------------------------------------------------
 * Approach: Binary Search on Answer (Min-Max Pattern)
 * -----------------------------------------------------------------------------
 * 1. Search Space Setup:
 *    - Minimum answer (st): The largest board in the array.
 *    - Maximum answer (end): The sum of all boards.
 * 2. Binary Search:
 *    - Calculate `mid` as the guessed maximum time allowed for any painter.
 *    - Check if it's possible to paint all boards in `mid` time using <= `k`
 * painters.
 *    - If possible, save `mid` and try for a smaller time (end = mid - 1).
 *    - If not, increase the allowed time (st = mid + 1).
 *
 * -----------------------------------------------------------------------------
 * Complexity Analysis:
 * -----------------------------------------------------------------------------
 * - Time Complexity: O(N * log(sum - max)).
 * - Space Complexity: O(1).
 * -----------------------------------------------------------------------------
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to check if all boards can be painted within maxAllowedTime using <=
// k painters
bool isValid(const vector<int>& boards, int n, int k, int maxAllowedTime) {
  int painters = 1;   // Start with the first painter
  int timeSpent = 0;  // Time spent by the current painter

  for (int i = 0; i < n; i++) {
    // If the current painter can take this board without exceeding the limit
    if (timeSpent + boards[i] <= maxAllowedTime) {
      timeSpent += boards[i];
    }
    // Otherwise, assign the board to the next painter
    else {
      painters++;
      timeSpent = boards[i];
    }
  }

  // Return true if we used 'k' or fewer painters
  return painters <= k;
}

// Function to find the minimum time to paint all boards
int painterPartition(const vector<int>& boards, int n, int k) {
  int sum = 0;
  int maxElement = 0;

  // Find the total length of all boards and the longest single board
  for (int i = 0; i < n; i++) {
    sum += boards[i];
    maxElement = max(maxElement, boards[i]);
  }

  // Set up binary search space
  int st = maxElement;  // Absolute minimum time is the longest board
  int end = sum;        // Absolute maximum time is 1 painter doing everything
  int ans = -1;

  // Perform binary search
  while (st <= end) {
    int mid = st + (end - st) / 2;

    if (isValid(boards, n, k, mid)) {
      ans = mid;      // Found a valid configuration, save it
      end = mid - 1;  // Try to minimize the maximum time further
    } else {
      st = mid + 1;  // Time limit was too strict, increase it
    }
  }

  return ans;
}

int main() {
  vector<int> boards = {10, 20, 30, 40};
  int n = boards.size();
  int k = 2;  // Number of painters

  cout << "The minimum time required to paint all boards is: "
       << painterPartition(boards, n, k) << endl;

  return 0;
}