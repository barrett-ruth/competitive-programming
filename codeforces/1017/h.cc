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
  i64 n, q;
  cin >> n >> q;
  vector<i64> a(n);
  map<i32, vector<u32>> m;
  for (i64 i = 0; i < n; ++i) {
    cin >> a[i];
    m[a[i]].emplace_back(i);
  }
  i64 k;
  i64 l, r;
  while (q--) {
    cin >> k >> l >> r;
    // NOTE: messed up one-indexing
    --l;
    --r;
    set<i64> indices;
    for (i64 i = 1; i <= floor(sqrt(k)); ++i) {
      if (k % i) {
        continue;
      }
      if (i != 1 && m.contains(i)) {
        auto it = lower_bound(m[i].begin(), m[i].end(), l);
        // NOTE: *it >= l unneedeed based on biesct
        if (it != m[i].end() && *it <= r)
          indices.emplace(*it);
      }
      if (k / i != i && m.contains(k / i)) {
        auto it = lower_bound(m[k / i].begin(), m[k / i].end(), l);
        if (it != m[k / i].end() && *it <= r)
          // typo, did i (NOT what you wanted ot code)
          indices.emplace(*it);
      }
    }
    i64 ans = 0;
    i64 i = l;
    for (auto it = indices.begin(); it != indices.end(); ++it) {
      // NOTE: confusion with maintaining invariants; decide one approach and go
      ans += k * (*it - i);
      while (k % a[*it] == 0) {
        k /= a[*it];
      }
      i = *it;
    }
    // NOTE: had to do l <= r
    // NOTE: was just counting wrong, this way was better
    if (i <= r)
      ans += k * (r - i + 1);
    cout << ans << '\n';
  }
}

// NOTE: didn't know data structure inserted value
// NOTE: was debugging and thought, for example, that u32 was the issue
// im not even inspectingmy thought s- i know this is impossible - why did i
// think this then?

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
