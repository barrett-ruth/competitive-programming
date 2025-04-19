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
  i64 n, c, d;
  cin >> n >> c >> d;

  vector<i64> a(n);
  for (auto& e : a)
    cin >> e;
  sort(a.rbegin(), a.rend());

  i64 low = 1, high = d + 2;
  i64 ans = -1;

  while (low <= high) {
    i64 k = low + (high - low) / 2;
    i64 total = 0;
    for (i64 i = 0; i < d; ++i) {
      total += a[i % k];
    }

    if (total >= c) {
      ans = k;
      low = k + 1;
    } else {
      high = k - 1;
    }
  }

  if (low == 0) {
    cout << "Impossible\n";
  } else if (low == d + 1) {
    cout << "Infinity\n";
  } else {
    cout << ans << '\n';
  }
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
