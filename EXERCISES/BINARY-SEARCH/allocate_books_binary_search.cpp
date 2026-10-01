/*
 * Filename: allocate_books_binary_search.cpp
 *
 * -----------------------------------------------------------------------------
 * Problem Statement: Allocate Books
 * -----------------------------------------------------------------------------
 * You are given an array `arr` of integer numbers where `arr[i]` represents
 * the number of pages in the i-th book. You are also given an integer `m`
 * representing the number of students.
 *
 * You need to allocate all the books to the students subject to the following
 * rules:
 * 1. Each student must get at least one book.
 * 2. Each book must be allocated to exactly one student.
 * 3. Book allocations to a single student must be contiguous (e.g., a student
 *    can get book 1 and 2, but not book 1 and 3 without book 2).
 *
 * Objective: Allocate the books so that the maximum number of pages assigned
 * to any student is minimized. If the allocation is not possible, return -1.
 *
 * -----------------------------------------------------------------------------
 * Approach: Binary Search on Answer (Min-Max Pattern)
 * -----------------------------------------------------------------------------
 * Instead of finding how to distribute the books directly, we guess a "maximum
 * number of pages a student is allowed to read" (mid) and check if it's
 * possible to distribute the books without exceeding this limit.
 *
 * 1. Defining the Search Space:
 *    - Minimum possible answer (st): The absolute minimum pages any student
 * will have to read is the largest single book in the array. You cannot split a
 *      book, so no student can read fewer pages than the biggest book they get.
 *      st = max(arr)
 *    - Maximum possible answer (end): If there is only 1 student, they will
 * have to read all the books. end = sum(arr)
 *
 * 2. Checking Validity (isValid function):
 *    - We iterate through the books and add their pages to the current
 * student's tally.
 *    - If adding the next book exceeds our guessed limit (mid), we must assign
 *      this book to a new student.
 *    - If the number of students needed exceeds `m`, our guessed limit was too
 * low, and we must increase it.
 *
 * -----------------------------------------------------------------------------
 * Complexity Analysis:
 * -----------------------------------------------------------------------------
 * - Time Complexity: O(N * log(sum - max)).
 *   Finding the sum and max takes O(N). The binary search runs log(sum - max)
 *   times. In each iteration, the `isValid` function traverses the array of
 *   size N, taking O(N) time.
 * - Space Complexity: O(1).
 *   No auxiliary extra space is used; only a few variables are maintained.
 * -----------------------------------------------------------------------------
 */

#include <algorithm>  // For std::max
#include <iostream>
#include <vector>
using namespace std;

// Function to check if a given max allowed page limit (maxAllowedPages) is
// valid
bool isValid(const vector<int>& arr, int n, int m, int maxAllowedPages) {
  int students = 1;  // Start with the first student
  int pages = 0;     // Pages currently assigned to the current student

  for (int i = 0; i < n; i++) {
    // If adding this book keeps the student under the limit, assign it
    if (pages + arr[i] <= maxAllowedPages) {
      pages += arr[i];
    }
    // Otherwise, allocate this book to the next student
    else {
      students++;
      pages = arr[i];  // The new student starts with this book's pages
    }
  }

  // If the number of students needed is within the allowed limit, it's valid
  return students <= m;
}

// Function to find the minimum of the maximum pages allocated
int allocateBooks(const vector<int>& arr, int n, int m) {
  // Edge case: If there are more students than books, allocation is impossible
  if (m > n) {
    return -1;
  }

  int sum = 0;
  int maxElement = 0;

  // Find the sum of all pages and the maximum single book
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    maxElement = max(maxElement, arr[i]);
  }

  // Optimized search space setup
  int st = maxElement;  // Minimum possible max-pages is the largest book
  int end = sum;        // Maximum possible max-pages is the sum of all books
  int ans = -1;

  // Binary search on the answer
  while (st <= end) {
    int mid = st + (end - st) / 2;

    if (isValid(arr, n, m, mid)) {
      ans = mid;      // This is a valid configuration, store it
      end = mid - 1;  // Try to find a smaller maximum (minimize the max)
    } else {
      st = mid + 1;  // The limit is too strict, we need more pages per student
    }
  }

  return ans;  // Return the optimally minimized maximum pages
}

int main() {
  // Example test case
  vector<int> arr = {12, 34, 67, 90};
  int n = arr.size();
  int m = 2;  // Number of students

  int result = allocateBooks(arr, n, m);

  if (result != -1) {
    cout << "The minimum of the maximum number of pages is: " << result << endl;
  } else {
    cout << "Book allocation is not possible." << endl;
  }

  return 0;
}