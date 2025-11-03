#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int n;
void solve() {
  cin >> n;
  a.resize(n);
  bool odd = false, even = false;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    odd |= a[i] & 1;
    even |= a[i] % 2 == 0;
  }

  if (odd && even) {
    sort(begin(a), end(a));
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i == n - 1];
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}


