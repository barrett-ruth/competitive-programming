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
  u32 n;
  cin >> n;

  vector<vector<char>> board(2 * n, vector<char>(2 * n, '.'));
  for (u32 i = 0; i < n; ++i) {
    for (u32 j = 0; j < n; ++j) {
      if ((i & 1) == (j & 1)) {
        board[2 * i][2 * j] = '#';
        board[2 * i + 1][2 * j] = '#';
        board[2 * i + 1][2 * j + 1] = '#';
        board[2 * i][2 * j + 1] = '#';
      }
    }
  }
  for (auto& r : board) {
    for (auto& c : r) {
      cout << c;
    }
    cout << '\n';
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
