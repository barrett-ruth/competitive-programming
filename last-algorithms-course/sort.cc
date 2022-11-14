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
  // Hi index implementation
  int i = lo;
  int pivot = arr[hi];

  for (int j = lo; j < hi; ++j) {
    if (arr[j] <= pivot) std::swap(arr[j], arr[i++]);
  }

  std::swap(arr[i], arr[hi]);

  return i;

  // Lo index implementation
  /* int pivot = arr[lo]; */
  /* int i = lo; */
  /**/
  /* for (int j = lo + 1; j <= hi; ++j) { */
  /*   if (arr[j] < pivot) std::swap(arr[j], arr[++i]); */
  /* } */
  /**/
  /* std::swap(arr[lo], arr[i]); */

  // Middle index implementation
  /* int mid = lo + (hi - lo) / 2; */
  /* int pivot = arr[mid]; */
  /* int i = lo; */
  /**/
  /* for (int j = lo; j < mid; ++j) { */
  /*   if (arr[j] < pivot) std::swap(arr[j], arr[i++]); */
  /* } */
  /**/
  /* for (int j = mid + 1; j <= hi; ++j) { */
  /*   if (arr[j] < pivot) { */
  /*     if (i == mid) ++i; */
  /*     if (i < hi) std::swap(arr[j], arr[i++]); */
  /*   } */
  /* } */
  /**/
  /* std::swap(arr[i], arr[mid]); */

  /* return i; */
}

void quicksort(vector<int>& arr, int lo, int hi) {
  if (lo >= hi) return;

  int idx = partition(arr, lo, hi);
  quicksort(arr, lo, idx - 1);
  quicksort(arr, idx + 1, hi);
}

void quicksort(vector<int>& arr) { quicksort(arr, 0, (int)arr.size() - 1); }

void merge(vector<int>& arr, int lo, int mid, int hi) {
  int left[mid - lo + 1];
  int right[hi - mid];

  for (int i = 0; i < mid - lo + 1; ++i) left[i] = arr[lo + i];

  for (int i = 0; i < hi - mid; ++i) right[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = lo;

  while (i < mid - lo + 1 && j < hi - mid)
    if (left[i] <= right[j])
      arr[k++] = left[i++];
    else
      arr[k++] = right[j++];

  while (i < mid - lo + 1) arr[k++] = left[i++];
  while (j < hi - mid) arr[k++] = right[j++];
}

void mergesort(vector<int>& arr, int lo, int hi) {
  if (lo >= hi) return;

  int mid = lo + (hi - lo) / 2;
  mergesort(arr, lo, mid);
  mergesort(arr, mid + 1, hi);
  merge(arr, lo, mid, hi);
}

void mergesort(vector<int>& arr) { mergesort(arr, 0, (int)arr.size() - 1); }

int main() {
  vector<int> arr = {-2, -3, 123, 0, 123, 1, 1, 2, 0, 3, 122, -2};

  for (const auto& e : arr) std::cout << e << ' ';
  std::cout << '\n';
  /* bubble_sort(arr); */
  /* insertion_sort(arr); */
  // quicksort(arr);
  mergesort(arr);
  for (const auto& e : arr) std::cout << e << ' ';
}
