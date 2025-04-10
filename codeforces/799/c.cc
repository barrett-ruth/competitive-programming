#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

#define prln(...) std::println(__VA_ARGS__)
#define pr(...) std::print(__VA_ARGS__)

#ifdef LOCAL
#define dbgln(...) std::println(__VA_ARGS__)
#define dbg(...) std::print(__VA_ARGS__)
#else
#define dbgln(...)
#define dbg(...)
#endif
//  }}}

void solve() {
  vector<string> board(8);
  for (auto& s : board)
    cin >> s;

  for (int r = 1; r <= 6; ++r) {
    for (int c = 1; c <= 6; ++c) {
      if (board[r][c] == '#' && board[r - 1][c - 1] == '#' &&
          board[r + 1][c + 1] == '#' && board[r - 1][c + 1] == '#' &&
          board[r + 1][c - 1] == '#') {
        cout << r + 1 << ' ' << c + 1 << '\n';
        return;
      }
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
