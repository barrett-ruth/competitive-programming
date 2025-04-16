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
  u32 r;
  cin >> r;
  u64 ans = 0;

  for (u64 y = 1; y <= r; ++y) {
    i64 hi_x, lo_x;

    {
      i64 l = 0, h = r;
      while (l <= h) {
        i64 m = l + (h - l) / 2;
        if (m * m + y * y < (u64)r * r) {
          l = m + 1;
        } else {
          h = m - 1;
        }
      }
      lo_x = l;
    }

    {
      i64 l = 0, h = r;
      while (l <= h) {
        i64 m = l + (h - l) / 2;
        if (m * m + y * y < ((u64)r + 1) * (r + 1)) {
          l = m + 1;
        } else {
          h = m - 1;
        }
      }
      hi_x = h;
    }

    ans += (hi_x - lo_x + 1) * 4;
  }

  cout << ans << '\n';
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
