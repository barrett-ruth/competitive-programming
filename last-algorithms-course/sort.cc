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

int main() {
  vector<int> arr = {123, 1, 2, 3, 122, -2};

  for (const auto& e : arr) std::cout << e << ' ';
  std::cout << '\n';
  /* bubble_sort(arr); */
  insertion_sort(arr);
  for (const auto& e : arr) std::cout << e << ' ';
}
