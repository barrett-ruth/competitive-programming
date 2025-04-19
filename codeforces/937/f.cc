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
  u64 a, b, c;
  cin >> a >> b >> c;

  u64 depth = 0;
  u64 to_take = 1;

  // NOTE :look at prev wrong submissions; full tree assumptions, when u can
  // have b on last layer this should be oe of ur first observatoins
  while (to_take && (a > 0 || b > 0 || c > 0)) {
    ++depth;
    u64 next_to_take = 0;

    auto take = min(a, to_take);
    a -= take;
    next_to_take = 2 * take;
    to_take -= take;

    take = min(b, to_take);
    b -= take;
    to_take -= take;
    next_to_take += take;

    take = min(c, to_take);
    c -= take;
    to_take -= take;

    if (to_take != 0) {
      break;
    }

    to_take = next_to_take;
  }

  if (to_take > 0 || a > 0 || b > 0 || c > 0) {
    cout << -1 << '\n';
  } else {
    cout << depth - 1 << '\n';
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
