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
  string time;
  cin >> time;
  u32 hour = stoi(time.substr(0, 2));
  u32 minute = stoi(time.substr(3, 2));

  bool pm = hour >= 12;
  if (hour > 12) {
    hour %= 12;
  }
  if (hour == 0) {
    hour = 12;
  }

  if (hour < 10) {
    cout << '0';
  }
  cout << hour << ':';
  if (minute < 10) {
    cout << '0';
  }
  cout << minute << ' ' << (pm ? "PM" : "AM") << '\n';
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
