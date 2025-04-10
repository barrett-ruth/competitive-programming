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

bitset<10000 + 1> seen;
void solve() {
  seen.reset();
  int n;
  cin >> n;
  int a, dups = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (seen[a]) {
      ++dups;
    } else {
      seen[a] = true;
    }
  }

  int unique = n - dups;
  cout << (dups & 1 ? unique - 1 : unique) << '\n';
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
