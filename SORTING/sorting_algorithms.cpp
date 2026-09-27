/*
 * ============================================================
 *  SORTING ALGORITHMS — Complete Reference
 * ============================================================
 *  Algorithms covered:
 *   1. Bubble Sort     O(n^2)     stable
 *   2. Selection Sort  O(n^2)     unstable
 *   3. Insertion Sort  O(n^2)     stable, good for nearly sorted
 *   4. Merge Sort      O(n log n) stable, extra space O(n)
 *   5. Quick Sort      O(n log n) avg, unstable, in-place
 *   6. Heap Sort       O(n log n) unstable, in-place
 *   7. Counting Sort   O(n+k)     stable (for integers in range)
 *   8. Radix Sort      O(d*(n+k)) for d-digit numbers
 *   9. Shell Sort      O(n log^2 n)
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────
//  NOTE ON DESCENDING ORDER:
//  Most ascending sorts can be converted to descending order by
//  reversing the comparison operator (e.g., changing > to <).
//  In C++ STL, you can use `greater<int>()` as a custom comparator:
//  `sort(arr.begin(), arr.end(), greater<int>());`
// ─────────────────────────────────────────────────────────────

void printArr(const vector<int>& a, const string& label = "") {
  if (!label.empty()) cout << label << ": ";
  for (int x : a) cout << x << " ";
  cout << "\n";
}

// ─────────────────────────────────────────────────────────────
//  1. Bubble Sort
//  Process: Repeatedly step through the list, compare adjacent
//  elements, and swap them if they are in the wrong order.
//  The largest element "bubbles" to the end in each pass.
//  Optimisation: Stop early if no swaps occur in a pass.
//  Descending Order: Change `arr[j] > arr[j + 1]` to `<`.
// ─────────────────────────────────────────────────────────────
void bubbleSort(vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - 1 - i; j++)
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    if (!swapped) break;
  }
  printArr(arr, "Bubble Sort");
}

// ─────────────────────────────────────────────────────────────
//  2. Selection Sort
//  Process: Divide the array into a sorted and unsorted region.
//  Find the minimum element in the unsorted region and swap it
//  with the first unsorted element.
//  Descending Order: Find the maximum element instead (change `<` to `>`).
// ─────────────────────────────────────────────────────────────
void selectionSort(vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[minIdx]) minIdx = j;
    swap(arr[i], arr[minIdx]);
  }
  printArr(arr, "Selection Sort");
}

// ─────────────────────────────────────────────────────────────
//  3. Insertion Sort
//  Process: Build the sorted array one item at a time. Pick the
//  next element and insert it into its correct position among
//  the already sorted elements by shifting larger elements right.
//  Best for small / nearly-sorted arrays.
//  Descending Order: Shift elements if they are smaller (change `>` to `<`).
// ─────────────────────────────────────────────────────────────
void insertionSort(vector<int> arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int curr = arr[i], prev = i - 1;
    while (prev >= 0 && arr[prev] > curr) {
      arr[prev + 1] = arr[prev];
      prev--;
    }
    arr[prev + 1] = curr;
  }
  printArr(arr, "Insertion Sort");
}

// ─────────────────────────────────────────────────────────────
//  4. Merge Sort
//  Process: Divide the array into two halves, recursively sort
//  both halves, and then merge them back together in order.
//  Stable, guaranteed O(n log n).
//  Descending Order: In `merge`, pick the larger element (`L[i] >= R[j]`).
// ─────────────────────────────────────────────────────────────
void merge(vector<int>& arr, int l, int m, int r) {
  vector<int> L(arr.begin() + l, arr.begin() + m + 1);
  vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
  int i = 0, j = 0, k = l;
  while (i < (int)L.size() && j < (int)R.size())
    arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
  while (i < (int)L.size()) arr[k++] = L[i++];
  while (j < (int)R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
  if (l >= r) return;
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);
}

// ─────────────────────────────────────────────────────────────
//  5. Quick Sort
//  Process: Choose a 'pivot' element. Partition the array so
//  all elements smaller than the pivot come before it, and all
//  larger elements come after. Recursively sort the sub-arrays.
//  Lomuto partition (simple) vs Hoare (faster in practice).
//  Descending Order: Put larger elements before pivot (`arr[j] >= pivot`).
// ─────────────────────────────────────────────────────────────
int partitionLomuto(vector<int>& arr, int lo, int hi) {
  int pivot = arr[hi], i = lo - 1;
  for (int j = lo; j < hi; j++)
    if (arr[j] <= pivot) swap(arr[++i], arr[j]);
  swap(arr[i + 1], arr[hi]);
  return i + 1;
}

void quickSort(vector<int>& arr, int lo, int hi) {
  if (lo >= hi) return;
  int p = partitionLomuto(arr, lo, hi);
  quickSort(arr, lo, p - 1);
  quickSort(arr, p + 1, hi);
}

// ─────────────────────────────────────────────────────────────
//  6. Heap Sort
//  Process: Build a max-heap from the array. Repeatedly extract
//  the maximum element (root) and swap it with the last element,
//  then restore the heap property for the remaining elements.
//  Descending Order: Build a min-heap instead of a max-heap.
// ─────────────────────────────────────────────────────────────
void heapify(vector<int>& arr, int n, int i) {
  int largest = i, l = 2 * i + 1, r = 2 * i + 2;
  if (l < n && arr[l] > arr[largest]) largest = l;
  if (r < n && arr[r] > arr[largest]) largest = r;
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(vector<int> arr) {
  int n = arr.size();
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);  // Build max-heap
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
  printArr(arr, "Heap Sort");
}

// ─────────────────────────────────────────────────────────────
//  7. Counting Sort   — for non-negative integers in range [0,k]
//  Process: Count the occurrences of each distinct element.
//  Compute prefix sums to find the correct sorted positions.
//  Descending Order: Iterate prefix sums backwards, or fill `out` from front.
// ─────────────────────────────────────────────────────────────
void countingSort(vector<int> arr) {
  int maxVal = *max_element(arr.begin(), arr.end());
  vector<int> count(maxVal + 1, 0);
  for (int x : arr) count[x]++;
  for (int i = 1; i <= maxVal; i++) count[i] += count[i - 1];  // prefix sum
  vector<int> out(arr.size());
  for (int i = arr.size() - 1; i >= 0; i--) out[--count[arr[i]]] = arr[i];
  printArr(out, "Counting Sort");
}

// ─────────────────────────────────────────────────────────────
//  8. Radix Sort (LSD — Least Significant Digit)
//  Process: Sort elements digit by digit, starting from the
//  least significant digit to the most. Uses a stable sort (Counting Sort).
//  Descending Order: Sort digits in reverse order (9 to 0).
// ─────────────────────────────────────────────────────────────
void countSortByDigit(vector<int>& arr, int exp) {
  int n = arr.size();
  vector<int> out(n), count(10, 0);
  for (int x : arr) count[(x / exp) % 10]++;
  for (int i = 1; i < 10; i++) count[i] += count[i - 1];
  for (int i = n - 1; i >= 0; i--) out[--count[(arr[i] / exp) % 10]] = arr[i];
  arr = out;
}

void radixSort(vector<int> arr) {
  int maxVal = *max_element(arr.begin(), arr.end());
  for (int exp = 1; maxVal / exp > 0; exp *= 10) countSortByDigit(arr, exp);
  printArr(arr, "Radix Sort");
}

// ─────────────────────────────────────────────────────────────
//  9. Shell Sort
//  Process: A generalized version of insertion sort. It sorts
//  elements separated by a 'gap', progressively reducing the gap
//  until it becomes 1 (which is standard insertion sort).
//  Descending Order: Shift if elements are smaller (change `>` to `<`).
// ─────────────────────────────────────────────────────────────
void shellSort(vector<int> arr) {
  int n = arr.size();
  for (int gap = n / 2; gap > 0; gap /= 2)
    for (int i = gap; i < n; i++) {
      int temp = arr[i], j = i;
      while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        j -= gap;
      }
      arr[j] = temp;
    }
  printArr(arr, "Shell Sort");
}

// ─────────────────────────────────────────────────────────────
int main() {
  vector<int> arr = {74, 34, 25, 12, 22, 11, 90};
  cout << "===== Sorting Algorithms =====\n";
  printArr(arr, "Input");
  cout << "\n";

  bubbleSort(arr);
  selectionSort(arr);
  insertionSort(arr);

  vector<int> ms = arr;
  mergeSort(ms, 0, ms.size() - 1);
  printArr(ms, "Merge Sort");

  vector<int> qs = arr;
  quickSort(qs, 0, qs.size() - 1);
  printArr(qs, "Quick Sort");

  heapSort(arr);
  countingSort(arr);
  radixSort(arr);
  shellSort(arr);

  cout << "\n===== Complexity Reference =====\n";
  cout << "Algorithm       | Best      | Avg       | Worst     | Space   | "
          "Stable\n";
  cout << "Bubble Sort     | O(n)      | O(n^2)    | O(n^2)    | O(1)    | "
          "Yes\n";
  cout
      << "Selection Sort  | O(n^2)    | O(n^2)    | O(n^2)    | O(1)    | No\n";
  cout << "Insertion Sort  | O(n)      | O(n^2)    | O(n^2)    | O(1)    | "
          "Yes\n";
  cout << "Merge Sort      | O(nlogn)  | O(nlogn)  | O(nlogn)  | O(n)    | "
          "Yes\n";
  cout
      << "Quick Sort      | O(nlogn)  | O(nlogn)  | O(n^2)    | O(logn) | No\n";
  cout
      << "Heap Sort       | O(nlogn)  | O(nlogn)  | O(nlogn)  | O(1)    | No\n";
  cout << "Counting Sort   | O(n+k)    | O(n+k)    | O(n+k)    | O(k)    | "
          "Yes\n";
  cout << "Radix Sort      | O(d(n+k)) | O(d(n+k)) | O(d(n+k)) | O(n+k)  | "
          "Yes\n";

  return 0;
}
