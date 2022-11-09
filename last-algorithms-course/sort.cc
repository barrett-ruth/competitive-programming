#include <iostream>
#include <vector>

using namespace std;

// Bubble sort
// O(n^2) time complexity
// O(1) space complexity
void bubble_sort(vector<int>& arr) {
  // After each iteration the ith largest number "bubbled up" to the right idx
  // Only iterate up until that spot -- succeeding elements ordered
  for (int til = (int)arr.size(); til > 1; --til) {
    for (int i = 0; i < til - 1; ++i) {
      if (arr[i] > arr[i + 1])
        // "bubble up" arr[i] -- arr[i] will be the same for the next iteration
        std::swap(arr[i], arr[i + 1]);
    }
  }
}

// Insertion sort
// O(n^2) time complexity
// O(1) space complexity
void insertion_sort(vector<int>& arr) {
  for (int i = 1; i < (int)arr.size(); ++i) {
    int j = i - 1;
    int key = arr[i];

    while (j > -1 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }

    arr[j + 1] = key;
  }
}

int partition(vector<int>& arr, int lo, int hi) {
  /* int pivot = lo + (hi - lo) / 2; */

  int pivot = arr[hi];  // last index for now
  int i = lo;

  for (int j = lo; j < hi; ++j) {
    if (arr[j] < pivot) std::swap(arr[i++], arr[j]);
  }

  std::swap(arr[i], arr[hi]);

  return i;
}

void quicksort(vector<int>& arr, int lo, int hi) {
  if (lo >= hi) return;

  int idx = partition(arr, lo, hi);
  quicksort(arr, lo, idx - 1);
  quicksort(arr, idx + 1, hi);
}

void quicksort(vector<int>& arr) { quicksort(arr, 0, (int)arr.size() - 1); }

int main() {
  vector<int> arr = {123, 1, 2, 3, 122, -2};

  for (const auto& e : arr) std::cout << e << ' ';
  std::cout << '\n';
  /* bubble_sort(arr); */
  /* insertion_sort(arr); */
  quicksort(arr);
  for (const auto& e : arr) std::cout << e << ' ';
}
