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

  vector<vector<int>> grid(n, vector<int>(m));
  int r = 0, c = 0;
  i32 cur = 1;
  for (i64 i = 0; i < n * m; ++i) {
    grid[r][c] = cur;
    if (++cur == k + 1) {
      cur = 1;
    }
    if (++c == m) {
      c = 0;
      ++r;
    }
  }
  if (m % k == 0) {
    for (int r = 0; r < n; r += 2) {
      for (int c = 0; c < m; ++c)
        if (++grid[r][c] == k + 1) {
          grid[r][c] = 1;
        }
    }
  }
  for (auto& row : grid) {
    for (auto& cell : row)
      cout << cell << ' ';
    cout << endl;
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
