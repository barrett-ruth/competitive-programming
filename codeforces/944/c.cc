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
  u32 a, b, c, d;
  cin >> a >> b >> c >> d;
  i32 acc = 0;
  for (u32 i = 1; i <= 12; ++i) {
    if (i == a || i == b)
      acc = (acc << 1) | 1;
    else if (i == c || i == d)
      acc <<= 1;
  }
  cout << ((acc == 0b1010 || acc == 0b0101) ? "YES" : "NO") << '\n';
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
