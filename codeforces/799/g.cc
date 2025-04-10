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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) {
    cin >> e;
  }
  vector<int> can(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    can[i] = a[i] / 2.0 < a[i + 1];
  }
  int ans = 0, window = 0;
  // had <= , not < k - 1, then had it wrong AGAIN
  // NOTE: sliding window impl bad - just decide on one approach and go with it
  for (int i = 0; i < n - 1; ++i) {
    window += can[i];
    if (i >= k - 1) {
      if (window == k) {
        ++ans;
      }
      window -= can[i - k + 1];
    }
  }
  // for (int i = 0; i < n - 1; ++i) {
  //   can[i] = (i ? can[i - 1] : 0) + (a[i] / 2.0 < a[i + 1]);
  // }
  // int ans = 0;
  // for (int i = k - 1; i < n - 1; ++i) {
  //   // cout << "i: " << i << endl;
  //   // NOTE: i - k - 1 before (wrong)
  //   if (can[i] - (i - k >= 0 ? can[i - k] : 0) == k) {
  //     // cout << "yes\n";
  //     ++ans;
  //   }
  // }
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
