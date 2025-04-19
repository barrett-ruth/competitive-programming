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
  vector<u32> a(n);
  for (u32 i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> prefix_one(n + 1, 0), postfix_zero(n + 2, 0);
  for (u32 i = 0; i < n; ++i) {
    prefix_one[i + 1] = (a[i] == 1) + prefix_one[i];
  }
  for (i32 i = n - 1; i >= 0; --i) {
    postfix_zero[i + 1] = postfix_zero[i + 2] + (a[i] == 0);
  }
  postfix_zero[0] = postfix_zero[1];

  i64 ans = 0;
  for (u32 i = 0; i < n; ++i) {
    if (a[i] == 1)
      ans += postfix_zero[i + 2];
  }
  i64 init = ans;

  for (u32 i = 0; i < n; ++i) {
    if (a[i] == 0)
      ans = max(ans, init + postfix_zero[i + 2] - prefix_one[i]);
    else if (a[i] == 1)
      ans = max(ans, init + prefix_one[i] - postfix_zero[i + 2]);
    // } else {  // NOTE: forgot 0->1 is possible
    // }
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

