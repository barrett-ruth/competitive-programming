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
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  int total = 0;
  for (auto& e : a) {
    cin >> e;
    total += e;
  }
  if (total < s) {
    cout << -1 << '\n';
    return;
  }

  int r = n - 1;
  int cur = 0;
  while (cur != total - s) {
    cur += a[r] == 1;
    --r;
  }
  ++r;
  int ans = n - r;
  for (int l = 0; l < n; ++l) {
    if (a[l] == 0) {
      continue;
    }
    // NOTE: while loop instead of maintaing invariant
    ++r;
    while (r < n && a[r] == 0) {
      ++r;
    }
    ans = min(ans, l + 1 + n - r);
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
