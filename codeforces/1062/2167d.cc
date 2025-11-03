#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;
using u64 = unsigned long long;
vector<u64> a;
int n;
void solve() {
  cin >> n;
  a.resize(n);
  for (auto& e : a) cin >> e;

  for (u64 i = 2;; ++i) {
    for (auto& e : a) {
      if (gcd(e, i) == 1) {
        cout << i << '\n';
        return;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}

