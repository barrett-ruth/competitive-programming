#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using f128 = long double;
//  }}}

void solve() {
  u64 n;
  u32 k, q;
  cin >> n >> k >> q;
  vector<u64> a(k + 1, 0), b(k + 1, 0);
  for (u32 i = 0; i < k; ++i) {
    cin >> a[i + 1];
  }
  for (u32 i = 0; i < k; ++i) {
    cin >> b[i + 1];
  }
  u64 d;
  while (q--) {
    cin >> d;
    auto it = lower_bound(a.begin(), a.end(), d);
    u64 dist = distance(a.begin(), it);
    u64 ans = b[dist];
    if (d < *it) {
      ans = b[dist - 1] +
            (d - a[dist - 1]) * (b[dist] - b[dist - 1]) / (*it - *prev(it));
    }
    cout << ans << ' ';
  }
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

