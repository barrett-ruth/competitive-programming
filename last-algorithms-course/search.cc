#include <iostream>
#include <vector>

using namespace std;

// Linear search
// O(n) time complexity
// O(1) space complexity
bool linear_search(vector<int> arr, int val) {
  for (int i = 0; i < (int)arr.size(); ++i)
    if (arr[i] == val) return true;
  return false;
}

// Binary search
// O(log(n)) time complexity
// O(1) space complexity
int binary_search(vector<int> arr, int val, int lo, int hi) {
  while (lo < hi) {
    // Same as (hi + lo) / 2 -- avoid overflow
    int mid = lo + (hi - lo) / 2;

    if (arr[mid] == val)
      return mid;
    else if (arr[mid] < val)
      lo = mid + 1;
    else
      hi = mid - 1;
  }

  // when equal, lo & hi may be at right *or* wrong value -- check
  return arr[lo] == val ? lo : -1;
}

// Return leftmost position in which val would be inserted
int bisect_left(vector<int> arr, int val, int lo, int hi) {
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;

    if (arr[mid] < val)
      lo = mid + 1;
    else
      hi = mid;
  }

  return lo;
}

// Return rightmost position in which val would be inserted
int bisect_right(vector<int> arr, int val, int lo, int hi) {
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;

    if (arr[mid] > val)
      hi = mid;
    else  // arr[mid] <= val
      lo = mid + 1;
  }

  return lo;
}

int main() {
  vector<int> arr = {1, 6, 8, 8, 12, 14, 23};

  std::cout << binary_search(arr, 8, 0, (int)arr.size());

  for (const auto& e : arr) {
    std::cout << linear_search(arr, e);
    std::cout << bisect_left(arr, e, 0, (int)arr.size());
    std::cout << bisect_right(arr, e, 0, (int)arr.size());
    std::cout << binary_search(arr, e, 0, (int)arr.size());
    std::cout << '\n';
  }
}
