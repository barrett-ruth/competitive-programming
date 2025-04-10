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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> f(10, 0);
  for (auto& e : a)
    cin >> e;

  for (int i = 0; i < n; ++i) {
    ++f[a[i] % 10];
  }
  // NOTE: missed n - 2, did just < n
  // NOTE: also, removed f[digit] after, causing a[i] % 10 to be
  // included in f erroneously
  for (int i = 0; i < n - 2; ++i) {
    int digit = a[i] % 10;
    --f[digit];

    for (int l = 0; l <= 9; ++l) {
      for (int r = 0; r <= 9; ++r) {
        if ((l + r + digit) % 10 == 3) {
          // NOTE: forgot l != r condition
          // simplify conditions
          if ((l == r && f[l] >= 2) || (l != r && f[l] >= 1 && f[r] >= 1)) {
            cout << "YES\n";
            return;
          }
        }
      }
    }
  }

  cout << "NO\n";
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
