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
  vector<i32> a(n);
  for (auto& e : a)
    cin >> e;
  if (n == 1) {
    cout << a[0] << '\n';
    return;
  }
  vector<i32> ans(n);
  auto copy = a;
  sort(copy.begin(), copy.end());
  auto big = copy.back(), big2 = copy[copy.size() - 2];
  for (u4 i = 0; i < n; ++i) {
    if (a[i] == big) {
      ans[i] = a[i] - big2;
    } else
      ans[i] = a[i] - big;
  }
  for (auto e : ans)
    cout << e << ' ';
  cout << '\n';
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
