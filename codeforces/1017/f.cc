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
  i32 n, m, k;
  cin >> n >> m >> k;

  if (n > m) {
    swap(n, m);
  }

    // 3x4 -> [1, 2 ,1, 2]
    //        [2, 1, 2, 1]
    //        [1, 2, 1, 2]

    // if even # cols/rows -> ez (i.e. either even, swap)
    // REDUCE: odd # cols & rows
    // [1, 2, 3]
    // [2, 3, 1]
    // [3, 2, 1]


  i32 cur = -1;
  if (n & 1 && m & 1) {
    cur = (cur + 1) % m;
    for (i32 i = 0; i < n; ++i) {
      for ()
    }
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
