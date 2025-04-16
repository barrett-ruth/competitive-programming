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
  string s;
  cin >> s;
  u64 ans = n;
  for (u32 i = 1; i < n; ++i) {
    if (n % i) {
      continue;
    }
    unordered_map<string, int> seen;
    bool bad = false;
    for (u32 j = 0; j < n; j += i) {
      ++seen[s.substr(j, i)];
      if (seen.size() > 2) {
        bad = true;
        break;
      }
    }
    if (bad)
      continue;
    if (seen.size() == 1) {
      ans = i;
      break;
    } else if (seen.size() == 2) {
      int first = seen.begin()->second, second = next(seen.begin())->second;
      int diff = 0;
      for (u32 j = 0; j < seen.begin()->first.size(); ++j) {
        diff += seen.begin()->first[j] != next(seen.begin())->first[j];
      }
      if ((first == 1 || second == 1) && diff <= 1) {
        ans = i;
        break;
      }
    }
  }
  cout << ans << endl;
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
