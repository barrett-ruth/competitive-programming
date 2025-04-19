#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u4 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using f128 = long double;
//  }}}

void solve() {
  u4 n;
  cin >> n;
  vector<u4> a(n);
  for (auto& e : a)
    cin >> e;
  u4 i = 0;
  while (i < n - 1 && a[i] >= a[i + 1]) {
    ++i;
  }
  while (i < n - 1 && a[i] <= a[i + 1]) {
    ++i;
  }

  if (i == n - 1)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int tc = 1;
  cin >> tc;

  for (int t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
