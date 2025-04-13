#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

void solve() {
  size_t n;
  cin >> n;
  vector<long long> a(n);
  for (auto& e : a)
    cin >> e;

  vector<long long> f(30, 0);
  for (long long x : a) {
    for (size_t bit = 0; bit < 30; ++bit) {
      if (x & (1 << bit))
        ++f[bit];
    }
  }

  long long ans = 0;
  for (long long x : a) {
    long long cur = 0;
    for (long long bit = 0; bit < 30; ++bit) {
      // add left/right accordingly
      cur += (x & (1 << bit)) ? ((n - f[bit]) * (1 << bit))
                              : (f[bit] * (1 << bit));
    }
    ans = max(ans, cur);
  }

  cout << ans << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int tc = 1;
  cin >> tc;

  for (long long t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
